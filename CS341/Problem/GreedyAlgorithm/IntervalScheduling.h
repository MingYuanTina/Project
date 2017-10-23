#ifndef INTERVAL_SCHEDULING_H
#define INTERVAL_SCHEDULING_H
#include "../Model.h"
#include <map>

class IntervalScheduling : public Model {
private:
	std::map<int, int>time;
	int len;

public:	
	void set_info();
	int get_iteration();
	void get_info();
	void perform_algo();
};

#endif
