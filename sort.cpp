#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "sort.h"
#include "task.h"

using namespace std;
void viewTasks(std::vector<Task>& general) {
	std::cout << "All Tasks: " << std::endl;
	for (Task t : general) {
		std::cout << "-Task-" << std::endl;
		std::cout << t.toString();
		std::cout << std::endl;
	}
}
void printMethods() {
	std::cout << "1. Name" << std::endl;
	std::cout << "2. Deadline" << std::endl;
	std::cout << "3, Reminder" << std::endl;
	std::cout << "4. Location" << std::endl;
	std::cout << "5. Subject" << std::endl;
	std::cout << "6. Marked as Urgent" << std::endl;
}

int selectMethodToSort() {
	int selected_method;
	std::cout << std:: endl << "Please select a Method to Sort: " << std::endl;
	printMethods(); 
	std::cin >> selected_method;
	return selected_method;
}

//all functions for sorting tasks by member
bool compareName(Task& prev, Task& next) {
	return prev.getName() < next.getName();
}
bool compareDeadline(Task& prev, Task& next) {
	return prev.getDeadline() < next.getDeadline();
}
bool compareReminder(Task& prev, Task& next) {
	return prev.getReminder() < next.getReminder();
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

void vecSortName(vector<Task>& input) { 
	sort(input.begin(), input.end(), compareName);
}
void vecSortDeadline(vector<Task>& input) {
	sort(input.begin(), input.end(), compareDeadline);
}
void vecSortReminder(vector<Task>& input) {
	sort(input.begin(), input.end(), compareReminder);
}
void vecSortLocation(vector<Task>& input) {
	sort(input.begin(), input.end(), compareLocation);
}
void vecSortSubject(vector<Task>& input) {
	sort(input.begin(), input.end(), compareSubject);
}
void vecSortUrgent(vector<Task>& input) {
	sort(input.begin(), input.end(), compareUrgent);
}
