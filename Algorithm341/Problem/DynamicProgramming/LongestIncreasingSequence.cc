#include <iostream>
#include <string>
#include <vector>
#include "LongestIncreasingSequence.h"
using namespace std;

void LongestIncreasingSequence::set_info(){
	this->general_info = "General: \n Takes a list of numbers and find the length of longest increasing sequence \n"
												+ string("Format: \n length, sequence \n")
												+ string("Example: \n  6, 1 4 3 5 7 2");
	this->algorithm_type = "Longest Increasing Sequence";
	this->run_time_complexity = "O(n^2)";
	this->space_complexity = "O(n)";
	this->iteration = 0;
}

int LongestIncreasingSequence::get_iteration(){
	return this->iteration;
}

void LongestIncreasingSequence::get_info(){
	int temp;
	cin >> this->len;
	for (int i = 0; i < this->len; i++){
		cin >> temp;
		this->list.push_back(temp);
	}
}

void LongestIncreasingSequence::perform_algo(){
	vector<int>temp (list.begin(), list.end());
	sort(temp.begin(), temp.end());
	int m[this->len+1][this->len+1];
	// Base Case
	for (int i = 0; i <= this->len; i++){
		m[i][0] = 0;
		m[0][i] = 0;
	}

	// Other Case
	for (int i = 1; i <= this->len; i++){
		for (int j = 1; j <= this->len; j++){
			int m1 = 0;
			if (this->list[i] == temp[j])
				m1 = m[i-1][j-1] + 1;
			int m2 = m[i-1][j];
			int m3 = m[i][j-1];
			m[i][j] = max(max(m1, m2), m3);
			this->iteration += 1;
		}
	}
	this->output.push_back(m[this->len][this->len]);
}
