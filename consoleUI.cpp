#include <iostream>
#include <string>
#include <vector>
#include "task.h"
#include "consoleUI.h"
using namespace std;

std::vector<Task> general;

void contents() {

	int contents_input;

	cout << "TODO MANAGER" << endl;
	cout << "Please select functionality: " << endl;
	cout << "1. create task" << endl;
	cout << "2. edit task" << endl;
	cout << "Press '0' to quit" << endl;

	while (1) {
		
		cin >> contents_input;

		switch (contents_input) {
		case 0:
			break;
		case 1:
			createTask();
			break;
		case 2:
			editTask();
			break;
		default:
			cout << "please enter an integer to represent the desired function: ";
			cin >> contents_input;
		}
		break;
	}
}

void createTask() {
	std::string create_name; 
	int create_deadline; 
	int create_reminder; 
	std::string create_location; 
	std::string create_subject;
	std::string create_note;

	cout << "Please enter the following data about your task: " << endl;

	cout << "Name: " << endl;
	cin >> create_name;
	cout << "Deadline: " << endl; 
	cin >> create_deadline;
	cout << "Reminder: " << endl; 
	cin >> create_reminder;
	cout << "Location: " << endl; 
	cin >> create_location;
	cout << "Subject: " << endl; 
	cin >> create_subject;
	cout << "Note: " << endl;
	cin >> create_note; 

	Task temp(create_name, create_deadline, create_reminder, create_location, create_subject, false, create_note);
	//general.push_back(temp); 
	
	std::cout << temp.toString() << std::endl;
	
}

void editTask() {

}
void sortTask() {

}
void deleteTask() {

}

void selectTaskToEdit() {

}
void editName() {

}
void editDeadline() {

}
void editLocation() {

}
void editSubject() {

}
void editUrgent() {

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

void selectTaskToDelete() {

}
