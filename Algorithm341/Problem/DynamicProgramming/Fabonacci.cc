#include <iostream>
#include <string>
#include <vector>
#include "Fabonacci.h"
using namespace std;

void Fabonacci::set_info(){
	this->general_info = "General: \n  The next number is sum of previous two \n"
												+ string("Format: \n len (len > 2)");
	this->algorithm_type = "Fabonacci";
	this->run_time_complexity = "O(n)";
	this->space_complexity = "O(1)";
	this->iteration = 0;
}

int Fabonacci::get_iteration(){
	return this->iteration;
}

void Fabonacci::get_info(){
	cin >> this->len;
}

void Fabonacci::perform_algo(){
	// Base Case
	vector<int>A;
	this->output.push_back(0);
	this->output.push_back(1);

	// Other Case
	for (int i = 2; i < this->len; i++){
		this->iteration += 1;
		this->output.push_back(this->output[i-1] + this->output[i-2]);
	}
}
