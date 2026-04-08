#include <iostream>
#include <cstdlib>  // rand() 함수를 위한 헤더
#include <ctime>    // 난수 생성을 위한 헤더

using namespace std;

//--- 셸 정렬 ---//
void shellSort(int a[], int n) {
    int count = 0;
    for (int h = n / 2; h > 0; h /= 2) {  // 간격 h로 삽입 정렬
        for (int i = h; i < n; i++) {
            int tmp = a[i];
            int j;
            for (j = i - h; j >= 0 && a[j] > tmp; j -= h) {  // h 간격으로 건너뛰며 삽입
                count++;
                a[j + h] = a[j];
            }
            a[j + h] = tmp;
        }
    }
    cout << "\n비교 횟수 = " << count << endl;
}

//--- 배열 출력 함수 ---//
void showData(int d[], int n) {
    for (int i = 0; i < n; i++) {
        cout << d[i] << " ";
    }
    cout << endl;
}

int main() {
    int nx;

    cout << "셸 정렬(버전 1)" << endl;
    cout << "요솟수: ";
    cin >> nx;

    int* x = new int[nx];  // 동적 배열 생성

    srand((unsigned)time(0));  // 난수 시드 설정

    // 배열에 난수 채우기
    for (int i = 0; i < nx; i++) {
        x[i] = rand() % 999;  // 0부터 998까지의 난수를 생성
    }

    cout << "정렬 전:" << endl;
    showData(x, nx);

    shellSort(x, nx);  // 배열 x를 셸 정렬

    cout << "정렬 후:" << endl;
    showData(x, nx);

    delete[] x;  // 동적 배열 해제
    return 0;
}
