#ifndef MENU_H
#define MENU_H

class Menu {
private:
	std::vector<std::string>general_menu;										// General Option (First level menu)
	std::vector<std::vector<std::string> >sub_menu_option; 	// Sub-menu Option
public:
	Menu(){}
	void set_option_type();
	void set_sub_menu();
	std::vector<std::string> get_sub_menu(int user_option);
	std::vector<std::string> get_option_type();
};
#endif