#include <iostream>
#include <vector>

using namespace std;

//--- Merges sorted arrays a and b into array c ---//
void merge(const vector<int>& a, const vector<int>& b, vector<int>& c) {
    int pa = 0;
    int pb = 0;
    int pc = 0;
    int na = a.size();
    int nb = b.size();

    while (pa < na && pb < nb)         // Add the smaller element to c
        c[pc++] = (a[pa] <= b[pb]) ? a[pa++] : b[pb++];

    while (pa < na)                    // Copy remaining elements from a
        c[pc++] = a[pa++];

    while (pb < nb)                    // Copy remaining elements from b
        c[pc++] = b[pb++];
}

void showData(const vector<int>& d) {
    for (int num : d)
        cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> a = { 2, 4, 6, 8, 11, 13 };
    vector<int> b = { 1, 2, 3, 4, 9, 16, 21 };
    vector<int> c(a.size() + b.size());

    cout << "Merging two arrays..." << endl;

    merge(a, b, c);   // Merge arrays a and b into c

    cout << "Array a: ";
    showData(a);
    cout << "Array b: ";
    showData(b);
    cout << "Merged array c: ";
    showData(c);

    return 0;
}
