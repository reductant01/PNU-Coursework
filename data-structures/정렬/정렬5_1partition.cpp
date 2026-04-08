#include <iostream>
#include <vector>

using namespace std;

//--- Swap values of array elements a[idx1] and a[idx2] ---//
void swap(vector<int>& a, int idx1, int idx2) {
    int t = a[idx1];
    a[idx1] = a[idx2];
    a[idx2] = t;
}

//--- Partition the array ---//
void partition(vector<int>& a, int n) {
    int pl = 0;         // Left cursor
    int pr = n - 1;     // Right cursor
    int x = a[n / 2];   // Pivot (middle element)

    do {
        while (a[pl] < x) pl++;
        while (a[pr] > x) pr--;
        cout << "pivot = " << x << ", pl = " << pl << ", pr = " << pr << endl;
        if (pl <= pr)
            swap(a, pl++, pr--);
        cout << "\t>> pl = " << pl << ", pr = " << pr << endl;

        for (int num : a)
            cout << " " << num;
        cout << endl;
    } while (pl <= pr);

    cout << "The value of the pivot is " << x << "." << endl;

    cout << "Group less than or equal to pivot: ";
    for (int i = 0; i < pl; i++)            // a[0] to a[pl - 1]
        cout << a[i] << " ";
    cout << endl;

    if (pl > pr + 1) {
        cout << "Group matching the pivot: ";
        for (int i = pr + 1; i < pl; i++)   // a[pr + 1] to a[pl - 1]
            cout << a[i] << " ";
        cout << endl;
    }

    cout << "Group greater than or equal to pivot: ";
    for (int i = pr + 1; i < n; i++)        // a[pr + 1] to a[n - 1]
        cout << a[i] << " ";
    cout << endl;
}

void showData(const vector<int>& d) {
    for (int num : d)
        cout << num << " ";
    cout << endl;
}

int main() {
    // Initialize array data
    int nx = 9;
    vector<int> x = { 1, 8, 7, 4, 5, 2, 6, 3, 9 };

    for (int n : x)
        cout << " " << n;
    cout << endl;

    partition(x, nx);  // Partition the array
}
