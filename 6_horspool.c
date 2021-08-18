#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

void endl(){
	printf("\n");
}

int * shiftTable(char * pattern){
	int n=strlen(pattern)-1;
	int * ar=malloc(sizeof(int)*258);
	for(int i=0;i<256;i++){
		ar[i]=n;
	}
	for(int i=0;i<n-1;i++){
		ar[pattern[i]]=n-i-1;
	}
	return ar;
}

int horspool(char * text,char * pattern, int * shift_table){
	int n=strlen(text)-1,m=strlen(pattern)-1;
	if(n<m){
		return -1;
	}
	int i=m-1,j=m-1,k=0;
	_Bool flag=false;
	while(i<n){
		if(text[i]==pattern[j]){
			flag=true;
			if(j==0){
				return i;
			}
			i--;j--;
		}else{
			if(flag){
				i+=shift_table[pattern[m-1]]+m-j-1;
				j=m-1;
			}else{
				i+=shift_table[text[i]];
			}
			flag=false;
		}
	}
	return -1;
}

void main(){
	char * text=malloc(sizeof(char)*100);
	char * pattern=malloc(sizeof(char)*20);
	printf("Enter the text -");endl();printf("->");
	fgets(text,100,stdin);
	printf("Enter the pattern -");endl();printf("->");
	fgets(pattern,20,stdin);
	int * shift_table=shiftTable(pattern);
	int pos=horspool(text,pattern,shift_table);
	if(pos!=-1){
		printf("The pattern was found at position %d",pos+1);endl();
	}else{
		printf("The pattern was not found");endl();
	}
	free(text);
	free(pattern);
	free(shift_table);
}
