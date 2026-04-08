/*
 * 단계8 : 원형 객체 이중 연결 리스트의 available list, getNode, retNode
 * head node를 갖고 있고 삭제된 노드들은 available list에 리턴한다.
 * CircularDoublyList를 대상으로 한 iterator를 구현한다.
 * Template 버전 구현 
 */

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
using namespace std;

// Forward declarations
template<class T> class DoublyListNode;
template<class T> class CircularDoublyList;
template<class T> class CircularDoublyListIterator;

// ------------- Employee 클래스 -------------
class Employee {
    template<class T> friend class DoublyListNode;
    template<class T> friend class CircularDoublyList;
    template<class T> friend class CircularDoublyListIterator;
private:
    string eno;    // 사원 번호
    string ename;  // 사원 이름
    int salary;    // 급여
public:
    Employee() {}
    Employee(string sno, string sname, int salary) :eno(sno), ename(sname), salary(salary) {}

    // operator<< 구현
    friend ostream& operator<<(ostream& os, const Employee& emp);

    // operator== 구현 (eno 기준)
    bool operator==(const Employee& emp) const;

    // operator< 구현 (eno 기준)
    bool operator<(const Employee& emp) const;

    // operator> 구현 (eno 기준)
    bool operator>(const Employee& emp) const;

    // compare 함수 구현
    char compare(const Employee* emp) const;

    // getSalary 함수
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

// operator< 구현 (eno 기준)
bool Employee::operator<(const Employee& emp) const {
    return this->eno < emp.eno;
}

// operator> 구현 (eno 기준)
bool Employee::operator>(const Employee& emp) const {
    return this->eno > emp.eno;
}

// compare 함수 구현
char Employee::compare(const Employee* emp) const {
    if (this->eno < emp->eno) return '<';
    if (this->eno > emp->eno) return '>';
    return '=';
}

// ------------- DoublyListNode 클래스 -------------
template<class T>
class DoublyListNode {
    friend class CircularDoublyList<T>;
    friend class CircularDoublyListIterator<T>;
public:
    DoublyListNode(T* p) {
        data = *p;
        llink = rlink = this;
    }
    DoublyListNode() {
        llink = rlink = this;
    }
private:
    T data;
    DoublyListNode<T>* llink, * rlink;
};

// ListNode operator<< 구현 (비필수, 주로 내부 사용)
template <class T>
ostream& operator<<(ostream& os, const DoublyListNode<T>& ln) {
    os << ln.data;
    return os;
}

// ------------- CircularDoublyList 클래스 -------------
template<class T>
class CircularDoublyList {
    friend class CircularDoublyListIterator<T>;
public:
    CircularDoublyList() { 
        first = GetNode();    // 더미 노드 생성
        first->rlink = first; // 더미 노드의 오른쪽 링크는 자기 자신
        first->llink = first; // 더미 노드의 왼쪽 링크도 자기 자신
        last = first;         // 초기에는 last도 더미 노드를 가리킴
    }

    // 복사 생성자
    CircularDoublyList(const CircularDoublyList<T>& l) {
        if (l.first == l.last) { // 빈 리스트
            first = GetNode();
            first->rlink = first;
            first->llink = first;
            last = first;
            return;
        }
        // 복사할 리스트가 비어있지 않은 경우
        first = GetNode();    // 새로운 더미 노드 생성
        first->rlink = first;
        first->llink = first;
        last = first;
        DoublyListNode<T>* current = l.first->rlink; // 첫 번째 실제 노드
        while (current != l.first) {
            Add(&current->data);
            current = current->rlink;
        }
    }

    ~CircularDoublyList() {
        Erase();
        RetNode(first);
    }

    // Add 함수: eno 기준 오름차순으로 삽입
    void Add(T* element) {
        DoublyListNode<T>* newNode = GetNode();
        newNode->data = *element;

        if (last->rlink == first) { // 리스트가 비어있는 경우
            // 새 노드를 리스트에 삽입
            newNode->rlink = first; // 새 노드의 오른쪽 링크는 더미 노드
            newNode->llink = last;   // 새 노드의 왼쪽 링크는 더미 노드
            first->rlink = newNode;  // 더미 노드의 오른쪽 링크는 새 노드
            first->llink = newNode;  // 더미 노드의 왼쪽 링크도 새 노드
            last = newNode;          // last를 새 노드로 업데이트
            return;
        }

        // eno 기준 오름차순으로 삽입 위치 찾기
        DoublyListNode<T>* current = first->rlink; // 첫 번째 실제 노드
        while (current != first && current->data.eno < newNode->data.eno) {
            current = current->rlink;
        }

        if (current == first) { // 리스트의 끝에 삽입
            newNode->rlink = first;
            newNode->llink = last;
            last->rlink = newNode;
            first->llink = newNode;
            last = newNode;
        }
        else { // 중간 또는 시작 위치에 삽입
            newNode->rlink = current;
            newNode->llink = current->llink;
            current->llink->rlink = newNode;
            current->llink = newNode;
        }
    }

    // Delete 함수: eno 기준으로 노드 삭제
    bool Delete(string eno) {
        if (last->rlink == first) return false; // 빈 리스트
        DoublyListNode<T>* current = first->rlink; // 첫 번째 실제 노드
        while (current != first) {
            if (current->data.eno == eno) {
                // 링크 조정
                current->llink->rlink = current->rlink;
                current->rlink->llink = current->llink;
                if (current == last) { // 삭제할 노드가 마지막 노드인 경우
                    last = current->llink;
                }
                RetNode(current); // 노드를 available list에 반환
                return true;
            }
            current = current->rlink;
        }
        return false; // eno를 가진 사원이 없음
    }

    // Search 함수: eno 기준으로 노드 검색
    bool Search(string eno) {
        if (last->rlink == first) return false; // 빈 리스트
        DoublyListNode<T>* current = first->rlink; // 첫 번째 실제 노드
        while (current != first) {
            if (current->data.eno == eno) return true;
            current = current->rlink;
        }
        return false;
    }

    // Show 함수: 리스트의 모든 노드를 출력
    void Show() const {
        if (last->rlink == first) { // 빈 리스트
            cout << "리스트가 비어 있습니다." << endl;
            return;
        }
        DoublyListNode<T>* p = first->rlink; // 첫 번째 실제 노드
        while (p != first) {
            cout << p->data << " <-> ";
            p = p->rlink;
        }
        cout << "head" << endl;
    }

    // Erase 함수: 모든 노드를 삭제하고 available list에 반환
    void Erase() {
        if (last->rlink == first) return; // 빈 리스트
        DoublyListNode<T>* current = first->rlink; // 첫 번째 실제 노드
        while (current != first) {
            DoublyListNode<T>* temp = current;
            current = current->rlink;
            RetNode(temp);
        }
        first->rlink = first; // 더미 노드의 링크를 자기 자신으로 설정
        first->llink = first; // 더미 노드의 왼쪽 링크도 자기 자신으로 설정
        last = first;         // last를 더미 노드로 재설정
    }

    // operator+ 구현: 두 리스트를 병합하여 새로운 리스트를 반환
    CircularDoublyList<T> operator+(const CircularDoublyList<T>& lb) const {
        CircularDoublyList<T> lc;
        CircularDoublyListIterator<T> Aiter(*this);
        CircularDoublyListIterator<T> Biter(lb);
        T* p = Aiter.First();
        T* q = Biter.First();

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
                lc.Add(p); // 또는 데이터를 병합하려면 추가 로직 필요
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

    // GetNode 함수: available list에서 노드를 가져오거나 새 노드를 생성
    DoublyListNode<T>* GetNode() {
        if (av != nullptr) { // available list에 노드가 있으면
            DoublyListNode<T>* temp = av;
            av = av->rlink; // rlink를 사용하여 available list를 순회
            temp->llink = temp->rlink = temp; // 링크 초기화
            return temp;
        }
        else { // 없으면 새 노드 생성
            return new DoublyListNode<T>();
        }
    }

    // RetNode 함수: 노드를 available list에 반환
    void RetNode(DoublyListNode<T>* x) {
        x->rlink = av; // rlink를 사용하여 available list에 추가
        av = x;
    }

    // Friend operator<< 구현
    template <class T>
    friend ostream& operator<<(ostream&, const CircularDoublyList<T>&);

private:
    DoublyListNode<T>* first;    // 더미 노드를 가리키는 포인터
    DoublyListNode<T>* last;     // 마지막 노드를 가리키는 포인터
    static DoublyListNode<T>* av; // available list (static)
};

// static 변수 초기화
template<class T>
DoublyListNode<T>* CircularDoublyList<T>::av = nullptr;

// operator<< 구현
template<class T>
ostream& operator<<(ostream& os, const CircularDoublyList<T>& l)
{
    l.Show();
    return os;
}

// ------------- CircularDoublyListIterator 클래스 -------------
template<class T>
class CircularDoublyListIterator {
public:
    CircularDoublyListIterator(const CircularDoublyList<T>& l) : list(l), current(l.first->rlink) {}

    ~CircularDoublyListIterator() {}

    // 리스트가 비어있는지 확인
    bool NotNull() const {
        return list.first != list.last;
    }

    // 다음 노드가 있는지 확인
    bool NextNotNull() const {
        return current->rlink != list.first;
    }

    // 첫 번째 노드로 이동
    T* First() {
        if (list.first == list.last) { // 빈 리스트
            return nullptr;
        }
        current = list.first->rlink;
        return &current->data;
    }

    // 다음 노드로 이동
    T* Next() {
        if (current->rlink == list.first) { // 원형 리스트의 끝
            return nullptr;
        }
        current = current->rlink;
        return &current->data;
    }

    // 현재 노드 반환
    T* GetCurrent() {
        if (current != list.first) {
            return &current->data;
        }
        return nullptr;
    }

private:
    const CircularDoublyList<T>& list;
    DoublyListNode<T>* current;
};

// ------------- 보조 함수 구현 -------------
template<class T>
int sum(const CircularDoublyList<T>& l)
{
    int total = 0;
    CircularDoublyListIterator<T> iter(l);
    T* p = iter.First();
    while (p != nullptr) {
        total += p->getSalary();
        p = iter.Next();
    }
    return total;
}

template<class T>
double avg(const CircularDoublyList<T>& l)
{
    int total = 0;
    int count = 0;
    CircularDoublyListIterator<T> iter(l);
    T* p = iter.First();
    while (p != nullptr) {
        total += p->getSalary();
        count++;
        p = iter.Next();
    }
    if (count == 0) return 0.0;
    return static_cast<double>(total) / count;
}

template<class T>
int min(const CircularDoublyList<T>& l)
{
    if (l.first == l.last) return 0; // 빈 리스트
    CircularDoublyListIterator<T> iter(l);
    T* p = iter.First();
    if (p == nullptr) return 0;
    int minimum = p->getSalary();
    p = iter.Next();
    while (p != nullptr) {
        if (p->getSalary() < minimum)
            minimum = p->getSalary();
        p = iter.Next();
    }
    return minimum;
}

template<class T>
int max(const CircularDoublyList<T>& l)
{
    if (l.first == l.last) return 0; // 빈 리스트
    CircularDoublyListIterator<T> iter(l);
    T* p = iter.First();
    if (p == nullptr) return 0;
    int maximum = p->getSalary();
    p = iter.Next();
    while (p != nullptr) {
        if (p->getSalary() > maximum)
            maximum = p->getSalary();
        p = iter.Next();
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
    CircularDoublyList<Employee> la, lb, lc;
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
            cout << *data << endl;
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
            cout << *data << endl;
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
            cout << "리스트 la = ";
            la.Show();
            cout << "리스트 lb = ";
            lb.Show();
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
            cout << "리스트 lc = ";
            lc.Show();
            cout << "리스트 la를 삭제" << endl;
            la.Erase();
            cout << "리스트 lb를 삭제" << endl;
            lb.Erase();
            cout << "리스트 la = ";
            la.Show();
            cout << "리스트 lb = ";
            lb.Show();
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
