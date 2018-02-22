#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "MinimizeLateness.h"
using namespace std;


void MinimizeLateness::set_info(){
	this->general_info = "General: \n   Given a list of  perform time and due time \n"
												+ string("   return minimize lateness of overall performance \n")
												+ string("Format: \n   length, list of perform hour, list of due hour");
	this->algorithm_type = "Interval Scheduling Greedy Algorithm";
	this->run_time_complexity = "O(nlogn)";
	this->space_complexity = "O(n)";
	this->iteration = 0;
}

int MinimizeLateness::get_iteration(){
	return this->iteration;
}

void MinimizeLateness::get_info(){
	cin >> this->len;
	int temp;
	for (int i = 0; i < len; i++){
		cin >> temp;
		this->perform_time.push_back(temp);
	}
	for (int i = 0; i < len; i++){
		cin >> temp;
		this->due_time.push_back(temp);
	}
}

// Strategy: Sort due time and count minimize lateness
	// Test Cases
		// No due: [1,2,3] [4,5,6] --> 0
		// Due:	 [2,3,4] [1,2,3] --> 1 + 3 + 6 = 10 
		// Small range: [3,2] [4,5] --> 0
		// Large range: [3,2,3,2,3] [4,5,6,7,8]
void MinimizeLateness::perform_algo(){
	map<int, int>time;
	// Map that sorted based on due time
	for (int i = 0; i < this->len; i++){
		time[due_time[i]] = perform_time[i];
	}

	// Count minimize lateness
	int cur_time = 0;
	int lateness_time = 0;
	for (map<int, int>:: iterator	it = time.begin(); it != time.end(); it++){
		cur_time += it->second;
		lateness_time += (it->first - cur_time);
		this->iteration += 1;
	}

	// Check if there is actual delay
	if (lateness_time >= 0){
		lateness_time = 0;
	} else {
		lateness_time = abs(lateness_time);
	}
	this->output.push_back(lateness_time);
}

