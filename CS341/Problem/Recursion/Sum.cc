#include <iostream>
#include <string>
#include <vector>
#include "Sum.h"
using namespace std;

void Sum::set_info(){
	this->general_info = "General: \n   Two sum takes in a target value and returns two index \n"
												+ string("where the elements sum up to target value \n")
												+ string("Format: \n   target value, length, list of numbers");
	this->algorithm_type = "Two Sum";
	this->run_time_complexity = "O(nlogn)";
	this->space_complexity = "O(1)";
	this->iteration = 0;
}

int Sum::get_iteration(){
	return this->iteration;
}

void Sum::get_info(){
	cin >> this->target;
	cin >> this->len;
	int temp;
	for (int i = 0; i < len; i++){
		cin >> temp;
		this->list.push_back(temp);
	}
}

void Sum::perform_algo(){
	sort(list.begin(), list.end()); // O(nlogn)
	int i = 0; 
	int j = list.size() -1;
	while (i <= j){
		if (list[i] + list[j] == this->target){
			this->output.push_back(i);
			this->output.push_back(j);
			break;
		} else if (list[i] + list[j] > this->target){
			j--;
		} else {
			i++;
		}
		this->iteration += 1;
	}
}

