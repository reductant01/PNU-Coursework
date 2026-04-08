#include <iostream>     // 화면에 출력하고 키보드 입력을 받기 위해 필요해요
#include <vector>       // 여러 개의 데이터를 저장할 수 있는 상자를 사용해요
#include <queue>        // 우선순위 큐를 사용하기 위해 필요해요
#include <climits>      // 가장 큰 숫자를 사용하기 위해 필요해요
#include <stack>        // 경로를 거꾸로 저장하기 위해 필요해요

using namespace std;

// 항공편 정보를 저장하는 상자
struct Edge {
    int to;        // 가는 공항 번호
    int cost;      // 가는 데 드는 비용
};

// 다익스트라 알고리즘을 실행하는 함수
vector<int> dijkstra(int n, vector<vector<Edge>> &adj, int start, vector<int> &predecessor) {
    // 모든 공항까지의 최소 비용을 저장하는 상자, 처음에는 모두 무한대로 설정
    vector<int> dist(n, INT32_MAX);
    dist[start] = 0; // 시작 공항의 비용은 0이에요

    // 가장 비용이 적은 공항을 먼저 선택하기 위한 우선순위 큐
    // (현재까지의 비용, 공항 번호)
    priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
    pq.push({0, start}); // 시작 공항을 큐에 넣어요

    while (!pq.empty()) { // 큐가 빌 때까지 반복해요
        pair<int, int> current = pq.top(); // 가장 비용이 적은 공항을 꺼내요
        pq.pop(); // 꺼낸 공항을 큐에서 빼요

        int current_dist = current.first; // 현재까지의 비용
        int u = current.second; // 현재 공항 번호

        // 이미 더 작은 비용으로 도착한 경우는 무시해요
        if (current_dist > dist[u])
            continue;

        // 현재 공항에서 갈 수 있는 모든 공항을 확인해요
        for (auto &edge : adj[u]) {
            int v = edge.to; // 다음에 가는 공항
            int cost = edge.cost; // 그 공항으로 가는 비용

            // 새로운 경로를 통해 v로 가는 비용을 계산해요
            if (dist[u] + cost < dist[v]) {
                dist[v] = dist[u] + cost; // 비용을 업데이트해요
                predecessor[v] = u; // 어디서 왔는지 기록해요
                pq.push({dist[v], v}); // 큐에 새로운 공항을 넣어요
            }
        }
    }

    return dist; // 모든 공항까지의 최소 비용을 반환해요
}

int main() {
    int n, m;
    cout << "공항의 수를 입력하세요: ";
    cin >> n; // 공항의 개수를 입력해요
    cout << "항로의 수를 입력하세요: ";
    cin >> m; // 항로의 개수를 입력해요

    // 모든 공항에서 갈 수 있는 다른 공항과 비용을 저장하는 상자
    vector<vector<Edge>> adj(n, vector<Edge>());

    cout << "각 항로의 출발 공항, 도착 공항, 비용을 입력하세요 (예: 0 1 100):\n";
    for (int i = 0; i < m; ++i) {
        int u, v, cost;
        cin >> u >> v >> cost; // 항로 정보를 입력해요
        adj[u].push_back(Edge{v, cost}); // 한 방향으로 연결해요
        // 만약 두 방향으로 가고 싶으면 아래 줄의 주석을 없애세요
        // adj[v].push_back(Edge{u, cost});
    }

    int start, end;
    cout << "출발 공항과 도착 공항을 입력하세요: ";
    cin >> start >> end; // 시작 공항과 도착 공항을 입력해요

    // 어디서 왔는지를 기록할 상자, 처음에는 아무것도 없어요
    vector<int> predecessor(n, -1);

    // 다익스트라 알고리즘을 실행해요
    vector<int> distances = dijkstra(n, adj, start, predecessor);

    // 도착 공항까지의 최소 비용을 보여줘요
    if (distances[end] == INT32_MAX) { // 만약 도착할 수 없으면
        cout << "출발 공항에서 도착 공항으로 가는 경로가 없어요.\n";
        return 0;
    }

    cout << "최소 비용: " << distances[end] << "\n"; // 최소 비용을 출력해요

    // 도착 공항에서 시작해서 역으로 경로를 찾아요
    stack<int> path;
    int current = end;
    while (current != -1) { // 더 이상 이전 공항이 없을 때까지
        path.push(current); // 경로에 추가해요
        current = predecessor[current]; // 이전 공항으로 이동해요
    }

    // 올바른 순서로 경로를 보여줘요
    cout << "최적 경로: ";
    while (!path.empty()) { // 모든 경로를 다 출력할 때까지
        cout << path.top(); // 현재 공항을 보여줘요
        path.pop(); // 다음 공항을 위해 빼요
        if (!path.empty())
            cout << " -> "; // 다음 공항이 있으면 화살표를 추가해요
    }
    cout << "\n";

    return 0; // 프로그램을 끝내요
}
