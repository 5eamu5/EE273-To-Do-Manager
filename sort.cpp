#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "sort.h"
#include "task.h"

using namespace std;

//all functions for sorting tasks by member
//look at Student.cpp from Lab11 Ex4. 
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