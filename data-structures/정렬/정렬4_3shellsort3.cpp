#include <iostream>
#include <cstdlib>  // rand() 함수 사용을 위한 헤더
#include <ctime>    // 시간에 따른 시드 설정을 위한 헤더
using namespace std;

//--- 셸 정렬 ---//
void shellSort(int a[], int n) {
    int count = 0;
    int h;

    // h 값을 1, 4, 13, 40,... 등으로 증가시킴
    for (h = 1; h < n; h = h * 3 + 1)
        ;

    // h 값을 1/3씩 감소시킴
    for (; h > 0; h /= 3) {
        for (int i = h; i < n; i++) {
            int j;
            int tmp = a[i];  // h 위치 데이터와 a[0]을 비교

            // h 간격으로 데이터를 비교하며 삽입 정렬 수행
            for (j = i - h; j >= 0 && a[j] > tmp; j -= h) {
                count++;
                a[j + h] = a[j];  // a[0]을 a[h]로 이동
            }
            cout << "\nh = " << h << ", tmp = " << tmp << ", a[j+h] = " << a[j + h] << endl;
            a[j + h] = tmp;

            // 배열 상태 출력
            for (int k = 0; k < n; k++)
                cout << " " << a[k];
            cout << endl;
        }
    }
    cout << "\n비교회수 = " << count << endl;
}

//--- 배열 출력 함수 ---//
void showData(int d[], int n) {
    for (int i = 0; i < n; i++) {
        cout << d[i] << " ";
    }
    cout << endl;
}

int main() {
    srand((unsigned)time(0));  // 랜덤 시드 설정
    int nx;

    cout << "셸 정렬(버전 2)" << endl;
    cout << "요솟수: ";
    cin >> nx;
    int* x = new int[nx];  // 동적 배열 할당

    // 배열에 랜덤 값 할당
    for (int i = 0; i < nx; i++) {
        x[i] = rand() % 100;  // 0에서 99까지의 랜덤 값
    }

    // 정렬 전 배열 출력
    showData(x, nx);

    shellSort(x, nx);  // 배열 x를 셸 정렬

    // 정렬 후 배열 출력
    cout << "오름차순으로 정렬했습니다." << endl;
    showData(x, nx);

    delete[] x;  // 동적 배열 해제
    return 0;
}
