/* Name: Ashwin Prasanth 
Roll No.: 21CS30009
Department: CSE
Machine No.: 40 */
#include<stdio.h>
#include<string.h>

/*
	Approach: 
		- We will make a hash table which will be a character array of size 26 (for 26 letters), 
		and it will be prefilled with some arbitrary character
		- The hashing function will simply give the position of the letter in the alphabet, but 0-indexed (a-0, b-1, .. z-25)
		- Iterating through the key, we will populate the hash table,
		making sure that it is filled only if the hash table was
		previously empty (ie contains the arbitrary character)
		- Finally this hash table will be used to decode the message 
*/

// Hashing function that returns the hash index for each character
int hashFunc(char c){
	return (int)(c-'a');
}

// Function to populate the hash table based on key
void populateHashTable(char* ht, char* key){

	// First prefill the hash table with '#'
	for(int i=0;i<26;i++) ht[i] = '#';


	// Now iterate through the key and fill the array 

	char c = 'a'; // character that will keep incrementing after every iteration (a,b,c,...)

	for(int i=0;key[i]!='\0';i++){

		// consider only letters (not spaces)
		if(key[i]!=' '){

			int hashIndex = hashFunc(key[i]);
			// It is populated only if it does not already contain a letter
			// This is done so that only first appearance of each character in the key is considered
			if(ht[hashIndex]=='#') ht[hashIndex] = c++;
		}

		if(c=='z'+1) break; // terminate when the hash table is filled
	}

}

// Function to decode the message using the hash function
void decode(char* ht, char* msg, char* d_msg){

	// iterate through "msg", and populate "d_msg" correspondingly with the help of hash table 
	for(int i=0;msg[i]!='\0';i++){

		if(msg[i]==' ') d_msg[i]=' '; // if it is a space, it is unchanged
		else{
			d_msg[i] = ht[hashFunc(msg[i])];
		}

		if(msg[i+1]=='\0') d_msg[i+1] = '\0'; // Finally terminating the string with null character

	}
}

int main()
{
	// Taking user input for key and message

	char key[100];
	printf("key = ");
	scanf("%[^\n]s",key);

	char dummy; // Dummy character to avoid "\n" being assigned to "message"
	scanf("%c",&dummy);

	char message[200];
	printf("message = ");
	scanf("%[^\n]s",message);

	// Declaring hash table and populating it using function
	char hash_table[26];

	populateHashTable(hash_table,key);

	// Declaring decoded message and finding it using function
	char decoded_message[200];

	decode(hash_table,message,decoded_message);

	// Finally, displaying the result
	printf("Decoded message: %s\n",decoded_message);

	return 0;
}