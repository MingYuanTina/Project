#ifndef __MODEL_H__
#define __MODEL_H__

class Model {
protected:
	std::string general_info;
	std::string algorithm_type;
	std::string run_time_complexity;
	std::string space_complexity;
	int iteration;
	std::vector<int>output;
	
public:
	std::string get_general_info();
	std::string get_algo_type();
	std::string get_time_complexity();
	std::string get_space_complexity();
	std::vector<int>get_algo_output();
	virtual void get_info() = 0;
	virtual void set_info() = 0;
	virtual void perform_algo() = 0;
	virtual int get_iteration() = 0;

};

#endif