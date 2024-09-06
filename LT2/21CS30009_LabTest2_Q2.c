/* Name: Ashwin Prasanth 
Roll No.: 21CS30009
Department: CSE
Machine No.: 40 */
#include<stdio.h>

/*  Approach:

		Observation: 
			If the initial pass ratio was a/b, after adding an extra student, it becomes (a+1)/(b+1) 
			We should give the extra student to that course which has the maximum value of (a+1)/(b+1)-(a/b) = (b-a)/(b)(b+1)

		- Based on the result of this observation, we will make a max-heap to store the above parameter for each class, along with the index of that class 
		  in the original classes array (for modification)
		- For every extra student, the maxHeap is popped and the student is added to the corresponding class, and the original class array is updated 
		  to reflect this change, also the new parameter for the class is pushed into the heap
		- This procedure is continued until all extra students have been alloted to a class 

		- Now the final average pass ratio is calculated and displayed

*/

typedef struct{
	float increase; 
	int index;
}heap_node; // node which will be used as elements of heap

// utility function to swap two integers
void swap(heap_node *a, heap_node *b){
	heap_node temp = *a; 
	*a = *b; 
	*b = temp;
}

// global variable to keep track of size of heap
int size = 0;


/*
	All utility functions required for making a heap, taking into account the factors that it is using a struct element instead of int, 
	and it is a max-heap and not a min-heap
*/

int root() {return 1;}
int parent(int n) {return n/2;}
int leftChild(int n) {return 2*n;}
int rightChild(int n) {return 2*n+1;}
int isNode(int n) {return n<=size;}
int hasParent(int n){return n!=root();}

void shiftUp(heap_node* H, int n){

	while(hasParent(n) && H[parent(n)].increase<H[n].increase){
		swap(&H[parent(n)],&H[n]);
		n = parent(n);
	}
}

void push(heap_node* H, float val, int index){
	heap_node new = {val,index};
	H[++size]=new;
	shiftUp(H,size);
}

void shiftDown(heap_node *H, int n){

	while(isNode(leftChild(n))){
		int child = leftChild(n);

		if(isNode(rightChild(n)) && H[rightChild(n)].increase>H[leftChild(n)].increase)
			child = rightChild(n);

		if(H[n].increase<H[child].increase) swap(&H[n],&H[child]);
		else break;

		n = child;
	}
}

void pop(heap_node *H){
	H[root()] = H[size--];
	shiftDown(H,root());
}

void heapify(heap_node *H, int n){
	size = n;
	//shift down starting from last node with a child, till root
	for(int i=size/2;i>=1;i--) shiftDown(H,i);

}

void printHeap(heap_node* H, int n){
	for(int i=1;i<=n;i++){
		printf("%f %d\n",H[i].increase,H[i].index);
	}
	printf("\n");
}

// Returns the parameter (a+1)/(b+1)-(a/b) = (b-a)/(b)(b+1) which will be used to choose the approppriate course to add a student into
float getIncrease(float a, float b){
	return (b-a)/(b*b+b);
}

// Returns the final average pass ratio, given the new no. of total students and no. of passing students (through 2d array)
float avgPassRatio(int classes[][2], int n){

	float ans = 0;

	for(int i=0;i<n;i++){
		// Adding pass ratio of each class
		ans+= (float)classes[i][0]/(float)classes[i][1];
	}

	ans/=n; // Finally taking average

	return ans;
}



int main()
{
	// Taking user input for number of classes and corresponding classes array, also the no. of extra students
	int n; 
	printf("Number of classes = ");
	scanf("%d",&n);

	int classes[n][2];
	printf("classes = ");
	for(int i=0;i<n;i++) scanf("%d %d",&classes[i][0],&classes[i][1]);

	int extraStudents;
	printf("extraStudents = ");
	scanf("%d",&extraStudents);

	

	heap_node H[n+1]; // making a 1-indexed heap

	for(int i=1;i<=n;i++){
		H[i].index = i-1;
		H[i].increase = getIncrease((float)classes[i-1][0],(float)classes[i-1][1]);
	}

	heapify(H,n); // Heapifying it to get a max-heap

	int temp = extraStudents; 

	while(temp>0){
		// pop the heap, add the student to the corresponding class, and accordingly push the new "increase" parameter
		int top_index = H[root()].index;

		pop(H);

		// incrementing both total students and no. of students passing
		classes[top_index][0]++;
		classes[top_index][1]++;

		float new_increase = getIncrease((float)classes[top_index][0],(float)classes[top_index][1]);

		push(H,new_increase,top_index);

		temp--;
	}

	// Now calculating average pass ratio and display it
	float ans = avgPassRatio(classes,n);

	printf("Average pass ratio = %0.4f\n", ans);

	return 0;
}