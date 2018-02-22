#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "IntervalScheduling.h"
using namespace std;

void IntervalScheduling::set_info(){
	this->general_info = "General: \n   Given a list of  time intervals (start time and end time) \n"
												+ string("   return maximum disjoin interval you could make \n")
												+ string("Format: \n   length, list of begin_time, list of end_time");
	this->algorithm_type = "Interval Scheduling Greedy Algorithm";
	this->run_time_complexity = "O(n^2)";
	this->space_complexity = "O(1)";
	this->iteration = 0;
}

int IntervalScheduling::get_iteration(){
	return this->iteration;
}

void IntervalScheduling::get_info(){
	cin >> this->len;
	int temp;
	for (int i = 0; i < len; i++){
		cin >> temp;
		this->time[temp] = 0;
	}
	for (map<int, int>::iterator it = this->time.begin(); it != this->time.end(); it++){
		cin >> temp;
		this->time[it->first] = temp;
	}
}

void IntervalScheduling::perform_algo(){
	// Sort by end_time
	map<int, int>temp;
	for (map<int, int>::iterator it = this->time.begin(); it != this->time.end(); it++){
		temp[it->second] = it->first;
	}
	this->time = temp; // first: end_time, second: start_time
	// Find maximum disjoin time interval
	map<int, int>A;
	for (map<int, int>::iterator it = this->time.begin(); it != this->time.end(); it++){
		if (A.size() == 0){
			A[it->second] = it->first;
		} else {
			map<int, int>::iterator it2 = A.end();
			it2--;
			if (it->second > it2->second){
				A[it->second] = it->first;
			}
		}
		this->iteration += 1;
	}
	this->output.push_back(A.size());
}