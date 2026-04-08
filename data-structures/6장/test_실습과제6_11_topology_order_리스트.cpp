#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

// 함수: 인접 행렬 반환
vector<vector<int>> makeGraph() {
    return {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };
}

class Graph {
private:
    int n;                       // Number of vertices
    vector<list<int>> adjacentList;       // Adjacency list
    vector<int> count;           // Count of incoming edges (in-degree)

public:
    Graph(int vertices) : n(vertices) {

    }

    // 행렬을 사용해 그래프 구성
    void buildFromMatrix(const vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
  
        }
    }

    void addEdge(int u, int v) {

    }

    void TopologicalOrder() {
        stack<int> st;           // Stack to store vertices with 0 in-degree
        for (int i = 0; i < n; i++) {
            if (count[i] == 0) { // Push vertices with no incoming edges
                st.push(i);
            }
        }

        vector<int> result;      // Store the topological order

        for (int i = 0; i < n; i++) {
   
        }

        // Output the topological order
        cout << "Topological Order: ";
        for (int vertex : result) {
            cout << vertex << " ";
        }
        cout << endl;
    }
};

int main() {
    // 그래프 생성 및 행렬로부터 그래프 빌드
    vector<vector<int>> matrix = makeGraph();
    int vertices = matrix.size();
    Graph g(vertices);
    g.buildFromMatrix(matrix);

    // 위상 정렬 수행
    g.TopologicalOrder();
    int num;
    cin >> num;
    return 0;
}
