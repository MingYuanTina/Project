#ifndef KNAPSACK_H
#define KNAPSACK_H
#include "../Model.h"

class Knapsack : public Model {
private:
	std::vector<int>w;
	std::vector<int>v;
	int len, wc;	// len = length of list, wc = weight constraints

public:	
	void set_info();
	int get_iteration();
	void get_info();
	void perform_algo();
};

#endif
