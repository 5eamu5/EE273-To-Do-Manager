#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "taskManager.h"
#include "task.h"


taskManager::taskManager() {

}
taskManager::taskManager(Task t) {

}
taskManager::~taskManager() {

}

//other
void printVector(std::vector<Task> vec) {
	for (Task t : vec) {
		std::cout << "-Task-" << std::endl;
		std::cout << t.toString() << std::endl;
	}
}

//creating
Task taskManager::createTask(){
	std::string create_name;
	int Dhour;
	int Dmin;
	int Dday;
	int Dmonth;
	int Dyear;
	int Rhour;
	int Rmin;
	int Rday;
	int Rmonth;
	int Ryear;
	std::string create_location;
	std::string create_subject;
	std::string create_note;

	std::cout << "Please enter the following data about your task: " << std::endl;
	std::cout << "Name: ";
	std::cin >> create_name;
	std::cout << "Deadline Hour: ";
	std::cin >> Dhour;
	std::cout << "Deadline Minute: ";
	std::cin >> Dmin;
	std::cout << "Deadline Day of the month: ";
	std::cin >> Dday;
	std::cout << "Deadline Month (March = 3, December = 12): ";
	std::cin >> Dmonth;
	std::cout << "Deadline Year (eg: 2024): ";
	std::cin >> Dyear;
	std::cout << "Reminder Hour: ";
	std::cin >> Rhour;
	std::cout << "Reminder Minute: ";
	std::cin >> Rmin;
	std::cout << "Reminder Day of the month: ";
	std::cin >> Rday;
	std::cout << "Reminder Month (March = 3, December = 12): ";
	std::cin >> Rmonth;
	std::cout << "Reminder Year (eg: 2024): ";
	std::cin >> Ryear;
	std::cout << "Location: ";
	std::cin >> create_location;
	std::cout << "Subject: ";
	std::cin >> create_subject;
	std::cout << "Note: ";
	std::cin >> create_note;

	Task temp(create_name, Dhour, Dmin, Dday, Dmonth, Dyear, Rhour, Rmin, Rday, Rmonth, Ryear, create_location, create_subject, 0, create_note);
	 
	return temp;
}

//editing
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

int selectTaskToEdit(std::vector<Task>& general) {
	int selected_task_edit;

	std::cout << "Please select a Task to edit: " << std::endl;

	for (int i{ 0 }; i < general.size(); i++) {
		std::cout << "Task " << i + 1 << ". " << general[i].getName() << std::endl;
	}
	std::cout << "0. Return to menu." << std::endl;

	std::cin >> selected_task_edit;
	return selected_task_edit;
}
void editName(Task& temp) {
	std::string edit_name;

	std::cout << "Current Name: " << temp.getName() << std::endl;
	std::cout << "Enter task new name: ";
	std::cin >> edit_name;
	temp.setName(edit_name);
	std::cout << std::endl;
	std::cout << "New Task Name: " << temp.getName();
}
void editDeadline(Task& temp) {
	int edit_Dhour;
	int edit_Dmin; 
	int edit_Dday; 
	int edit_Dmonth; 
	int edit_Dyear; 

	std::cout << "Current Deadline: " << temp.getDeadline() << std::endl;
	std::cout << "Enter task new Deadline: ";
	std::cout << "Deadline Hour: ";
	std::cin >> edit_Dhour; 
	std::cout << "Deadline Minute: ";
	std::cin >> edit_Dmin; 
	std::cout << "Deadline Day of the month: ";
	std::cin >> edit_Dday; 
	std::cout << "Deadline Month (March = 3, December = 12): ";
	std::cin >> edit_Dmonth; 
	std::cout << "Deadline Year (eg: 2024): ";
	std::cin >> edit_Dyear;  

	temp.setDhour(edit_Dhour); 
	temp.setDmin(edit_Dmin); 
	temp.setDday(edit_Dday); 
	temp.setDmonth(edit_Dmonth);  
	temp.setDyear(edit_Dyear); 

	std::cout << "New Task Deadline: " << temp.getDeadline(); 
}
void editReminder(Task& temp) {
	int edit_Rhour;
	int edit_Rmin;
	int edit_Rday;
	int edit_Rmonth;
	int edit_Ryear;

	std::cout << "Current Reminder: " << temp.getReminder() << std::endl;
	std::cout << "Enter task new Reminder: ";
	std::cout << "Reminder Hour: ";
	std::cin >> edit_Rhour;
	std::cout << "Reminder Minute: ";
	std::cin >> edit_Rmin;
	std::cout << "Reminder Day of the month: ";
	std::cin >> edit_Rday;
	std::cout << "Reminder Month (March = 3, December = 12): ";
	std::cin >> edit_Rmonth;
	std::cout << "Reminder Year (eg: 2024): ";
	std::cin >> edit_Ryear;

	temp.setRhour(edit_Rhour); 
	temp.setRmin(edit_Rmin); 
	temp.setRday(edit_Rday); 
	temp.setRmonth(edit_Rmonth); 
	temp.setRyear(edit_Ryear); 

	std::cout << "New Task Reminder: " << temp.getReminder();
}
void editLocation(Task& temp) {
	std::string edit_location;

	std::cout << "Current Location: " << temp.getName() << std::endl;
	std::cout << "Enter task new Location: ";
	std::cin >> edit_location;
	temp.setLocation(edit_location);
	std::cout << "New Task Location: " << temp.getLocation();
}
void editSubject(Task& temp) {
	std::string edit_subject;

	std::cout << "Current Subject: " << temp.getName() << std::endl;
	std::cout << "Enter task new Subject: ";
	std::cin >> edit_subject;
	temp.setSubject(edit_subject);
	std::cout << "New Task Subject: " << temp.getSubject();
}
void editNote(Task& temp) {
	std::string edit_note;

	std::cout << "Current Note: " << temp.getName() << std::endl;
	std::cout << "Enter task new Note: ";
	std::cin >> edit_note;
	temp.setNote(edit_note);
	std::cout << "New Task Note: " << temp.getNote();
}
void editUrgent(Task& temp) {
	bool edit_urgent;

	std::cout << "Current Urgent: " << temp.getName() << std::endl;
	std::cout << "Enter task new Urgent: ";
	std::cin >> edit_urgent;
	temp.setUrgent(edit_urgent);
	std::cout << "New Task Urgent: " << temp.getUrgent();
}

//sorting
void taskManager::sortTask(std::vector<Task> general) {
	
	std::vector<Task> sorted_name = vecSortName(general);
	std::vector<Task> sorted_deadline = vecSortDeadline(general);
	std::vector<Task> sorted_reminder = vecSortReminder(general);
	std::vector<Task> sorted_location = vecSortLocation(general);
	std::vector<Task> sorted_urgent = vecSortUrgent(general);

	printVector(general);

	int selected_method = selectMethodToSort(); 

	switch (selected_method) {
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
		std::cout << "Sorted by marked as urgent: " << std::endl;
		printVector(sorted_urgent);
		break;
	}
}

int selectMethodToSort() {
	int selected_method;
	std::cout << std::endl << "Please select a Method to Sort: " << std::endl;
	std::cout << "1. Name" << std::endl;
	std::cout << "2. Deadline" << std::endl;
	std::cout << "3, Reminder" << std::endl;
	std::cout << "4. Location" << std::endl;
	std::cout << "5. Subject" << std::endl;
	std::cout << "6. Marked as Urgent" << std::endl;
	std::cout << "0. Return to menu." << std::endl;	std::cin >> selected_method;
	return selected_method;
}
bool compareName(Task& prev, Task& next) {
	return prev.getName() < next.getName();
}

bool compareDeadline(Task& prev, Task& next) {
	if (prev.getDyear() < next.getDyear()) {
		return 1;
	}
	else if (prev.getDyear() > next.getDyear()) {
		return 0;
	}
	else {
		if (prev.getDmonth() < next.getDmonth()) {
			return 1;
		}
		else if (prev.getDmonth() > next.getDmonth()) {
			return 0;
		}
		else {
			if (prev.getDday() < next.getDday()) {
				return 1;
			}
			else if (prev.getDday() > next.getDday()) {
				return 0;
			}
			else {
				if (prev.getDhour() < next.getDhour()) {
					return 1;
				}
				else if (prev.getDday() > next.getDday()) {
					return 0;
				}
				else {
					if (prev.getDmin() <= next.getDmin()) {
						return 1;
					}
					else {
						return 0;
					}
				}
			}
		}
	}
}

bool compareReminder(Task& prev, Task& next) {
	if (prev.getRyear() < next.getRyear()) {
		return 1;
	}
	else if (prev.getRyear() > next.getRyear()) {
		return 0;
	}
	else {
		if (prev.getRmonth() < next.getRmonth()) {
			return 1;
		}
		else if (prev.getRmonth() > next.getRmonth()) {
			return 0;
		}
		else {
			if (prev.getRday() < next.getRday()) {
				return 1;
			}
			else if (prev.getRday() > next.getRday()) {
				return 0;
			}
			else {
				if (prev.getRhour() < next.getRhour()) {
					return 1;
				}
				else if (prev.getRday() > next.getRday()) {
					return 0;
				}
				else {
					if (prev.getRmin() <= next.getRmin()) {
						return 1;
					}
					else {
						return 0;
					}
				}
			}
		}
	}
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

std::vector<Task> vecSortName(std::vector<Task> &general) {
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
void taskManager::deleteTask(std::vector<Task> &general) {
	int selected_task_delete = selectTaskToDelete(general) - 1; 
	Task temp = general[selected_task_delete];

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




