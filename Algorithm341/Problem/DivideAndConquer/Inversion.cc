#include <iostream>
#include <string>
#include <vector>
#include "Inversion.h"
using namespace std;

void Inversion::set_info(){
	this->general_info = "General: \n  Inversion counts all out-of-order pairs \n"
												+ string("   i.e. index i < j and A[i] > A[j] \n")
												+ string("Format: \n   length, list of numbers");
	this->algorithm_type = "Count Inversion Number";
	this->run_time_complexity = "O(n^2)";
	this->space_complexity = "O(1)";
	this->iteration = 0;
}

int Inversion::get_iteration(){
	return this->iteration;
}

void Inversion::get_info(){
	cin >> this->len;
	int temp;
	for (int i = 0; i < len; i++){
		cin >> temp;
		this->list.push_back(temp);
	}
}

void Inversion::perform_algo(){
	int num_inversion = 0;
	for (int i = 0; i < this->list.size(); i++){
		for (int j = i + 1; j < this->list.size(); j++){
			if (list[i] > list[j]){
				num_inversion += 1;
			}
			this->iteration += 1;
		}
	}
	this->output.push_back(num_inversion);
}
