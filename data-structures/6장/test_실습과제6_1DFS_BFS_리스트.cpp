//소스코드 6.1: Graph Representation
//6.1 Adjacency Lists + BFS + DFS 

#include <iostream>
#include <string>

using namespace std;

template <class Type> class List;
template <class Type> class ListIterator;

template <class Type>
class ListNode {
	friend class List<Type>;
	friend class ListIterator<Type>;
private:
	Type data;
	ListNode* link;
	ListNode(Type);
};

template <class Type>
ListNode<Type>::ListNode(Type Default)
{
	data = Default;
	link = 0;
}

template <class Type>
class List {
	friend class ListIterator<Type>;
public:
	List() { first = 0; };
	void Insert(Type);
	void Delete(Type);
private:
	ListNode<Type>* first;
};

template <class Type>
void List<Type>::Insert(Type k)
{

}

template <class Type>
void List<Type>::Delete(Type k)
{

}

template <class Type>
class ListIterator {
public:
	ListIterator(const List<Type>& l) : list(l) { current = l.first; }
	Type* First();
	Type* Next();
	bool NotNull();
	bool NextNotNull();
private:
	const List<Type>& list;
	ListNode<Type>* current;
};


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
	void InsertVertex(int startNode, int endNode);
	void Setup();

	void displayAdjacencyLists();


	void DFS(int v);

};

void Graph::displayAdjacencyLists() {
	for (int i = 0; i < n; i++) {

	}
}

void Graph::InsertVertex(int start, int end) {

}

void Graph::BFS(int v)
{
	visited = new bool[n]; //  visited  is declared as a  Boolean \(** data member of  Graph .
	for (int i = 0; i < n; i++) visited[i] = false; // initially, no vertices have been visited

	visited[v] = true;
	cout << v << ",";
	Queue q;
	q.Insert(v);

	while (!q.IsEmpty()) {

	}
	delete[] visited;
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

int main(void)
{

	int select = 0, n, startEdge = -1, endEdge = -1;
	int startBFSNode = 100;//the start node to BFS

	cout << "Input the total node number: ";
	cin >> n;
	Graph g(n);

	while (select != '0')
	{
		cout << "\nSelect command 1: Add edges, 2: Display Adjacency Lists, 3: BFS, 4: DFS, 5: Quit => ";
		cin >> select;
		switch (select) {
		case 1:
			cout << "Add an edge: " << endl;
			cout << "--------Input start node: ";
			cin >> startEdge;

			cout << "--------Input  end  node: ";
			cin >> endEdge;
			if (startEdge < 0 || startEdge >= n || endEdge < 0 || endEdge >= n) {
				cout << "the input node is out of bound." << endl;
				break;
			}
			//get smallest start node.
			if (startEdge < startBFSNode)startBFSNode = startEdge;
			if (endEdge < startBFSNode) startBFSNode = endEdge;

			g.InsertVertex(startEdge, endEdge);
			break;

		case 2:
			//display
			g.displayAdjacencyLists();
			break;

		case 3:
			cout << "Start BFS from node: " << startBFSNode << endl;
			g.BFS(startBFSNode);
			break;
		case 4:
			cout << "Start DFS from node: " << startBFSNode << endl;
			g.DFS(startBFSNode);
			break;
		case 5:
			exit(0);
			break;
		default:
			cout << "WRONG INPUT  " << endl;
			cout << "Re-Enter" << endl;
			break;
		}
	}

	system("pause");
	return 0;
}
