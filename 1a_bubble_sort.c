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

void bubble_sort(int * ar,int n){
	_Bool flag=true;
	int temp=0;
	while(flag){
		flag=false;
		for(int i=1;i<n;i++){
			if(ar[i-1]>ar[i]){
				temp=ar[i];
				ar[i]=ar[i-1];
				ar[i-1]=temp;
				flag=true;
			}
		}
		n--;
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

void main(){
	int n=0;
	printf("Enter size of array - ");
	scanf("%d",&n);
	int * ar=inpIntArray(n);
	if(ar==NULL){
		printf("Invalid input!");endl();
		return;
	}
	bubble_sort(ar,n);
	printf("Sorted array-\n-> ");
	print_IntArr(ar,n);endl();
}
