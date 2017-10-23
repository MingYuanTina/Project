#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "Menu.h"
using namespace std;


void Menu::set_option_type(){
	const string menu[] = {"Sum", "DivideAndConquer", "Greedy Algorithm", "DynamicProgramming", "q"};
	for (int i = 0; i < sizeof(menu)/sizeof(string); i++){
		this->general_menu.push_back(menu[i]);
	}
}

void Menu::set_sub_menu(){
	vector<vector<string> >sub_menu;

	// Initialize all sub_menu
	const string sum_menu[] = {"Two Sum", "Three Sum", "Four Sum"};
	const string dnc_menu[] = {"Inversion (Naive)", "Inversion (Improved)"};
	const string ga_menu[] = {"Interval Scheduling", "Minimize Lateness"};
	const string dp_menu[] = {"Fibonacci", "Max Common Sequence", "Longest Increaseing Sequence", "Coin Change", "Knapsack"};
	vector<string>sum(sum_menu, sum_menu + sizeof(sum_menu)/sizeof(string));
	vector<string>divide_and_conquer(dnc_menu, dnc_menu + sizeof(dnc_menu)/sizeof(string));
	vector<string>greedy_algorithm(ga_menu, ga_menu + sizeof(ga_menu)/sizeof(string));
	vector<string>dynamic_programming(dp_menu, dp_menu + sizeof(dp_menu)/sizeof(string));

	// Assign all sub_menu
	sub_menu.push_back(sum);
	sub_menu.push_back(divide_and_conquer);
	sub_menu.push_back(greedy_algorithm);
	sub_menu.push_back(dynamic_programming);

	this->sub_menu_option = sub_menu;
}


vector<string> Menu::get_sub_menu(int user_option){
	return this->sub_menu_option[user_option];
}

vector<string> Menu::get_option_type(){
	return this->general_menu;
}