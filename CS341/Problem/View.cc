#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "View.h"
using namespace std;

void View::print_instruction(string instr){
	cout << instr << endl;
}

void View::print_user_prompt(){
	cout << "Would you like to continue? [Y/N]" << endl;
}

void View::print_menu(){
	this->m.set_option_type();
	this->general_menu = this->m.get_option_type();
	for (int i = 0; i < this->general_menu.size(); i++){
		cout << "[" << i << "]" << " " << this->general_menu[i] << endl;
	}
}

void View::print_sub_menu(int user_option){
	this->sub_menu = this->m.get_sub_menu(user_option);
	for (int i = 0; i < this->sub_menu.size(); i++){
		cout << "[" << i << "]" << " " << this->sub_menu[i] << endl;
	}
}

void View::print_output(string algo, string time, string space, int iteration, vector<int>output){
	cout << "---------Beginning of Output---------" << endl;
	cout << "Algorithm: " << algo << endl;
	cout << "Time Complexity: " << time << endl;
	cout << "Space Complexity: " << space << endl;
	cout << "Num Iteration: " << iteration << endl;
	for (int i = 0; i < output.size(); i++){
		cout << output[i] << " ";
	} 
	cout << endl;
	cout << "---------End of Output---------" << endl;
}

