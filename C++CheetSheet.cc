// Reference: 
/* http://www.cplusplus.com/reference/string/string/string/
 * http://www.cplusplus.com/reference/vector/vector/insert/
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

class Section {
protected:
	vector<string> type_list;
	map<string, string> map_list;
public:
	virtual void printSection() {};
};

/***************************** String *****************************/
class StringSection: public Section {
public:
	StringSection(){
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
		this->type_list.assign(strList, strList + sizeof(strList) / sizeof(strList[0]));
	}
	void printSection(){
		for (unsigned int i = 0; i < type_list.size(); i++){
			cout << "THIS IS S" << i << ": ";
			string str = type_list[i];
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
				str.replace(str.find("X"), str.length(), type_list[i-1]);
				cout << str << endl;
			} else if (i == 7){
				//*************** Conversion STR --> NUM ***************
				int a;
				stringstream ss(str);				// StringStream
				ss >> a;
				cout << a << " ";
				int b = atoi(str.c_str());	// ATOI
				cout << b << endl;
				
				//*************** Conversion NUM --> STR ***************
				stringstream iss;
				iss << a;
				string str_copy = iss.str();	// StringStream
				str_copy = to_string(a);		// TO_STRING

			} else {
				cout << str << endl;
			}
		}
	}
};

/***************************** Vector *****************************/
class VectorSection: public Section {
public:
	VectorSection(){
		string vectorList[] = {"1"};
		vector<string> first;																// empty constructor
		vector<string> second(1, "2");											// fill constructor (n, val)
		vector<string> third(second.begin(), second.end()); // range constructor (first, last)
		vector<string> fourth(third);												// copy constructor
		
		this->type_list.assign(vectorList, vectorList + sizeof(vectorList) / sizeof(vectorList[0]));
		this->type_list.push_back("2");											// PUSH_BACK (val)
		vector<string>::iterator it = this->type_list.begin();
		this->type_list.insert(it + this->type_list.size(), "3");									  // INSERT (iterator, n, val)
	}
	void printSection(){
		//********************** Container Iterator **********************
		for (vector<string>::iterator it = this->type_list.begin(); it != this->type_list.end(); it++){
			cout << *it << endl;
		}
		//********************** Integer Iterator **********************
		for (unsigned int i = 0; i < this->type_list.size(); i++){
			cout << this->type_list[i] << endl;
			//cout << this->type_list.at(i) << endl;
		}
	}
};

/***************************** Map *****************************/
class MapSection: public Section {
public:
	MapSection(){
		this->map_list["1"] = "1";
		this->map_list["2"] = "2";
		this->map_list["3"] = "3";
		map<string, string>second(this->map_list.begin(), this->map_list.end()); // fill constructor
		map<string, string>third(second); 		// copy constructor
	}
	void printSection(){
		//********************** Container Iterator **********************
		for (map<string,string>::iterator it = this->map_list.begin(); it != this->map_list.end(); it++){
			cout << it->first << " " << it->second << endl;
		}
		//********************** FIND **********************
		string searchElement = "1";
		map<string, string>::iterator it = this->map_list.find(searchElement);
		if (it != this->map_list.end()){
			cout << searchElement << " is an element of map list" << endl;
		}
		//********************** COUNT **********************
		if (this->map_list.count("1") > 0){
			cout << searchElement << " is an element of map list" << endl;
		}
	}
};

int main(){
	Section *sectionString = new StringSection();
	sectionString->printSection();

	Section *sectionVector = new VectorSection();
	sectionVector->printSection();

	Section *sectionMap = new MapSection();
	sectionMap->printSection();

	return 0;
}