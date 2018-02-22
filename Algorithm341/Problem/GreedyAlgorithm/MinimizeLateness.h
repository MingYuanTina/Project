#ifndef MINIMIZE_LATENESS_H
#define MINIMIZE_LATENESS_H
#include "../Model.h"
#include <map>

class MinimizeLateness : public Model {
private:
	std::vector<int>perform_time;
	std::vector<int>due_time;
	int len;

public:	
	void set_info();
	int get_iteration();
	void get_info();
	void perform_algo();
};

#endif
