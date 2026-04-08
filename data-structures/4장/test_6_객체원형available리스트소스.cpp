/*
* 6단계- 원형 객체 연결 리스트의 available list, getNode, retNode
* head node를 갖고 있고 삭제된 노드들은 available list에 리턴한다.
* CircularList를 대상으로 한 iterator를 구현한다.
* template version으로 구현 
*/
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

// ------------- Employee 클래스 -------------
class Employee {
    friend class Node;
    friend class CircularList;
    friend class ListIterator;
private:
    string eno;    // 사원 번호
    string ename;  // 사원 이름
    int salary;    // 급여
public:
    Employee() {}
    Employee(string sno, string sname, int salary) : eno(sno), ename(sname), salary(salary) {}
    friend ostream& operator<<(ostream& os, const Employee&);
    bool operator<(const Employee& emp) const;
    bool operator==(const Employee& emp) const;
    char compare(const Employee* emp) const;
    int getSalary() const {
        return salary;
    }
};

// operator<< 구현
ostream& operator<<(ostream& os, const Employee& emp) {
    os << "[eno: " << emp.eno << ", ename: " << emp.ename << ", salary: " << emp.salary << "]";
    return os;
}

// operator== 구현 (eno 기준)
bool Employee::operator==(const Employee& emp) const {
    return this->eno == emp.eno;
}

// operator< 구현 (eno 기준, 오름차순)
bool Employee::operator<(const Employee& emp) const {
    return this->eno < emp.eno;
}

// compare 함수 구현
char Employee::compare(const Employee* emp) const {
    if (this->eno < emp->eno)
        return '<';
    else if (this->eno > emp->eno)
        return '>';
    else
        return '=';
}

// ------------- Node 클래스 -------------
class Node {
    friend class ListIterator;
    friend class CircularList;
    friend ostream& operator<<(ostream& os, const CircularList& l); // 친구 함수 선언 추가
private:
    Employee data;
    Node* link;
public:
    Node() : link(nullptr) {}
    Node(const Employee& element) : data(element), link(nullptr) {}
};

// ------------- CircularList 클래스 -------------
class CircularList {
    friend class ListIterator;
    Node* first;       // 더미 노드를 가리키는 포인터
    Node* last;        // 마지막 노드를 가리키는 포인터
    static Node* av;    // available list (static)
public:
    CircularList() {
        first = new Node(); // 더미 노드 생성
        first->link = first; // 자기 자신을 가리킴 (빈 리스트)
        last = first;        // 초기에는 last도 더미 노드를 가리킴
    }

    ~CircularList() {
        // 모든 노드를 available list로 반환
        if (first != nullptr) {
            Node* p = first->link;
            while (p != first) {
                Node* temp = p;
                p = p->link;
                RetNode(temp);
            }
            RetNode(first); // 더미 노드도 반환
            first = nullptr;
            last = nullptr;
        }
    }

    bool Delete(string); // eno로 삭제
    void Show() const;    // 전체 리스트 출력
    void Add(Employee*);  // eno 기준으로 정렬하여 삽입
    bool Search(string) const; // eno 검색
    Node* GetNode();      // available list에서 노드 가져오기
    void RetNode(Node*); // 노드 available list에 반환
    void Erase();         // 모든 노드 삭제 (available list로 반환)
    CircularList operator+(const CircularList& lb) const; // 리스트 병합
    friend ostream& operator<<(ostream& os, const CircularList& l);
};

// static 변수 초기화
Node* CircularList::av = nullptr;

// GetNode 구현
Node* CircularList::GetNode() {
    if (av != nullptr) { // available list에 노드가 있으면
        Node* temp = av;
        av = av->link;
        return temp;
    }
    else { // 없으면 새 노드 생성
        return new Node();
    }
}

// RetNode 구현
void CircularList::RetNode(Node* x) {
    x->link = av;
    av = x;
}

// operator<< 구현
ostream& operator<<(ostream& os, const CircularList& l) {
    if (l.first->link == l.first) { // 빈 리스트
        os << "리스트가 비어 있습니다." << endl;
        return os;
    }
    Node* p = l.first->link; // 첫 번째 실제 노드
    do {
        os << p->data << " -> ";
        p = p->link;
    } while (p != l.first->link);
    os << "head" << endl;
    return os;
}

// Show 구현
void CircularList::Show() const {
    if (first->link == first) { // 빈 리스트
        cout << "리스트가 비어 있습니다." << endl;
        return;
    }
    Node* p = first->link; // 첫 번째 실제 노드
    do {
        cout << p->data << " -> ";
        p = p->link;
    } while (p != first->link);
    cout << "head" << endl;
}

// Add 구현 (eno 기준 오름차순)
void CircularList::Add(Employee* element) {
    Node* newNode = GetNode();
    newNode->data = *element;

    Node* p = first->link; // 첫 번째 실제 노드
    Node* q = first;       // 이전 노드

    // 빈 리스트이거나, 첫 노드보다 eno가 작은 경우
    if (p == first || newNode->data.eno < p->data.eno) {
        newNode->link = p;
        q->link = newNode;
        if (p == first) { // 리스트가 비어 있었던 경우, last를 새 노드로 설정
            last = newNode;
        }
        return;
    }

    // 적절한 위치 찾기
    while (p != first && newNode->data.eno > p->data.eno) {
        q = p;
        p = p->link;
    }

    // eno가 동일한 경우 업데이트 후 반환
    if (p != first && newNode->data.eno == p->data.eno) {
        p->data = newNode->data; // 기존 데이터를 새로운 데이터로 대체
        RetNode(newNode);        // 새 노드 반환
        return;
    }

    // 노드 삽입
    newNode->link = p;
    q->link = newNode;

    // 마지막 노드를 업데이트
    if (p == first) { // 리스트의 끝에 삽입된 경우
        last = newNode;
    }
}

// Search 구현
bool CircularList::Search(string eno) const {
    if (first->link == first) // 빈 리스트
        return false;

    Node* p = first->link; // 첫 번째 실제 노드
    while (p != first) { // head node까지
        if (p->data.eno == eno)
            return true;
        p = p->link;
    }
    return false;
}

// Delete 구현
bool CircularList::Delete(string eno) {
    if (first->link == first) // 빈 리스트
        return false;

    Node* p = first->link; // 첫 번째 실제 노드
    Node* q = first;       // 이전 노드

    while (p != first) { // head node까지
        if (p->data.eno == eno) {
            q->link = p->link;
            // 삭제할 노드가 last인 경우 last를 이전 노드로 업데이트
            if (p == last) {
                last = q;
                // 만약 리스트가 비게 되면 last를 더미 노드로 설정
                if (last == first) {
                    // 리스트가 비었음을 이미 q->link = first로 설정했으므로 추가 작업 필요 없음
                }
            }
            RetNode(p);
            return true;
        }
        q = p;
        p = p->link;
    }
    return false; // eno를 가진 사원이 없음
}

// Erase 구현 (모든 노드 삭제)
void CircularList::Erase() {
    if (first->link == first) // 빈 리스트
        return;

    Node* p = first->link; // 첫 번째 실제 노드
    while (p != first) {
        Node* temp = p;
        p = p->link;
        RetNode(temp);
    }
    first->link = first; // 자기 자신을 가리키도록 설정
    last = first;        // 리스트가 비었으므로 last를 더미 노드로 설정
}

// operator+ 구현 (두 리스트 병합)
CircularList CircularList::operator+(const CircularList& lb) const {
    CircularList lc;
    ListIterator Aiter(*this);
    ListIterator Biter(lb);
    Employee* p = Aiter.First();
    Employee* q = Biter.First();

    while (p != nullptr && q != nullptr) {
        if (p->eno < q->eno) {
            lc.Add(p);
            p = Aiter.Next();
        }
        else if (p->eno > q->eno) {
            lc.Add(q);
            q = Biter.Next();
        }
        else { // eno가 같은 경우 하나만 추가
            lc.Add(p);
            p = Aiter.Next();
            q = Biter.Next();
        }
    }

    // 남아있는 노드 추가
    while (p != nullptr) {
        lc.Add(p);
        p = Aiter.Next();
    }
    while (q != nullptr) {
        lc.Add(q);
        q = Biter.Next();
    }

    return lc;
}

// ------------- ListIterator 클래스 -------------
class ListIterator {
public:
    ListIterator(const CircularList& lst);
    ~ListIterator();
    bool NotNull();
    bool NextNotNull();
    Employee* First();
    Employee* Next();
    Employee& operator*() const;
    Employee* operator->() const;
    ListIterator& operator++(); // Pre-increment
    ListIterator operator++(int); // Post-increment
    bool operator!=(const ListIterator) const;
    bool operator==(const ListIterator) const;
    Employee* GetCurrent();
private:
    Node* current; // pointer to nodes
    const CircularList& list; // existing list
};

// ListIterator 생성자
ListIterator::ListIterator(const CircularList& lst) : list(lst), current(nullptr) {
    // 초기화 시 첫 번째 실제 노드로 설정
    if (lst.first->link != lst.first) { // 리스트가 비어있지 않다면
        current = lst.first->link;
    }
}

// NotNull 구현
bool ListIterator::NotNull() {
    return current != nullptr && current != list.first;
}

// NextNotNull 구현
bool ListIterator::NextNotNull() {
    if (current && current->link != list.first)
        return true;
    return false;
}

// First 구현
Employee* ListIterator::First() {
    if (list.first->link == list.first) { // 빈 리스트
        current = nullptr;
        return nullptr;
    }
    current = list.first->link; // 첫 번째 실제 노드
    return &current->data;
}

// Next 구현
Employee* ListIterator::Next() {
    if (current && current->link != list.first) {
        current = current->link;
        return &current->data;
    }
    current = nullptr;
    return nullptr;
}

// GetCurrent 구현
Employee* ListIterator::GetCurrent() {
    if (current != nullptr)
        return &current->data;
    return nullptr;
}

// Destructor
ListIterator::~ListIterator() {
    // 특별한 메모리 관리 필요 없음
}

// Dereference operators
Employee& ListIterator::operator*() const {
    return current->data;
}

Employee* ListIterator::operator->() const {
    return &current->data;
}

// Pre-increment 연산자 구현
ListIterator& ListIterator::operator++() {
    if (current && current->link != list.first)
        current = current->link;
    else
        current = nullptr;
    return *this;
}

// Post-increment 연산자 구현
ListIterator ListIterator::operator++(int) {
    ListIterator temp = *this;
    if (current && current->link != list.first)
        current = current->link;
    else
        current = nullptr;
    return temp;
}

// operator!= 구현
bool ListIterator::operator!=(const ListIterator right) const {
    return current != right.current;
}

// operator== 구현
bool ListIterator::operator==(const ListIterator right) const {
    return current == right.current;
}

// ------------- sum, avg, min, max 함수 구현 -------------
int sum(const CircularList& l)
{
    ListIterator li(l);
    int total = 0;
    Employee* p = li.First();
    while (p != nullptr) {
        total += p->getSalary();
        p = li.Next();
    }
    return total;
}

double avg(const CircularList& l)
{
    ListIterator li(l);
    int total = 0;
    int count = 0;
    Employee* p = li.First();
    while (p != nullptr) {
        total += p->getSalary();
        count++;
        p = li.Next();
    }
    if (count == 0)
        return 0.0;
    return static_cast<double>(total) / count;
}

int min(const CircularList& l)
{
    ListIterator li(l);
    Employee* p = li.First();
    if (p == nullptr)
        return 0; // 빈 리스트일 경우
    int minimum = p->getSalary();
    p = li.Next();
    while (p != nullptr) {
        if (p->getSalary() < minimum)
            minimum = p->getSalary();
        p = li.Next();
    }
    return minimum;
}

int max(const CircularList& l)
{
    ListIterator li(l);
    Employee* p = li.First();
    if (p == nullptr)
        return 0; // 빈 리스트일 경우
    int maximum = p->getSalary();
    p = li.Next();
    while (p != nullptr) {
        if (p->getSalary() > maximum)
            maximum = p->getSalary();
        p = li.Next();
    }
    return maximum;
}

// ------------- main 함수 구현 -------------
enum Enum {
    Add0, Add1, DeleteOp, ShowOp, SearchOp, MergeOp, SUM, AVG, MIN, MAX, ExitOp
};

int main() {
    Enum menu; // 메뉴
    int selectMenu;
    string eno, ename;
    int pay;
    Employee* data;
    bool result = false;
    CircularList la, lb, lc;
    Employee* s;

    do {
        cout << endl << "0.Add0, 1.Add1, 2.Delete, 3.Show, 4.Search, 5.Merge, 6.sum, 7.avg, 8.min, 9.max, 10.exit 선택::";
        cin >> selectMenu;
        switch (static_cast<Enum>(selectMenu)) {
        case Add0:
            cout << "사원번호 입력:: ";
            cin >> eno;
            cout << "사원 이름 입력:: ";
            cin >> ename;
            cout << "사원 급여:: ";
            cin >> pay;
            data = new Employee(eno, ename, pay);
            la.Add(data);
            break;
        case Add1:
            cout << "사원번호 입력:: ";
            cin >> eno;
            cout << "사원 이름 입력:: ";
            cin >> ename;
            cout << "사원 급여:: ";
            cin >> pay;
            data = new Employee(eno, ename, pay);
            lb.Add(data);
            break;
        case DeleteOp:
            cout << "사원번호 입력:: ";
            cin >> eno;
            result = la.Delete(eno);
            if (result)
                cout << "eno = " << eno << " 삭제 완료." << endl;
            else
                cout << "eno = " << eno << " 삭제 실패: 해당 사원번호가 없습니다." << endl;
            break;
        case ShowOp:
            cout << "리스트 la = " << la;
            cout << "리스트 lb = " << lb;
            break;
        case SearchOp:
            cout << "사원번호 입력:: ";
            cin >> eno;
            result = la.Search(eno);
            if (!result)
                cout << "검색 값 = " << eno << " 데이터가 없습니다." << endl;
            else
                cout << "검색 값 = " << eno << " 데이터가 존재합니다." << endl;
            break;
        case MergeOp:
            lc = la + lb;
            cout << "리스트 lc = " << lc;
            cout << "리스트 la를 삭제" << endl;
            la.Erase();
            cout << "리스트 lb를 삭제" << endl;
            lb.Erase();
            cout << "리스트 la = " << la;
            cout << endl << "리스트 lb = " << lb;
            break;
        case SUM:
            cout << "sum() = " << sum(la) << endl;
            break;
        case AVG:
            cout << "avg() = " << avg(la) << endl;
            break;
        case MIN:
            cout << "min() = " << min(la) << endl;
            break;
        case MAX:
            cout << "max() = " << max(la) << endl;
            break;
        case ExitOp:
            cout << "프로그램을 종료합니다." << endl;
            break;
        default:
            cout << "잘못된 선택입니다. 다시 시도해주세요." << endl;
            break;
        }
    } while (selectMenu != ExitOp);
    return 0;
}
