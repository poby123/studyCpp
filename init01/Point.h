#pragma once
//#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

class Point
{
private:
	int x;
	int y;
	char* name = nullptr;

public:
	// Constructor
	Point();
	Point(int x, int y);
	Point(int x, int y, const char* s);

	// Copy Constructor
	Point(const Point& p);

	// Move Constructor
	Point(Point&& p) noexcept;

	// Destructor
	~Point();

	// Setter
	void setX(int x);
	void setY(int y);
	void setName(const char* s);

	// Operator overloading
	Point operator+(Point& p);
	Point operator-(Point& p);
	Point& operator=(const Point& p);
	Point& operator=(Point&& p) noexcept;

	friend std::ostream& operator<<(std::ostream& os, const Point& p);
};

