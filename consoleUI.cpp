#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "task.h" 
#include "taskManager.h"
#include "consoleUI.h"
#include "fmanip.h"
#include "time.h"

using namespace std;

taskManager task_manager;

std::vector<Task> general;
std::vector<Task> overdue_vec; 

bool startup = false;

void contents() {

	//all startup actions
	if (startup == false) {
		readfromFile(general, "savedata.txt");
		readfromFile(overdue_vec, "overdue.txt");
		updateTime(general);
		reminderCheck(general);
		asciiLogo(); 
		startup = true;
	}
	std::string contents_input;

	//table of contents
	divider();

	std::cout << "Please select functionality: " << endl;
	std::cout << "1. create task" << endl;
	std::cout << "2. edit task" << endl;
	std::cout << "3. view & sort tasks" << endl;
	std::cout << "4. delete task" << endl << endl;

	std::cout << "Press 's' to save" << endl;
	std::cout << "Press 'q' to quit" << endl;
	std::cout << "Press 'w' to wipe file" << endl; 

	divider();

	//save, quit, wipe functionality
	std::cin >> contents_input;
	if (contents_input == "q") {
		savetoFile(general, "savedata.txt"); 
		exit(0);
	}
	else if (contents_input == "s") {
		savetoFile(general, "savedata.txt");
		returnToContents();
	}
	else if (contents_input == "w") {
		char wipe_conf;

		divider();

		std::cout << "WARNING: You will permanently lose ALL of your data. Are you sure?: " << std::endl;
		std::cout << "y / n" << std::endl;

		divider();

		std::cin >> wipe_conf; 

		while (wipe_conf != 'y' && wipe_conf != 'n') {
			std::cout << "y / n: " << std::endl;
			std::cin >> wipe_conf;
		}
		if (wipe_conf == 'y') {
			wipeFile(general, "savedata.txt");
			wipeFile(overdue_vec, "overdue.txt");
			returnToContents(); 
		}
		else {
			contents();  
		}

	}
	int contents_input_int = std::stoi(contents_input);

	//switch case to direct user to desired functionality
	if (contents_input_int < 9 && contents_input_int >= 0) {
		switch (contents_input_int) {
		case 0:
			break;
		case 1:
			createTaskUI();
			break;
		case 2:
			editTaskUI();
			break;
		case 3:
			sortTaskUI();
			break;
		case 4:
			deleteTaskUI();
			break;
		default:
			std::cout << "please enter an integer between 1 and 4 to represent the desired function" << endl;
			contents();
		}
	}
}

//UI for create, edit, sort and delete
//direct user to func. and then offer to continue or quit
void createTaskUI() {

	divider();

	std::cout << "- CREATE TASKS -" << endl;
	Task temp = task_manager.createTask();
	temp.toString();
	general.push_back(temp);
	returnToCreate();

	divider();

}
void editTaskUI() {

	divider();

	std::cout << "- EDIT TASKS -" << endl;
	Task temp = task_manager.editTask(general);
	general.push_back(temp);
	returnToEdit();

	divider();

}
void sortTaskUI() {

	divider();
	std::cout << "- SORT / VIEW TASKS -" << endl;
	std::cout << "You Currently Have: " << general.size() << " Tasks" << endl;
	std::cout << "Your Tasks: ";
	divider();
	task_manager.sortTask(general, overdue_vec);
	returnToSort();
	divider();

}
void deleteTaskUI() {

	divider();
	std::cout << "- DELETE TASKS -" << std::endl;
	task_manager.deleteTask(general);
	returnToDelete();
	divider();
}

//allow user to continue working or quit
void returnToContents() {
	char return_to_contents;

	divider();

	std::cout << "Return to Contents?: " << std::endl;
	std::cout << "y / n" << std::endl;

	divider();

	std::cin >> return_to_contents;

	while (return_to_contents != 'y' && return_to_contents != 'n') {
		std::cout << "y / n: " << std::endl;
		std::cin >> return_to_contents;
	}
	if (return_to_contents == 'y') {
		contents();
	}
	else {
		savetoFile(general, "savedata.txt");
		exit(0);
	}
}
void returnToCreate() {
	char return_to_create;

	divider();

	std::cout << "Create Another Task?: " << std::endl;
	std::cout << "y / n" << std::endl;

	divider();

	std::cin >> return_to_create;

	while (return_to_create != 'y' && return_to_create != 'n') {
		std::cout << "y / n: " << std::endl;
		std::cin >> return_to_create;
	}
	if (return_to_create == 'y') {
		 createTaskUI();
	}
	else {
		savetoFile(general, "savedata.txt");
		contents();
	}
}
void returnToEdit() {
	char return_to_edit;

	divider();

	std::cout << "Edit Another Task?: " << std::endl;
	std::cout << "y / n" << std::endl;

	divider();

	std::cin >> return_to_edit;

	while (return_to_edit != 'y' && return_to_edit != 'n') {
		std::cout << "y / n: " << std::endl;
		std::cin >> return_to_edit;
	}
	if (return_to_edit == 'y') {
		editTaskUI();
	}
	else {
		savetoFile(general, "savedata.txt");
		contents();
	}
}
void returnToSort() {
	char return_to_sort;

	divider();

	std::cout << "Sort Another Task?: " << std::endl;
	std::cout << "y / n" << std::endl;

	divider();

	std::cin >> return_to_sort;

	while (return_to_sort != 'y' && return_to_sort != 'n') {
		std::cout << "y / n: " << std::endl;
		std::cin >> return_to_sort;
	}
	if (return_to_sort == 'y') {
		sortTaskUI();
	}
	else {
		savetoFile(general, "savedata.txt");
		contents();
	}
}
void returnToDelete() {
	char return_to_delete;

	divider();

	std::cout << "Delete Another Task?: " << std::endl;
	std::cout << "y / n" << std::endl;

	divider();

	std::cin >> return_to_delete;

	while (return_to_delete != 'y' && return_to_delete != 'n') {
		std::cout << "y / n: " << std::endl;
		std::cin >> return_to_delete;
	}
	if (return_to_delete == 'y') {
		deleteTaskUI();
	}
	else {
		savetoFile(general, "savedata.txt");
		contents();
	}
}

//readability
void divider() {
	std::cout << std::endl << std::string(45, '=') << std::endl;
}
//logo
void asciiLogo() {
	std::cout << "88888888888  d88888b   8888888b     d88888b        888b     d888        d8888 888b    888        d8888   d8888b   8888888888 8888888b." << endl; 
	std::cout << "    888    d88P' 'Y88b 888  'Y88b d88P' 'Y88b      8888b   d8888       d88888 8888b   888       d88888 d88P  Y88b 888        888   Y88b" << endl;
	std::cout << "    888    888     888 888    888 888     888      88888b.d88888      d88P888 88888b  888      d88P888 888    888 888        888    888" << endl;
	std::cout << "    888    888     888 888    888 888     888      888Y88888P888     d88P 888 888Y88b 888     d88P 888 888        8888888    888   d88P" << endl;
	std::cout << "    888    888     888 888    888 888     888      888 Y888P 888    d88P  888 888 Y88b888    d88P  888 888  88888 888        8888888P" << endl;
	std::cout << "    888    888     888 888    888 888     888      888  Y8P  888   d88P   888 888  Y88888   d88P   888 888    888 888        888 T88b" << endl;
	std::cout << "    888    Y88b   d88P 888   d88P Y88b   d88P      888   '   888  d8888888888 888   Y8888  d8888888888 Y88b  d88P 888        888  T88b" << endl;
	std::cout << "    888     'Y88888P'  8888888P'   'Y88888P'       888       888 d88P     888 888    Y888 d88P     888  'Y8888P88 8888888888 888   T88b" << endl;
}