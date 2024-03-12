#include <iostream>
#include <vector>
#include "edit.h"
#include "task.h"

int selectTaskToEdit(std::vector<Task> &general) { 
	int selected_task_edit;

	std::cout << "Please select a Task to edit: " << std::endl;

	for (int i{ 0 }; i < general.size(); i++) {
		std::cout << "Task " << i + 1 << ". " << general[i].getName() << std::endl;
	}
	std::cin >> selected_task_edit;
	return selected_task_edit;
}

void editName(Task &temp) {
	std::string edit_name;

	std::cout << "Current Name: " << temp.getName() << std::endl;
	std::cout << "Enter task new name: ";
	std::cin >> edit_name;
	temp.setName(edit_name);
	std::cout << std::endl;
	std::cout << "New Task Name: " << temp.getName();
}
void editDeadline(Task &temp) {
	int Dhour;
	int Dmin;
	int Dday;
	int Dmonth;
	int Dyear;

	std::cout << "Current Deadline: " << temp.getDeadline() << std::endl;
	std::cout << "Enter task new Deadline: ";
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

	temp.setDhour(Dhour);
	temp.setDmin(Dhour);
	temp.setDday(Dhour);
	temp.setDmonth(Dhour);
	temp.setDyear(Dhour);

	std::cout << "New Task Deadline: " << temp.getDeadline();
}
void editReminder(Task &temp) {
	int Rhour;
	int Rmin;
	int Rday;
	int Rmonth;
	int Ryear;

	std::cout << "Current Reminder: " << temp.getReminder() << std::endl;
	std::cout << "Enter task new Reminder: ";
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

	temp.setRhour(Rhour);
	temp.setRmin(Rhour);
	temp.setRday(Rhour);
	temp.setRmonth(Rhour);
	temp.setRyear(Rhour);

	std::cout << "New Task Reminder: " << temp.getReminder();
}
void editLocation(Task &temp) {
	std::string edit_location;

	std::cout << "Current Location: " << temp.getName() << std::endl;
	std::cout << "Enter task new Location: ";
	std::cin >> edit_location;
	temp.setLocation(edit_location);
	std::cout << "New Task Location: " << temp.getLocation();
}
void editSubject(Task &temp) {
	std::string edit_subject;

	std::cout << "Current Subject: " << temp.getName() << std::endl;
	std::cout << "Enter task new Subject: ";
	std::cin >> edit_subject;
	temp.setSubject(edit_subject);
	std::cout << "New Task Subject: " << temp.getSubject();
}
void editNote(Task &temp) {
	std::string edit_note;

	std::cout << "Current Note: " << temp.getName() << std::endl;
	std::cout << "Enter task new Note: ";
	std::cin >> edit_note;
	temp.setNote(edit_note);
	std::cout << "New Task Note: " << temp.getNote();
}
void editUrgent(Task &temp) {
	bool edit_urgent;

	std::cout << "Current Urgent: " << temp.getName() << std::endl;
	std::cout << "Enter task new Urgent: ";
	std::cin >> edit_urgent;
	temp.setUrgent(edit_urgent);
	std::cout << "New Task Urgent: " << temp.getUrgent();
}
