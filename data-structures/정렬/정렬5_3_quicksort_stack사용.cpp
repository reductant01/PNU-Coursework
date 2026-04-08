#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>

using namespace std;

class Point {
private:
    int ix;
    int iy;

public:
    Point(int x, int y) : ix(x), iy(y) {}

    int getX() const { return ix; }
    int getY() const { return iy; }
    void setX(int x) { ix = x; }
    void setY(int y) { iy = y; }
};

// --- Swap values of array elements a[idx1] and a[idx2] ---//
void swap(vector<int>& a, int idx1, int idx2) {
    int t = a[idx1];
    a[idx1] = a[idx2];
    a[idx2] = t;
}

// --- Non-recursive version of Quick Sort ---//
void quickSort(vector<int>& a, int left, int right) {
    stack<Point> st;
    st.push(Point(left, right));

    while (!st.empty()) {
        Point rt = st.top();
        st.pop();

        int pl = left = rt.getX();
        int pr = right = rt.getY();
        int mp = a[(pl + pr) / 2];

        do {
            while (a[pl] < mp) pl++;
            while (a[pr] > mp) pr--;
            if (pl <= pr) swap(a, pl++, pr--);
        } while (pl <= pr);

        cout << "left = " << left << ", right = " << right << endl;
        for (int i = left; i <= right; i++)
            cout << " " << a[i];
        cout << endl;

        if (left < pr) st.push(Point(left, pr));
        if (pl < right) st.push(Point(pl, right));
    }
}

void showData(const vector<int>& d) {
    for (int num : d)
        cout << num << " ";
    cout << endl;
}

int main() {
    int nx = 10;
    vector<int> x(nx);

    for (int ix = 0; ix < nx; ix++) {
        x[ix] = rand() % 20;
    }

    cout << "Original array: ";
    showData(x);

    quickSort(x, 0, nx - 1);

    cout << "Sorted in ascending order: ";
    showData(x);

    return 0;
}
