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

//--- 버블 정렬 ---//
void bubbleSort(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n - 1; i++) {  // 패스
        for (int j = n - 1; j > i; j--) {  // 끝에서 앞쪽으로 이동하면서 버블 처리
            count++;
            if (a[j - 1] > a[j]) {  // 버블
                swap(a, j - 1, j);
            }
        }
    }
    cout << "\n비교 횟수 = " << count << endl;
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

    cout << "버블 정렬(버전 1)" << endl;
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
