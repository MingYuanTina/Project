#include <iostream>
#include <string>
#include <vector>
#include "MaxCommonSequence.h"
using namespace std;

void MaxCommonSequence::set_info(){
	this->general_info = "General: \n Takes two common sequence and find the maximum of common sequence \n"
												+ string("Format: \n seq_one length, seq_two length, sequence_one, sequence_two \n")
												+ string("Example: \n  7, 9, T A R M A C, C A T A M A R A N");
	this->algorithm_type = "Max Common Sequence";
	this->run_time_complexity = "O(n^2)";
	this->space_complexity = "O(1)";
	this->iteration = 0;
}

int MaxCommonSequence::get_iteration(){
	return this->iteration;
}

void MaxCommonSequence::get_info(){
	string temp;
	cin >> this->len_one;
	cin >> this->len_two;
	for (int i = 0; i < this->len_one; i++){
		cin >> temp;
		this->seq_one.push_back(temp);
	}
	for (int i = 0; i < this->len_two; i++){
		cin >> temp;
		this->seq_two.push_back(temp);
	}
}

void MaxCommonSequence::perform_algo(){
	int m[this->len_one+1][this->len_two+1];
	// Base Case
	for (int i = 0; i <= this->len_one; i++){
		m[i][0] = 0;
	}
	for (int i = 0; i <= this->len_two; i++){
		m[0][i] = 0;
	}

	// Other Case
	for (int i = 1; i <= this->len_one; i++){
		for (int j = 1; j <= this->len_two; j++){
			int m1 = 0;
			if (this->seq_one[i] == this->seq_two[j])
				m1 = m[i-1][j-1] + 1;
			int m2 = m[i-1][j];
			int m3 = m[i][j-1];
			m[i][j] = max(max(m1, m2), m3);
			this->iteration += 1;
		}
	}
	this->output.push_back(m[this->len_one][this->len_two]);
}
