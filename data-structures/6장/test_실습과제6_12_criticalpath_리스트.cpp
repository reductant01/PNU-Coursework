#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

// 그래프의 간선을 표현하는 구조체
struct Pair {
    int vertex; // 연결된 정점
    int weight; // 간선의 가중치

    Pair(int v, int d) : vertex(v), weight(d) {}
};

class Graph {
private:
    vector<vector<Pair>> HeadNodes; // 인접 리스트
    vector<int> count; // 각 노드의 진입 차수
    vector<int> ee;  // Earliest Event Time (조기 이벤트 시간)
    vector<int> le;  // Latest Event Time (늦은 이벤트 시간)
    int n;  // 전체 노드 수

public:
    // 생성자: 그래프 초기화
    Graph(int vertices = 0) : n(vertices) {
        HeadNodes.resize(n);
        count.resize(n, 0);
        ee.resize(n, 0);
        le.resize(n, 0);
    }

    // 배열을 출력하는 함수
    void showArray(const std::vector<int>& arr) const;

    // 그래프를 설정하는 함수들
    void Setup8();
    void Setup9();

    // 활동 시간 계산 함수들
    void EarlyActivity();
    void EarlyActivity_display();
    void LateActivity();
    void LateActivity_display();
    void display_early_late_criticalActivity();

    // 위상 정렬 함수
    void TopologicalOrder();

    // 간선을 추가하는 함수
    void addEdge(int start, int end, int weight);

    // 인접 리스트를 출력하는 함수
    void printAdjacencyLists() const;

    // 역방향 그래프를 생성하는 함수
    Graph* inverseGraph() const;
};

// 간선을 추가하는 함수 구현
void Graph::addEdge(int start, int end, int weight) {
    if (start < 0 || start >= n || end < 0 || end >= n) {
        cout << "노드 번호가 out of bounds." << endl;
        return;
    }

    // 인접 리스트에 간선 추가
    HeadNodes[start].emplace_back(end, weight);

    // 끝 노드의 진입 차수 증가
    count[end]++;
}

// 인접 리스트를 출력하는 함수 구현
void Graph::printAdjacencyLists() const {
    cout << "Adjacency Lists:" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << " -> ";
        for (const auto& pair : HeadNodes[i]) {
            cout << "(" << pair.vertex << ", " << pair.weight << ") ";
        }
        cout << endl;
    }
}

// 역방향 그래프를 생성하는 함수 구현
Graph* Graph::inverseGraph() const {
    // 새로운 그래프 객체 생성 (노드 수 동일)
    auto* inverseGraph = new Graph(n);

    // 모든 간선을 역방향으로 추가
    for (int i = 0; i < n; i++) {
        for (const auto& pair : HeadNodes[i]) {
            int end = pair.vertex;
            int weight = pair.weight;

            // 역방향 간선 추가
            inverseGraph->addEdge(end, i, weight);
        }
    }
    return inverseGraph;
}

// 위상 정렬을 수행하는 함수 구현 (Kahn's Algorithm)
void Graph::TopologicalOrder() {
    // 진입 차수 복사
    vector<int> indegreeCount = count;
    queue<int> queZeroNodes;

    // 진입 차수가 0인 노드를 큐에 추가
    for (int i = 0; i < n; i++) {
        if (indegreeCount[i] == 0) {
            queZeroNodes.push(i);
        }
    }

    cout << "Topological Order: ";
    while (!queZeroNodes.empty()) {
        int current = queZeroNodes.front();
        queZeroNodes.pop();
        cout << current << " ";

        // 현재 노드의 모든 이웃 노드 처리
        for (const auto& pair : HeadNodes[current]) {
            int neighbor = pair.vertex;
            indegreeCount[neighbor]--;

            // 이웃 노드의 진입 차수가 0이 되면 큐에 추가
            if (indegreeCount[neighbor] == 0) {
                queZeroNodes.push(neighbor);
            }
        }
    }
    cout << endl;
}

// 조기 활동 시간을 계산하는 함수 구현
void Graph::EarlyActivity() {
    // 진입 차수 복사
    vector<int> indegreeCount = count;
    queue<int> queZeroNodes;

    // 진입 차수가 0인 노드를 큐에 추가
    for (int i = 0; i < n; i++) {
        if (indegreeCount[i] == 0) {
            queZeroNodes.push(i);
        }
    }

    // 모든 노드의 조기 시간을 0으로 초기화
    ee.assign(n, 0);

    // 위상 정렬 순서로 조기 시간 계산
    while (!queZeroNodes.empty()) {
        int current = queZeroNodes.front();
        queZeroNodes.pop();

        // 현재 노드의 모든 이웃 노드에 대해 조기 시간 업데이트
        for (const auto& pair : HeadNodes[current]) {
            int neighbor = pair.vertex;
            int duration = pair.weight;

            // 조기 시간 업데이트: 현재 노드의 ee + 간선의 가중치
            if (ee[neighbor] < ee[current] + duration) {
                ee[neighbor] = ee[current] + duration;
            }

            // 이웃 노드의 진입 차수 감소
            indegreeCount[neighbor]--;

            // 이웃 노드의 진입 차수가 0이 되면 큐에 추가
            if (indegreeCount[neighbor] == 0) {
                queZeroNodes.push(neighbor);
            }
        }
    }
}

// 조기 활동 시간을 출력하는 함수 구현
void Graph::EarlyActivity_display() {
    EarlyActivity();

    cout << "Earliest Event Times (ee):" << endl;
    showArray(ee);
}

// 늦은 활동 시간을 계산하는 함수 구현
void Graph::LateActivity() {
    // 먼저 조기 활동 시간을 계산
    EarlyActivity();

    // ee 배열에서 최대 값을 찾음 (프로젝트의 총 소요 시간)
    int maxTime = *max_element(ee.begin(), ee.end());

    // 모든 노드의 늦은 시간을 최대 시간으로 초기화
    le.assign(n, maxTime);

    // 역방향 그래프 생성
    Graph* invGraph = this->inverseGraph();

    // 역방향 그래프의 진입 차수 복사 (원래 그래프의 진출 차수)
    vector<int> outdegreeCount = invGraph->count;
    queue<int> queZeroNodes;

    // 진출 차수가 0인 노드를 큐에 추가
    for (int i = 0; i < n; i++) {
        if (outdegreeCount[i] == 0) {
            queZeroNodes.push(i);
        }
    }

    // 위상 정렬 순서로 늦은 시간 계산
    while (!queZeroNodes.empty()) {
        int current = queZeroNodes.front();
        queZeroNodes.pop();

        // 역방향 그래프에서 현재 노드의 모든 이웃 노드에 대해 늦은 시간 업데이트
        for (const auto& pair : invGraph->HeadNodes[current]) {
            int neighbor = pair.vertex;
            int duration = pair.weight;

            // 늦은 시간 업데이트: 현재 노드의 le - 간선의 가중치
            if (le[neighbor] > le[current] - duration) {
                le[neighbor] = le[current] - duration;
            }

            // 이웃 노드의 진입 차수 감소
            outdegreeCount[neighbor]--;

            // 이웃 노드의 진입 차수가 0이 되면 큐에 추가
            if (outdegreeCount[neighbor] == 0) {
                queZeroNodes.push(neighbor);
            }
        }
    }

    // 역방향 그래프 메모리 해제
    delete invGraph;
}

// 늦은 활동 시간을 출력하는 함수 구현
void Graph::LateActivity_display() {
    LateActivity();

    cout << "Latest Event Times (le):" << endl;
    showArray(le);
}

// 조기/늦은 활동 시간과 중요 활동(Slack)을 출력하는 함수 구현
void Graph::display_early_late_criticalActivity() {
    EarlyActivity();
    LateActivity();

    cout << endl;
    cout << "Node | Earliest Time (ee) | Latest Time (le) | Slack" << endl;
    for (int i = 0; i < n; i++) {
        int slack = le[i] - ee[i]; // Slack 계산
        cout << i << "     | " << ee[i] << "                | " << le[i] << "               | " << slack << endl;
    }
}

// 배열을 출력하는 함수 구현
void Graph::showArray(const std::vector<int>& arr) const {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

// 그래프를 설정하는 함수 Setup8 구현
void Graph::Setup8() {
    addEdge(0, 3, 5);
    addEdge(0, 2, 4);
    addEdge(0, 1, 6);
    addEdge(1, 4, 1);
    addEdge(2, 4, 1);
    addEdge(3, 5, 2);
    addEdge(4, 7, 7);
    addEdge(4, 6, 9);
    addEdge(5, 7, 4);
    addEdge(6, 8, 2);
    addEdge(7, 8, 4);
}

// 그래프를 설정하는 함수 Setup9 구현
void Graph::Setup9() {
    addEdge(0, 2, 6);
    addEdge(0, 1, 5);
    addEdge(1, 3, 3);
    addEdge(2, 3, 6);
    addEdge(2, 4, 3);
    addEdge(3, 5, 4);
    addEdge(3, 6, 4);
    addEdge(3, 4, 3);
    addEdge(4, 6, 1);
    addEdge(4, 7, 4);
    addEdge(5, 8, 7);
    addEdge(5, 9, 4);
    addEdge(6, 8, 5);
    addEdge(7, 8, 2);
    addEdge(8, 9, 2);
}

int main() {
    Graph* g = nullptr;
    int select = 0, n, start, end, weight;

    // 그래프 선택
    cout << "1: 연습문제 그래프 사용, 2: 교재 그래프 사용: ";
    cin >> select;
    if (select == 1) {
        cout << "그래프 노드 수: 10개인 그래프: ";
        g = new Graph(10);
        g->Setup8();
    }
    else if (select == 2) {
        cout << "그래프 노드 수: 10개인 그래프: ";
        g = new Graph(10);
        g->Setup9();
    }

    // 메뉴 루프
    while (select != 8) {
        cout << "\n2: Print Adjacency Lists, 3: Inverse Graph, 4: Early Activity,"
            << " 5: Late Activity, 6: Critical Activity, 7: Topological Order, 8: Quit => ";
        cin >> select;

        switch (select) {
        case 1:
            // 선택 1은 초기 그래프 설정과 연관되었으나, main에서 이미 처리됨
            break;
        case 2:
            // 인접 리스트 출력
            g->printAdjacencyLists();
            break;
        case 3: {
            // 역방향 그래프 생성 및 출력
            Graph* invGraph = g->inverseGraph();
            cout << "Inverse Graph:" << endl;
            invGraph->printAdjacencyLists();
            delete invGraph; // 역방향 그래프 메모리 해제
            break;
        }
        case 4:
            // 조기 활동 시간 출력
            g->EarlyActivity_display();
            break;
        case 5:
            // 늦은 활동 시간 출력
            g->LateActivity_display();
            break;
        case 6:
            // 조기/늦은 활동 시간과 Slack 출력
            g->display_early_late_criticalActivity();
            break;
        case 7:
            // 위상 정렬 수행 및 출력
            g->TopologicalOrder();
            break;
        case 8:
            // 프로그램 종료
            cout << "Exiting..." << endl;
            break;
        default:
            // 잘못된 입력 처리
            cout << "Invalid input. Try again." << endl;
        }
    }

    // 동적 메모리 해제
    delete g;
    return 0;
}
