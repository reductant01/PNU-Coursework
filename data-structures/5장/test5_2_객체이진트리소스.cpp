#include <iostream>
#include <string>
using namespace std;

#define MaxCapacity 20

// Employee 클래스: 사원 번호와 이름을 가지며, 비교 연산자를 오버로딩하여 트리에서의 비교를 가능하게 함
class Employee {
    friend class TreeNode; // TreeNode 클래스가 Employee 클래스의 private 멤버에 접근할 수 있도록 허용
    friend class Tree;     // Tree 클래스가 Employee 클래스의 private 멤버에 접근할 수 있도록 허용
    string eno;            // 사원 번호
    string ename;          // 사원 이름
public:
    Employee() {}
    Employee(string sno, string sname) : eno(sno), ename(sname) {}
    friend ostream& operator<<(ostream& os, Employee&); // 출력 연산자 오버로딩
    bool operator<(Employee&);                          // 사원 번호를 기준으로 비교 연산자(<) 오버로딩
    bool operator==(Employee&);                         // 사원 번호와 이름이 같은지 비교 연산자(==) 오버로딩
};

// 출력 연산자 오버로딩: 사원의 번호와 이름을 출력
ostream& operator<<(ostream& os, Employee& emp) {
    os << " " << emp.eno << emp.ename;
    return os;
}

// == 연산자 오버로딩: 사원 번호와 이름이 같을 경우 true를 반환
bool Employee::operator==(Employee& emp) {
    return (eno == emp.eno) && (ename == emp.ename);
}

// < 연산자 오버로딩: 사원 번호를 기준으로 비교
bool Employee::operator<(Employee& emp) {
    return eno < emp.eno;
}

// TreeNode 클래스: 트리의 노드를 나타내며, Employee 데이터를 저장
class TreeNode {
    friend class Tree;    // Tree 클래스가 TreeNode의 private 멤버에 접근할 수 있도록 허용
private:
    TreeNode* LeftChild;  // 왼쪽 자식 노드
    Employee data;        // 사원 정보
    TreeNode* RightChild; // 오른쪽 자식 노드
public:
    TreeNode(Employee emp) : data(emp), LeftChild(NULL), RightChild(NULL) {} // 생성자
};

// Tree 클래스: 이진 탐색 트리의 구현
class Tree {
public:
    Tree() { root = NULL; }             // 생성자
    Tree(const Tree& s) { root = copy(s.root); } // 복사 생성자

    bool insert(Employee ex);            // 트리에 사원 정보 삽입
    bool remove(Employee ex);            // 트리에서 사원 정보 삭제
    bool search(Employee ex);            // 트리에서 사원 정보 검색
    void inorder() { inorder(root); }    // 중위 순회
    void preorder() { preorder(root); }  // 전위 순회
    void postorder() { postorder(root); } // 후위 순회

    TreeNode* inorderSucc(TreeNode* current); // 중위 후속자(다음 노드) 찾기
    bool isLeafNode(TreeNode* current);       // 리프 노드인지 확인
    int operator==(const Tree& t) {           // 트리 비교 연산자 오버로딩
        return equal(this->root, t.root);
    }
private:
    TreeNode* root;                           // 트리의 루트 노드
    void inorder(TreeNode* CurrentNode);      // 중위 순회 재귀 함수
    void preorder(TreeNode* CurrentNode);     // 전위 순회 재귀 함수
    void postorder(TreeNode* CurrentNode);    // 후위 순회 재귀 함수
    TreeNode* copy(TreeNode* orignode);       // 트리를 복사하는 함수
    int equal(TreeNode* a, TreeNode* b);      // 두 트리가 같은지 비교
};

// 중위 후속자(다음 노드)를 찾기 위한 함수
TreeNode* Tree::inorderSucc(TreeNode* current) {
    TreeNode* temp = current->RightChild;
    if (current->RightChild != NULL) {
        while (temp->LeftChild != NULL)
            temp = temp->LeftChild;
    }
    return temp;
}

// 리프 노드인지 확인하는 함수
bool Tree::isLeafNode(TreeNode* current) {
    return current->LeftChild == NULL && current->RightChild == NULL;
}

// 중위 순회
void Tree::inorder(TreeNode* CurrentNode) {
    if (CurrentNode) {
        inorder(CurrentNode->LeftChild);
        cout << " " << CurrentNode->data;
        inorder(CurrentNode->RightChild);
    }
}

// 전위 순회
void Tree::preorder(TreeNode* CurrentNode) {
    if (CurrentNode) {
        cout << CurrentNode->data << " ";
        preorder(CurrentNode->LeftChild);
        preorder(CurrentNode->RightChild);
    }
}

// 후위 순회
void Tree::postorder(TreeNode* CurrentNode) {
    if (CurrentNode) {
        postorder(CurrentNode->LeftChild);
        postorder(CurrentNode->RightChild);
        cout << CurrentNode->data << " ";
    }
}

// 트리를 복사하는 함수
TreeNode* Tree::copy(TreeNode* orignode) {
    if (orignode == NULL) return NULL;
    TreeNode* newNode = new TreeNode(orignode->data);
    newNode->LeftChild = copy(orignode->LeftChild);
    newNode->RightChild = copy(orignode->RightChild);
    return newNode;
}

// 두 트리가 동일한지 비교
int Tree::equal(TreeNode* a, TreeNode* b) {
    if (a == NULL && b == NULL) return 1;
    if (a != NULL && b != NULL && a->data == b->data)
        return equal(a->LeftChild, b->LeftChild) && equal(a->RightChild, b->RightChild);
    return 0;
}

// 사원 정보 삽입 함수
bool Tree::insert(Employee ex) {
    TreeNode* newNode = new TreeNode(ex);
    if (root == NULL) {
        root = newNode;
        return true;
    }
    TreeNode* p = root;
    TreeNode* q = NULL;
    while (p != NULL) {
        q = p;
        if (ex < p->data)
            p = p->LeftChild;
        else if (p->data < ex)
            p = p->RightChild;
        else
            return false; // 중복된 데이터이므로 삽입하지 않음
    }
    if (ex < q->data)
        q->LeftChild = newNode;
    else
        q->RightChild = newNode;
    return true;
}

// 사원 정보 삭제 함수
bool Tree::remove(Employee ex) {
    TreeNode* parent = NULL;
    TreeNode* node = root;
    while (node != NULL && !(node->data == ex)) {
        parent = node;
        if (ex < node->data)
            node = node->LeftChild;
        else
            node = node->RightChild;
    }
    if (node == NULL) return false;

    if (isLeafNode(node)) { // 리프 노드인 경우
        if (node == root)
            root = NULL;
        else if (parent->LeftChild == node)
            parent->LeftChild = NULL;
        else
            parent->RightChild = NULL;
        delete node;
    }
    else if (node->LeftChild && node->RightChild) { // 자식 노드가 두 개 있는 경우
        TreeNode* succ = inorderSucc(node);
        Employee succValue = succ->data;
        node->data = succValue;  
        remove(succValue);       
    }
    else { // 자식 노드가 하나인 경우
        TreeNode* child = (node->LeftChild) ? node->LeftChild : node->RightChild;
        if (node == root)
            root = child;
        else if (parent->LeftChild == node)
            parent->LeftChild = child;
        else
            parent->RightChild = child;
        delete node;
    }
    return true;
}

// 사원 정보 검색 함수
bool Tree::search(Employee ex) {
    TreeNode* node = root;
    while (node != NULL) {
        if (ex == node->data)
            return true;
        else if (ex < node->data)
            node = node->LeftChild;
        else
            node = node->RightChild;
    }
    return false;
}

// 명령어를 선택할 때 사용하는 Enum
enum Enum { Insert, Remove, Inorder, Preorder, Postorder, Search, Copy, Quit };

int main() {
    Tree t;
    bool eq = -1;
    int select = 0;
    Employee* data;

    while (select != 7) {
        cout << "BinarySearchTree. Select 0.Insert, 1. Remove, 2.Inorder, 3.Preorder, 4.Postorder, 5.Search, 6.Copy, 7.Quit =>";
        cin >> select;
        string eno, ename;
        switch (static_cast<Enum>(select)) {
        case Insert:
            cout << "삽입 사원번호 입력:: ";
            cin >> eno;
            cout << "삽입 사원 이름 입력:: ";
            cin >> ename;
            data = new Employee(eno, ename);
            t.insert(*data);
            break;
        case Remove:
            cout << "삭제 사원번호 입력:: ";
            cin >> eno;
            cout << "삭제 사원 이름 입력:: ";
            cin >> ename;
            data = new Employee(eno, ename);
            cout << t.remove(*data) << endl;
            break;
        case Inorder:
            cout << "inorder print:: ";
            t.inorder();
            cout << endl;
            break;
        case Preorder:
            cout << "preorder print:: ";
            t.preorder();
            cout << endl;
            break;
        case Postorder:
            cout << "postorder print:: ";
            t.postorder();
            cout << endl;
            break;
        case Search:
            cout << "검색 사원번호 입력:: ";
            cin >> eno;
            cout << "검색 사원 이름 입력:: ";
            cin >> ename;
            data = new Employee(eno, ename);
            if (t.search(*data))
                cout << eno << " 값이 존재한다" << endl;
            else
                cout << "값이 없다" << endl;
            break;
        case Copy:
            eq = (t == Tree(t));
            if (eq) cout << "compare result: true" << endl;
            else cout << "compare result: false" << endl;
            break;
        case Quit:
            cout << "Quit" << endl;
            break;
        default:
            cout << "WRONG INPUT  " << endl;
            cout << "Re-Enter" << endl;
            break;
        }
    }

    system("pause");
    return 0;
}
