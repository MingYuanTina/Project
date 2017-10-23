#include <iostream>
#include <string>
#include <vector>
#include "CoinChange.h"
using namespace std;

void CoinChange::set_info(){
	this->general_info = "General: \n   Taking a target value and greedy algorithm \n"
												+ string("   always making change works for its system \n")
												+ string("   The greedy change algorithm can be implemented using quotient and remainders\n")
												+ string("Format: \n   target value, length, list of numbers");
	this->algorithm_type = "Coin Change Greedy Algorithm";
	this->run_time_complexity = "O(n^2)";
	this->space_complexity = "O(1)";
	this->iteration = 0;
}

int CoinChange::get_iteration(){
	return this->iteration;
}

void CoinChange::get_info(){
	cin >> this->target;
	cin >> this->len;
	int temp;
	for (int i = 0; i < len; i++){
		cin >> temp;
		this->list.push_back(temp);
	}
}

void CoinChange::perform_algo(){
	// Need to implement
}