/* Name: Ashwin Prasanth 
Roll No.: 21CS30009
Department: CSE
Machine No.: 40 */
#include<stdio.h>
#include<stdlib.h>

#define SIZE 100

/*
	Approach: 
		- Perform BFS traversal on the graph, with "source" as "sink"
		- In this process, store the parent of each vertex 
		- Now that we know the parent of each vertex when the source is "sink",
		  we will make a new directed graph by adding a directed graph from the vertex to its parent
		- Based on our choice of the source, this directed path will always lead to the sink

		NOTE: The output of this program gives a different output from the one given in question, 
		but it is correct nonetheless
*/

// struct to define a node which is the vertex of the graph
typedef struct _node{
	int val; 
	struct _node* next; 	
}node;

// struct to define a graph with a list of nodes, along with number of vertices, 
// array to keep track of whether the vertex has been visited, and parent of each vertex
typedef struct{
	int n_vertices; 
	node** list;
	int* visited;
	int* parent;
}graph;

// struct to implement queue data type
typedef struct{
	int list[SIZE];
	int top; 
	int bottom;
}queue;

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

	// using 1-based arrays

	G->list = malloc((v+1)*sizeof(node*));
	G->visited = malloc((v+1)*sizeof(int));
	G->parent = malloc((v+1)*sizeof(int));


	for(int i=1;i<=v;i++){
		G->list[i]=NULL;
		G->visited[i]=0;
		G->parent[i]=0;
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

// Utility function to add a directed edge from a to b (a->b)
void addDirectedEdge(graph* G, int a, int b){
	node* nodeB = createNode(b);
	nodeB->next = G->list[a];
	G->list[a] = nodeB;
}

// Utility functions of queue: dequeue, enqueue and isEmpty

int dequeue(queue* q){
	q->top++;
	return q->list[q->top-1];
}

void enqueue(queue* q, int val){
	q->bottom++;
	q->list[q->bottom] = val;
}

int isEmpty(queue* q){
	return q->top > q->bottom;
}

// Function to implement BFS traversal on graph, given a source
void bfs(graph* G, int source){

	// Declaring a queue to store vertices
	queue* q = malloc(sizeof(queue));
	q->top = 0;
	q->bottom = -1;

	// since source has been visited, its status is updated
	// also, the source is enqueued into the queue
	G->visited[source]=1;

	enqueue(q,source);

	while(!isEmpty(q)){
		int currentVertex = dequeue(q);
		// now we traverse through the neighbors of each vertex in the queue
		node* temp = G->list[currentVertex];
		while(temp){
			int adjVertex = temp->val; 

			if(G->visited[adjVertex]==0){
				// if its not visited, its enqueued, also its parent is updated
				G->visited[adjVertex]=1;
				G->parent[adjVertex]=currentVertex;
				enqueue(q,adjVertex);
			}
			temp=temp->next;
		}

	}
}

// Making a directed graph based on the parent of each vertex
void makeDirectedGraph(graph* G, graph* newGraph, int sink){
	for(int i=1;i<=G->n_vertices;i++){

		if(i==sink); // no need to check parent of sink

		else{
			// add a directed edge from node to parent
			addDirectedEdge(newGraph,i,G->parent[i]);
		}
	}
}

// Function to print the path from each vertex to the sink, given the directed graph
void printPaths(graph* newGraph, int sink){
	for(int i=1;i<=newGraph->n_vertices;i++){

		if(i==sink);

		else{
			printf("Path from vertex %d to sink is: %d->",i,i);

			node* temp = newGraph->list[i];
			while(temp->val!=sink){
				printf("%d->",temp->val);
				temp = newGraph->list[temp->val];
			}
			printf("%d\n",sink);
		}
	}
}

int main()
{	
	// hardcoding graph (same one given in question)
	graph* G = createGraph(6);
	addEdge(G, 1, 2); 
	addEdge(G, 2, 3);
	addEdge(G, 3, 4);
	addEdge(G, 6, 3);	
	addEdge(G, 1, 6);
	addEdge(G, 6, 5); 
	addEdge(G, 5, 3);

	int sink = 1; //hardcoding sink (same one given in question)

	bfs(G,sink); // BFS traversal on G, taking source as "sink"

	// new graph which will store the directed graph that is required
	graph* newGraph = createGraph(G->n_vertices);

	// Making the directed graph, and then printing it
	makeDirectedGraph(G,newGraph,sink);

	printPaths(newGraph,sink);

	return 0;
}