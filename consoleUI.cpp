#include <iostream>
#include <string>
#include <vector>
#include "task.h" 
#include "taskManager.h"
#include "consoleUI.h"
#include "editTask.h"
#include "sortTask.h"3

#include "deleteTask.h"

using namespace std;
taskManager task_manager;
std::vector<Task> general = task_manager.pushGeneral();  

void contents() {

	int contents_input;

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
	
	if (std::to_string(contents_input) == "q") {
		exit(0);
	}
	

	//need to catch false inputs here
	switch (contents_input) {
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

void createTaskUI() {

	upperDivider();

	std::cout << "-CREATE NEW TASK-" << endl;
	std::cout << "Please enter the following data about your task: " << endl;

	Task temp = task_manager.createTask(); 
	std::cout << "\n" << temp.toString() << std::endl;

	std::cout << "Task Created Sucessfully" << endl;

	lowerDivider(); 

	returnToContents();
}


void editTaskUI() {

	upperDivider();

	std::cout << "-EDIT A TASK-" << endl;

	int index_response = task_manager.selectTaskToEdit(general); 
	Task temp = general[index_response];

	std::cout << "You have selected task: " << temp.getName() << endl;
	std::cout << "Select an element to edit: " << endl << temp.toString() << endl;	


	std::cin >> edit_input;


	//need to catch false inputs here
	switch (edit_input) {
		case 1:
			upperDivider();
			task_manager.editName(temp, general);
			returnToEdit(); 
			lowerDivider();

		case 2:
			upperDivider();
			task_manager.editDeadline(temp, general);
			returnToEdit();
			lowerDivider();

		case 3:
			upperDivider();

			task_manager.editReminder(temp, general);
			returnToEdit();
			lowerDivider();

		case 4:
			upperDivider();

			task_manager.editLocation(temp, general);
			returnToEdit();
			lowerDivider();

		case 5:
			upperDivider();

			task_manager.editSubject(temp, general);
			returnToEdit();
			lowerDivider();

		case 6:
			upperDivider();

			task_manager.editNote(temp, general);
			returnToEdit();
			lowerDivider();

		case 7:
			upperDivider();
			task_manager.editUrgent(temp, general);
			returnToEdit();
			lowerDivider();

	}
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

	std::cout << "anything else?: " << endl;
	std::cout << "y / n" << endl;
	std::cout << std::string(2, '\n') << std::string(10, '-') << std::string(2, '\n');

	std::cin >> return_to_contents;

	while (return_to_contents != 'y' && return_to_contents != 'n') {
		std::cout << "y / n" << endl;
		std::cout << std::string(10, '-') << std::string(2, '\n');
		std::cin >> return_to_contents;
	}
	if (return_to_contents == 'y') {
		contents();
	}
	else {
		exit(0);
	}
}
void returnToEdit() {
	char return_to_edit;

	std::cout << std::string(10, '-') << std::string(2, '\n');

	std::cout << "edit anything else?: " << endl;
	std::cout << "y / n" << endl;
	std::cout << std::string(2, '\n') << std::string(10, '-') << std::string(2, '\n');

	std::cin >> return_to_edit;

	while (return_to_edit != 'y' && return_to_edit != 'n') {
		std::cout << "y / n" << endl;
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
