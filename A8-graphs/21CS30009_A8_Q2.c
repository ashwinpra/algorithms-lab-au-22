/* Name: Ashwin Prasanth 
Roll No.: 21CS30009
Department: CSE
Machine No.: 40 */
#include<stdio.h>
#include<stdlib.h>

/*
	Approach: 
		- First make a graph given the pairs
		- The graph is represented by an adjacency list 
		- For each vertex, the color of every member in its adjacency list is checked
		- If any color is left unused (this is guaranteed), it is assigned to this vertex

		- For simplicity, the first unused color is assigned to the vertex
*/

// struct to define a node which is the vertex of the graph
typedef struct _node{
	int val; 
	struct _node* next; 	
}node;

// struct to define graph, with a list of nodes and information on 
// color of each node and total no. of vertices
typedef struct{
	int n_vertices; 
	node** list;
	int* color; //0 -> unvisited, 1-4 -> color
}graph;

// Utility function to create a node given its corresponding value
node* createNode(int val){
	node* newNode = malloc(sizeof(node));

	newNode->val = val;
	newNode->next = NULL;

	return newNode;
}

// Utility function to create an empty graph given number of vertices 
graph* createGraph(int v){
	graph* G = malloc(sizeof(graph));

	G->n_vertices=v;

	// using both 1-based arrays

	G->list = malloc((v+1)*sizeof(node*));
	G->color = malloc((v+1)*sizeof(int));

	for(int i=1;i<=v;i++){
		G->list[i]=NULL;
		G->color[i]=0;
	}

	return G;
}

// Utility function to add a bidirectional edge between a and b 
void addEdge(graph* G, int a, int b){
	// add b->a edge
	node* nodeA = createNode(a);
	nodeA->next = G->list[b];
	G->list[b] = nodeA;
	// add a->b edge
	node* nodeB = createNode(b);
	nodeB->next = G->list[a];
	G->list[a] = nodeB;
}

// Function to assign color to each garden (vertex)
void assignColors(graph* G){
	// iterating through each vertex in the adjacency list
	for(int v=1;v<=G->n_vertices;v++){

		int src = v; // The current "source" vertex for which we have to assign color
		node* temp = G->list[v];

		int colors[5] = {0}; // Colors array to keep track of which color is available (hashing)

		while(temp){
			// Iterating through every neighbour of the current vertex to rule out the unavailable colors
			int color = G->color[temp->val];
			if(color!=0) colors[color]++;
			temp=temp->next;
		}

		// we have traversed all the neighbors of "src", now we assign one of the available colors
		for(int i=1;i<=4;i++){
			// for simplicity, we just assign the first unused color
			if(colors[i]==0) {
				G->color[src] = i;
				break;
			}
		}	
	}
}


int main()
{
	// Taking user input for number of gardens and paths
	int n; 
	printf("Enter number of gardens: ");
	scanf("%d",&n);

	int n_paths;
	printf("Enter the number of paths: ");
	scanf("%d",&n_paths);
	int paths[n_paths][2];
	printf("Enter the paths: ");
	for(int i=0;i<n_paths;i++) scanf("%d %d",&paths[i][0],&paths[i][1]);

	// Creating a graph based on the received input
	graph* G = createGraph(n);
	for(int i=0;i<n_paths;i++) addEdge(G,paths[i][0],paths[i][1]);

	assignColors(G); // Assigning colors to each garden
	
	// Displaying the color of each garden
	for(int i=1;i<=n;i++){
		printf("%d ",G->color[i]);
	}
	return 0;
}