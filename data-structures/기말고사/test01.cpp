#include <iostream>
#include <string>

using namespace std;

// -----------------------------
// 주문 정보를 저장하는 구조체
// -----------------------------
struct Order {
    int orderID;            // 주문 ID (정수형, 트리의 키 값으로 사용)
    string customerName;    // 고객 이름 (문자열)
    int orderAmount;        // 주문 금액 (정수형)
};

// -----------------------------
// 이진 탐색 트리의 노드 구조체
// -----------------------------
struct BSTNode {
    Order data;             // 노드가 저장하는 주문 데이터
    BSTNode* left;         // 왼쪽 자식 노드를 가리키는 포인터
    BSTNode* right;        // 오른쪽 자식 노드를 가리키는 포인터

    // 생성자: 새로운 노드를 생성할 때 데이터 초기화
    BSTNode(Order order) : data(order), left(nullptr), right(nullptr) {}
};

// -----------------------------
// 이진 탐색 트리 클래스
// -----------------------------
class BST {
private:
    BSTNode* root; // 트리의 루트 노드를 가리키는 포인터

    // -----------------------------
    // 트리에 새 노드를 삽입하는 재귀 함수
    // -----------------------------
    BSTNode* insertNode(BSTNode* node, Order order) {
        // 현재 위치가 NULL이면 새 노드를 생성하여 반환
        if (node == nullptr) {
            return new BSTNode(order);
        }

        // 삽입하려는 orderID가 현재 노드의 orderID보다 작으면 왼쪽 서브트리에 삽입
        if (order.orderID < node->data.orderID) {
            node->left = insertNode(node->left, order);
        }
        // 삽입하려는 orderID가 현재 노드의 orderID보다 크면 오른쪽 서브트리에 삽입
        else if (order.orderID > node->data.orderID) {
            node->right = insertNode(node->right, order);
        }
        // orderID가 중복되는 경우는 무시 (중복 삽입 방지)
        return node;
    }

    // -----------------------------
    // 트리에서 특정 orderID를 가진 노드를 검색하는 재귀 함수
    // -----------------------------
    BSTNode* searchNode(BSTNode* node, int orderID) {
        // 현재 노드가 NULL이거나 찾고자 하는 orderID와 일치하면 현재 노드 반환
        if (node == nullptr || node->data.orderID == orderID) {
            return node;
        }

        // 찾고자 하는 orderID가 현재 노드의 orderID보다 작으면 왼쪽 서브트리 검색
        if (orderID < node->data.orderID) {
            return searchNode(node->left, orderID);
        }
        // 찾고자 하는 orderID가 현재 노드의 orderID보다 크면 오른쪽 서브트리 검색
        else {
            return searchNode(node->right, orderID);
        }
    }

    // -----------------------------
    // 트리에서 가장 작은 orderID를 가진 노드를 찾는 함수
    // -----------------------------
    BSTNode* findMin(BSTNode* node) {
        // 가장 왼쪽 노드가 가장 작은 orderID를 가짐
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // -----------------------------
    // 트리에서 특정 orderID를 가진 노드를 삭제하는 재귀 함수
    // -----------------------------
    BSTNode* deleteNode(BSTNode* node, int orderID) {
        // 현재 노드가 NULL이면 삭제할 노드가 없으므로 그대로 반환
        if (node == nullptr) return node;

        // 삭제하려는 orderID가 현재 노드의 orderID보다 작으면 왼쪽 서브트리에서 삭제 시도
        if (orderID < node->data.orderID) {
            node->left = deleteNode(node->left, orderID);
        }
        // 삭제하려는 orderID가 현재 노드의 orderID보다 크면 오른쪽 서브트리에서 삭제 시도
        else if (orderID > node->data.orderID) {
            node->right = deleteNode(node->right, orderID);
        }
        // 삭제하려는 orderID가 현재 노드의 orderID와 같으면 삭제 진행
        else {
            // 자식이 없는 노드 또는 하나의 자식만 있는 노드인 경우
            if (node->left == nullptr) {
                BSTNode* temp = node->right; // 오른쪽 자식을 임시 저장
                delete node; // 현재 노드 삭제
                return temp; // 오른쪽 자식 반환
            }
            else if (node->right == nullptr) {
                BSTNode* temp = node->left; // 왼쪽 자식을 임시 저장
                delete node; // 현재 노드 삭제
                return temp; // 왼쪽 자식 반환
            }

            // 자식이 두 개인 경우: 오른쪽 서브트리에서 최소값을 가진 노드를 찾아 현재 노드에 대체
            BSTNode* temp = findMin(node->right); // 오른쪽 서브트리의 최소값 노드 찾기
            node->data = temp->data; // 현재 노드의 데이터를 최소값 노드의 데이터로 대체
            node->right = deleteNode(node->right, temp->data.orderID); // 오른쪽 서브트리에서 최소값 노드 삭제
        }
        return node; // 변경된 노드 반환
    }

    // -----------------------------
    // 트리를 중위 순회(Inorder Traversal)하여 orderID 순서대로 출력하는 재귀 함수
    // -----------------------------
    void inorderTraversal(BSTNode* node) {
        if (node != nullptr) { // 노드가 존재하면
            inorderTraversal(node->left); // 왼쪽 서브트리 순회
            // 현재 노드의 주문 정보 출력
            cout << "Order ID: " << node->data.orderID
                 << ", Customer Name: " << node->data.customerName
                 << ", Order Amount: " << node->data.orderAmount << endl;
            inorderTraversal(node->right); // 오른쪽 서브트리 순회
        }
    }

    // -----------------------------
    // 특정 금액 이상인 주문만을 중위 순회하여 출력하는 재귀 함수
    // -----------------------------
    void printWithMinAmount(BSTNode* node, int minAmount) {
        if (node != nullptr) { // 노드가 존재하면
            printWithMinAmount(node->left, minAmount); // 왼쪽 서브트리 순회
            // 현재 노드의 주문 금액이 최소 금액 이상인 경우에만 출력
            if (node->data.orderAmount >= minAmount) {
                cout << "Order ID: " << node->data.orderID
                     << ", Customer Name: " << node->data.customerName
                     << ", Order Amount: " << node->data.orderAmount << endl;
            }
            printWithMinAmount(node->right, minAmount); // 오른쪽 서브트리 순회
        }
    }

    // -----------------------------
    // 트리에 저장된 모든 주문의 총 주문 금액을 계산하는 재귀 함수
    // -----------------------------
    int calculateTotal(BSTNode* node) {
        if (node == nullptr) return 0; // 노드가 없으면 0 반환
        // 현재 노드의 주문 금액 + 왼쪽 서브트리의 합 + 오른쪽 서브트리의 합
        return node->data.orderAmount + calculateTotal(node->left) + calculateTotal(node->right);
    }

public:
    // 생성자: 초기 루트 노드를 NULL로 설정
    BST() : root(nullptr) {}

    // -----------------------------
    // 외부에서 주문을 삽입할 때 호출하는 함수
    // -----------------------------
    void insert(Order order) {
        root = insertNode(root, order); // 루트 노드부터 삽입 시작
    }

    // -----------------------------
    // 외부에서 주문을 검색할 때 호출하는 함수
    // -----------------------------
    void search(int orderID) {
        BSTNode* result = searchNode(root, orderID); // 루트 노드부터 검색 시작
        if (result != nullptr) { // 주문이 존재하면
            cout << "Order Found - ID: " << result->data.orderID
                 << ", Customer: " << result->data.customerName
                 << ", Amount: " << result->data.orderAmount << endl;
        }
        else { // 주문이 존재하지 않으면
            cout << "Order ID " << orderID << " not found." << endl;
        }
    }

    // -----------------------------
    // 외부에서 주문을 삭제할 때 호출하는 함수
    // -----------------------------
    void remove(int orderID) {
        root = deleteNode(root, orderID); // 루트 노드부터 삭제 시도
    }

    // -----------------------------
    // 외부에서 모든 주문을 출력할 때 호출하는 함수
    // -----------------------------
    void displayInOrder() {
        inorderTraversal(root); // 중위 순회로 모든 주문 출력
    }

    // -----------------------------
    // 외부에서 특정 금액 이상인 주문을 출력할 때 호출하는 함수
    // -----------------------------
    void displayWithMinAmount(int minAmount) {
        printWithMinAmount(root, minAmount); // 중위 순회로 조건에 맞는 주문 출력
    }

    // -----------------------------
    // 외부에서 총 주문 금액을 계산할 때 호출하는 함수
    // -----------------------------
    void totalOrderAmount() {
        int total = calculateTotal(root); // 총 주문 금액 계산
        cout << "Total Order Amount: " << total << endl; // 결과 출력
    }
};

// -----------------------------
// 사용자에게 메뉴를 출력하는 함수
// -----------------------------
void printMenu() {
    cout << "\n===== 주문 관리 시스템 =====\n";
    cout << "1. 주문 삽입\n";
    cout << "2. 주문 검색\n";
    cout << "3. 주문 삭제\n";
    cout << "4. 모든 주문 출력\n";
    cout << "5. 특정 금액 이상인 주문 출력\n";
    cout << "6. 총 주문 금액 계산\n";
    cout << "7. 종료\n";
    cout << "선택: ";
}

// -----------------------------
// 메인 함수: 프로그램의 시작점
// -----------------------------
int main() {
    BST bst; // 이진 탐색 트리 객체 생성
    int choice; // 사용자 선택을 저장할 변수

    while (true) { // 무한 루프: 사용자가 종료할 때까지 계속 실행
        printMenu(); // 메뉴 출력
        cin >> choice; // 사용자로부터 선택 입력

        if (choice == 1) {
            // -------------------------
            // 1. 주문 삽입
            // -------------------------
            Order order; // 새로운 주문을 저장할 변수
            cout << "주문 ID: ";
            cin >> order.orderID; // 주문 ID 입력
            cout << "고객 이름: ";
            cin >> ws; // 이전 입력의 남은 공백 문자 제거
            getline(cin, order.customerName); // 고객 이름 입력 (공백 포함 가능)
            cout << "주문 금액: ";
            cin >> order.orderAmount; // 주문 금액 입력
            bst.insert(order); // 트리에 주문 삽입
            cout << "주문이 삽입되었습니다.\n";
        }
        else if (choice == 2) {
            // -------------------------
            // 2. 주문 검색
            // -------------------------
            int id;
            cout << "검색할 주문 ID: ";
            cin >> id; // 검색할 주문 ID 입력
            bst.search(id); // 주문 검색 및 결과 출력
        }
        else if (choice == 3) {
            // -------------------------
            // 3. 주문 삭제
            // -------------------------
            int id;
            cout << "삭제할 주문 ID: ";
            cin >> id; // 삭제할 주문 ID 입력
            bst.remove(id); // 주문 삭제
            cout << "주문이 삭제되었습니다 (존재하지 않을 수도 있습니다).\n";
        }
        else if (choice == 4) {
            // -------------------------
            // 4. 모든 주문 출력
            // -------------------------
            cout << "\n--- 모든 주문 ---\n";
            bst.displayInOrder(); // 모든 주문을 orderID 순서대로 출력
        }
        else if (choice == 5) {
            // -------------------------
            // 5. 특정 금액 이상인 주문 출력
            // -------------------------
            int minAmount;
            cout << "최소 주문 금액: ";
            cin >> minAmount; // 최소 주문 금액 입력
            cout << "\n--- 주문 금액이 " << minAmount << " 이상인 주문 ---\n";
            bst.displayWithMinAmount(minAmount); // 조건에 맞는 주문만 출력
        }
        else if (choice == 6) {
            // -------------------------
            // 6. 총 주문 금액 계산
            // -------------------------
            bst.totalOrderAmount(); // 모든 주문의 총 금액 계산 및 출력
        }
        else if (choice == 7) {
            // -------------------------
            // 7. 종료
            // -------------------------
            cout << "프로그램을 종료합니다.\n";
            break; // 루프 종료: 프로그램 종료
        }
        else {
            // -------------------------
            // 잘못된 선택 처리
            // -------------------------
            cout << "잘못된 선택입니다. 다시 시도하세요.\n";
        }
    }

    return 0; // 프로그램 정상 종료
}
