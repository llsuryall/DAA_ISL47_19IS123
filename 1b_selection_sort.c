#include<stdio.h>
#include<stdlib.h>

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

void selection_sort(int * ar,int n){
	int min_pos,temp;
	for(int base=0;base<n-1;base++){
		min_pos=base;
		for(int i=base+1;i<n;i++){
			if(ar[i]<ar[min_pos]){
				min_pos=i;
			}
		}
		temp=ar[min_pos];
		ar[min_pos]=ar[base];
		ar[base]=temp;
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
	selection_sort(ar,n);
	printf("Sorted array-\n-> ");
	print_IntArr(ar,n);endl();
}
