#include<stdio.h>


void main(){
	int n=0;
	printf("Enter number of vertices-");
	scanf("%d",&n);
	int temp=n*n;
	int * ar=malloc(temp*sizeof(int));
	printf("Enter weight matrix - ");
	for(int i=0;i<temp;i++){
		scanf("%d",ar+i);
	}
}
