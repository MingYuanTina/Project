#include <iostream>
#include <string>
#include <vector>
#include "Knapsack.h"
using namespace std;

void Knapsack::set_info(){
	this->general_info = "General: \n  Take a list of items with w(i) as weight and v(i) as value  \n"
												+ string("   maximize the total sum of value subject to given constraints wc (weight) \n")
												+ string("Format: \n length, list of weight, list of value, weight \n") 
												+ string("Example: \n 5, [1,2,3,4,5], [1,2,3,4,5], 15");
	this->algorithm_type = "Knapsack";
	this->run_time_complexity = "O(n*k), where n = target, k = items list length";
	this->space_complexity = "O(n*k)";
	this->iteration = 0;
}

int Knapsack::get_iteration(){
	return this->iteration;
}

void Knapsack::get_info(){
	cin >> this->len;
	int temp;
	for (int i = 0; i < this->len; i++){
		cin >> temp;
		this->w.push_back(temp);
	}
	for (int i = 0; i < this->len; i++){
		cin >> temp;
		this->v.push_back(temp);
	}
	cin >> this->wc;
}

void Knapsack::perform_algo(){
	int m[this->len+1][this->wc+1];

	// Base Case
	//for (int i = 0; i <= this->len; i++){
		for (int j = 0; j <= this->wc; j++){
			m[0][j] = 0;
		}
	//}

	// Recursive Case
	for (int i = 1; i <= this->len; i++){
		for (int j = 0; j <= this->wc; j++){
			int m1 = m[i-1][j];
			int m2 = 0;
			if (j >= w[i])
				m2 = v[i] + m[i-1][j-w[i]];
			m[i][j] = max(m1, m2);
		}
	}
	this->output.push_back(m[this->len][this->wc]);
}
