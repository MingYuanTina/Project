#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "Menu.h"
using namespace std;

void Menu::set_option_type(){
	const string menu[] = {"Sum", "DivideAndConquer", "Dynamic Programming", "q"};
	for (int i = 0; i < sizeof(menu)/sizeof(string); i++){
		this->general_menu.push_back(menu[i]);
	}
}

vector<string> Menu::get_sub_menu(int user_option){
	vector<vector<string> >sub_menu;

	// Initialize all sub_menu
	const string sum_menu[] = {"Two Sum", "Three Sum", "Four Sum"};
	const string dnc_menu[] = {"Inversion (Naive)", "Inversion (Improved)"};
	vector<string>sum(sum_menu, sum_menu + sizeof(sum_menu)/sizeof(string));
	vector<string>divide_and_conquer(dnc_menu, dnc_menu + sizeof(dnc_menu)/sizeof(string));
	
	// Assign all sub_menu
	sub_menu.push_back(sum);
	sub_menu.push_back(divide_and_conquer);

	return sub_menu[user_option];
}

vector<string> Menu::get_option_type(){
	return this->general_menu;
}