#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//Callable
struct S {
	void operator()(int a, int b) { std::cout << "a + b = " << a + b << std::endl; }
};
int some_func1(const std::string& a) {
	std::cout << "Func1 호출! " << a << std::endl;
	return 0;
}

struct S2 {
	void operator()(char c) { std::cout << "Func2 호출! " << c << std::endl; }
};
int main() {
	int n;
	S s_add;//객체, 그러나 함수처럼 호출 가능 

	s_add(3, 5);

	auto f = [](int a, int b) { std::cout << "a + b = " << a + b << std::endl; };
	f(3, 5);

	/*******
	람다식 구문:
	[capture](parameters) -> return_type {
	// 함수 본문
	}
		capture: 람다 함수 내부에서 외부 변수에 접근할 때 사용.
			캡처 방식
			[ ]: 외부 변수 캡처 안 함.
			[=]: 외부 변수를 값으로 캡처.
			[&]: 외부 변수를 참조로 캡처.
			[x, &y]: 특정 변수만 캡처, x는 값으로, y는 참조로 캡처.
		parameters: 람다 함수의 매개변수. (생략 가능)
		return_type: 반환 타입. 생략 가능하며, 자동 추론됨.
		본문: 람다식이 실행할 코드 블록.
	*/

	vector<int> v = { 5, 2, 9, 1, 5, 6 };
	// 내림차순 정렬
	sort(v.begin(), v.end(), [](int a, int b) {
		return a > b;
		});


	int x = 10;

	// []는 외부 변수 x를 캡처(복사)하여 람다식 내부에서 사용한다
	auto g = [x](int a) {
		std::cout << "a + x = " << a + x << std::endl;
	};

	g(5); // 출력: a + x = 15

	// x 값을 변경해도, f의 내부에서는 기존의 복사된 x 값(10)을 사용
	x = 20;
	g(5); // 여전히 출력: a + x = 15
	/******************
	C++ 에서는 이러한 Callable 들을 객체의 형태로 보관할 수 있는 std::function 이라는 
	클래스를 제공. 
	C 에서의 함수 포인터는 진짜 함수들만 보관할 수 있는 객체
	std::function 의 경우 함수 뿐만이 아니라 모든 Callable 들을 보관할 수 있는 객체
	std::function<int(const std::string&)>

	std::function은 호출 가능한 객체를 캡슐화합니다.
	int(const std::string&)은 함수 서명을 지정합니다.
		반환 타입: int
		매개변수: const std::string& (문자열을 상수 참조로 받음)
	f1에는 리턴 타입이 int이고, 하나의 const std::string& 매개변수를 받는 모든 호출 가능한 객체를 저장
	*/
	std::function<int(const std::string&)> f1 = some_func1;
	std::function<void(char)> f2 = S2();
	std::function<void()> f3 = []() { std::cout << "Func3 호출! " << std::endl; };

	f1("hello");
	f2('c');
	f3();
	/************** Lambda  식
	[capture list](parameter list) -> return type { function body };
		capture list: 외부 변수를 람다 내부로 가져올 방법을 지정 ([], [&], [=], 등).
		parameter list: 함수처럼 매개변수 정의.
		return type: 반환 타입(생략 가능, 컴파일러가 추론).
		function body: 함수의 동작을 정의.
	*/
	auto divide = [](int a, int b) -> double {
		return static_cast<double>(a) / b;
	};

	std::cout << "10 / 4 = " << divide(10, 4) << std::endl; // 출력: 10 / 4 = 2.5

	/*****************  정렬 기준으로 람다식 사용 **/

	std::vector<int> numbers = { 5, 2, 8, 1, 4 };

	// 내림차순 정렬
	std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
		return a > b;
		});

	for (int n : numbers) {
		std::cout << n << " ";
	}
	// 출력: 8 5 4 2 1
	cin >> n;
}