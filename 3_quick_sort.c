#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

int partition(int * ar,int n){
	int pi=n-1,pv=ar[pi],temp,i=0;
	for(;i<n-1;i++){
		if(ar[i]>pv){
			pi=i;
			i++;
			break;
		}
	}
	for(;i<n-1;i++){
		if(ar[i]<=pv){
			temp=ar[i];
			ar[i]=ar[pi];
			ar[pi]=temp;
			pi++;
		}
	}
	temp=ar[n-1];
	ar[n-1]=ar[pi];
	ar[pi]=temp;
	return pi;
}

void quick_sort(int * ar,int n){
	if(n>=2){
		int pivot=partition(ar,n);
		quick_sort(ar,pivot);
		quick_sort(ar+pivot+1,n-pivot-1);
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
	quick_sort(ar,n);
	printf("Sorted array-\n-> ");
	print_IntArr(ar,n);endl();
	free(ar);
}
