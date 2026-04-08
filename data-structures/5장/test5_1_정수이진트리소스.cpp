#include <iostream>
#define MaxCapacity 20
using namespace std;

class TreeNode {
	friend class Tree;
private:
	TreeNode* LeftChild;
	int data;
	TreeNode* RightChild;

public:
	TreeNode(int d) : data(d), LeftChild(NULL), RightChild(NULL) {}
};

class Tree {
public:
	Tree() {
		root = NULL;
	}

	// Copy constructor: 새 트리를 생성하고 원본 트리를 복사
	Tree(const Tree& s) {
		root = copy(s.root);
	}

	// 현재 노드의 Inorder Successor(중위 순서의 다음 노드)를 반환
	TreeNode* inorderSucc(TreeNode* current);

	// 현재 노드가 리프(자식이 없는 노드)인지 확인
	bool isLeafNode(TreeNode* current);

	// 중위(inorder) 순회, main에서 사용할수 있도록 public으로 오버로딩 (드라이버)
	void inorder() {
		inorder(root);
	}

	// 전위(preorder) 순회
	void preorder() {
		preorder(root);
	}

	// 후위(postorder) 순회
	void postorder() {
		postorder(root);
	}

	// 트리에 새로운 데이터를 삽입
	bool insert(int x);

	// 트리에서 특정 데이터를 삭제
	bool remove(int num);

	// 트리에서 특정 데이터를 탐색
	bool search(int num);

	// 연산자 오버로딩: 두 트리가 같은지 비교
	int operator==(const Tree& t) {
		return equal(this->root, t.root);
	}

private:
	TreeNode* root;

	// 중위(inorder) 순회 재귀 함수
	void inorder(TreeNode* CurrentNode);

	// 전위(preorder) 순회 재귀 함수
	void preorder(TreeNode* CurrentNode);

	// 후위(postorder) 순회 재귀 함수
	void postorder(TreeNode* CurrentNode);

	// 트리 복사
	TreeNode* copy(TreeNode* orignode);

	// 두 트리가 같은지 확인
	int equal(TreeNode* a, TreeNode* b);
};

// Inorder Successor 찾기
TreeNode* Tree::inorderSucc(TreeNode* current) {
	TreeNode* temp = current->RightChild;
	if (current->RightChild != NULL) {
		// 오른쪽 자식이 있는 경우, 오른쪽 하위 트리의 가장 왼쪽 노드를 반환
		while (temp->LeftChild != NULL) temp = temp->LeftChild;
	}
	return temp;
}

// 현재 노드가 리프(자식이 없는 노드)인지 확인
bool Tree::isLeafNode(TreeNode* current) {
	return current->LeftChild == NULL && current->RightChild == NULL;
}

// 중위(inorder) 순회: 왼쪽 -> 현재 -> 오른쪽
void Tree::inorder(TreeNode* CurrentNode) {
	if (CurrentNode) { // 현재 노드가 NULL이 아닐 때만 수행
		inorder(CurrentNode->LeftChild); // 왼쪽 자식을 먼저 방문
		cout << " " << CurrentNode->data; // 현재 노드의 데이터를 출력
		inorder(CurrentNode->RightChild); // 오른쪽 자식을 방문
	}
}


// 전위(preorder) 순회: 현재 -> 왼쪽 -> 오른쪽
void Tree::preorder(TreeNode* CurrentNode) {
	if (CurrentNode) {
		cout << CurrentNode->data << " ";
		preorder(CurrentNode->LeftChild);
		preorder(CurrentNode->RightChild);
	}
}

// 후위(postorder) 순회: 왼쪽 -> 오른쪽 -> 현재
void Tree::postorder(TreeNode* CurrentNode) {
	if (CurrentNode) {
		postorder(CurrentNode->LeftChild);
		postorder(CurrentNode->RightChild);
		cout << CurrentNode->data << " ";
	}
}

// 트리 복사 (재귀적으로 모든 노드 복사)
TreeNode* Tree::copy(TreeNode* orignode) {
	if (orignode == NULL)
		return NULL;

	// 현재 노드를 복사하고 자식 노드들도 재귀적으로 복사
	TreeNode* newNode = new TreeNode(orignode->data);
	newNode->LeftChild = copy(orignode->LeftChild);
	newNode->RightChild = copy(orignode->RightChild);
	return newNode;
}

// 두 트리가 같은지 확인
int Tree::equal(TreeNode* a, TreeNode* b) {
	if (a == NULL && b == NULL)
		return 1;
	else if (a != NULL && b != NULL && a->data == b->data)
		return equal(a->LeftChild, b->LeftChild) && equal(a->RightChild, b->RightChild);
	else
		return 0;
}

// 트리에 새로운 데이터를 삽입
bool Tree::insert(int x) {
    TreeNode* newNode = new TreeNode(x); // 새 노드 생성
    if (root == NULL) { // 트리가 비어 있는 경우
        root = newNode; // 새 노드를 루트에 추가
        return true;
    }
    TreeNode* p = root; // 탐색을 시작할 포인터, 현재 노드 위치
    TreeNode* q = NULL; // 현재 노드의 부모 노드를 가리킬 포인터
    while (p != NULL) {
        q = p; // 부모 노드 포인터를 현재 위치로 업데이트, 나중에 p는 Null이 되기 때문에 꼭 필요한 과정이다.
        if (x < p->data)
            p = p->LeftChild; // 삽입하려는 값이 현재 노드보다 작으면 왼쪽으로 이동
        else if (x > p->data)
            p = p->RightChild; // 삽입하려는 값이 현재 노드보다 크면 오른쪽으로 이동
        else
            return false; // 값이 같다면 중복 데이터이므로 삽입하지 않음
    }
    // 새 노드를 찾은 위치에 추가
    if (x < q->data)
        q->LeftChild = newNode; // 새 노드를 부모의 왼쪽에 연결
    else
        q->RightChild = newNode; // 새 노드를 부모의 오른쪽에 연결
    return true;
}

// 트리에서 특정 데이터를 삭제
bool Tree::remove(int num) {
	TreeNode* parent = NULL;
	TreeNode* node = root;

	while (node != NULL && node->data != num) {
		parent = node; // 부모를 현재 노드로 갱신
		if (num < node->data)
			node = node->LeftChild; // 찾으려는 값이 더 작으면 왼쪽으로 이동
		else
			node = node->RightChild; // 찾으려는 값이 더 크면 오른쪽으로 이동
	}

	if (node == NULL) // 노드를 찾지 못한 경우
		return false;

	if (node == NULL)
		return false;

	// 리프 노드 삭제
	if (isLeafNode(node)) {
		if (node == root)
			root = NULL; // 삭제할 노드가 루트인 경우 트리를 비웁니다.
		else if (parent->LeftChild == node)
			parent->LeftChild = NULL; // 부모의 왼쪽 자식에서 해당 노드 제거
		else
			parent->RightChild = NULL; // 부모의 오른쪽 자식에서 해당 노드 제거
		delete node; // 메모리 해제
	}

	// 자식이 두 개인 노드 삭제
	else if (node->LeftChild && node->RightChild) {
		TreeNode* succ = inorderSucc(node); // 중위 후속자 찾기
		int succValue = succ->data;
		remove(succValue); // 중위 후속자를 삭제
		node->data = succValue; // 현재 노드의 데이터를 중위 후속자의 값으로 대체
	}

	// 자식이 하나인 노드 삭제
	else {
	TreeNode* child = (node->LeftChild) ? node->LeftChild : node->RightChild;
		if (node == root)
			root = child; // 삭제할 노드가 루트인 경우 자식을 새로운 루트로 지정
		else if (parent->LeftChild == node)
			parent->LeftChild = child; // 부모의 왼쪽 자식으로 연결
		else
			parent->RightChild = child; // 부모의 오른쪽 자식으로 연결
		delete node; // 메모리 해제
	}
}

// 트리에서 특정 데이터 탐색
bool Tree::search(int num) {
	TreeNode* p = root;
	while (p != NULL) {
		if (num < p->data)
			p = p->LeftChild;
		else if (num > p->data)
			p = p->RightChild;
		else
			return true;
	}
	return false;
}

enum { Insert, Remove, Inorder, Preorder, Postorder, Search, Copy, Quit };

int main() {
	srand(time(NULL));
	Tree t;
	bool eq = -1;
	int select = 0;
	int max = 0, x = 0;
	while (select != 7) {
		int rnd = 0;
		cout << "BinarySearchTree. Select 0.Insert, 1. Remove, 2.Inorder, 3.Preorder, 4.Postorder, 5.Search, 6.Copy, 7.Quit =>";
		cin >> select;
		switch (select) {
		case Insert:
			cout << "The number of items = ";
			cin >> max;
			for (int i = 0; i < max; i++) {
				rnd = rand() % 20;
				if (!t.insert(rnd)) cout << "Insert Duplicated data" << endl;
			}
			break;
		case Remove:
			int x;
			cin >> x;
			cout << t.remove(x);
			cout << endl;
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
			cin >> x;
			if (t.search(x))
				cout << x << " 값이 존재한다" << endl;
			else
				cout << "값이 없다" << endl;
			break;
		case Copy:
			eq = (t == Tree(t));
			if (eq) {
				cout << "compare result: true" << endl;
			}
			else
				cout << "compare result: false" << endl;
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
