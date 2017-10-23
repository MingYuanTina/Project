#ifndef COIN_CHANGE_H
#define COIN_CHANGE_H
#include "../Model.h"

class CoinChange : public Model {
private:
	std::vector<int>list;
	int target;
	int len;

public:	
	void set_info();
	int get_iteration();
	void get_info();
	void perform_algo();
};

#endif
