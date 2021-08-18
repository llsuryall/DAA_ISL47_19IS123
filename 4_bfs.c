#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int q[100],f=-1,r=-1;

void endl(){
	printf("\n");
}

void insert_rear(int d){	
	if(f==-1){
		f=0,r=0;
		q[r]=d;
	}else{
		q[++r]=d;
	}
}

int pop_front(){
	if(f==-1){
		return 0;
	}else if(f>=r){
		int temp=f;
		f=-1,r=-1;
		return q[temp];
	}else{
		f++;
		return q[f-1];
	}
}

_Bool * nodes_reachable(int *ar,int n,int src){
	src--;
	_Bool *visited=calloc(n,sizeof(_Bool));
	insert_rear(src);
	visited[src]=true;
	while(f!=-1){
		src=pop_front();
		for(int j=0;j<n;j++){
			if(*(ar+src*n+j) && (!visited[j])){
				insert_rear(j);
				visited[j]=true;
			}
		}
	}
	return visited;
}

int * inpSqIntMatrix(int n){
	n=n*n;
	int * ar=malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		scanf("%d",ar+i);
	}
	return ar;
}

void printVisitedNodes(_Bool * ar,int n){
	printf("List of visited nodes (out of %d nodes) - ",n);
	for(int i=0;i<n;i++){
		if(ar[i]){
			printf("%d ",i+1);
		}
	}
	endl();
}

void main(){
	int n=0;
	printf("Enter number of vertices - ");
	scanf("%d",&n);
	printf("Enter the adjacency matrix - ");endl();
	int * ar=inpSqIntMatrix(n);
	printf("Enter the initial node no. - ");
	int src=0;
	scanf("%d",&src);
	_Bool * ans=nodes_reachable(ar,n,src);
	printVisitedNodes(ans,n);
}
