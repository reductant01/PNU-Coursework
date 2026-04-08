#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class QuickSort {
public:
    static int count;

    //--- Swap values of array elements a[idx1] and a[idx2] ---//
    static void swap(vector<int>& a, int idx1, int idx2) {
        int t = a[idx1];
        a[idx1] = a[idx2];
        a[idx2] = t;
    }

    //--- Quick Sort ---//
    static void quickSort(vector<int>& a, int left, int right) {
        int pl = left;                   // Left cursor
        int pr = right;                  // Right cursor
        int x = a[(pl + pr) / 2];        // Pivot (middle element)

        cout << "a[" << left << "] ~ a[" << right << "]: {";
        for (int i = left; i < right; i++)
            cout << a[i] << ", ";
        cout << a[right] << "}" << endl;

        do {
            while (a[pl] < x) { pl++; count++; }
            while (a[pr] > x) { pr--; count++; }
            if (pl <= pr) {
                swap(a, pl++, pr--);
                count++;
            }
        } while (pl <= pr);

        if (left < pr) quickSort(a, left, pr);
        if (pl < right) quickSort(a, pl, right);
    }

    //--- Display array data ---//
    static void showData(const vector<int>& d) {
        for (int num : d)
            cout << num << " ";
        cout << endl;
    }
};

int QuickSort::count = 0;

int main() {
    int nx = 100;
    vector<int> x(nx);

    for (int ix = 0; ix < nx; ix++) {
        x[ix] = rand() % 100; // Random values between 0 and 99
    }

    cout << "Before quick sort:" << endl;
    QuickSort::showData(x);

    QuickSort::quickSort(x, 0, nx - 1);  // Quick sort on array x
    cout << "Number of comparisons = " << QuickSort::count << endl;

    cout << "After quick sort:" << endl;
    QuickSort::showData(x);
}
