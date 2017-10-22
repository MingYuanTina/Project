#include <string>
#include <iostream>
#include <vector>
#include "Model.h"
using namespace std;

string Model::get_general_info(){
	return this->general_info;
}

string Model::get_algo_type(){ 
	return this->algorithm_type; 
}

string Model::get_time_complexity(){
	return this->run_time_complexity;
}

string Model::get_space_complexity(){
	return this->space_complexity;
}

vector<int> Model::get_algo_output(){
	return this->output;
}




