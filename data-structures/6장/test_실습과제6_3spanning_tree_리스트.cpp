//소스코드 6.3: Minial Spanning Tree
// 6.4 minimal spanning tree:: Kruskal’s source code
// set 사용하여 MST 구현
// stack, queue, linked list는 STL 사용 버젼으로 수정 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;


class Sets {
public:
	Sets(int);
	void display();
	void SimpleUnion(int, int);
	int SimpleFind(int);
	void WeightedUnion(int, int);
	int CollapsingFind(int);
private:
	int* parent;
	int n;
};

Sets::Sets(int sz = HeapSize)
{
	n = sz;
	parent = new int[sz + 1]; // Don't want to use parent[0]
	for (int i = 1; i <= n; i++) parent[i] = -1;  // 0 for Simple versions
}

void Sets::SimpleUnion(int i, int j)
// Replace the disjoint sets with roots i and j, i != j with their union
{
	parent[j] = i;
}

int Sets::SimpleFind(int i)
// Find the root of the tree containing element i
{
	while (parent[i] > 0) i = parent[i];
	return i;
}

void Sets::WeightedUnion(int i, int j)
// Union sets with roots i and j, i != j, using the weighting rule.
// parent[i]~=~-count[i] and parent[i]~=~-count[i].
{
	int temp = parent[i] + parent[j];
	if (parent[i] > parent[j]) { // i has fewer nodes
		parent[i] = j;
		parent[j] = temp;
	}
	else { // j has fewer nodes
		parent[j] = i;
		parent[i] = temp;
	}
}

void Sets::display()
{
	cout << "display:index= ";
	for (int i = 1; i <= n; i++) cout << " " << i;
	cout << "\n";
	cout << "display: value= ";
	for (int i = 1; i <= n; i++) cout << " " << parent[i];
	cout << "\n";
}


class Graph
{
private:
	List<int>* HeadNodes;
	int n;
	bool* visited;

	void _DFS(const int v);
public:
	Graph(int vertices = 0) : n(vertices) {
		HeadNodes = new List<int>[n];
	};
	void BFS(int);
	void InsertVertex(int startNode, int endNode, int weight);
	void Setup();

	void displayAdjacencyLists();


	void DFS(int v);

};

void Graph::displayAdjacencyLists() {
	for (int i = 0; i < n; i++) {

	}
}

void Graph::InsertVertex(int start, int end, int weight) {
	
}

void Graph::BFS(int v)
{
	visited = new bool[n]; //  visited  is declared as a  Boolean \(** data member of  Graph .
	for (int i = 0; i < n; i++) visited[i] = false; // initially, no vertices have been visited

}

// Driver
void Graph::DFS(int v)
{
	visited = new bool[n]; //  visited  is declared as a  bool \(** data member of  Graph .
	for (int i = 0; i < n; i++)
		visited[i] = false; // initially, no vertices have been visited

	_DFS(v); // start search at vertex 0
	delete[] visited;

}

// Workhorse
void Graph::_DFS(const int v)
//  visit all previously unvisited vertices that are reachable from vertex v
{
	visited[v] = true;

}



// The main function to construct MST using Kruskal's algorithm
void KruskalMST(struct Graph* graph)
{
	int V = graph->V;
	struct Edge result[20];  // Tnis will store the resultant MST
	int e = 0;  // An index variable, used for result[]
	int i = 0;  // An index variable, used for sorted edges

	// Step 1:  Sort all the edges in non-decreasing order of their weight
	// If we are not allowed to change the given graph, we can create a copy of
	// array of edges
	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);

	// Allocate memory for creating V subsets
	struct subset* subsets =
		(struct subset*)malloc(V * sizeof(struct subset));

	// Create V subsets with single elements
	for (int v = 0; v < V; ++v)
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

	// Number of edges to be taken is equal to V-1
	while (e < V - 1)
	{
		// Step 2: Pick the smallest edge. And increment the index
		// for next iteration
		struct Edge next_edge = graph->edge[i++];

		int x = find(subsets, next_edge.src);
		int y = find(subsets, next_edge.dest);

		// If including this edge does't cause cycle, include it
		// in result and increment the index of result for next edge
		if (x != y)
		{
			result[e++] = next_edge;
			Union(subsets, x, y);
		}
		// Else discard the next_edge
	}

	// print the contents of result[] to display the built MST
	printf("Following are the edges in the constructed MST\n");
	for (i = 0; i < e; ++i)
		printf("%d -- %d == %d\n", result[i].src, result[i].dest,
			result[i].weight);
	return;
}

// Driver program to test above functions
int main(void)
{
	int select = 0, n, start, end, weight;
	int startBFSNode = 100;//the start node to BFS

	cout << "Input the total node number: ";
	cin >> n;

	/* Let us create following weighted graph */
	struct Graph graph(n);
	Graph* spanningTree = nullptr;
	while (select != '0')
	{
		cout << "\nSelect command 1: Add edges and Weight, 2: Display Adjacency Lists, 3: spanningTree, 4: Quit => ";
		cin >> select;
		switch (select) {
		case 1:
			cout << "Add an edge: " << endl;
			cout << "--------Input start node: ";
			cin >> start;
			cout << "--------Input  destination  node: ";
			cin >> end;
			if (start < 0 || start >= n || end < 0 || end >= n) {
				cout << "the input node is out of bound." << endl;
				break;
			}
			cout << "--------Input  weight: ";
			cin >> weight;

			graph.InsertVertex(start, end, weight);
			break;
		case 2:
			//display
			graph.displayAdjacencyLists();
			break;
		case 3:
			cout << "\nSpanningTree - Prim's algorithm: " << endl;
			spanningTree = KruskalMST(&graph);
			if (spanningTree) {
				spanningTree->displayAdjacencyLists();
			}
			delete spanningTree;
			spanningTree = nullptr;
			break;
		case 4:
			exit(0);
			break;
		default:
			cout << "WRONG INPUT  " << endl;
			cout << "Re-Enter" << endl;
			break;
		}
	}

	KruskalMST(graph);
	system("pause");
	return 0;
}
