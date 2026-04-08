#include <iostream>
#include <vector>
#include <queue>
#include <stack>

class Graph {
    vector<vector<int>> matrix;
    int n;
    vector<bool> visited;

public:
    Graph(int vertices) : n(vertices), matrix(vertices, vector<int>(vertices, 0)), visited(vertices, false) {}

    // Insert an edge into the graph
    void insertEdge(int start, int end) {

    }

    // Display adjacency matrix
    void displayMatrix() {

    }

    // BFS implementation using a queue
    void BFS(int v) {

    }

    // Recursive DFS
    void DFS(int v) {
        visited.assign(n, false); // Reset visited array
        cout << "DFS traversal (recursive): ";
        _DFS(v);
        cout << "\n";
    }

private:
    void _DFS(int v) {

    }

public:
    // Non-recursive DFS using a stack
    void NonRecursiveDFS(int v) {
        visited.assign(n, false); // Reset visited array
        stack<int> stack;
        stack.push(v);

        cout << "DFS traversal (non-recursive): ";
        while (!stack.empty()) {
            
        }
        cout << "\n";
    }
};

const int N = 8;

vector<vector<int>> makeGraph() {
    return {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0, 0},
        {1, 0, 0, 0, 0, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 1, 1, 1, 1, 0}
    };
}

int main() {
    vector<vector<int>> matrix = makeGraph();
    int select;
    int startNode = 0; // Default start node for BFS/DFS

    Graph g(N);

    // Initialize the graph with edges from the matrix
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] == 1) {
                g.insertEdge(i, j);
            }
        }
    }

    while (true) {
        cout << "\n명령 선택 1: 그래프 행렬 출력, 2: BFS, 3: DFS (Recursive), 4: DFS (Non-Recursive), 5: 종료 => ";
        cin >> select;
        switch (select) {
        case 1:
            g.displayMatrix();
            break;
        case 2:
            cout << "Start BFS from node: " << startNode << "\n";
            g.BFS(startNode);
            break;
        case 3:
            cout << "Start DFS (recursive) from node: " << startNode << "\n";
            g.DFS(startNode);
            break;
        case 4:
            cout << "Start DFS (non-recursive) from node: " << startNode << "\n";
            g.NonRecursiveDFS(startNode);
            break;
        case 5:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "WRONG INPUT. Re-Enter.\n";
            break;
        }
    }
}
