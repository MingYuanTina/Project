#ifndef INVERSION_H
#define INVERSION_H
#include "../Model.h"

class Inversion : public Model {
private:
	std::vector<int>list;
	int len;

public:	
	void set_info();
	int get_iteration();
	void get_info();
	void perform_algo();
};

#endif

