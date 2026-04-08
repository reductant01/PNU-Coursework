#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

// 그래프를 표현하는 클래스
class Graph {
    vector<list<int>> adjacencyList; // 각 노드의 인접 리스트를 저장
    int n;                           // 정점의 개수
    vector<bool> visited;            // 방문 여부를 저장할 벡터

public:
    // 그래프 생성자: 정점의 개수를 입력받아 초기화
    Graph(int vertices) : n(vertices), adjacencyList(vertices), visited(vertices, false) {}

    // 그래프의 인접 리스트를 출력하는 함수
    void displayAdjacencyLists() {
        cout << "Adjacency Lists:" << endl;
        for (int i = 0; i < n; i++) {
            cout << i << ": ";
            for (int neighbor : adjacencyList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    // 그래프에 간선을 추가하는 함수
    void insertEdge(int start, int end) {
        adjacencyList[start].push_back(end); // 시작 노드의 인접 리스트에 종료 노드를 추가
        adjacencyList[end].push_back(start); // 종료 노드의 인접 리스트에 시작 노드를 추가
    }

    // BFS 탐색 함수: 큐를 사용하여 너비 우선 탐색을 구현
    void bfs(int startNode) {
        vector<bool> visited(n, false); // 모든 노드를 방문하지 않은 상태로 초기화
        queue<int> queue;               // BFS에 사용할 큐

        visited[startNode] = true;      // 시작 노드를 방문 처리
        queue.push(startNode);          // 큐에 시작 노드를 삽입

        cout << "BFS traversal: ";
        while (!queue.empty()) {
            int node = queue.front();   // 큐의 맨 앞 노드를 가져옴
            queue.pop();                // 큐에서 제거
            cout << node << " ";        // 방문한 노드를 출력

            // 현재 노드에 연결된 모든 노드를 확인
            for (int neighbor : adjacencyList[node]) {
                if (!visited[neighbor]) {   // 인접한 노드 중 방문하지 않은 노드만
                    visited[neighbor] = true; // 방문 처리
                    queue.push(neighbor);     // 큐에 삽입
                }
            }
        }
        cout << endl;
    }

    // DFS 탐색 함수: 재귀적으로 깊이 우선 탐색을 수행
    void dfs(int startNode) {
        fill(visited.begin(), visited.end(), false); // 방문 여부 초기화
        cout << "DFS traversal: ";
        nonRecursiveDfs(startNode);                  // 비재귀 DFS 시작
        cout << endl;
    }

    // 비재귀 DFS 탐색 함수
    void nonRecursiveDfs(int startNode) {
        stack<int> stack;             // DFS에 사용할 스택
        stack.push(startNode);         // 시작 노드를 스택에 추가
        visited[startNode] = true;     // 시작 노드를 방문 처리

        while (!stack.empty()) {
            int node = stack.top();    // 스택의 맨 위 노드를 가져옴
            stack.pop();               // 스택에서 제거

            cout << node << " ";       // 방문한 노드를 출력

            // 인접한 노드를 역순으로 스택에 추가 (인접 노드를 역순으로 추가해야 작은 번호부터 탐색 가능)
            for (auto it = adjacencyList[node].rbegin(); it != adjacencyList[node].rend(); ++it) {
                int neighbor = *it;
                if (!visited[neighbor]) {
                    visited[neighbor] = true;  // 방문 처리
                    stack.push(neighbor);      // 스택에 추가
                }
            }
        }
    }
};

// 간선 정보를 저장하는 구조체
struct InputGraph3 {
    int start, end;

    InputGraph3(int start, int end) : start(start), end(end) {}
};

// 그래프 예제 행렬 생성 함수
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

// 행렬을 출력하는 함수
void showMatrix(const vector<vector<int>>& matrix) {
    cout << "Adjacency Matrix:" << endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

// main 함수
int main() {
    vector<vector<int>> matrix = makeGraph(); // 그래프 예제 행렬 생성
    showMatrix(matrix);                       // 인접 행렬 출력

    Graph g(N);                               // 그래프 객체 생성

    // 간선을 그래프에 추가
    while (true) {
        cout << "\nChoose Command: 1: Add edges, 2: Display Adjacency List, 3: BFS, 4: DFS, 5: DFS (Non-Recursive), 6: Exit => ";
        int select;
        cin >> select;

        switch (select) {
        case 1: {
            vector<InputGraph3> inputData;
            for (int i = 0; i < matrix.size(); i++) {
                for (int j = 0; j < matrix[0].size(); j++) {
                    if (matrix[i][j] == 1) {
                        inputData.emplace_back(i, j);
                    }
                }
            }
            for (const auto& edge : inputData) {
                g.insertEdge(edge.start, edge.end); // 간선을 그래프에 삽입
            }
            break;
        }

        case 2:
            g.displayAdjacencyLists(); // 인접 리스트 출력
            break;

        case 3: {
            cout << "Enter starting node for BFS: ";
            int startBfsNode;
            cin >> startBfsNode;
            g.bfs(startBfsNode); // BFS 탐색 실행
            break;
        }

        case 4: {
            cout << "Enter starting node for DFS: ";
            int startDfsNode;
            cin >> startDfsNode;
            g.dfs(startDfsNode); // DFS 탐색 실행
            break;
        }
        
        case 5: {
            cout << "Enter starting node for DFS (Non-Recursive): ";
            int startDfsNode;
            cin >> startDfsNode;
            g.nonRecursiveDfs(startDfsNode); // 비재귀 DFS 탐색 실행
            break;
        }
        
        case 6:
            return 0; // 프로그램 종료

        default:
            cout << "Invalid input. Please re-enter." << endl;
        }
    }
}
