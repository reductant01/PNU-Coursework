#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

class MaxHeap2 {
public:
    virtual void Insert(int x) = 0;
    virtual int DeleteMax() = 0;
};

class Heap2 : public MaxHeap2 {
private:
    const int heapSize = 100;
    vector<int> heap;
    int n; // Current number of elements in the MaxHeap
    int MaxSize; // Maximum allowable size of MaxHeap

public:
    Heap2(int sz) : MaxSize(sz), n(0) {
        heap.resize(MaxSize + 1); // heap[0] is unused
    }

    void display() const { // Displays the heap as index-value pairs
        for (int i = 1; i <= n; i++)
            cout << "  (" << i << ", " << heap[i] << ") ";
        cout << endl;
    }

    void Insert(int x) override { // Inserts x into the heap while maintaining max-heap properties
        if (n == MaxSize) {
            HeapFull();
            return;
        }
        n++;
        int i;
        for (i = n; i > 1 && x > heap[i / 2]; i /= 2)
            heap[i] = heap[i / 2];
        heap[i] = x;
    }

    int DeleteMax() override { // Deletes the max element and returns it
        if (n == 0) {
            HeapEmpty();
            return 0;
        }
        int x = heap[1];
        int k = heap[n--];
        int i, j;
        for (i = 1, j = 2; j <= n;) {
            if (j < n && heap[j] < heap[j + 1])
                j++;
            if (k >= heap[j]) break;
            heap[i] = heap[j];
            i = j;
            j *= 2;
        }
        heap[i] = k;
        return x;
    }

private:
    void HeapEmpty() const {
        cout << "Heap Empty" << endl;
    }

    void HeapFull() const {
        cout << "Heap Full" << endl;
    }
};

void showData(const vector<int>& d) { // Display elements of an integer array
    for (int num : d)
        cout << num << " ";
    cout << endl;
}

int main() {
    srand(static_cast<unsigned>(time(0)));
    int select = 0;
    Heap2 heap(20);
    const int count = 10; // Number of random numbers to generate
    vector<int> x(count); // Array to store generated random numbers
    vector<int> sorted(count); // Array to store sorted values after deletion from the heap

    do {
        cout << "Max Tree. Select: 1 insert, 2 display, 3 sort, 4 exit => ";
        cin >> select;
        switch (select) {
        case 1: // Generate random numbers, insert into heap
            for (int i = 0; i < count; i++) {
                x[i] = rand() % 100;
                heap.Insert(x[i]);
            }
            showData(x);
            break;
        case 2: // Display the heap
            heap.display();
            break;
        case 3: // Delete elements to get sorted values
            for (int i = 0; i < count; i++)
                sorted[i] = heap.DeleteMax();
            showData(sorted);
            break;
        case 4:
            return 0;
        }
    } while (select < 5);

    return 0;
}
