#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PhyscData3 {
public:
    string name;  // Name
    int height;   // Height
    double vision; // Vision

    // Constructor
    PhyscData3(string n, int h, double v) : name(n), height(h), vision(v) {}

    // String representation of PhyscData3
    string toString() const {
        return name + " " + to_string(height) + " " + to_string(vision);
    }

    // Compare height first, then vision
    bool operator<(const PhyscData3& d2) const {
        if (height != d2.height) return height < d2.height;
        return vision < d2.vision;
    }
};

// Merge sorted subarrays within array a
void merge(vector<PhyscData3>& a, int lefta, int righta, int leftb, int rightb) {
    vector<PhyscData3> temp(30); // Temporary array
    int ix = 0;
    int p = lefta, q = leftb;

    while (p <= righta && q <= rightb) {
        if (a[p] < a[q]) temp[ix++] = a[p++];
        else if (a[q] < a[p]) temp[ix++] = a[q++];
        else {
            temp[ix++] = a[p++];
            temp[ix++] = a[q++];
        }
    }
    while (p <= righta) temp[ix++] = a[p++];
    while (q <= rightb) temp[ix++] = a[q++];

    for (int j = 0; j < ix; j++) {
        a[lefta + j] = temp[j];
        cout << " " << a[lefta + j].toString();
    }
    cout << endl;
}

// Recursive merge sort
void mergeSort(vector<PhyscData3>& a, int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    merge(a, left, mid, mid + 1, right);
}

int main() {
    vector<PhyscData3> x = {
        PhyscData3("강민하", 162, 0.3),
        PhyscData3("김찬우", 173, 0.7),
        PhyscData3("박준서", 171, 2.0),
        PhyscData3("유서범", 171, 1.5),
        PhyscData3("이수연", 168, 0.4),
        PhyscData3("장경오", 171, 1.2),
        PhyscData3("황지안", 169, 0.8)
    };

    cout << "Original list:" << endl;
    for (const auto& data : x) {
        cout << data.toString() << endl;
    }

    // Sort array x
    mergeSort(x, 0, x.size() - 1);

    cout << "\nSorted in ascending order:" << endl;
    cout << "■ Physical Exam List ■" << endl;
    cout << " Name    Height Vision" << endl;
    cout << "----------------------" << endl;

    for (const auto& data : x) {
        printf("%-8s %3d %5.1f\n", data.name.c_str(), data.height, data.vision);
    }

    return 0;
}
