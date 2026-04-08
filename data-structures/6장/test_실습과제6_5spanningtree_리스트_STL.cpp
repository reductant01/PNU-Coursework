#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

// 간선(Edge)을 표현하는 클래스
class Edge3 {
public:
    int src, dest, weight; // 시작 노드, 끝 노드, 가중치

    Edge3() {}

    Edge3(int s, int d, int w) : src(s), dest(d), weight(w) {}

    // 가중치 기준으로 정렬하기 위해 < 연산자 오버로딩
    bool operator<(const Edge3& e) const {
        return weight < e.weight;
    }

    // 간선 출력 형식을 정의 (예: "<0, 1, 10>")
    friend ostream& operator<<(ostream& os, const Edge3& edge) {
        os << "<" << edge.src << ", " << edge.dest << ", " << edge.weight << ">";
        return os;
    }
};

// 그래프 클래스
class Graph_MST {
public:
    int n; // 노드 개수
    vector<list<Edge3>> adjacencyList; // 인접 리스트를 저장하는 벡터

    Graph_MST(int nodes) : n(nodes), adjacencyList(nodes) {}

    // 간선 추가 함수
    void insertEdge3(int src, int dest, int weight) {
        adjacencyList[src].emplace_back(src, dest, weight);
        // 무방향 그래프인 경우 아래 코드의 주석을 해제
        // adjacencyList[dest].emplace_back(dest, src, weight);
        // push_back은 객체를 생성한 다음 추가해야하지만 emplace_back은 객체를 즉시 생성하고 이동할수있다
    }

    // 인접 리스트 출력 함수
    void displayAdjacencyLists() {
        for (int i = 0; i < n; i++) {
            cout << i << " -> ";
            for (const auto& edge : adjacencyList[i]) { // auto는 컴파일러가 변수의 타입을 자동으로 추천하도록 한다
                cout << edge << " ";
            }
            cout << endl;
        }
    }
};

// 서로소 집합(Disjoint Set)을 관리하는 클래스
class Sets {
public:
    vector<int> parent; // 부모 노드를 저장 (-1이면 루트 노드)

    Sets(int n) : parent(n, -1) {}

    // 특정 노드가 속한 집합의 루트 노드를 찾는 함수 (경로 압축 적용)
    int find(int i) {
        if (parent[i] == -1) // 루트 노드인 경우 자기 자신 반환
            return i;
        return parent[i] = find(parent[i]); // 경로 압축으로 최적화
    }

    // 두 집합을 병합하는 함수
    void unionSets(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);

        if (xRoot != yRoot) {
            parent[yRoot] = xRoot; // y 집합을 x 집합에 병합
        }
    }
};

// Kruskal 알고리즘으로 최소 신장 트리(MST)를 찾는 함수
void KruskalMST(Graph_MST& graph) {
    vector<Edge3> listEdges;

    // 그래프의 모든 간선을 리스트에 추가
    for (int i = 0; i < graph.n; i++) {
        for (const auto& edge : graph.adjacencyList[i]) {
            if (edge.src < edge.dest) { // 중복 간선 방지 (무방향 그래프)
                listEdges.push_back(edge);
            }
        }
    }

    // 간선들을 가중치 기준으로 정렬
    sort(listEdges.begin(), listEdges.end());

    // 서로소 집합 초기화
    Sets ds(graph.n);
    vector<Edge3> mst; // 최소 신장 트리 간선 리스트

    for (const auto& edge : listEdges) {
        int set1 = ds.find(edge.src); // 간선의 시작 노드가 속한 집합
        int set2 = ds.find(edge.dest); // 간선의 끝 노드가 속한 집합

        // 사이클이 발생하지 않는 경우에만 간선을 MST에 추가
        if (set1 != set2) {
            mst.push_back(edge);
            ds.unionSets(set1, set2); // 두 집합 병합
        }
    }

    // 결과 출력
    if (mst.size() != graph.n - 1) {
        cout << "스패닝 트리를 만들 수 없습니다." << endl;
    }
    else {
        cout << "최소 신장 트리:" << endl;
        for (const auto& edge : mst) {
            cout << edge << endl;
        }
    }
}

// 그래프의 노드 개수
const int N = 7;

// 인접 행렬을 생성하는 함수
vector<vector<int>> makeGraph() {
    return {
        {0, 28, 0, 0, 0, 10, 0},
        {28, 0, 16, 0, 0, 0, 14},
        {0, 16, 0, 12, 0, 0, 0},
        {0, 0, 12, 0, 22, 0, 18},
        {0, 0, 0, 22, 0, 25, 24},
        {10, 0, 0, 0, 25, 0, 0},
        {0, 14, 0, 18, 24, 0, 0}
    };
}

// 인접 행렬을 출력하는 함수
void showMatrix(const vector<vector<int>>& matrix) {
    cout << "인접 행렬:" << endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // 인접 행렬 생성 및 출력
    vector<vector<int>> matrix = makeGraph();
    showMatrix(matrix);

    // 그래프 객체 생성 및 초기화
    Graph_MST graph(N);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] != 0) { // 간선이 존재하는 경우에만 추가
                graph.insertEdge3(i, j, matrix[i][j]);
            }
        }
    }

    int select; // 사용자 입력 변수
    while (true) {
        cout << "\n명령을 선택하세요:: 1. 인접 리스트 출력, 2. 최소 신장 트리(Kruskal), 3: 종료 => ";
        cin >> select;
        switch (select) {
        case 1:
            graph.displayAdjacencyLists(); // 인접 리스트 출력
            break;
        case 2:
            cout << "\n최소 신장 트리 생성 중..." << endl;
            KruskalMST(graph); // Kruskal 알고리즘 실행
            break;
        case 3:
            cout << "프로그램 종료..." << endl;
            return 0; // 프로그램 종료
        default:
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
        }
    }
}
