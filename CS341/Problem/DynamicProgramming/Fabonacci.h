#ifndef FABONACCI_H
#define FABONACCI_H
#include "../Model.h"

class Fabonacci : public Model {
private:
	int len;

public:	
	void set_info();
	int get_iteration();
	void get_info();
	void perform_algo();
};

#endif
