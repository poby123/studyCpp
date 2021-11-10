/*
	About Inherit
	point : 
		- virtual function. 
		- initialization in child class. 
*/

#include<iostream>
using namespace std;

/*
	Point class is parent of Circle class.
*/
class Point{
protected:
	int x;
	int y;

public:
	Point(int x, int y):x(x), y(y){
		cout << "[Point Initializer](" << x << "," << y << ")\n";
	}
	
	virtual int getX(){
		cout << "Point getX() is invoked.\n";
		return x;
	}
	
	int getY(){
		cout << "Point getY() is invoked\n";
		return y;
	}
	
	friend ostream& operator<<(ostream& os, Point& p){
		os << "[Point class](" << p.x << "," << p.y << ")\n";
		return os;
	}
};

class Circle : public Point{
private:
	int radius;
	
public:
	Circle(int x, int y, int radius): Point(x, y), radius(radius){
		cout << "[Circle Initializer](" << x << "," << y << ") : r = " << radius << "\n";
	}
	
	int  getRadius(){
		return radius;
	}
	
	int getX() override{
		cout << "\nCircle getX() is invoked.\n";
		return x;
	}
	
	int getY(){
		cout << "\nCircle getY() is invoked\n";
		return y;
	}
	
	friend ostream& operator<<(ostream& os, Circle& c){
		os << "[Circle class](" << c.getX() << "," << c.getY() << ") : r = " << c.radius << "\n";
		return os;
	}
};

int main(){
	Point p(2,3); // [Point Initializer](2, 3)
	Circle c(5,4,2); // [Point Initializer](5, 4) [Circle Initializer](5, 4)
	
	cout << p; // [Point class](2, 3)
	cout << c; // [Circle class](Circle getX() is invoked. 5, Circle getY() is invoked. 4) : r = 2
	
	Point *pp = &c;
	
	cout << *pp; // [Point class](5, 4)
	pp->getX(); // Circle getX() is invoked.
	pp->getY(); // Point getY() is invoked.
	//pp->getRadius(); // Error Point has no member named getRadius
}

