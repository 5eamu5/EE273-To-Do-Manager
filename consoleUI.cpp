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

	if (startup == false) {
		readfromFile(general, "savedata.txt");
		readfromFile(overdue_vec, "overdue.txt");
		updateTime(general);
		reminderCheck(general);
		startup = true;
	}
	std::string contents_input;

	upperDivider();

	std::cout << "-TODO MANAGER-" << endl;
	std::cout << "Please select functionality: " << endl;
	std::cout << "1. create task" << endl;
	std::cout << "2. edit task" << endl;
	std::cout << "3. view & sort tasks" << endl;
	std::cout << "4. delete task" << endl << endl;

	std::cout << "Press 'w' to wipe file (dev)" << endl;
	std::cout << "Press 's' to save" << endl;
	std::cout << "Press 'q' to quit" << endl;

	lowerDivider();

	std::cin >> contents_input;
	if (contents_input == "q") {
		savetoFile(general, "savedata.txt"); 
		exit(0);
	}
	else if (contents_input == "s") {
		//task_manager.pushGeneral();
		savetoFile(general, "savedata.txt");
		returnToContents();
	}
	else if (contents_input == "w") {
		wipeFile(general, "savedata.txt");
		returnToContents();
	}
	int contents_input_int = std::stoi(contents_input);

	//need to catch false inputs here
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

void createTaskUI() {

	upperDivider();

	std::cout << "- CREATE TASKS -" << endl;
	Task temp = task_manager.createTask();
	std::cout << "\n" << temp.toString() << std::endl;
	std::cout << "unix deadline: " << temp.unixDeadline() << std::endl;

	time_t ttime = time(0);
	struct tm buf;
	localtime_s(&buf, &ttime);
	time_t current = mktime(&buf);

	std::cout << "unix current: " << current << std::endl;

	general.push_back(temp);
	returnToContents();

	lowerDivider();

}

void editTaskUI() {

	upperDivider();

	std::cout << "- EDIT TASKS -" << endl;
	Task temp = task_manager.editTask(general);
	general.push_back(temp);
	returnToEdit();

	lowerDivider();

}

void sortTaskUI() {

	upperDivider();
	std::cout << "- SORT / VIEW TASKS -" << endl;
	task_manager.sortTask(general, overdue_vec);
	returnToSort();
	lowerDivider();

}

void deleteTaskUI() {

	upperDivider();
	std::cout << "- DELETE TASKS -" << std::endl;
	task_manager.deleteTask(general);
	returnToDelete();
	lowerDivider();
}

void returnToContents() {
	char return_to_contents;

	upperDivider();

	std::cout << "anything else?: " << std::endl;
	std::cout << "y / n" << std::endl;

	lowerDivider();

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
void returnToEdit() {
	char return_to_edit;

	upperDivider();

	std::cout << "edit anything else?: " << std::endl;
	std::cout << "y / n" << std::endl;

	lowerDivider();

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

	upperDivider();

	std::cout << "sort anything else?: " << std::endl;
	std::cout << "y / n" << std::endl;

	lowerDivider();

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

	upperDivider();

	std::cout << "delete anything else?: " << std::endl;
	std::cout << "y / n" << std::endl;

	lowerDivider();

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

void upperDivider() {
	std::cout << std::string(2, '\n') << std::string(10, '-') << endl;
	std::cout << std::string(10, '*') << std::string(2, '\n');
}
void lowerDivider() {
	std::cout << std::string(2, '\n') << std::string(10, '^') << endl;
	std::cout << std::string(10, '-') << std::string(2, '\n');
}
