#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class SimpleObject5 {
public:
    static const int NO = 1;
    static const int NAME = 2;

    string no;
    string name;

    SimpleObject5(string sno = "", string sname = "") : no(sno), name(sname) {}

    friend ostream& operator<<(ostream& os, const SimpleObject5& obj) {
        return os << "(" << obj.no << ") " << obj.name;
    }

    // Comparator for ordering by number
    struct NoOrderComparator {
        bool operator()(const SimpleObject5& a, const SimpleObject5& b) const {
            return a.no < b.no;
        }
    };

    // Comparator for ordering by name
    struct NameOrderComparator {
        bool operator()(const SimpleObject5& a, const SimpleObject5& b) const {
            return a.name < b.name;
        }
    };

    void scanData(const string& guide, int sw) {
        cout << guide << "할 데이터를 입력하세요: " << endl;
        if (sw & NO) {
            cout << "번호: ";
            cin >> no;
        }
        if (sw & NAME) {
            cout << "이름: ";
            cin >> name;
        }
    }
};

class ChainHash5 {
private:
    struct Node {
        SimpleObject5 data;
        Node* next;

        Node(const SimpleObject5& s, Node* p = nullptr) : data(s), next(p) {}
    };

    int size;
    vector<Node*> table;

public:
    // 생성자: 테이블 크기 초기화
    ChainHash5(int capacity) : size(capacity), table(capacity, nullptr) {}

    // 해시 함수: 문자열 번호를 정수로 변환 후 테이블 크기로 나눈 나머지를 반환
    int hashValue(const string& key) const {
        // 예외 처리: key가 비어있을 경우
        if(key.empty()) return 0;
        int hash = 0;
        for(char ch : key){
            hash = (hash * 31 + (ch - '0')) % size;
        }
        return hash;
    }

    // 데이터 검색: cmp는 비교 함수 (예: NoOrderComparator)
    bool search(const SimpleObject5& st, const function<bool(const SimpleObject5&, const SimpleObject5&)>& cmp) {
        int hash = hashValue(st.no); // 번호를 기준으로 해시값 계산
        Node* p = table[hash];
        while (p != nullptr) {
            if (cmp(p->data, st)) {
                return true; // 데이터가 존재함
            }
            p = p->next;
        }
        return false; // 데이터가 없음
    }

    // 데이터 추가: 중복이 없을 경우 리스트의 앞에 삽입
    bool add(const SimpleObject5& st, const function<bool(const SimpleObject5&, const SimpleObject5&)>& cmp) {
        if (search(st, cmp)) {
            return false; // 중복 데이터 존재
        }
        int hash = hashValue(st.no); // 해시값 계산
        Node* newNode = new Node(st, table[hash]); // 새로운 노드를 리스트 앞에 삽입
        table[hash] = newNode;
        return true; // 추가 성공
    }

    // 데이터 삭제: 일치하는 노드를 찾아 삭제
    bool remove(const SimpleObject5& st, const function<bool(const SimpleObject5&, const SimpleObject5&)>& cmp) {
        int hash = hashValue(st.no); // 해시값 계산
        Node* p = table[hash];
        Node* prev = nullptr;

        while (p != nullptr) {
            if (cmp(p->data, st)) {
                if (prev == nullptr) {
                    table[hash] = p->next; // 첫 노드 삭제
                }
                else {
                    prev->next = p->next; // 중간 또는 마지막 노드 삭제
                }
                delete p; // 메모리 해제
                return true; // 삭제 성공
            }
            prev = p;
            p = p->next;
        }
        return false; // 삭제할 데이터가 없음
    }

    // 모든 데이터를 출력
    void dump() const {
        for (int i = 0; i < size; ++i) {
            cout << i << ": ";
            Node* p = table[i];
            while (p != nullptr) {
                cout << p->data << " -> ";
                p = p->next;
            }
            cout << "nullptr" << endl;
        }
    }

    // 소멸자: 모든 노드의 메모리 해제
    ~ChainHash5() {
        for (int i = 0; i < size; ++i) {
            Node* p = table[i];
            while (p != nullptr) {
                Node* tmp = p;
                p = p->next;
                delete tmp;
            }
        }
    }
};

enum class Menu {
    Add, Delete, Search, Show, Exit
};

// 메뉴 선택 함수
Menu selectMenu() {
    int choice;
    do {
        cout << "(0) 삽입 (1) 삭제 (2) 검색 (3) 출력 (4) 종료 : ";
        cin >> choice;
    } while (choice < static_cast<int>(Menu::Add) || choice > static_cast<int>(Menu::Exit));
    return static_cast<Menu>(choice);
}

int main() {
    ChainHash5 hash(13); // 해시 테이블 크기 13
    SimpleObject5 data;
    Menu menu;

    do {
        menu = selectMenu();
        switch (menu) {
        case Menu::Add:
            data.scanData("삽입", SimpleObject5::NO | SimpleObject5::NAME);
            if (!hash.add(data, SimpleObject5::NoOrderComparator()))
                cout << " 중복 데이터가 존재합니다." << endl;
            else
                cout << " 입력 처리됨." << endl;
            break;
        case Menu::Delete:
            data.scanData("삭제", SimpleObject5::NO);
            if (hash.remove(data, SimpleObject5::NoOrderComparator()))
                cout << " 삭제 처리됨." << endl;
            else
                cout << " 삭제할 데이터가 없습니다." << endl;
            break;
        case Menu::Search:
            data.scanData("검색", SimpleObject5::NO);
            if (hash.search(data, SimpleObject5::NoOrderComparator()))
                cout << " 검색 데이터가 존재합니다." << endl;
            else
                cout << " 검색 데이터가 없습니다." << endl;
            break;
        case Menu::Show:
            hash.dump();
            break;
        case Menu::Exit:
            break;
        }
    } while (menu != Menu::Exit);

    return 0;
}
