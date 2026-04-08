#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// 무방향 그래프를 표현하는 Graph2 클래스
class Graph2 {
    vector<vector<int>> matrix; // 그래프의 인접 행렬을 저장할 벡터
    int n;                      // 정점의 개수
    vector<bool> visited;       // 방문 여부를 기록하는 벡터

public:
    // 생성자: 정점의 개수에 맞는 크기로 인접 행렬과 방문 벡터 초기화
    Graph2(int vertices) : n(vertices), matrix(vertices, vector<int>(vertices, 0)), visited(vertices, false) {}

    // 간선을 추가하는 함수: start와 end 사이의 간선을 추가 (무방향)
    void insertEdge(int start, int end) {
        matrix[start][end] = 1;
        matrix[end][start] = 1; // 양방향 간선이므로 대칭으로 값을 설정
    }

    // 인접 행렬을 출력하는 함수
    void displayMatrix() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " "; // 각 요소 출력 (0 또는 1)
            }
            cout << endl;
        }
    }

    // BFS (너비 우선 탐색) 함수
    void BFS(int v) {
        visited.assign(n, false); // 모든 노드를 방문하지 않은 상태로 초기화
        queue<int> q;             // BFS에 사용할 큐
        visited[v] = true;        // 시작 노드를 방문 처리
        q.push(v);                // 시작 노드를 큐에 삽입

        cout << "BFS traversal: ";
        while (!q.empty()) {
            int node = q.front(); // 큐의 가장 앞 노드를 꺼냄
            q.pop();              // 큐에서 제거
            cout << node << " ";  // 방문한 노드를 출력

            // 현재 노드에 연결된 모든 노드 검사
            for (int i = 0; i < n; i++) {
                // 인접하고 아직 방문하지 않은 노드만 큐에 추가
                if (matrix[node][i] == 1 && !visited[i]) {
                    visited[i] = true; // 방문 처리
                    q.push(i);         // 큐에 삽입
                }
            }
        }
        cout << endl;
    }

    // DFS (깊이 우선 탐색) 함수 (재귀 방식)
    void DFS(int v) {
        visited.assign(n, false); // 모든 노드를 방문하지 않은 상태로 초기화
        cout << "DFS traversal (recursive): ";
        _DFS(v); // 재귀 호출로 탐색 시작
        cout << endl;
    }

private:
    // 재귀 DFS 탐색의 실제 구현 함수
    void _DFS(int v) {
        visited[v] = true;         // 현재 노드를 방문 처리
        cout << v << " ";          // 방문한 노드를 출력
        for (int i = 0; i < n; i++) {
            // 인접하고 아직 방문하지 않은 노드가 있으면 재귀 호출
            if (matrix[v][i] != 0 && !visited[i]) {
                _DFS(i);
            }
        }
    }

public:
    // DFS (깊이 우선 탐색) 함수 (비재귀 방식)
    void NonRecursiveDFS(int v) {
        visited.assign(n, false); // 모든 노드를 방문하지 않은 상태로 초기화
        stack<int> stack;         // DFS에 사용할 스택
        stack.push(v);            // 시작 노드를 스택에 추가

        cout << "DFS traversal (non-recursive): ";
        while (!stack.empty()) {
            int node = stack.top(); // 스택의 맨 위 노드를 확인
            stack.pop();            // 스택에서 제거

            if (!visited[node]) {
                visited[node] = true;  // 방문 처리
                cout << node << " ";   // 방문한 노드를 출력

                // 인접한 노드를 역순으로 스택에 추가 (인접 노드를 역순으로 추가해야 작은 번호부터 탐색 가능)
                for (int i = n - 1; i >= 0; i--) {
                    if (matrix[node][i] == 1 && !visited[i]) {
                        stack.push(i);
                    }
                }
            }
        }
        cout << endl;
    }
};

// 예제 그래프의 인접 행렬을 반환하는 함수
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

// 인접 행렬을 출력하는 함수
void showMatrix(const vector<vector<int>>& matrix) {
    cout << "Adjacency Matrix:" << endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = makeGraph(); // 예제 그래프 생성
    showMatrix(matrix);                        // 인접 행렬 출력

    int select;
    int startNode = 0; // BFS/DFS 시작 노드

    Graph2 g(N);

    // 그래프 초기화: 인접 행렬에서 간선 정보를 가져와 그래프에 추가
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == 1) {
                g.insertEdge(i, j);
            }
        }
    }

    // 메뉴를 통해 사용자가 선택한 기능 실행
    while (true) {
        cout << "\n메뉴 선택 1: 인접 행렬 출력, 2: BFS, 3: DFS (재귀), 4: DFS (비재귀), 5: 종료 => ";
        cin >> select;
        switch (select) {
        case 1:
            g.displayMatrix();
            break;
        case 2:
            cout << "Start BFS from node: " << startNode << endl;
            g.BFS(startNode);
            break;
        case 3:
            cout << "Start DFS (recursive) from node: " << startNode << endl;
            g.DFS(startNode);
            break;
        case 4:
            cout << "Start DFS (non-recursive) from node: " << startNode << endl;
            g.NonRecursiveDFS(startNode);
            break;
        case 5:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "잘못된 입력. 다시 입력하세요." << endl;
            break;
        }
    }
}
