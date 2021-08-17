#include<stdio.h> //for input/output
#include<stdlib.h> // for malloc
#include<stdbool.h> // for _Bool

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


// Bubble sort array starting from base address 'ar' till 'n' elements
void bubble_sort(int * ar,int n){
	_Bool flag=true; //initially set flag to be true
	int temp=0; //declare temp variable optionally inititalize it
	while(flag){
		flag=false;
		/* 
		set 'flag' to be false inside loop
		so that if the inner 'if' statement doesn't run even once it should exit
		as it implies loop is already sorted
		OR
		if limit for 'n' inside 'for' loop is reached the inner statements won't run
		so loop will exit
		*/
		for(int i=1;i<n;i++){// start from i=1, as we are comparing previous element with current one
			/* 
			we need bigger elements on the right(ascending)
			so we swap if previous element is greater
			*/
			if(ar[i-1]>ar[i]){ 
				temp=ar[i];
				ar[i]=ar[i-1];
				ar[i-1]=temp;
				flag=true;
			}
		}
		/*
		decrement 'n', as we know that the biggest element will bubble to the top(or end of array) in first iteration
		so we don't need to check the last element as it is already sorted 
		*/
		n--;
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
	bubble_sort(ar,n);
	printf("Sorted array-\n-> ");
	print_IntArr(ar,n);endl();
	free(ar); // deallocate the heap memory used for 'ar'
}
