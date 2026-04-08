#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

const int HeapSize = 100;

class Sets {
public:
    Sets(int);
    void display();  // 집합별로 {1,2,3} 형태로 출력
    void SimpleUnion(int i, int j);  // 합집합 결과를 출력
    int SimpleFind(int);  // 집합의 루트 찾기
    void WeightedUnion(int i, int j);  // 차집합 결과를 출력
    void Delete(int n);  // n이 포함된 집합에서 n을 제거
    void Difference(int i, int j);  // 차집합 결과를 출력
    void Intersection(int i, int j);  // 교차 집합 결과를 출력
private:
    int* parent;  // 각 노드의 부모를 추적
    int n;  // 집합의 크기
};

// 생성자: 각 원소의 부모를 -1로 초기화
Sets::Sets(int sz = HeapSize) {
    n = sz;
    parent = new int[sz + 1];  // 0은 사용하지 않음
    for (int i = 1; i <= n; i++) parent[i] = -1;  // -1로 초기화
}

// SimpleFind: 주어진 원소의 루트를 찾는 함수
int Sets::SimpleFind(int i) {
    if (parent[i] < 0) return i;  // 부모가 -1이면 루트
    return SimpleFind(parent[i]);  // 재귀적으로 부모를 찾아가며 루트 찾기
}

// SimpleUnion: 두 집합을 합치는 함수 (단순 합집합)
void Sets::SimpleUnion(int i, int j) {
    int rootI = SimpleFind(i);
    int rootJ = SimpleFind(j);
    if (rootI != rootJ) parent[rootJ] = rootI;  // rootI를 rootJ의 부모로 설정
}

// WeightedUnion: 두 집합을 합치되, 작은 트리를 큰 트리에 합침
void Sets::WeightedUnion(int i, int j) {
    int rootI = SimpleFind(i);
    int rootJ = SimpleFind(j);
    if (rootI != rootJ) {
        int sizeI = -parent[rootI];  // rootI의 트리 크기
        int sizeJ = -parent[rootJ];  // rootJ의 트리 크기
        if (sizeI >= sizeJ) {
            parent[rootI] -= sizeJ;  // rootI가 더 크면 rootJ를 rootI에 붙임
            parent[rootJ] = rootI;   // rootJ의 부모를 rootI로 설정
        } else {
            parent[rootJ] -= sizeI;  // rootJ가 더 크면 rootI를 rootJ에 붙임
            parent[rootI] = rootJ;   // rootI의 부모를 rootJ로 설정
        }
    }
}

// Delete: 특정 원소를 포함한 집합에서 원소를 삭제
void Sets::Delete(int n) {
    int rootN = SimpleFind(n);
    parent[n] = -1;  // 삭제된 원소는 -1로 표시 (루트일 경우 트리 재구성 필요)
}

// Difference: 집합 i에서 집합 j의 요소들을 제거 (차집합)
void Sets::Difference(int i, int j) {
    int rootI = SimpleFind(i);
    int rootJ = SimpleFind(j);
    if (rootI == rootJ) return;  // 두 집합이 같으면 차집합이 없음

    for (int k = 1; k <= n; k++) {
        if (SimpleFind(k) == rootJ) parent[k] = -1;  // j 집합의 모든 원소를 제거
    }
}

// Intersection: 집합 i와 j의 교집합을 구해서 i에 저장
void Sets::Intersection(int i, int j) {
    int rootI = SimpleFind(i);
    int rootJ = SimpleFind(j);
    if (rootI != rootJ) return;  // 두 집합이 다르면 교집합이 없음

    for (int k = 1; k <= n; k++) {
        if (SimpleFind(k) != rootI) parent[k] = -1;  // 교집합만 남기고 나머지 삭제
    }
}

// display: 각 집합을 {1,2,3} 형태로 출력
void Sets::display() {
    for (int i = 1; i <= n; i++) {
        if (parent[i] < 0) {  // 루트인 경우
            cout << "{ ";
            for (int j = 1; j <= n; j++) {
                if (SimpleFind(j) == i) cout << j << " ";
            }
            cout << "}" << endl;
        }
    }
}

int main(void) {
    Sets m(20);
    m.SimpleUnion(7, 1); m.SimpleUnion(2, 3); m.SimpleUnion(4, 5); m.SimpleUnion(6, 7);
    m.SimpleUnion(4, 2); m.SimpleUnion(5, 7); m.SimpleUnion(8, 10); m.SimpleUnion(13, 11);
    m.SimpleUnion(12, 9); m.SimpleUnion(14, 20); m.SimpleUnion(16, 19);
    m.SimpleUnion(17, 18); m.SimpleUnion(12, 19); m.SimpleUnion(13, 15);
    cout << "SimpleUnion() 실행 결과::" << endl;
    m.display();
    
    m.WeightedUnion(1, 2); m.WeightedUnion(1, 4); m.WeightedUnion(23, 29); m.WeightedUnion(29, 15);
    m.WeightedUnion(29, 4); m.WeightedUnion(2, 29);
    cout << "WeightedUnion() 실행 결과::" << endl;
    m.display();

    if (m.SimpleFind(2) == m.SimpleFind(18))
        cout << "2, 18은 같은 집합이다" << endl;
    else
        cout << "2, 18은 다른 집합이다" << endl;
    
    cout << "***2를 집합에서 삭제한다***" << endl;
    m.Delete(2);
    
    if (m.SimpleFind(2) == m.SimpleFind(18))
        cout << "2, 18은 같은 집합이다" << endl;
    else
        cout << "2, 18은 다른 집합이다" << endl;

    m.display();
    m.Difference(19, 29);
    m.display();
    m.Intersection(19, 29);
    m.display();
    
    system("pause");
    return 0;
}
