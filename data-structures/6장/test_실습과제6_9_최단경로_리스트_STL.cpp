#include <iostream>
#include <vector>
#include <list>
#include <limits.h>
using namespace std;

const int MAX_WEIGHT = 9999999;

// Graph class with adjacency list
class Graph {
private:
    int n; // number of nodes
    vector<list<pair<int, int>>> adjList; // adjacency list (node, weight)
    vector<int> dist;
    vector<bool> s;
    vector<int> newdist;

public:
    Graph(int nodeSize) : n(nodeSize), adjList(nodeSize), dist(nodeSize), s(nodeSize), newdist(nodeSize) {}

    void insertEdge(int start, int end, int weight);
    void displayConnectionList();
    void ShortestPath(const int v);
    void ShortestPath_display(const int v);
    void BellmanFord(const int v);
    void BellmanFord2(const int v);
    int choose();
    void Out(int startNode);
    bool isNonNegativeEdgeCost();

    // Helper functions for output
    void displayS();
};

void Graph::insertEdge(int start, int end, int weight) {
    if (start >= n || end >= n || start < 0 || end < 0) {
        cout << "The input node is out of bound, the largest node is " << (n - 1) << endl;
        return;
    }
    adjList[start].emplace_back(end, weight);
}

void Graph::displayConnectionList() {
    for (int i = 0; i < n; i++) {
  
    }
}

void Graph::Out(int startNode) {
    for (int i = 0; i < n; i++) {

    }
    cout << endl;
}

bool Graph::isNonNegativeEdgeCost() {
    for (int i = 0; i < n; i++) {
  
    }
    return true;
}

void Graph::ShortestPath(const int v) {
    fill(dist.begin(), dist.end(), MAX_WEIGHT);
    fill(s.begin(), s.end(), false);

    dist[v] = 0;
    s[v] = true;

    for (int i = 0; i < n - 1; i++) {
  
    }
}

void Graph::ShortestPath_display(const int v) {
    fill(dist.begin(), dist.end(), MAX_WEIGHT);
    fill(s.begin(), s.end(), false);

    dist[v] = 0;
    s[v] = true;

    for (int i = 0; i < n - 1; i++) {

    }
    displayS();
    Out(v);
}

int Graph::choose() {
    int minDist = MAX_WEIGHT;
    int index = -1;
    for (int i = 0; i < n; i++) {

    }
    return index;
}

void Graph::displayS() {

}



void Graph::BellmanFord(const int v)
// Single source all destination shortest paths with negative edge lengths
{

}

void Graph::AllLengths()
// length[n][n] is the adjacency matrix of a graph with n vertices.
// a[i][j] is the length of the shortest path between i and j
{

}






vector<vector<int>> makeGraph1() {
    return {
        {0, 6, 5, 7, 0, 0, 0},
        {6, 0, -2, 0, -1, 0, 0},
        {5, -2, 0, -2, 1, 0, 0},
        {7, 0, -2, 0, 0, -1, 0},
        {0, -1, 1, 0, 0, 0, 3},
        {0, 0, 0, -1, 0, 0, 8},
        {0, 0, 0, 0, 3, 8, 0}
    };
}

vector<vector<int>> makeGraph2() {
    return {
        {0, 300, 1000, 0, 0, 0, 0, 1700},
        {300, 0, 800, 0, 0, 0, 0, 0},
        {1000, 800, 0, 1200, 0, 0, 0, 0},
        {0, 0, 0, 1200, 1500, 1000, 0, 0},
        {0, 0, 0, 1500, 0, 250, 0, 0},
        {0, 0, 0, 1000, 250, 0, 900, 1400},
        {0, 0, 0, 0, 0, 900, 0, 1000},
        {1700, 0, 0, 0, 0, 1400, 1000, 0}
    };
}

int main() {
    int select;
    Graph5* g = nullptr;

    cout << "1: Graph with Negative Weights, 2: City Distance Graph\n";
    cin >> select;

    if (select == 1) {
        auto matrix = makeGraph1();
        showMatrix(matrix);
        g = new Graph5(7);
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] != 0) {
                    g->insertEdge(i, j, matrix[i][j]);
                }
            }
        }
    }
    else if (select == 2) {
        auto matrix = makeGraph2();
        showMatrix(matrix);
        g = new Graph5(8);
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] != 0) {
                    g->insertEdge(i, j, matrix[i][j]);
                }
            }
        }
    }
    else {
        cout << "Invalid input. Exiting." << endl;
        return 0;
    }
    while (select != '0')
    {
        cout << "\nSelect command 1: AddEdge, 2: AdjacencyLists, 3: singleSource/all destinations(non-negative edge cost)"
            << "4:  single source/all destinations(negative edge costs), 5. All-pairs shortest paths, 6. Quit => ";
        cin >> select;
        switch (select) {
        case 1:
            cout << "Add an edge: " << endl;
            cout << "--------Input start node: ";
            cin >> start;
            cout << "--------Input  destination  node: ";
            cin >> end;
            cout << "--------Input  weight: ";
            cin >> weight;

            g->insertEdge(start, end, weight);
            break;
        case 2:
            //display
            g->displayConnectionMatrix();
            break;
        case 3:
            cout << "\nsingle source/all destinations: non-negative edge costs: " << endl;
            if (!g->isNonNegativeEdgeCost()) {
                cout << "Negative edge cost exists!!" << endl;
                cout << "Please re-build the graph with non-negative edge costs." << endl;
                break;
            }

            cout << "\n ----------> Input start node: ";
            cin >> start;

            g->ShortestPath_display(start);
            break;
        case 4:
            cout << "\nsingle source/all destinations: negative edge costs: " << endl;
            cout << "\n ----------> Input start node: ";
            cin >> start;

            g->BellmanFord(start);
            break;
        case 5:
            cout << "\nAll-pairs shortest paths:" << endl;
            g->AllLengths();
            break;
        case 6:
            exit(0);
        default:
            cout << "WRONG INPUT  " << endl;
            cout << "Re-Enter" << endl;
            break;
        }
    }


    delete g;
    return 0;
}
