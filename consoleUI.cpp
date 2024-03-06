#include <iostream>
#include <string>
#include <vector>
#include "task.h" 
#include "taskManager.h"
#include "consoleUI.h"
#include "editTask.h"
#include "sortTask.h"
#include "deleteTask.h"
#include "fmanip.h"

using namespace std;
taskManager task_manager;
std::vector<Task> general = task_manager.pushGeneral();

void contents() {

	std::string contents_input;

	upperDivider();

	std::cout << "-TODO MANAGER-" << endl;
	std::cout << "Please select functionality: " << endl;
	std::cout << "1. create task" << endl;
	std::cout << "2. edit task" << endl;
	std::cout << "3. view & sort tasks" << endl;
	std::cout << "4. delete task" << endl << endl; //needs functionality {see editTask()}

	std::cout << "Press 's' to save" << endl; //needs functionality
	std::cout << "Press 'q' to quit" << endl; //needs funcitonality

	lowerDivider();

	std::cin >> contents_input;
	if (contents_input == "q") {
		exit(0);
	}
	else if (contents_input == "s") {
		savetoFile(task_manager.pushGeneral(), "savedata.txt");
		contents();
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

	std::cout << "-CREATE NEW TASK-" << endl;
	Task temp = task_manager.createTask(); 
	std::cout << "\n" << temp.toString() << std::endl;
	returnToContents();

	lowerDivider(); 

}
void editTaskUI() {

	upperDivider();

	std::cout << "-EDIT A TASK-" << endl;
	Task temp = task_manager.editTask();
	std::cout << "\n" << temp.toString() << std::endl;
	returnToEdit();

	lowerDivider();

}

//everything above finished
//nothing below started yet 

void sortTaskUI() {

}

void UIsortName() {

}
void UIsortDeadline() {

}
void UIsortLocation() {

}
void UIsortSubject() {

}
void UIsortUrgent() {

}


void deleteTaskUI() {

}

void selectTaskToDelete() {

}

void returnToContents() {
	char return_to_contents;

	std::cout << std::string(10, '-') << std::string(2, '\n');

	std::cout << "anything else?: " << std::endl;
	std::cout << "y / n" << std::endl;
	std::cout << std::string(2, '\n') << std::string(10, '-') << std::string(2, '\n');

	std::cin >> return_to_contents;

	while (return_to_contents != 'y' && return_to_contents != 'n') {
		std::cout << "y / n" << std::endl;
		std::cout << std::string(10, '-') << std::string(2, '\n');
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

	std::cout << std::string(10, '-') << std::string(2, '\n');

	std::cout << "edit anything else?: " << std::endl;
	std::cout << "y / n" << std::endl;
	std::cout << std::string(2, '\n') << std::string(10, '-') << std::string(2, '\n');

	std::cin >> return_to_edit;

	while (return_to_edit != 'y' && return_to_edit != 'n') {
		std::cout << "y / n" << std::endl;
		std::cout << std::string(10, '-') << std::string(2, '\n');
		std::cin >> return_to_edit;
	}
	if (return_to_edit == 'y') {
		editTaskUI();
	}
	else {
		contents();
	}
}
void returnToSort() {

}
void returnToDelete() {

}

void upperDivider() {
	std::cout << std::string(2, '\n') << std::string(10, '-') << endl;
	std::cout << std::string(10, '*') << std::string(2, '\n');
}
void lowerDivider() { 
	std::cout << std::string(2, '\n') << std::string(10, '^') << endl;
	std::cout << std::string(10, '-') << std::string(2, '\n');
}
