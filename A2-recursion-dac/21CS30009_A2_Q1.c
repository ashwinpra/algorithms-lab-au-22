/* Name: Ashwin Prasanth 
Roll No.: 21CS30009
Department: CSE
Machine No.: 40 */

#include<stdlib.h>
#include<stdio.h>

/*
	Recursive approach:
	
	We will move index-by-index recursively, and store the string generated in an array, 
	which will be done character-by-character
	Finally when we reach the last index, we print this array (message) and return 

 */


// Making a structure to store letters corresponding to each switch
typedef struct{
	char* letters;
}key;

key keys[8]; // Declaring a global array of keys that will store letters of every switch


void getMsg(int *seq, int size, int idx, char* store){

	// Base case, i.e. when it reaches the end
	if(idx==size) {
		for(int i=0;store[i]!='\0'; i++) printf("%c",store[i]);
		printf("\n");
		return;
	}
	// Recursive Case
	else{
		// for each index, we store every possible letter in the string
		int key = seq[idx];
		for(int i=0;keys[key-1].letters[i]!='\0';i++){
			store[idx] = keys[key-1].letters[i]; //storing the letter one by one
			
			getMsg(seq,size,idx+1,store); // recursive call
		}
	}
}


int main()
{	
	// Previously declared global array is filled to store the letters corresponding 
	// to each switch
	for(int i=0;i<8;i++){
		
		switch(i+1){
		case 1: {
			keys[i].letters = (char*)malloc(3*sizeof(char));
			keys[i].letters = "ABC";
			break;
		}
		case 2:{
			keys[i].letters = (char*)malloc(3*sizeof(char));
			keys[i].letters = "ONM";
			break;

		}
		case 3: {
			keys[i].letters = (char*)malloc(3*sizeof(char));
			keys[i].letters = "IHG";
			break;

		}
		case 4: {
			keys[i].letters = (char*)malloc(4*sizeof(char));
			keys[i].letters = "JLKZ";
			break;

		}
		case 5: {
			keys[i].letters = (char*)malloc(3*sizeof(char));
			keys[i].letters = "DFE";
			break;

		}
		case 6: {
			keys[i].letters = (char*)malloc(3*sizeof(char));
			keys[i].letters = "WYX";
			break;

		}
		case 7: {
			keys[i].letters = (char*)malloc(4*sizeof(char));
			keys[i].letters = "TUVS";
			break;

		}
		case 8: {
			keys[i].letters = (char*)malloc(3*sizeof(char));
			keys[i].letters = "RQP";
			break;
		}
	}
	}

	// Taking switch sequence as input from user
	int n;
	printf("Enter size of switch sequence:\n");
	scanf("%d",&n);

	int sw_seq[n];
	printf("Enter switch sequence:\n");
	for (int i = 0; i < n; ++i) scanf("%d",&sw_seq[i]);

	char store[100]; //placeholder array that will store each sequence
	
	printf("All possible messages are: ");
	getMsg(sw_seq,n,0,store); // Calling the main recursive function


	return 0;
}