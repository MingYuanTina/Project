#include <iostream>
#include <string>
#include <vector>
#include "CoinChange.h"
using namespace std;

void CoinChange::set_info(){
	this->general_info = "General: \n  Take a list of coin denominator and  \n"
												+ string("find the mininmum combination that sum up to target values\n")
												+ string("Format: \n target, length, list of coin") 
												+ string("Example: \n 5, 3, [1,2,3]");
	this->algorithm_type = "Coin Change";
	this->run_time_complexity = "O(n*k), where n = target, k = length of coins";
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
	for (int i = 0; i < this->len; i++){
		cin >> temp;
		this->list.push_back(temp);
	}
}

void CoinChange::perform_algo(){
	// Special Case
	if (this->target == 0)
		this->output.push_back(0);

	int c[this->target+1];
	sort(this->list.begin(), this->list.end());
	
	// Base Case
	c[0] = 0;

	// Other Case
	for (int i = 1; i <= this->target; i++){
		c[i] = 1000000; // assign to a big number
		for (int j = 0; j < this->len; j++){
			if (this->list[j] <= this->target && 1 + c[i-this->list[j]] < c[i])
				c[i] = 1 + c[i-this->list[j]];
			this->iteration += 1;
		}
	}
	this->output.push_back(c[this->target]);
}
