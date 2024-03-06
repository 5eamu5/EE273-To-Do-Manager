#include <iostream>
#include <string>
#include <vector>
#include "taskManager.h"
#include "task.h"

taskManager::taskManager() {

}
taskManager::taskManager(Task t) {

}
taskManager::~taskManager() {

}
 
std::vector<Task> taskManager::pushGeneral() {
	return general;  
}

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
Task taskManager::editTask() {
	int edit_input;
	int index_response = selectTaskToEdit(general);
	Task temp = general[index_response];

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
Task taskManager::sortTask(std::vector<Task> vec) {
	Task temp;
	return temp;
}
Task taskManager::deleteTask(std::vector<Task> vec) {
	Task temp;
	return temp;
}

//editing manager
int taskManager::selectTaskToEdit(std::vector<Task> vec) {
	int index_response;

	std::cout << "Please select a Task to edit: " << std::endl;

	for (int i{ 0 }; i < general.size(); i++) { 
		std::cout << "Task " << i << ". " << general[i].getName() << std::endl;
	}
	std::cin >> index_response; 

	return index_response; 
}

void taskManager::editName(Task temp) {
	std::string edit_name;

	std::cout << "Current Name: " << temp.getName() << std::endl;
	std::cout << "Enter task new name: ";
	std::cin >> edit_name;
	temp.setName(edit_name);
	std::cout << std::endl;
	std::cout << "New Task Name: " << temp.getName();
}
void taskManager::editDeadline(Task temp) {
	int edit_deadline;

	std::cout << "Current Deadline: " << temp.getName() << std::endl;
	std::cout << "Enter task new Deadline: ";
	std::cin >> edit_deadline;
	temp.setDeadline(edit_deadline);
	std::cout << "New Task Deadline: " << temp.getDeadline();
}
void taskManager::editReminder(Task temp) {
	int edit_reminder;

	std::cout << "Current Reminder: " << temp.getName() << std::endl;
	std::cout << "Enter task new Reminder: ";
	std::cin >> edit_reminder;
	temp.setReminder(edit_reminder);
	std::cout << "New Task Reminder: " << temp.getReminder();
}
void taskManager::editLocation(Task temp) {
	std::string edit_location;

	std::cout << "Current Location: " << temp.getName() << std::endl;
	std::cout << "Enter task new Location: ";
	std::cin >> edit_location;
	temp.setLocation(edit_location);
	std::cout << "New Task Location: " << temp.getLocation();
}
void taskManager::editSubject(Task temp) {
	std::string edit_subject;

	std::cout << "Current Subject: " << temp.getName() << std::endl;
	std::cout << "Enter task new Subject: ";
	std::cin >> edit_subject;
	temp.setSubject(edit_subject);
	std::cout << "New Task Subject: " << temp.getSubject();
}
void taskManager::editNote(Task temp) {
	std::string edit_note;

	std::cout << "Current Note: " << temp.getName() << std::endl;
	std::cout << "Enter task new Note: ";
	std::cin >> edit_note;
	temp.setNote(edit_note);
	std::cout << "New Task Note: " << temp.getNote();
}
void taskManager::editUrgent(Task temp) {
	bool edit_urgent;

	std::cout << "Current Urgent: " << temp.getName() << std::endl;
	std::cout << "Enter task new Urgent: ";
	std::cin >> edit_urgent;
	temp.setUrgent(edit_urgent);
	std::cout << "New Task Urgent: " << temp.getUrgent();
}

