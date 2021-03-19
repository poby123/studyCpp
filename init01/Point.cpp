#include "Point.h"

// Constructor
Point::Point()
{
	// �ʱ�ȭ�� �ƴ� �Ҵ�. const�� reference Ÿ�Կ��� �� ����� �Ұ����ϴ�.
	x = 0;
	y = 0;
	name = new char[strlen("Point") + 1];
	strcpy(name, "Point");

	std::cout << "[������] �⺻�����ڰ� ȣ��Ǿ����ϴ�.\n";
}

Point::Point(int x, int y) :x(x), y(y) // ��� �ʱ�ȭ ����Ʈ�� �̿��� �ʱ�ȭ
{
	name = new char[strlen("Point") + 1];
	strcpy(name, "Point");
	std::cout << "[������] Point(int x, int y) �����ڰ� ȣ��Ǿ����ϴ�.\n";
}

Point::Point(int x, int y, const char* s) : x(x), y(y) // ��� �ʱ�ȭ ����Ʈ�� �̿��� �ʱ�ȭ
{
	name = new char[strlen(s) + 1];
	strcpy(name, s);

	std::cout << "[������] Point(int x, int y, string name) �����ڰ� ȣ��Ǿ����ϴ�.\n";
}

Point::Point(const Point& p)
{
	this->x = p.x;
	this->y = p.y;
	this->name = new char[strlen(p.name) + 1];
	strcpy(this->name, p.name);

	std::cout << "[������] ���� �����ڰ� ȣ��Ǿ����ϴ� >> \n";
}


// Destructor
Point::~Point()
{
	std::cout << "[�Ҹ���] " << name << " Point �⺻ �Ҹ��ڰ� ȣ��Ǿ����ϴ�\n";

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

	return ret; // ��ü�� return �� �ӽ� ��ü�� ����� ���� ���� �����ڰ� ȣ��ȴ�.
}

Point Point::operator-(Point& p)
{
	char temp[30] = { 0 };
	strcat(temp, this->name);
	strcat(temp, "-");
	strcat(temp, p.name);

	Point ret(this->x - p.x, this->y - p.y, temp);

	return ret; // ��ü�� return �� �ӽ� ��ü�� ����� ���� ���� �����ڰ� ȣ��ȴ�.
}

Point& Point::operator=(const Point& p) {
	std::cout << "[������] ���� �����ڰ� ȣ��Ǿ����ϴ�\n";

	if (this != &p) {
		delete[] this->name; // ���� ���� �����ڿ����� delete �� ������Ѵ�.

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
