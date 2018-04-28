#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

/***************************** Description *****************************/
/*  Description:
 *	- Creational design pattern -> concern with instatiation of objects/classes
 *. - Class design pattern -> inheritance between class and its subclasses
 *  Purpose:
 *  - Create object without exposing the creation logic to the client
 *  - Refer to newly created object using a common interface
 *  Application:
 *  - Developing applications with different database as backend
 */

/***************************** Abstract *****************************/
class Shape {
public:
	virtual void draw() {};
	static Shape *makeShape(int type);
};

/***************************** Concrete *****************************/
class Rectangle: public Shape {
public:
	void draw() {
		cout << "This is a Rectangle" << endl;
	}
};

class Circle: public Shape {
public:
	void draw() {
		cout << "This is a Circle" << endl;
	}
};

class Square: public Shape {
public:
	void draw() {
		cout << "This is a Square" << endl;
	}
};

Shape *Shape::makeShape(int type){
	switch(type){
		case 1: return new Circle;
		case 2: return new Rectangle;
		case 3: return new Square;
		default: return new Shape;
	}
}

int main(){	
	map<string, int>shape_dict;
	shape_dict["CIRCLE"] = 1;
	shape_dict["RECTANGLE"] = 2;
	shape_dict["SQUARE"] = 3;

	Shape shapeFactory;

	vector<Shape*> shapes;
	shapes.push_back(shapeFactory.makeShape(shape_dict["SQUARE"]));
	shapes[0]->draw();

	Shape *shape1 = shapeFactory.makeShape(shape_dict["CIRCLE"]);
	shape1->draw();

	for (int i = 0; i < shapes.size(); i++)
		delete shapes[i];
}