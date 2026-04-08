#include <iostream>
#include <cstdlib> // 난수 생성에 필요한 헤더
#include <ctime>   // 난수 시드 초기화에 필요한 헤더
using namespace std;

const int HeapSize = 1000;
enum Boolean { FALSE, TRUE };

template <class Type>
class Element {
public:
	Type key;
	Element() {}
	Element(Type key) :key(key) {}
};

template <class Type>
class MaxPQ {
public:
	virtual void Insert(const Element<Type>&) = 0;
	virtual Element<Type>* DeleteMax(Element<Type>&) = 0;
};

template <class Type>
class MaxHeap : public MaxPQ<Type> {
public:
	MaxHeap(int sz = HeapSize) {
		MaxSize = sz;
		n = 0;
		heap = new Element<Type>[MaxSize + 1]; // heap[0]은 사용하지 않음
	};
	void display();
	void Insert(const Element<Type>& x);
	Element<Type>* DeleteMax(Element<Type>&);
private:
	Element<Type>* heap;
	int n; // 현재 힙의 크기
	int MaxSize; // 힙의 최대 크기
	void HeapEmpty() { cout << "Heap Empty" << "\n"; };
	void HeapFull() { cout << "Heap Full"; };
};

// 힙의 요소를 레벨 순서로 출력하는 함수
template <class Type>
void MaxHeap<Type>::display() {
	if (n == 0) {
		cout << "Heap is empty." << endl;
		return;
	}
	cout << "Heap elements in level order: ";
	for (int i = 1; i <= n; i++) {
		cout << heap[i].key << " ";
	}
	cout << endl;
}

// 힙에 새로운 요소를 삽입하는 함수
template <class Type>
void MaxHeap<Type>::Insert(const Element<Type>& x) {
	if (n >= MaxSize) { // 힙이 가득 찬 경우
		HeapFull();
		return;
	}
	n++; // 새로운 요소를 삽입할 위치
	int i = n;
	while (i > 1 && x.key > heap[i / 2].key) { // 부모보다 큰 경우 스왑
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = x; // 새로운 요소 삽입
}

// 힙에서 최대값을 삭제하고 반환하는 함수
template <class Type>
Element<Type>* MaxHeap<Type>::DeleteMax(Element<Type>& x) {
	if (n == 0) { // 힙이 비어있는 경우
		HeapEmpty();
		return nullptr;
	}
	x = heap[1]; // 루트에 있는 최대값을 반환
	heap[1] = heap[n--]; // 마지막 요소를 루트로 이동 후 크기 감소
	int i = 1, j = 2; // i는 부모 인덱스, j는 자식 인덱스
	while (j <= n) {
		if (j < n && heap[j].key < heap[j + 1].key) j++; // 큰 자식 선택
		if (heap[i].key >= heap[j].key) break; // 부모가 자식보다 크면 멈춤
		swap(heap[i], heap[j]); // 부모와 자식을 스왑
		i = j;
		j *= 2;
	}
	return &x;
}

// 힙을 사용하여 정렬하는 함수
void heapSort(MaxHeap<int> hp) {
	Element<int> ele;
	cout << "Sorted elements: ";
	while (hp.DeleteMax(ele)) { // 최대값을 계속 삭제하면서 정렬
		cout << ele.key << " ";
	}
	cout << endl;
}

int main() {
	int select = 0;
	int data = 0;

	MaxHeap<int> heap(20); // 최대 크기 20의 힙 생성
	Element<int> ele;

	Element<int>* deletedEle = nullptr;

	// 난수 생성을 위한 시드 초기화
	srand(time(NULL));

	do {
		cout << endl << "Max Tree. Select: 1 insert, 2 display, 3 delete, 4 sort, 5 exit" << endl;
		cin >> select;
		switch (select) {
		case 1:
			// 난수를 생성하여 20개의 요소를 힙에 삽입
			for (int i = 0; i < 20; i++) {
				data = rand() % 100; // 0부터 99까지의 난수 생성
				cout << "Inserting " << data << endl;
				heap.Insert(Element<int>(data));
			}
			heap.display();
			break;
		case 2:
			// 힙의 요소를 레벨 순서로 출력
			heap.display();
			break;
		case 3:
			// 최대값을 삭제하고 출력
			deletedEle = heap.DeleteMax(ele);
			if (deletedEle != nullptr) {
				cout << "Deleted element: " << deletedEle->key << endl;
			}
			cout << "Current max heap: " << endl;
			heap.display();
			break;
		case 4:
			// 힙을 사용하여 정렬
			heapSort(heap);
			break;
		case 5:
			exit(1);
			break;
		}
	} while (select < 5);

	return 0;
}
