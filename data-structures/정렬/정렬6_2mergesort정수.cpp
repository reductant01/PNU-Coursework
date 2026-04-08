#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

// --- Merges sorted subarrays within array a --- //
void merge(vector<int>& a, int lefta, int righta, int leftb, int rightb) {
    vector<int> temp(30);
    int ix = 0;
    int p = lefta, q = leftb;

    while (p <= righta && q <= rightb) {
        if (a[p] < a[q]) temp[ix++] = a[p++];
        else if (a[p] > a[q]) temp[ix++] = a[q++];
        else {
            temp[ix++] = a[p++];
            temp[ix++] = a[q++];
        }
    }
    while (p <= righta) temp[ix++] = a[p++];
    while (q <= rightb) temp[ix++] = a[q++];

    for (int j = 0; j < ix; j++) {
        a[lefta + j] = temp[j];
        cout << " " << a[lefta + j];
    }
    cout << endl;
}

// --- Merge Sort (recursive) --- //
void mergeSort(vector<int>& a, int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    merge(a, left, mid, mid + 1, right);
}

int main() {
    int nx = 20;
    vector<int> x(nx);

    for (int ix = 0; ix < nx; ix++) {
        x[ix] = rand() % 50;  // Random numbers between 0 and 49
    }

    cout << "Original array:" << endl;
    for (int i = 0; i < nx; i++) {
        cout << " " << x[i];
    }
    cout << endl;

    mergeSort(x, 0, nx - 1); // Sort array x

    cout << "Sorted in ascending order:" << endl;
    for (int i = 0; i < nx; i++) {
        cout << " " << x[i];
    }
    cout << endl;

    return 0;
}
