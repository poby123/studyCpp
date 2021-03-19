#include "Point.h"

// Constructor
Point::Point()
{
	// 초기화가 아닌 할당. const나 reference 타입에서 이 방식은 불가능하다.
	x = 0;
	y = 0;
	name = new char[strlen("Point") + 1];
	strcpy(name, "Point");

	std::cout << "[생성자] 기본생성자가 호출되었습니다.\n";
}

Point::Point(int x, int y) :x(x), y(y) // 멤버 초기화 리스트를 이용한 초기화
{
	name = new char[strlen("Point") + 1];
	strcpy(name, "Point");
	std::cout << "[생성자] Point(int x, int y) 생성자가 호출되었습니다.\n";
}

Point::Point(int x, int y, const char* s) : x(x), y(y) // 멤버 초기화 리스트를 이용한 초기화
{
	name = new char[strlen(s) + 1];
	strcpy(name, s);

	std::cout << "[생성자] Point(int x, int y, string name) 생성자가 호출되었습니다.\n";
}

Point::Point(const Point& p)
{
	this->x = p.x;
	this->y = p.y;
	this->name = new char[strlen(p.name) + 1];
	strcpy(this->name, p.name);

	std::cout << "[생성자] 복사 생성자가 호출되었습니다 >> \n";
}


// Destructor
Point::~Point()
{
	std::cout << "[소멸자] " << name << " Point 기본 소멸자가 호출되었습니다\n";

	delete[] name;
	name = nullptr;
}

// Setter
void Point::setX(int x) {
	this->x = x;
}

void Point::setY(int y) {
	this->y = y;
}

void Point::setName(const char* s) {
	delete[] name;
	this->name = new char[strlen(s) + 1];
	strcpy(this->name, s);
}

// Operator overloading
Point Point::operator+(Point& p)
{
	char temp[30] = { 0 };
	strcat(temp, this->name);
	strcat(temp, "+");
	strcat(temp, p.name);

	Point ret(this->x + p.x, this->y + p.y, temp);

	return ret; // 객체를 return 시 임시 객체를 만들기 위해 복사 생성자가 호출된다.
}

Point Point::operator-(Point& p)
{
	char temp[30] = { 0 };
	strcat(temp, this->name);
	strcat(temp, "-");
	strcat(temp, p.name);

	Point ret(this->x - p.x, this->y - p.y, temp);

	return ret; // 객체를 return 시 임시 객체를 만들기 위해 복사 생성자가 호출된다.
}

Point& Point::operator=(const Point& p) {
	std::cout << "[연산자] 대입 연산자가 호출되었습니다\n";

	if (this != &p) {
		delete[] this->name; // 복사 대입 연산자에서는 delete 를 해줘야한다.

		this->name = new char[strlen(p.name) + 1];
		strcpy(this->name, p.name);

		this->x = p.x;
		this->y = p.y;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Point& p)
{
	os << "Point[" << p.name << "] : (" << p.x << ", " << p.y << ")" << std::endl;
	return os;
}
