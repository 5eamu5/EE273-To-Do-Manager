#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include "task.h" 

using namespace std;

//constructors/destructors
Task::Task(std::string func_name, int func_deadline, int func_reminder, std::string func_location, std::string func_subject, bool func_urgent, std::string func_note) {
	Name = func_name;
	Deadline = func_deadline;
	Reminder = func_deadline;
	Location = func_location; 
	Subject = func_subject; 
	Urgent = func_urgent; 
	Note = func_note; 
}
Task::Task() {

}
Task::Task(std::string func_name) {
	func_name = Name;
}
Task::~Task() {}

std::string Task::toString() {
	std::stringstream ss;
	ss << "1. Name: " << getName() << endl; //string
	ss << "2. Deadline: " << getDeadline() << endl; //int
	ss << "3. Reminder: " << getReminder() << endl; //int
	ss << "4. Location: " << getLocation() << endl; //string
	ss << "5. Subject: " << getSubject() << endl; //string
	ss << "6. Note: " << getNote() << endl; //string
	ss << "7. Urgent: " << getUrgent() << endl; //string
	return ss.str();
}


//setters and getters
std::string Task::getName(){
	return Name;
}
std::string Task::getNote() {
	return Note;
}
int Task::getDeadline() {
	return Deadline;
}
int Task::getReminder() {
	return Reminder;
}
std::string Task::getLocation() {
	return Location;
}
std::string Task::getSubject() {
	return Subject;
}
bool Task::getUrgent() {
	return Urgent;
}

void Task::setName(std::string Name) {
	this->Name = Name;
}
void Task::setNote(std::string Note) {
	this->Note = Note;
}
void Task::setDeadline(int Deadline) {
	this->Deadline = Deadline;
}
void Task::setReminder(int Reminder) {
	this->Reminder = Reminder;
}
void Task::setLocation(std::string Location) {
	this->Location = Location;
}
void Task::setSubject(std::string Subject) {
	this->Subject = Subject;
}
void Task::setUrgent(bool Urgent) {
	this->Urgent = Urgent;
}
