#include <iostream>
#define MaxCapacity 20
using namespace std;

// 트리 노드 클래스
class TreeNode {
	friend class Tree;  // Tree 클래스가 TreeNode의 private 멤버에 접근할 수 있도록 허용
private:
	TreeNode* LeftChild;  // 왼쪽 자식 노드
	int data;             // 노드의 데이터 (정수 값)
	int leftSize;         // 왼쪽 서브트리에 있는 노드의 개수
	TreeNode* RightChild; // 오른쪽 자식 노드
public:
	TreeNode(int x) : data(x), LeftChild(NULL), RightChild(NULL), leftSize(0) {}
};

// 이진 탐색 트리 클래스
class Tree {
public:
	Tree() : root(NULL) {}  // 기본 생성자
	Tree(const Tree& s) { root = copy(s.root); } // 복사 생성자

	void inorder() { inorder(root); }     // 중위 순회
	void preorder() { preorder(root); }   // 전위 순회
	void postorder() { postorder(root); } // 후위 순회

	bool insert(int x);          // 값 삽입
	bool remove(int x);          // 값 삭제
	int search(int rank);        // n번째 작은 값을 찾는다
	int rank(TreeNode* node);    // 랭크 계산
	void rank() { rank(root); }  // 트리 전체 랭크 계산 시작점

	// 트리 비교 연산자 오버로딩
	int operator==(const Tree& t) {
		return equal(this->root, t.root);
	}

private:
	TreeNode* root;                        // 트리의 루트 노드
	TreeNode* inorderSucc(TreeNode* node); // 중위 후속자 찾기
	bool isLeafNode(TreeNode* node);       // 리프 노드 확인
	void inorder(TreeNode* node);          // 중위 순회 재귀 함수
	void preorder(TreeNode* node);         // 전위 순회 재귀 함수
	void postorder(TreeNode* node);        // 후위 순회 재귀 함수
	TreeNode* copy(TreeNode* node);        // 트리 복사
	int equal(TreeNode* a, TreeNode* b);   // 두 트리가 같은지 비교
};

// 중위 순회
void Tree::inorder(TreeNode* node) {
	if (node) {
		inorder(node->LeftChild);
		cout << node->data << " ";
		inorder(node->RightChild);
	}
}

// 전위 순회
void Tree::preorder(TreeNode* node) {
	if (node) {
		cout << node->data << " ";
		preorder(node->LeftChild);
		preorder(node->RightChild);
	}
}

// 후위 순회
void Tree::postorder(TreeNode* node) {
	if (node) {
		postorder(node->LeftChild);
		postorder(node->RightChild);
		cout << node->data << " ";
	}
}

// 랭크 계산 (왼쪽 서브트리 크기 저장)
int Tree::rank(TreeNode* node) {
	if (node == NULL) return 0;
	node->leftSize = rank(node->LeftChild);
	return node->leftSize + 1 + rank(node->RightChild);
}

// n번째 작은 값 검색
int Tree::search(int targetRank) {
	TreeNode* node = root;
	while (node != NULL) {
		int currentRank = node->leftSize + 1;
		if (targetRank == currentRank)
			return node->data;  // targetRank 위치의 값을 찾았을 경우
		else if (targetRank < currentRank)
			node = node->LeftChild;  // 왼쪽으로 이동
		else {
			targetRank -= currentRank;
			node = node->RightChild; // 오른쪽으로 이동
		}
	}
	return -1; // targetRank 위치가 없을 경우
}

// 트리에 값 삽입
bool Tree::insert(int x) {
	TreeNode* newNode = new TreeNode(x);
	if (root == NULL) {
		root = newNode;
		return true;
	}

	TreeNode* parent = NULL;
	TreeNode* current = root;
	while (current != NULL) {
		parent = current;
		if (x < current->data) {
			current->leftSize++;
			current = current->LeftChild;
		}
		else if (x > current->data) {
			current = current->RightChild;
		}
		else {
			delete newNode; // 중복된 값이면 삽입하지 않음
			return false;
		}
	}

	if (x < parent->data)
		parent->LeftChild = newNode;
	else
		parent->RightChild = newNode;

	return true;
}

// 노드 삭제
bool Tree::remove(int x) {
	TreeNode* parent = NULL;
	TreeNode* node = root;

	// 삭제할 노드 검색
	while (node != NULL && node->data != x) {
		parent = node;
		if (x < node->data)
			node = node->LeftChild;
		else
			node = node->RightChild;
	}
	if (node == NULL) return false; // 삭제할 노드가 없을 경우

	// 리프 노드인 경우
	if (isLeafNode(node)) {
		if (node == root)
			root = NULL;
		else if (parent->LeftChild == node)
			parent->LeftChild = NULL;
		else
			parent->RightChild = NULL;
		delete node;
	}
	// 자식 노드가 하나만 있는 경우
	else if (node->LeftChild == NULL || node->RightChild == NULL) {
		TreeNode* child = (node->LeftChild != NULL) ? node->LeftChild : node->RightChild;
		if (node == root)
			root = child;
		else if (parent->LeftChild == node)
			parent->LeftChild = child;
		else
			parent->RightChild = child;
		delete node;
	}
	// 자식 노드가 두 개 있는 경우
	else {
		TreeNode* succ = inorderSucc(node);
		int succData = succ->data;
		remove(succData); // 후속자를 삭제
		node->data = succData; // 삭제할 노드에 후속자 값을 대체
	}

	return true;
}

// 리프 노드인지 확인
bool Tree::isLeafNode(TreeNode* node) {
	return node->LeftChild == NULL && node->RightChild == NULL;
}

// 중위 후속자 찾기
TreeNode* Tree::inorderSucc(TreeNode* node) {
	TreeNode* temp = node->RightChild;
	while (temp->LeftChild != NULL) temp = temp->LeftChild;
	return temp;
}

// 트리 복사
TreeNode* Tree::copy(TreeNode* node) {
	if (node == NULL) return NULL;
	TreeNode* newNode = new TreeNode(node->data);
	newNode->leftSize = node->leftSize;
	newNode->LeftChild = copy(node->LeftChild);
	newNode->RightChild = copy(node->RightChild);
	return newNode;
}

// 트리 비교
int Tree::equal(TreeNode* a, TreeNode* b) {
	if (a == NULL && b == NULL) return 1;
	if (a != NULL && b != NULL && a->data == b->data)
		return equal(a->LeftChild, b->LeftChild) && equal(a->RightChild, b->RightChild);
	return 0;
}

// main 함수
enum { Insert, Remove, Inorder, Preorder, Postorder, Search, Copy, Quit };
int main() {
	Tree t;
	int select = 0;
	int max = 0, x = 0;
	while (select != 7) {
		cout << "BinarySearchTree. Select 0.Insert, 1. Remove, 2.Inorder, 3.Preorder, 4.Postorder, 5.Search, 6.Copy, 7.Quit =>";
		cin >> select;
		switch (select) {
		case Insert:
			cout << "The number of items = ";
			cin >> max;
			for (int i = 0; i < max; i++) {
				int rnd = rand() % 20;
				if (!t.insert(rnd)) cout << "Insert Duplicated data" << endl;
			}
			break;
		case Remove:
			cout << "삭제할 값 입력: ";
			cin >> x;
			cout << t.remove(x) << endl;
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
			t.rank();
			cout << "찾고자 하는 rank 순위 입력: ";
			cin >> x;
			int rankNumber = t.search(x);
			cout << x << " 번째 순위 값은 " << rankNumber << endl;
			break;
		case Copy:
			cout << ((t == Tree(t)) ? "compare result: true" : "compare result: false") << endl;
			break;
		case Quit:
			cout << "Quit" << endl;
			break;
		default:
			cout << "WRONG INPUT" << endl;
			break;
		}
	}
	return 0;
}
