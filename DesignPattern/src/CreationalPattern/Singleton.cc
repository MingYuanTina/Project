#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

/***************************** Description *****************************/
/*  Description:
 *	- Creational design pattern -> concern with instatiation of objects/classes
 *. - Object design pattern -> inheritance between object
 *  Purpose:
 *  - Single class which is responsible to create a single object
 *  - Encapsulate the instantiation of object
 *  Application:
 *  - Shared resources: memory, database connection
 */

class SingleObject {
private:
	//static SingleObject instance = new SingleObject();
	SingleObject() {}; 							// Private constructor
public:
	~SingleObject() {};
	static SingleObject getInstance(){
		static SingleObject instance;
		return instance;
	}
	void showMessage(){
		cout << "TEST" << endl;
	}
};

int main(){
	SingleObject object1 = SingleObject::getInstance();
	object1.showMessage();
	return 0;
}