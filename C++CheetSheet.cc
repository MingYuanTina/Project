// Reference: http://www.cplusplus.com/reference/string/string/string/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

class Section {
public:
	virtual void printSection() {};
	virtual void initializeSection() {};
};

/***************************** String *****************************/
class StringSection: public Section {
private:
	vector<string> str_list;
public:
	void initializeSection(){
		string s = "TEST";
		string s0;							// default string
		string s1(s);			    	// copy constructor
		string s2(s, 0, 4);   	// substring constuctor (str, pos, len)
		string s3("TEST");    	// from c-string constructor
		string s4("TEST", 4); 	// from buffer constructor (str, len)
		string s5(5, 'X');   		// fill constructor (#, char)
		string s6(s.begin(), s.begin() + s.length()); // range constructor (start, last)
		string s7 = "25";				// assignment operator

		// Copy string value into vector list
		string strList[] = {s0, s1, s2, s3, s4, s5, s6, s7};
		this->str_list.assign(strList, strList + sizeof(strList) / sizeof(strList[0]));
	}

	void printSection(){
		for (unsigned int i = 0; i < str_list.size(); i++){
			cout << "THIS IS S" << i << ": ";
			string str = str_list[i];
			if (i == 1){
				//********************** String Iterator **********************
				for (string::iterator it = str.begin(); it != str.end(); it++){
					cout << *it;
				}
				cout << endl;
			} else if (i == 2){
			  //********************** Integer Iterator **********************
				for (int i = 0; i < str.size(); i++){
					cout << str[i];
				}
				cout << endl;
			} else if (i == 3){
				//******************* Substring (pos, len) ********************
				cout << str.substr(0, str.size()) << endl;
			} else if (i == 4){
				//*************************** CStr ****************************
				char *cstr = new char[str.length() + 1];
				strcpy(cstr, str.c_str());
				for (char *p = cstr; p != cstr + sizeof(cstr)/sizeof(cstr[0]) - 1; p++){
					cout << *p;
				}
				cout << endl;
			} else if (i == 5){ 
				//*************** Replace (pos, len, substitue) ***************
				str.replace(str.find("X"), str.length(), str_list[i-1]);
				cout << str << endl;
			} else if (i == 7){
				//*************** Conversion STR --> NUM ***************
				int a;
				stringstream ss(str);				// StringStream
				ss >> a;
				cout << a << " ";

				int b = atoi(str.c_str());	// ATOI
				cout << b << endl;

			} else {
				cout << str << endl;
			}
		}
	}
};

/***************************** Vector *****************************/


/***************************** Map *****************************/

int main(){
	Section *sectionString = new StringSection();
	sectionString->initializeSection();
	sectionString->printSection();
	return 0;
}