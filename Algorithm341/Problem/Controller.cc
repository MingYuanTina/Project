#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "View.h"
#include "Model.h"
using namespace std;

// Include list of algorithm
#include "Recursion/Sum.h"
#include "DivideAndConquer/Inversion.h"

// Greedy Algorithm
#include "GreedyAlgorithm/IntervalScheduling.h"
#include "GreedyAlgorithm/MinimizeLateness.h"

// Dynamic Programming
#include "DynamicProgramming/Fabonacci.h"
#include "DynamicProgramming/MaxCommonSequence.h"
#include "DynamicProgramming/LongestIncreasingSequence.h"
#include "DynamicProgramming/CoinChange.h"
#include "DynamicProgramming/Knapsack.h"

class Controller {
private:
	View v;
	Model *m;
	string function_type;
	int user_option;
	int sub_menu_option;

public:
	Controller(View view, string type){
		this->v = view;
		this->function_type = type;
	}

	void perform_sub_menu(){
		this->v.print_sub_menu(this->user_option);
	}

	void perform_menu(){
		this->v.print_menu();
	}

	void perform_prompt(){
		this->v.print_user_prompt();
	}

	void perform_output(){
		if (this->user_option == 0){		// Recursion
			this->m = new Sum();
		} else if (user_option == 1){ 	// Divide and Conquer
			if (sub_menu_option == 0){
				this->m = new Inversion();
			} else if (sub_menu_option == 1){
				// New Inversion
			}
		} else if (user_option == 2){		// Greedy Algorithm
			if (sub_menu_option == 0){
				this->m = new IntervalScheduling();
			} else if (sub_menu_option == 1){
				this->m = new MinimizeLateness();
			}
		} else if (user_option == 3){	 	// Dynamic Programming
			if (sub_menu_option == 0){
				this->m = new Fabonacci();
			} else if (sub_menu_option == 1){
				this->m = new MaxCommonSequence();
			} else if (sub_menu_option == 2){
				this->m = new LongestIncreasingSequence();
			} else if (sub_menu_option == 3){
				this->m = new CoinChange();
			} else if (sub_menu_option == 4){
				this->m = new Knapsack();
			}
		} 
		
		this->m->set_info();
		this->v.print_instruction(this->m->get_general_info());
		this->m->get_info();
		this->m->perform_algo();
		this->v.print_output(this->m->get_algo_type(), 
												this->m->get_time_complexity(),
												this->m->get_space_complexity(),
												this->m->get_iteration(),
												this->m->get_algo_output());
	}

	void perform_user_flow(){
		perform_menu();
		// user input
		string ui;
		while (cin >> ui){
			if (ui == "q")
				break;

			// Perform User Input and Prompt after finished
			stringstream ss(ui);
			ss >> this->user_option;
			this->perform_sub_menu();
			
			// Perform sub-menu for user input
			string ui_sub;
			cin >> ui_sub;
			stringstream s(ui_sub);
			s >> this->sub_menu_option;

			perform_output();
			perform_prompt();
			string t;
			cin >> t;
			if (t == "Y")
				perform_menu();
			else
				break;
		}
	}

};

int main(){
	View v;
	Controller c(v, "");
	c.perform_user_flow();
	return 0;
}
