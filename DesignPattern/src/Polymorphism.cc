// Resources:
//	http://www.catonmat.net/blog/cpp-polymorphism/

// These polymorphisms also go by different names in C++,

// Subtype polymorphism is also known as runtime polymorphism.
// Parametric polymorphism is also known as compile-time polymorphism.
// Ad-hoc polymorphism is also known as overloading.
// Coercion is also known as (implicit or explicit) casting.

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

/***************************** Polymorphism *****************************/
/*  Description:
 *	- Concept of creating common interface under different type of entities/data
 *  Purpose/Benefit:
 *  - Common abstraction between entities/classes
 *  - 
 */

/***************************** Subtyping Polymorphism *****************************/
/*  Description:
 *	- Use derived class through base class pointers or reference
 */

/*  Example:
 *	- Shape as the base class contains attributes e.g. width and height
 *  - Rectangle is a subclass of Shape that initialize properties
 *  - 	defines the implementation of getArea
 */
class Shape {
protected:
	int width, height;
public:
	virtual int getArea() = 0;
};

class Rectangle: public Shape {
public:
	Rectangle(int h, int w){
		this->width = w;
		this->height = h;
	}
	int getArea(){
		return width * height;
	}
};


int main(){
	Shape *obj1 = new Rectangle(10, 10);
	cout << "The area of Rectangle is: " << obj1->getArea() << endl;
	return 0;
}