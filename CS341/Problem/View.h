#ifndef VIEW_H
#define VIEW_H
#include "Menu.h"

class View {
private:
	Menu m;
	std::vector<std::string>general_menu;	
	std::vector<std::string>sub_menu;
public:
	void print_menu();
	void print_sub_menu(int user_option);
	void print_output(std::string algo, std::string time, std::string space, int iteration, std::vector<int>output);
	void print_instruction(std::string instr);
	void print_user_prompt();
};

#endif