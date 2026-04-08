#include <iostream>
#include <vector>
#include <list>
#include <string>

// 해시 테이블의 크기를 정의합니다.
// 이 값은 해시 테이블이 몇 개의 버킷(bucket)을 가질지를 결정합니다.
// 적절한 크기를 선택하면 충돌을 줄일 수 있습니다.
const int TABLE_SIZE = 10;

// Book 구조체: 도서의 기본 정보를 저장하는 구조체입니다.
struct Book {
    std::string id;      // 도서의 고유 ID (예: "B001")
    std::string title;   // 도서의 제목 (예: "C++ 프로그래밍")
    std::string author;  // 도서의 저자 (예: "홍길동")

    // 생성자: Book 객체를 초기화할 때 사용됩니다.
    Book(std::string _id, std::string _title, std::string _author)
        : id(_id), title(_title), author(_author) {}
};

// HashTable 클래스: 해시 테이블을 구현한 클래스입니다.
// 이 클래스는 체이닝을 사용하여 충돌을 해결합니다.
class HashTable {
private:
    // 해시 테이블을 벡터로 구현합니다. 각 인덱스는 리스트(체인)를 가집니다.
    std::vector<std::list<Book>> table;

    // 해시 함수: 주어진 키(도서 ID)를 해시 테이블의 인덱스로 변환합니다.
    // 여기서는 간단하게 문자열의 각 문자 ASCII 값을 합산하고 테이블 크기로 나눈 나머지를 사용합니다.
    int hashFunction(const std::string& key) {
        int sum = 0;
        for(char ch : key) {
            sum += ch; // 각 문자의 ASCII 값을 합산
        }
        return sum % TABLE_SIZE; // 합산된 값을 테이블 크기로 나눈 나머지를 인덱스로 사용
    }

public:
    // 생성자: 해시 테이블을 초기화합니다.
    HashTable() {
        // 테이블의 각 인덱스에 빈 리스트를 할당합니다.
        table.resize(TABLE_SIZE);
    }

    // 1. 새로운 책 정보를 해시 테이블에 추가하는 함수
    void addBook(const std::string& id, const std::string& title, const std::string& author) {
        int index = hashFunction(id); // 도서 ID를 해시 함수에 넣어 인덱스를 계산
        // 동일한 ID의 책이 이미 존재하는지 확인
        for(auto &book : table[index]) {
            if(book.id == id) {
                std::cout << "이미 존재하는 ID입니다.\n";
                return; // 중복 ID가 있으면 추가하지 않고 함수 종료
            }
        }
        // 중복이 없으면 새로운 책을 리스트에 추가
        table[index].emplace_back(id, title, author);
        std::cout << "책이 성공적으로 추가되었습니다.\n";
    }

    // 2. 특정 책 ID로 책을 검색하는 함수
    void searchBook(const std::string& id) {
        int index = hashFunction(id); // 검색할 도서 ID의 해시 인덱스를 계산
        // 해당 인덱스의 리스트를 순회하며 일치하는 ID를 찾음
        for(auto &book : table[index]) {
            if(book.id == id) {
                std::cout << "책을 찾았습니다:\n";
                std::cout << "ID: " << book.id << ", 제목: " << book.title << ", 저자: " << book.author << "\n";
                return; // 책을 찾으면 함수 종료
            }
        }
        std::cout << "해당 ID의 책을 찾을 수 없습니다.\n";
    }

    // 3. 특정 책 ID로 책을 삭제하는 함수
    void deleteBook(const std::string& id) {
        int index = hashFunction(id); // 삭제할 도서 ID의 해시 인덱스를 계산
        // 해당 인덱스의 리스트를 순회하며 일치하는 ID를 찾음
        for(auto it = table[index].begin(); it != table[index].end(); ++it) {
            if(it->id == id) {
                table[index].erase(it); // 책을 리스트에서 삭제
                std::cout << "책이 성공적으로 삭제되었습니다.\n";
                return; // 삭제 후 함수 종료
            }
        }
        std::cout << "해당 ID의 책을 찾을 수 없습니다.\n";
    }

    // 4. 해시 테이블 전체를 출력하는 함수
    void displayTable() {
        std::cout << "\n해시 테이블 전체 내용:\n";
        for(int i = 0; i < TABLE_SIZE; ++i) {
            std::cout << "인덱스 " << i << ": ";
            // 각 인덱스의 리스트를 순회하며 저장된 책들을 출력
            for(auto &book : table[i]) {
                std::cout << "[" << book.id << ", " << book.title << ", " << book.author << "] -> ";
            }
            std::cout << "nullptr\n"; // 체인의 끝을 표시
        }
    }
};

// 메뉴를 표시하고 사용자 입력을 처리하는 함수
void menu() {
    HashTable ht; // 해시 테이블 객체 생성
    int choice; // 사용자의 메뉴 선택을 저장할 변수
    std::string id, title, author; // 도서 정보를 저장할 변수

    while(true) { // 무한 루프를 사용하여 메뉴를 반복 표시
        // 메뉴 옵션을 출력
        std::cout << "\n===== 도서 관리 시스템 메뉴 =====\n";
        std::cout << "1. 새로운 책 정보 추가\n";
        std::cout << "2. 특정 책 ID로 검색\n";
        std::cout << "3. 특정 책 ID로 삭제\n";
        std::cout << "4. 해시 테이블 전체 출력\n";
        std::cout << "5. 종료\n";
        std::cout << "================================\n";
        std::cout << "선택하세요: ";
        std::cin >> choice; // 사용자로부터 선택을 입력받음

        switch(choice) {
            case 1:
                // 새로운 책 정보를 추가하는 과정
                std::cout << "책 ID 입력: ";
                std::cin >> id; // 책 ID 입력
                std::cin.ignore(); // 입력 버퍼 정리 (개행 문자 제거)
                std::cout << "책 제목 입력: ";
                std::getline(std::cin, title); // 책 제목 입력
                std::cout << "저자 입력: ";
                std::getline(std::cin, author); // 저자 입력
                ht.addBook(id, title, author); // 해시 테이블에 책 추가
                break;
            case 2:
                // 특정 책 ID로 책을 검색하는 과정
                std::cout << "검색할 책 ID 입력: ";
                std::cin >> id; // 검색할 책 ID 입력
                ht.searchBook(id); // 해시 테이블에서 책 검색
                break;
            case 3:
                // 특정 책 ID로 책을 삭제하는 과정
                std::cout << "삭제할 책 ID 입력: ";
                std::cin >> id; // 삭제할 책 ID 입력
                ht.deleteBook(id); // 해시 테이블에서 책 삭제
                break;
            case 4:
                // 해시 테이블 전체를 출력하는 과정
                ht.displayTable(); // 해시 테이블 내용 출력
                break;
            case 5:
                // 프로그램을 종료하는 과정
                std::cout << "프로그램을 종료합니다.\n";
                return; // 함수 종료 (프로그램 종료)
            default:
                // 잘못된 선택을 처리하는 과정
                std::cout << "잘못된 선택입니다. 다시 시도하세요.\n";
        }
    }
}

int main() {
    menu(); // 메뉴 함수를 호출하여 프로그램 실행
    return 0; // 프로그램 종료
}
