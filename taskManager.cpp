#include <iostream>
#include <string>
#include <vector>
#include "taskManager.h"
#include "task.h" 
//all the functionality for each taskmanager function is in the following files
//like a music mixer, everything goes through the task manager, but it doesnt actually do any of the functions
#include "create.h"
#include "edit.h"
#include "sort.h"
#include "delete_.h"

taskManager::taskManager() {

}
taskManager::taskManager(Task t) {

}
taskManager::~taskManager() {

}
 
//std::vector<Task> taskManager::pushGeneral() {
	//return general;  
//}

//general manager
//they take in a vector so that they can interact with the global vector
Task taskManager::createTask(){
	std::string create_name;
	int create_deadline;
	int create_reminder;
	std::string create_location;
	std::string create_subject;
	std::string create_note;

	std::cout << "Please enter the following data about your task: " << std::endl;
	std::cout << "Name: ";
	std::cin >> create_name;
	std::cout << "Deadline: ";
	std::cin >> create_deadline;
	std::cout << "Reminder: ";
	std::cin >> create_reminder;
	std::cout << "Location: ";
	std::cin >> create_location;
	std::cout << "Subject: ";
	std::cin >> create_subject;
	std::cout << "Note: ";
	std::cin >> create_note;

	Task temp(create_name, create_deadline, create_reminder, create_location, create_subject, false, create_note);
	 
	return temp;
}

Task taskManager::editTask(std::vector<Task> &general) {
	int edit_input;
	int selected_task_edit = selectTaskToEdit(general) - 1;
	
	//creates a copy of the task being edited and then erases the origional task
	Task temp = general[selected_task_edit];
	general.erase(general.begin() + selected_task_edit);

	std::cout << "You have selected task: " << temp.getName() << std::endl;
	std::cout << "Select an element to edit: " << std::endl << temp.toString() << std::endl;

	std::cin >> edit_input;
	switch (edit_input) {
	case 1:
		editName(temp);
		break;
	case 2:
		editDeadline(temp);
		break;
	case 3:
		editReminder(temp);
		break;
	case 4:
		editLocation(temp);
		break;
	case 5:
		editSubject(temp);
		break;
	case 6:
		editNote(temp);
		break; 
	case 7:
		editUrgent(temp);
		break; 
	}
	return temp;
}

std::vector<Task> taskManager::sortTask(std::vector<Task> general) {
	
	viewTasks(general);

	int selected_method = selectMethodToSort() - 1; 

	switch (selected_method) {
	case 1:
		std::cout << "Sorted by name: " << std::endl;
		vecSortName(general);
		break;
	case 2:
		std::cout << "Sorted by deadline: " << std::endl;
		vecSortDeadline(general);
		break;
	case 3:
		std::cout << "Sorted by reminder: " << std::endl;
		vecSortReminder(general);
		break;
	case 4:
		std::cout << "Sorted by location: " << std::endl;
		vecSortLocation(general);
		break;
	case 5:
		std::cout << "Sorted by marked as urgent: " << std::endl;
		vecSortUrgent(general);
		break;
	}
	return general;
}
Task taskManager::deleteTask(std::vector<Task> &general) {
	Task temp;
	return temp;
}

//editing manager


