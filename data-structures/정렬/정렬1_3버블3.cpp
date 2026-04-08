#include <iostream>
#include <cstdlib>  // rand() 함수를 위한 헤더
#include <ctime>    // 난수 생성을 위한 헤더

using namespace std;

//--- 배열 요소 a[idx1]와 a[idx2]의 값을 교환 ---//
void swap(int a[], int idx1, int idx2) {
    int t = a[idx1];
    a[idx1] = a[idx2];
    a[idx2] = t;
}

//--- 버블 정렬(버전 3: 스캔 범위를 한정) ---//
void bubbleSort(int a[], int n) {
    int count = 0;
    int k = 0;  // a[k]보다 앞쪽은 정렬을 마침
    while (k < n - 1) {  // for문 대신 while문 사용
        int last = n - 1;  // 마지막으로 교환한 위치
        for (int j = n - 1; j > k; j--) {  // j > k로 변경
            count++;
            if (a[j - 1] > a[j]) {
                swap(a, j - 1, j);
                last = j;  // last를 사용한 성능 개선
            }
        }
        k = last;
    }
    cout << "\n비교횟수 = " << count << endl;
}

//--- 배열 요소 출력 ---//
void showData(int d[], int n) {
    for (int i = 0; i < n; i++) {
        cout << d[i] << " ";
    }
    cout << endl;
}

int main() {
    int nx;

    cout << "단순교환정렬(버블정렬)" << endl;
    cout << "요솟수: ";
    cin >> nx;

    int* x = new int[nx];

    srand((unsigned)time(0));  // 난수 시드 설정

    // 배열에 난수 채우기
    for (int i = 0; i < nx; i++) {
        x[i] = rand() % 999;  // 0부터 998 사이의 난수
    }

    cout << "정렬전:" << endl;
    showData(x, nx);

    bubbleSort(x, nx);  // 배열 x를 단순교환정렬

    cout << "정렬후:" << endl;
    showData(x, nx);

    delete[] x;  // 동적 배열 해제
    return 0;
}
