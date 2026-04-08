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

//--- 단순 선택 정렬 ---//
void selectionSort(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        int min = i;  // 아직 정렬되지 않은 부분에서 가장 작은 요소의 인덱스 저장
        for (int j = i + 1; j < n; j++) {
            count++;
            if (a[j] < a[min])  // 가장 작은 것을 선택
                min = j;  // min이 가장 작은 요소의 인덱스를 가짐
        }
        swap(a, i, min);  // 아직 정렬되지 않은 부분의 첫 요소와 가장 작은 요소를 교환
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

    cout << "단순 선택 정렬" << endl;
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

    selectionSort(x, nx);  // 배열 x를 단순선택정렬

    cout << "정렬후:" << endl;
    showData(x, nx);

    delete[] x;  // 동적 배열 해제
    return 0;
}
