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

void build_heap(int * ar,int n){
	int temp=0;
	for(int i=1;i<n;i++){
		while(ar[(i-1)/2]<ar[i]){
			temp=ar[i];
			ar[i]=ar[(i-1)/2];
			ar[(i-1)/2]=temp;
			i=(i-1)/2;
		}
	}
}

void heapify(int * ar,int n,int i){
	int l=2*i+1,r=2*i+2,temp=0;
	if(l<n){
		if(r<n){
			if(ar[l]>ar[i] || ar[r]>ar[i]){
				if(ar[l]>ar[r]){
					temp=ar[i];
					ar[i]=ar[l];
					ar[l]=temp;
					heapify(ar,n,l);
				}else{
					temp=ar[i];
					ar[i]=ar[r];
					ar[r]=temp;
					heapify(ar,n,r);
				}
			}
		}
		else{
			if(ar[l]>ar[i]){
				temp=ar[i];
				ar[i]=ar[l];
				ar[l]=temp;
			}
		}
	}
}

void heap_sort(int * ar,int n){
	if(n>=2){
		int temp=0;
		build_heap(ar,n);
		for(int i=n-1;i>0;i--){
			temp=ar[i];
			ar[i]=ar[0];
			ar[0]=temp;
			n--;
			heapify(ar,n,0);
		}
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
	heap_sort(ar,n);
	printf("Sorted array-\n-> ");
	print_IntArr(ar,n);endl();
	free(ar); // deallocate the heap memory used for 'ar'
}
