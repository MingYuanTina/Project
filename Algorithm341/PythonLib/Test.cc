#include <iostream>
#include <string>
using namespace std;

int main(){
	string s = "abcdefghijklmn";
	int i = 5;
	string pre = s.substr(0, i);
	string post = s.substr(i+1, s.size()-i);
	cout << pre << endl;
	cout << post << endl;
	return 0;
}