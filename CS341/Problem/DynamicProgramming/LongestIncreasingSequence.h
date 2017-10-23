#ifndef LONGEST_INCREASING_SEQUENCE_H
#define LONGEST_INCREASING_SEQUENCE_H
#include "../Model.h"

class LongestIncreasingSequence : public Model {
private:
	int len;
	std::vector<int>list;

public:	
	void set_info();
	int get_iteration();
	void get_info();
	void perform_algo();
};

#endif
