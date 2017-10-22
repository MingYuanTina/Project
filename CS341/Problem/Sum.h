#ifndef SUM_H
#define SUM_H
#include "Model.h"

class Sum : public Model {
private:
	std::vector<int>list;
	int len;
	int target;

public:	
	void set_info();
	int get_iteration();
	void get_info();
	void perform_algo();
};

#endif

