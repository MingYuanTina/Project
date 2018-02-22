#ifndef MAX_COMMON_SEQUENCE_H
#define MAX_COMMON_SEQUENCE_H
#include "../Model.h"

class MaxCommonSequence : public Model {
private:
	std::vector<std::string>seq_one;
	std::vector<std::string>seq_two;
	int len_one, len_two;

public:	
	void set_info();
	int get_iteration();
	void get_info();
	void perform_algo();
};

#endif
