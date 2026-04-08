#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 간선을 표현하는 구조체
struct Edge {
    int u;        // 간선의 시작 노드 (송전탑)
    int v;        // 간선의 끝 노드 (송전탑)
    int weight;   // 간선의 비용 (송전선 비용)

    // Kruskal 알고리즘에서 간선을 비용 순으로 정렬하기 위해 비교 연산자 오버로딩
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Union-Find 자료구조를 구현한 구조체
struct UnionFind {
    vector<int> parent;  // 각 노드의 부모를 저장하는 벡터

    // 생성자: 노드의 개수 n을 받아 부모를 초기화
    UnionFind(int n) : parent(n + 1) { // 노드 번호가 1부터 시작한다고 가정
        for(int i = 0; i <= n; ++i)
            parent[i] = i; // 초기에는 각 노드의 부모가 자기 자신
    }

    // Find 함수: 노드 x의 루트 부모를 찾음 (경로 압축 기법 사용)
    int find_set(int x) {
        if(parent[x] != x)
            parent[x] = find_set(parent[x]); // 재귀적으로 부모를 찾아 경로 압축
        return parent[x];
    }

    // Union 함수: 노드 x와 노드 y가 속한 집합을 합침
    void union_set(int x, int y) {
        int fx = find_set(x); // 노드 x의 루트 부모
        int fy = find_set(y); // 노드 y의 루트 부모
        if(fx != fy)
            parent[fy] = fx; // 한 집합의 루트 부모를 다른 집합의 루트 부모로 설정
    }
};

// Kruskal 알고리즘을 사용하여 최소 신장 트리를 계산하는 함수
pair<long long, vector<Edge>> Kruskal(int n, vector<Edge> edges) {
    // 모든 간선을 비용 오름차순으로 정렬
    sort(edges.begin(), edges.end());

    UnionFind uf(n);           // Union-Find 자료구조 초기화
    long long total_cost = 0; // MST의 총 비용을 저장할 변수
    vector<Edge> mst;          // MST에 포함된 간선들을 저장할 벡터

    // 모든 간선을 순서대로 확인
    for(auto &edge : edges){
        // 간선의 두 노드가 다른 집합에 속해있다면, 이 간선을 MST에 포함
        if(uf.find_set(edge.u) != uf.find_set(edge.v)){
            uf.union_set(edge.u, edge.v);  // 두 집합을 합침
            total_cost += edge.weight;      // 총 비용에 간선의 비용을 더함
            mst.push_back(edge);            // MST에 간선을 추가
        }
    }

    return {total_cost, mst}; // 총 비용과 MST에 포함된 간선들을 반환
}

int main(){
    int n, m; // n: 노드의 수 (송전탑의 수), m: 간선의 수 (송전선의 수)
    cout << "노드의 수와 간선의 수를 입력하세요 (예: 4 5): ";
    cin >> n >> m;

    vector<Edge> edges(m); // 간선 정보를 저장할 벡터
    cout << "각 간선의 정보를 입력하세요 (예: 1 2 3):" << endl;
    for(int i = 0; i < m; ++i){
        cin >> edges[i].u >> edges[i].v >> edges[i].weight; // 각 간선의 시작 노드, 끝 노드, 비용 입력
    }

    // Kruskal 알고리즘을 사용하여 기본 MST 계산
    pair<long long, vector<Edge>> result = Kruskal(n, edges);
    cout << "\nMST의 총 비용: " << result.first << endl; // MST의 총 비용 출력
    cout << "MST에 포함된 간선들:" << endl;
    for(auto &edge : result.second){
        cout << edge.u << " - " << edge.v << " : " << edge.weight << endl; // MST에 포함된 각 간선 출력
    }

    // 추가 확장: 특정 송전탑이 고장날 경우 대체 전력망 계산
    char choice;
    cout << "\n특정 송전탑이 고장났을 경우 대체 전력망을 계산하시겠습니까? (y/n): ";
    cin >> choice;

    if(choice == 'y' || choice == 'Y'){
        int failed_node;
        cout << "고장난 송전탑의 번호를 입력하세요: ";
        cin >> failed_node;

        // 고장난 송전탑을 포함하지 않는 간선만 선택하여 새로운 간선 리스트 생성
        vector<Edge> filtered_edges;
        for(auto &edge : edges){
            if(edge.u != failed_node && edge.v != failed_node)
                filtered_edges.push_back(edge); // 고장난 노드와 연결된 간선을 제외
        }

        // 고장난 노드를 제외한 노드의 수 계산
        int remaining_nodes = n - 1;

        // Kruskal 알고리즘을 사용하여 대체 전력망의 MST 계산
        pair<long long, vector<Edge>> new_result = Kruskal(n, filtered_edges);

        // MST에 포함된 간선의 수가 (남은 노드 수 - 1)과 같은지 확인하여 연결 가능 여부 판단
        if(new_result.second.size() != remaining_nodes -1){
            cout << "고장난 송전탑을 제외한 전력망을 구성할 수 없습니다." << endl;
        }
        else{
            cout << "\n대체 전력망의 총 비용: " << new_result.first << endl; // 대체 MST의 총 비용 출력
            cout << "대체 전력망에 포함된 간선들:" << endl;
            for(auto &edge : new_result.second){
                cout << edge.u << " - " << edge.v << " : " << edge.weight << endl; // 대체 MST에 포함된 간선 출력
            }
        }
    }

    return 0; // 프로그램 종료
}
