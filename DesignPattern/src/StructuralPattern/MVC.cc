// Resource: https://www.geeksforgeeks.org/mvc-design-pattern/

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

/***************************** Description *****************************/
/*  Description:
 *  - Software architecture that specifies an application
 *  - into data modal, presentation and control information
 *  
 *  - The model contains pure application data
 *  - The view presents the model's data to the user
 *  - The controller listens to the events triggered by the view
 *  - and executes the appropriate reaction to the these events
 */


class StudentModel {
private:
	string name;
public:
	string getStudentName(){
		return name;
	}
	void setStudentName(string name){
		this->name = name;
	}
};

class StudentView {
public:
	void printStudentDetails(string studentName){
		cout << "Student's Name: " << studentName << endl;
	}
};

class StudentController {
private:
	StudentModel model;
	StudentView view;
public:
	StudentController(StudentModel model, StudentView view){
		this->model = model;
		this->view = view;
	}

	void setStudentName(string name){
		model.setStudentName(name);
	}

	string getStudentName(){
		return model.getStudentName();
	}

	void updateView(){
		string name = getStudentName();
		view.printStudentDetails(name);
	}
};

int main(){
	StudentModel model;
	model.setStudentName("Ti NA");
	StudentView view;
	StudentController controller(model, view);
	controller.updateView();
	return 0;
}