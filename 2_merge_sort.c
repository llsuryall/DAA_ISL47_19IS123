#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int * inpIntArray(int n){
	if(n>0){
		printf("Enter the elements of array -\n-> ");
		int * ar=malloc(n*sizeof(int));
		for(int i=0;i<n;i++){
			scanf("%d",ar+i);
		}
		return ar;
	}else{
		return NULL;
	}
}

void print_IntArr(int * ar,int n){
	if(n>0){
		for(int i=0;i<n-1;i++){
			printf("%d ",ar[i]);
		}
		printf("%d",ar[n-1]);
	}
}

void endl(){
	printf("\n");
}

void merge(int * ar,int n){
	int curL=0,curR=n/2,i=0;
	int * cpy=malloc(n*sizeof(int));
	memcpy(cpy,ar,n*sizeof(int));
	while(curL<n/2 && curR<n){
		if(cpy[curL]<cpy[curR]){
			ar[i]=cpy[curL];
			curL++;
		}else{
			ar[i]=cpy[curR];
			curR++;
		}
		i++;
	}
	if(curL<n/2){
		memcpy(ar+i,cpy+curL,(n-i)*sizeof(int));
	}else{
		memcpy(ar+i,cpy+curR,(n-i)*sizeof(int));
	}
	free(cpy);
}

void merge_sort(int * ar,int n){
	if(n>=2){
		merge_sort(ar,n/2);
		merge_sort(ar+n/2,n-n/2);
		merge(ar,n);
	}
}

void main(){
	int n=0;
	printf("Enter size of array - ");
	scanf("%d",&n);
	int * ar=inpIntArray(n);
	if(ar==NULL){
		printf("Invalid input!");endl();
		return;
	}
	merge_sort(ar,n);
	printf("Sorted array-\n-> ");
	print_IntArr(ar,n);endl();
	free(ar);
}
