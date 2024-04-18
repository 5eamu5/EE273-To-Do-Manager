#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <thread>
#include "taskManager.h"
#include "task.h"


taskManager::taskManager() {

}
taskManager::taskManager(Task t) {

}
taskManager::~taskManager() {

}

//other
//prints all tasks in the general vector
void printVector(std::vector<Task> vec) {
	for (Task t : vec) {
		std::cout << "-Tasks-" << std::endl;
		t.toString();
	}
}
//prints all tasks in the overdue vector
void printOverdue(std::vector<Task> overdue_vec) {
	for (Task t : overdue_vec) {
		std::cout << "-Overdue Tasks-" << std::endl;
		t.toString();
	}
}
//custom <cctype> function to check that an entire string is a digit
bool taskisdigit(std::string str) {

	int length = str.length();

	for (int i{ 0 }; i < length; i++) {
		if (!isdigit(str[i])) {
			return 0;
		}
	}
	return 1;
} 

//creating
Task taskManager::createTask() {

	std::string create_name{ "" };

	struct tm create_deadline;
	std::string ec_dmin, ec_dhour, ec_dday, ec_dmon, ec_dyear; //error catching values 

	struct tm create_reminder;
	std::string ec_rmin, ec_rhour, ec_rday, ec_rmon, ec_ryear; //error catching 

	std::string create_location{ "" };

	std::string create_subject{ "" };

	std::string create_note{ "" };

	//testing error catching here
	//string inputs need to use .ignore() to skip white spaces, and getline for multiple word inputs
	//integer inputs are held in an 'error check' variable (ec_), to check for int with isdigit(), and check the limits for the tm_time struct
	std::cout << "Please enter the following data about your task: " << std::endl;

	//name
	std::cout << "Name: ";
	std::cin.ignore();  
	getline(std::cin, create_name); 
	std::cout.flush(); 

	//deadline
	std::cout << "Deadline Hour (0-23): ";
	std::cin >> ec_dhour;
	while (!taskisdigit(ec_dhour) or  0 > stoi(ec_dhour) or 23 < stoi(ec_dhour)) {
		std::cout << "Only integer value within limits accepted. Deadline Hour (0-23): ";
		std::cin >> ec_dhour;
	}
	create_deadline.tm_hour = stoi(ec_dhour); 

	std::cout << "Deadline Minute (0-59): ";
	std::cin >> ec_dmin;
	while (!taskisdigit(ec_dmin) or 0 > stoi(ec_dmin) or stoi(ec_dmin) > 59) { 
		std::cout << "Only integer value within limits accepted. Deadline Minute (0-59): ";
		std::cin >> ec_dmin; 
	}
	create_deadline.tm_min = stoi(ec_dmin); 

	std::cout << "Deadline Day of the month (1-31): ";
	std::cin >> ec_dday;
	while (!taskisdigit(ec_dday) or 1 > stoi(ec_dday) or stoi(ec_dday) > 31) {
		std::cout << "Only integer value within limits accepted. Deadline Day (1-31): ";
		std::cin >> ec_dday;
	}
	create_deadline.tm_mday = stoi(ec_dday);

	std::cout << "Deadline Month (1-12): ";
	std::cin >> ec_dmon;
	while (!taskisdigit(ec_dmon) or 1 > stoi(ec_dmon) or stoi(ec_dmon) > 31) {
		std::cout << "Only integer value within limits accepted. Deadline Month (1-12): ";
		std::cin >> ec_dmon;
	}
	create_deadline.tm_mon = stoi(ec_dmon) - 1; 

	std::cout << "Deadline Year (2024 onwards): ";
	std::cin >> ec_dyear;
	while (!taskisdigit(ec_dyear) or 2024 > stoi(ec_dyear)) {
		std::cout << "Only integer value within limits accepted. Deadline Year (2024 onwards): ";
		std::cin >> ec_dyear;
	}
	create_deadline.tm_year = stoi(ec_dyear) - 1900; 

	//reminder
	std::cout << "Reminder Hour (0-23): ";
	std::cin >> ec_rhour;
	while (!taskisdigit(ec_rhour) or 0 > stoi(ec_rhour) or stoi(ec_rhour) > 23) {
		std::cout << "Only integer value within limits accepted. Reminder Hour (0-23): ";
		std::cin >> ec_rhour;
	}
	create_reminder.tm_hour = stoi(ec_rhour);

	std::cout << "Reminder Minute (0-59): ";
	std::cin >> ec_rmin;
	while (!taskisdigit(ec_rmin) or 0 > stoi(ec_rmin) or stoi(ec_rmin) > 59) {
		std::cout << "Only integer value within limits accepted. Reminder Minute (0-59): ";
		std::cin >> ec_rmin;
	}
	create_reminder.tm_min = stoi(ec_rmin);

	std::cout << "Reminder Day of the month (1-31): ";
	std::cin >> ec_rday;
	while (!taskisdigit(ec_rday) or 1 > stoi(ec_rday) or stoi(ec_rday) > 31) {
		std::cout << "Only integer value within limits accepted. Reminder Day (1-31): ";
		std::cin >> ec_rday;
	}
	create_reminder.tm_mday = stoi(ec_rday);

	std::cout << "Reminder Month (1-12): ";
	std::cin >> ec_rmon;
	while (!taskisdigit(ec_rmon) or 1 > stoi(ec_rmon) or stoi(ec_rmon) > 31) {
		std::cout << "Only integer value within limits accepted. Reminder Month (1-12): ";
		std::cin >> ec_rmon;
	}
	create_reminder.tm_mon = stoi(ec_rmon) - 1;

	std::cout << "Reminder Year (2024 onwards): ";
	std::cin >> ec_ryear;
	while (!taskisdigit(ec_ryear) or 2024 > stoi(ec_ryear)) {
		std::cout << "Only integer value within limits accepted. Reminder Year (2024 onwards): ";
		std::cin >> ec_ryear;
	}
	create_reminder.tm_year = stoi(ec_ryear) - 1900;

	//location
	//need to ignore previous console text, and flush the console after input
	std::cin.ignore(); 
	std::cout << "Location: ";
	std::cout.flush();
	getline(std::cin, create_location);

	//subject
	std::cout << "Subject: ";
	std::cout.flush();
	getline(std::cin, create_subject);

	//note
	std::cout << "Note: ";
	std::cout.flush();
	getline(std::cin, create_note);

	create_deadline.tm_sec = 0; //need to initialise seconds otherwise it will default to random memory value
	create_reminder.tm_sec = 0;

	Task temp(create_name, create_deadline, create_reminder, create_location, create_subject, 0, create_note);

	return temp;
}

//editing
Task taskManager::editTask(std::vector<Task>& general) {
	int edit_input;
	int selected_task_edit = selectTaskToEdit(general) - 1;


	//creates a copy of the task being edited and then erases the origional task
	Task temp = general[selected_task_edit];
	general.erase(general.begin() + selected_task_edit);

	std::cout << "You have selected task: " << temp.getName() << std::endl;
	std::cout << "Select an element to edit: " << std::endl;
	temp.toString();

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
	case 8:
		break; 	 //this occurs when the user inputs '0' into select task to edit
	}
	return temp;
}

//chooses which task the user wants to edit 
int selectTaskToEdit(std::vector<Task>& general) {
	int selected_task_edit;

	std::cout << "Please select a Task to edit: " << std::endl;

	for (int i{ 0 }; i < general.size(); i++) {
		std::cout << "Task " << i + 1 << ". " << general[i].getName() << std::endl;
	}
	std::cout << std::endl << "Press '0' to exit" << std::endl; 

	std::cin >> selected_task_edit;

	//ugly work-around but edit task breaks if 0 is input because it relies on the return value to index your task 
	//if it returns 0, it searches for general[-1] whicb fails
	//set it to 8 to put it at the end of case statement 
	if (selected_task_edit == 0) {
		selected_task_edit = 8;
	}

	return selected_task_edit;
}

//all editing functions
void editName(Task& temp) {
	std::string edit_name;

	std::cout << "Current Name: " << temp.getName() << std::endl;
	std::cout << "New Name: ";
	std::cin.ignore();
	getline(std::cin, edit_name); 
	temp.setName(edit_name);
	std::cout << std::endl;
	std::cout << "New Task Name: " << temp.getName();
}
void editDeadline(Task& temp) {
	struct tm edit_deadline;
	std::string ec_dmin, ec_dhour, ec_dday, ec_dmon, ec_dyear; //error catching values 

	std::cout << "Current Deadline: " << temp.disDeadline() << std::endl; 
	std::cout << "Deadline Hour (0-23): ";
	std::cin >> ec_dhour;
	while (!taskisdigit(ec_dhour) or 0 > stoi(ec_dhour) or 23 < stoi(ec_dhour)) {
		std::cout << "Only integer value within limits accepted. Deadline Hour (0-23): ";
		std::cin >> ec_dhour;
	}
	edit_deadline.tm_hour = stoi(ec_dhour);

	std::cout << "Deadline Minute (0-59): ";
	std::cin >> ec_dmin;
	while (!taskisdigit(ec_dmin) or 0 > stoi(ec_dmin) or stoi(ec_dmin) > 59) {
		std::cout << "Only integer value within limits accepted. Deadline Minute (0-59): ";
		std::cin >> ec_dmin;
	}
	edit_deadline.tm_min = stoi(ec_dmin);

	std::cout << "Deadline Day of the month (1-31): ";
	std::cin >> ec_dday;
	while (!taskisdigit(ec_dday) or 1 > stoi(ec_dday) or stoi(ec_dday) > 31) {
		std::cout << "Only integer value within limits accepted. Deadline Day (1-31): ";
		std::cin >> ec_dday;
	}
	edit_deadline.tm_mday = stoi(ec_dday);

	std::cout << "Deadline Month (1-12): ";
	std::cin >> ec_dmon;
	while (!taskisdigit(ec_dmon) or 1 > stoi(ec_dmon) or stoi(ec_dmon) > 31) {
		std::cout << "Only integer value within limits accepted. Deadline Month (1-12): ";
		std::cin >> ec_dmon;
	}
	edit_deadline.tm_mon = stoi(ec_dmon) - 1;

	std::cout << "Deadline Year (2024 onwards): ";
	std::cin >> ec_dyear;
	while (!taskisdigit(ec_dyear) or 2024 > stoi(ec_dyear)) {
		std::cout << "Only integer value within limits accepted. Deadline Year (2024 onwards): ";
		std::cin >> ec_dyear;
	}
	edit_deadline.tm_year = stoi(ec_dyear) - 1900;

	edit_deadline.tm_sec = 0;  

	temp.setDeadline(edit_deadline); 

	std::cout << "New Task Deadline: " << temp.disDeadline();
}
void editReminder(Task& temp) {
	struct tm edit_reminder;
	std::string ec_rmin, ec_rhour, ec_rday, ec_rmon, ec_ryear; //error catching  

	std::cout << "Current Reminder: " << temp.disReminder() << std::endl;
	std::cout << "Reminder Hour (0-23): ";
	std::cin >> ec_rhour;
	while (!taskisdigit(ec_rhour) or 0 > stoi(ec_rhour) or stoi(ec_rhour) > 23) {
		std::cout << "Only integer value within limits accepted. Reminder Hour (0-23): ";
		std::cin >> ec_rhour;
	}
	edit_reminder.tm_hour = stoi(ec_rhour);

	std::cout << "Reminder Minute (0-59): ";
	std::cin >> ec_rmin;
	while (!taskisdigit(ec_rmin) or 0 > stoi(ec_rmin) or stoi(ec_rmin) > 59) {
		std::cout << "Only integer value within limits accepted. Reminder Minute (0-59): ";
		std::cin >> ec_rmin;
	}
	edit_reminder.tm_min = stoi(ec_rmin);

	std::cout << "Reminder Day of the month (1-31): ";
	std::cin >> ec_rday;
	while (!taskisdigit(ec_rday) or 1 > stoi(ec_rday) or stoi(ec_rday) > 31) {
		std::cout << "Only integer value within limits accepted. Reminder Day (1-31): ";
		std::cin >> ec_rday;
	}
	edit_reminder.tm_mday = stoi(ec_rday);

	std::cout << "Reminder Month (1-12): ";
	std::cin >> ec_rmon;
	while (!taskisdigit(ec_rmon) or 1 > stoi(ec_rmon) or stoi(ec_rmon) > 31) {
		std::cout << "Only integer value within limits accepted. Reminder Month (1-12): ";
		std::cin >> ec_rmon;
	}
	edit_reminder.tm_mon = stoi(ec_rmon) - 1;

	std::cout << "Reminder Year (2024 onwards): ";
	std::cin >> ec_ryear;
	while (!taskisdigit(ec_ryear) or 2024 > stoi(ec_ryear)) {
		std::cout << "Only integer value within limits accepted. Reminder Year (2024 onwards): ";
		std::cin >> ec_ryear;
	}
	edit_reminder.tm_year = stoi(ec_ryear) - 1900;

	edit_reminder.tm_sec = 0; 

	temp.setReminder(edit_reminder); 

	std::cout << "New Task Reminder: " << temp.disDeadline();
}
void editLocation(Task& temp) {
	std::string edit_location;

	std::cout << "Current Location: " << temp.getName() << std::endl;
	std::cout << "New Location: ";
	std::cin.ignore();
	getline(std::cin, edit_location);
	temp.setLocation(edit_location); 
	std::cout << "New Task Location: " << temp.getLocation(); 
}
void editSubject(Task& temp) {
	std::string edit_subject;

	std::cout << "Current Subject: " << temp.getName() << std::endl;
	std::cout << "New Subject: ";
	std::cin.ignore(); 
	getline(std::cin, edit_subject); 
	temp.setSubject(edit_subject); 
	std::cout << "New Task Subject: " << temp.getSubject();
}
void editNote(Task& temp) {
	std::string edit_note;

	std::cout << "Current Note: " << temp.getName() << std::endl;
	std::cout << "New Note: ";
	std::cin.ignore();
	getline(std::cin, edit_note); 
	std::cout << "New Task Note: " << temp.getNote();
}
void editUrgent(Task& temp) {
	char edit_urgent;

	std::cout << "Current Task Status: " << std::boolalpha << temp.getUrgent() << std::endl; 
	std::cout << "Mark Task as Urgent? (y/n): ";
	std::cin >> edit_urgent;

	while (edit_urgent != 'y' && edit_urgent != 'n') { 
		std::cout << "y / n: " << std::endl;
		std::cin >> edit_urgent;
	}
	if (edit_urgent == 'y') {
		temp.setUrgent(1);
	}
	else {
		temp.setUrgent(0); 
	}
	std::cout << "New Task Status: " << std::boolalpha << temp.getUrgent() << std::endl; 
}

//sorting
void taskManager::sortTask(std::vector<Task> general, std::vector<Task> overdue_tasks) {

	//when program is run, 6 vectors created sorted by member
	//switch case calls one of these vecors
	std::vector<Task> sorted_name = vecSortName(general);
	std::vector<Task> sorted_deadline = vecSortDeadline(general);
	std::vector<Task> sorted_reminder = vecSortReminder(general);
	std::vector<Task> sorted_location = vecSortLocation(general);
	std::vector<Task> sorted_subject = vecSortSubject(general);
	std::vector<Task> sorted_urgent = vecSortUrgent(general);

	printVector(general);
	printOverdue(overdue_tasks);

	int selected_method = selectMethodToSort();

	switch (selected_method) {
	case 0:
		break; 
	case 1:
		std::cout << "Sorted by name: " << std::endl;
		printVector(sorted_name);
			break;
	case 2:
		std::cout << "Sorted by deadline: " << std::endl;
		printVector(sorted_deadline);
		break;
	case 3:
		std::cout << "Sorted by reminder: " << std::endl;
		printVector(sorted_reminder);
		break;
	case 4:
		std::cout << "Sorted by location: " << std::endl;
		printVector(sorted_location);
		break;
	case 5:
		std::cout << "Sorted by subject: " << std::endl;
		printVector(sorted_subject);
		break;
	case 6:
		std::cout << "Sorted by marked as urgent: " << std::endl;
		printVector(sorted_urgent);
		break;
	case 7:
		std::cout << "Printed Overdue Tasks: " << std::endl;
		printOverdue(overdue_tasks);
		break;
	}
}

//choose which member to sort by
int selectMethodToSort() {
	int selected_method;
	std::cout << std::endl << "Please select a Method to Sort: " << std::endl;
	std::cout << "1. Name" << std::endl;
	std::cout << "2. Deadline" << std::endl;
	std::cout << "3, Reminder" << std::endl;
	std::cout << "4. Location" << std::endl;
	std::cout << "5. Subject" << std::endl;
	std::cout << "6. Marked as Urgent" << std::endl;
	std::cout << "7. Print Overdue" << std::endl;
	std::cout << std::endl << "Press '0' to exit" << std::endl;	std::cin >> selected_method;
	return selected_method;
}
bool compareName(Task& prev, Task& next) {
	return prev.getName() < next.getName();
}
bool compareDeadline(Task& prev, Task& next) {
	return prev.unixDeadline() < next.unixDeadline();
}
bool compareReminder(Task& prev, Task& next) {
	return prev.unixReminder() < next.unixReminder();
}
bool compareLocation(Task& prev, Task& next) {
	return prev.getLocation() < next.getLocation();
}
bool compareSubject(Task& prev, Task& next) {
	return prev.getSubject() < next.getSubject();
}
bool compareUrgent(Task& prev, Task& next) {
	return prev.getUrgent() > next.getUrgent();
}

std::vector<Task> vecSortName(std::vector<Task>& general) {
	std::sort(general.begin(), general.end(), compareName);
	return general;
}
std::vector<Task> vecSortDeadline(std::vector<Task>& general) {
	std::sort(general.begin(), general.end(), compareDeadline);
	return general;
}
std::vector<Task> vecSortReminder(std::vector<Task>& general) {
	std::sort(general.begin(), general.end(), compareReminder);
	return general;
}
std::vector<Task> vecSortLocation(std::vector<Task>& general) {
	std::sort(general.begin(), general.end(), compareLocation);
	return general;
}
std::vector<Task> vecSortSubject(std::vector<Task>& general) {
	std::sort(general.begin(), general.end(), compareSubject);
	return general;
}
std::vector<Task> vecSortUrgent(std::vector<Task>& general) {
	std::sort(general.begin(), general.end(), compareUrgent);
	return general;
}

//deleting
void taskManager::deleteTask(std::vector<Task>& general) { 
	int selected_task_delete = selectTaskToDelete(general) - 1;
	Task temp = general[selected_task_delete];

	//confirmation for deleting
	char del_conf;
	std::cout << "Are you sure you want to delete task? y/n: " << temp.getName() << std::endl;
	std::cin >> del_conf;

	while (del_conf != 'y' and del_conf != 'n') {
		std::cout << "y/n: " << std::endl;
		std::cin >> del_conf;
	};

	if (del_conf == 'y') {
		general.erase(general.begin() + selected_task_delete);
	}
	else {
		std::cout << "cancelled deletion of: " << temp.getName();
	}
}
int selectTaskToDelete(std::vector<Task> general) {
	int selected_task_delete;

	std::cout << "Please select a Task to delete: " << std::endl;

	for (int i{ 0 }; i < general.size(); i++) {
		std::cout << "Task " << i + 1 << ". " << general[i].getName() << std::endl;
	}
	std::cin >> selected_task_delete;
	return selected_task_delete;
}
