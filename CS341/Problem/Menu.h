#ifndef MENU_H
#define MENU_H

class Menu {
private:
	std::vector<std::string>general_menu;								// General Option (First level menu)
public:
	Menu(){}
	void set_option_type();
	std::vector<std::string> get_sub_menu(int user_option);
	std::vector<std::string> get_option_type();
};
#endif