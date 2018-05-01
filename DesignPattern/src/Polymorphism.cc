// Resources:
//	http://www.catonmat.net/blog/cpp-polymorphism/
//  https://www.hackerearth.com/practice/notes/virtual-function-and-virtual-table-in-c/

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
 *  - Also called runtime polymorphism since it occurs at runtime
 *  - v_ptr is created to the base class that contains virtual functions
 *  - vtable is created compile time v_ptr holds the address of v_table of the corresponding class
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

/***************************** Parametric Polymorphism *****************************/
/* Description:
 * - provide a means to execute the same code for any type using template
 * - build generic methods (binding types with shared functionality)
 * - compile time polymorphism
 */
template <class T>
T max(T a, T b) {
 return a > b ? a : b;
}

template <class T>
T add(T a, T b) {
	return a + b;
}

/***************************** Ad-hoc Polymorphism *****************************/
/* Description:
 * - Ad-hoc polymorphism allows functions with the same name act differently for each type
 * - build generic methods (binding function interface with different functionality)
 * - runtime polymorphism
 */
const char *max(const char *a, const char *b) {
 return strcmp(a, b) > 0 ? a : b;
}

/***************************** Coercion Polymorphism *****************************/
/* Description:
 * - Casting
 */

int main(){
	Shape *obj1 = new Rectangle(10, 10);
	cout << "The area of Rectangle is: " << obj1->getArea() << endl;
	cout << ::max(5,9) << endl;
	cout << ::max("A", "B") << endl;
	return 0;
}