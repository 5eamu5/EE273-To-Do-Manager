#include <iostream>
#include <string>
#include <vector>
#include "task.h"
#include "consoleUI.h"
#include "editTask.h"
#include "sortTask.h"
#include "deleteTask.h"

using namespace std;
std::vector<Task> general;

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
		createTask();
		break;
	case 2:
		editTask();
		break;
	case 3:
		deleteTask();
		break;
	default:
		std::cout << "please enter an integer between 1 and 4 to represent the desired function" << endl;
		contents();
	}
			
}

void createTask() {

	//local variables to store user inputs
	//used to construct temporary task object
	//temporary task 'temp' is then added to the global vector 'general'
	//createTask() can then be called again with fresh variables as the created object is stored in global container

	std::string create_name;
	int create_deadline;
	int create_reminder;
	std::string create_location;
	std::string create_subject;
	std::string create_note;

	upperDivider();

	std::cout << "-CREATE NEW TASK-" << endl;
	std::cout << "Please enter the following data about your task: " << endl;

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
	general.push_back(temp); 
	
	std::cout << "\n" << temp.toString() << std::endl;
	std::cout << "Task Created Sucessfully" << endl;

	lowerDivider(); 

	returnToContents();
}


void editTask() {

	int edit_input;

	upperDivider();

	std::cout << "-EDIT A TASK-" << endl;

	int index_response = selectTaskToEdit(general);
	Task temp = general[index_response];

	std::cout << "You have selected task: " << temp.getName() << endl;
	std::cout << "Select an element to edit: " << endl << temp.toString() << endl;	

	lowerDivider();

	std::cin >> edit_input;

	//need to catch false inputs here
	switch (edit_input) {
		case 1:
			editName(temp);
			returnToEdit(); 
		case 2:
			editDeadline(temp);
			returnToEdit();
		case 3:
			editReminder(temp);
			returnToEdit();
		case 4:
			editLocation(temp);
			returnToEdit();
		case 5:
			editSubject(temp); 
			returnToEdit();
		case 6:
			editNote(temp);
			returnToEdit();
		case 7:
			editUrgent(temp); 
			returnToEdit();
	}
}

int selectTaskToEdit(std::vector<Task> general) {
	int index_response;

	std::cout << "Please select a Task to edit: " << endl;

	for (int i{ 0 }; i < general.size(); i++) {
		std::cout << "Task " << i << ". " << general[i].getName() << endl;
	}
	std::cin >> index_response;

	return index_response;
}

void editName(Task temp) { 
	std::string edit_name;
	
	upperDivider();
	std::cout << "Current Name: " << temp.getName() << endl;
	std::cout << "Enter task new name: ";
	std::cin >> edit_name;
	temp.setName(edit_name);
	std::cout << endl;
	std::cout << "New Task Name: " << temp.getName();
	lowerDivider();
}
void editDeadline(Task temp) {
	int edit_deadline;

	upperDivider();
	std::cout << "Current Deadline: " << temp.getName() << endl;
	std::cout << "Enter task new Deadline: ";
	std::cin >> edit_deadline;
	temp.setDeadline(edit_deadline);
	std::cout << "New Task Deadline: " << temp.getDeadline();
	lowerDivider();
}
void editReminder(Task temp) {
	int edit_reminder;

	upperDivider();
	std::cout << "Current Reminder: " << temp.getName() << endl;
	std::cout << "Enter task new Reminder: ";
	std::cin >> edit_reminder;
	temp.setReminder(edit_reminder);
	std::cout << "New Task Reminder: " << temp.getReminder();
	lowerDivider(); 
}
void editLocation(Task temp) {
	std::string edit_location;

	upperDivider();
	std::cout << "Current Location: " << temp.getName() << endl;
	std::cout << "Enter task new Location: ";
	std::cin >> edit_location;
	temp.setLocation(edit_location);
	std::cout << "New Task Location: " << temp.getLocation();
	lowerDivider(); 
}
void editSubject(Task temp) {
	std::string edit_subject;

	upperDivider();
	std::cout << "Current Subject: " << temp.getName() << endl;
	std::cout << "Enter task new Subject: ";
	std::cin >> edit_subject;
	temp.setSubject(edit_subject);
	std::cout << "New Task Subject: " << temp.getSubject();
	lowerDivider();
}
void editNote(Task temp) {
	std::string edit_note;
	
	upperDivider();
	std::cout << "Current Note: " << temp.getName() << endl;
	std::cout << "Enter task new Note: ";
	std::cin >> edit_note;
	temp.setNote(edit_note);
	std::cout << "New Task Note: " << temp.getNote();
	lowerDivider(); 
}
void editUrgent(Task temp) {
	bool edit_urgent;

	upperDivider(); 
	std::cout << "Current Urgent: " << temp.getName() << endl;
	std::cout << "Enter task new Urgent: ";
	std::cin >> edit_urgent;
	temp.setUrgent(edit_urgent); 
	std::cout << "New Task Urgent: " << temp.getUrgent();
	lowerDivider(); 
}


//everything above finished
//nothing below started yet 

void sortTask() {

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


void deleteTask() {

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
		editTask();
	}
	else {
		contents();
	}
}
void returnToSort() {

}

void upperDivider() {
	std::cout << std::string(2, '\n') << std::string(10, '-') << endl;
	std::cout << std::string(10, '*') << std::string(2, '\n');
}
void lowerDivider() { 
	std::cout << std::string(2, '\n') << std::string(10, '^') << endl;
	std::cout << std::string(10, '-') << std::string(2, '\n');
}
