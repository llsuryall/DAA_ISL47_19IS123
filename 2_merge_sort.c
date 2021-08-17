#include<stdio.h> //for input/output
#include<stdlib.h> // for malloc
#include<string.h> // for memcpy


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

/*
 The following function merges 2 paritions inside an array of size 'n' with following assumptions,
 	1. the array is divided into 2 partitions as follows
		 Left partition - [ 0, (n/2)-1 ]
		 Right partition - [ n/2, n-1 ]
	2. both paritions are sorted in ascending order
 With these assumtions it merges those partitions to into a single sorted array
*/
void merge(int * ar,int n){
	int curL=0,curR=n/2,i=0; // curL - current Left, curR - current Right
	int * cpy=malloc(n*sizeof(int)); // allocate for copy of current array
	memcpy(cpy,ar,n*sizeof(int)); // copy the current array to the allocated space

	/*
	compare both partitions and insert the smallest element to the main array one by one
	loop until any one of the partitions are fully traversed
	*/
	while(curL<n/2 && curR<n){
		// comparing curL and curR
		if(cpy[curL]<cpy[curR]){
			ar[i]=cpy[curL];// insert the smaller one(curL)
			curL++;// increment curL to move to the next element in left array
		}else{
			ar[i]=cpy[curR];// insert eh smaller one(curR)
			curR++;// increment curR to move to the next element in right array
		}
		i++;
	}
	// insert leftovers from either left or right array to the main array
	if(curL<n/2){
		memcpy(ar+i,cpy+curL,(n-i)*sizeof(int));
	}else{
		memcpy(ar+i,cpy+curR,(n-i)*sizeof(int));
	}
	free(cpy); // deallocate the copy
}

// Merge sort array starting from base address 'ar' till 'n' elements
void merge_sort(int * ar,int n){
	/*
	if 'n' is '0' or '1' then array will already be sorted, no need to sort
	otherwise we sort in the following way,
		1. partition array into 2 parts, namely left part [0,(n/2)-1] & right part [n/2,n-1]
		2. sort each of them seperately
		3. merge together

	this will result in a recursive call of 'merge_sort' function,
	which will happen until the array is split into 2 paritions with only 1 element in each(or no element in one side of array)
	these 2 single elments are sorted by themselves, so we only need to merge them with 'merge' function
	*/
	if(n>=2){
		merge_sort(ar,n/2); // sort left partition
		merge_sort(ar+n/2,n-n/2); // sort right partition
		merge(ar,n); // merge both partitions
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
	free(ar); // deallocate the heap memory used for 'ar'
}
