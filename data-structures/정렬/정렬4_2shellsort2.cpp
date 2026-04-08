#include <iostream>
using namespace std;

//--- 셸 정렬 ---//
void shellSort(int a[], int n) {
    int h;
    for (h = 1; h < n; h = h * 3 + 1)
        ;  // h 값을 1, 4, 13, 40,... 등으로 증가시킴
    cout << "h = " << h << endl;

    for (; h > 0; h /= 3) {  // h 값을 1/3씩 감소시킴
        for (int i = h; i < n; i++) {
            cout << "h = " << h << endl;
            int j;
            int tmp = a[i];  // 현재 요소 저장

            // 간격 h를 기준으로 비교하고 정렬
            for (j = i - h; j >= 0 && a[j] > tmp; j -= h) {
                a[j + h] = a[j];
            }
            cout << "h = " << h << ", tmp = " << tmp << ", a[j+h] = " << a[j + h] << endl;
            a[j + h] = tmp;  // tmp를 제자리에 삽입

            // 배열의 현재 상태 출력
            for (int k = 0; k < n; k++)
                cout << " " << a[k];
            cout << endl;
        }
    }
}

//--- 배열 출력 함수 ---//
void showData(int d[], int n) {
    for (int i = 0; i < n; i++) {
        cout << d[i] << " ";
    }
    cout << endl;
}

int main() {
    int nx = 8;
    int x[] = { 8, 1, 4, 2, 7, 6, 3, 5 };  // 정렬할 배열

    // 정렬 전 배열 출력
    for (int i = 0; i < nx; i++) {
        cout << " " << x[i];
    }
    cout << endl;

    shellSort(x, nx);  // 배열 x를 셸 정렬

    // 정렬 후 배열 출력
    cout << "오름차순으로 정렬했습니다." << endl;
    for (int i = 0; i < nx; i++) {
        cout << " " << x[i];
    }
    cout << endl;

    return 0;
}
