#include<stdio.h>
#include<stdlib.h>

// Input 'n' elements into an array and return the base address
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

// Print array of till 'n' from base address
void print_IntArr(int * ar,int n){
	if(n>0){
		for(int i=0;i<n-1;i++){
			printf("%d ",ar[i]);
		}
		printf("%d",ar[n-1]);
	}
}

// Print newline character
void endl(){
	printf("\n");
}

// Selection sort array starting from base address 'ar' till 'n' elements
void selection_sort(int * ar,int n){
	/*
	in selection sort, we consider the first element and swap it with least element
	then we select the second element and do the same thing
	until (n-1)th element ( as the last element will be sorted by itself )
	*/
	int min_pos,temp;
	for(int base=0;base<n-1;base++){
		min_pos=base;// selecting a base element
		for(int i=base+1;i<n;i++){
		// for finding least element position
			if(ar[i]<ar[min_pos]){
				min_pos=i;
			}
		}
		// swaping with least element
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
	free(ar); // deallocate the heap memory used for 'ar'
}
