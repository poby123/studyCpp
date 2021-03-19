#include<iostream>
#include"Point.h"

using namespace std;

int main() {

	cout << "========== 생성자 =========\n";
	// 기본 생성자 호출
	Point p1;
	cout << p1 << "\n";

	// Point(int x, int y) 생성자 호출
	Point p2(3, 4);
	cout << p2 << "\n";

	// Point(int x, int y, string name) 생성자 호출
	Point p3(5, 7, "A");
	cout << p3 << "\n";

	// Point(int x, int y, string name) 생성자 호출. 유니폼 초기화 방식(Uniform Initialization)
	Point p4 = { 10,9, "B" };
	cout << p4 << "\n";


	cout << "\n\n========== 복사생성자 =========\n";
	// 선언과 동시에 대입하는 경우, 복사 생성자가 호출된다.
	Point temp1 = p3;
	temp1.setName("temp1");
	cout << "원본 : " << p3 << "\n";
	cout << "복사본 : " << temp1 << "\n";

	// 선언과 대입을 따로하면, 복사 생성자가 호출되지 않는다.
	Point temp2; // 기본 생성자 호출
	temp2 = p4; // 대입 연산자 호출
	temp2.setName("temp2");
	cout << "원본 : " << p4 << "\n";
	cout << "복사본 : " << temp2 << "\n";


	cout << "\n\n========== 오버로딩 함수 예시 =========\n";
	// + 오버로딩
	Point result1 = p3 + p4;
	cout << result1 << "\n";

	// - 오버로딩
	Point result2;
	result2 = p3 - p4; // 대입연산자 호출
	cout << result2 << "\n";

	cout << "\n\n========== 소멸자 호출 =========\n";

	return 0;
}

/*
< 실행결과 >
========== 생성자 =========
[생성자] 기본생성자가 호출되었습니다.
Point[Point] : (0, 0)

[생성자] Point(int x, int y) 생성자가 호출되었습니다.
Point[Point] : (3, 4)

[생성자] Point(int x, int y, string name) 생성자가 호출되었습니다.
Point[A] : (5, 7)

[생성자] Point(int x, int y, string name) 생성자가 호출되었습니다.
Point[B] : (10, 9)



========== 복사생성자 =========
[생성자] 복사 생성자가 호출되었습니다 >>
원본 : Point[A] : (5, 7)

복사본 : Point[temp1] : (5, 7)

[생성자] 기본생성자가 호출되었습니다.
[연산자] 대입 연산자가 호출되었습니다
원본 : Point[B] : (10, 9)

복사본 : Point[temp2] : (10, 9)



========== 오버로딩 함수 예시 =========
[생성자] Point(int x, int y, string name) 생성자가 호출되었습니다.
[생성자] 복사 생성자가 호출되었습니다 >>
[소멸자] A+BPoint 기본 소멸자가 호출되었습니다
Point[A+B] : (15, 16)

[생성자] 기본생성자가 호출되었습니다.
[생성자] Point(int x, int y, string name) 생성자가 호출되었습니다.
[생성자] 복사 생성자가 호출되었습니다 >>
[소멸자] APoint 기본 소멸자가 호출되었습니다
[연산자] 대입 연산자가 호출되었습니다
[소멸자] APoint 기본 소멸자가 호출되었습니다
Point[A] : (-5, -2)



========== 소멸자 호출 =========
[소멸자] APoint 기본 소멸자가 호출되었습니다
[소멸자] A+BPoint 기본 소멸자가 호출되었습니다
[소멸자] temp2Point 기본 소멸자가 호출되었습니다
[소멸자] temp1Point 기본 소멸자가 호출되었습니다
[소멸자] BPoint 기본 소멸자가 호출되었습니다
[소멸자] APoint 기본 소멸자가 호출되었습니다
[소멸자] PointPoint 기본 소멸자가 호출되었습니다
[소멸자] PointPoint 기본 소멸자가 호출되었습니다
*/