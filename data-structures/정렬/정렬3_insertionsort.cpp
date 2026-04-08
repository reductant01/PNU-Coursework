#include <iostream>
#include <cstdlib>  // rand() 함수를 위한 헤더
#include <ctime>    // 난수 생성을 위한 헤더

using namespace std;

//--- 단순 삽입 정렬 ---//
void insertionSort(int a[], int n) {
    int count = 0;
    for (int i = 1; i < n; i++) {
        int tmp = a[i];  // 두번째 값부터 삽입할 위치를 찾는다
        int j = i;

        // 선택한 카드의 좌측에 넣을 곳을 찾는다
        while (j > 0 && a[j - 1] > tmp) {  // a[j-1]을 기준으로 이동
            count++;
            a[j] = a[j - 1];  // 한 칸씩 이동
            j--;
        }
        count++;
        a[j] = tmp;  // tmp를 삽입한다.
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

    cout << "단순 삽입 정렬" << endl;
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

    insertionSort(x, nx);  // 배열 x를 단순 삽입 정렬

    cout << "정렬 후:" << endl;
    showData(x, nx);

    delete[] x;  // 동적 배열 해제
    return 0;
}
