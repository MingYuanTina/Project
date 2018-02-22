#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Singleton {
private:
	static Singleton *s;
	bool if_create;
	Singleton(){
		if_create = false;
	}
public:
	void get_general_info(){
		string s = "Singleton Pattern is "
	}

	Singleton* get_Singleton(){
		if (!this->if_create){
			s = new Singleton();
			this->if_create = true;
		}
		return s;
	}
};

int main(){
	return 0;
}