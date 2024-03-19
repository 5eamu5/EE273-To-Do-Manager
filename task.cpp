#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include "task.h" 
#include <ctime>

using namespace std;

//constructors/destructors
Task::Task(std::string func_name, struct tm func_deadline, struct tm func_reminder, std::string func_location, std::string func_subject, bool func_urgent, std::string func_note) {
	Name = func_name;
	Deadline = func_deadline;
	Reminder = func_reminder;
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
	ss << "2. Deadline: " << getDhour() << ":" << getDmin() << " " << getDday() << "/" << getDmonth() << "/" << getDyear() << endl; //int
	ss << "3. Reminder: " << getRhour() << ":" << getRmin() << " " << getRday() << "/" << getRmonth() << "/" << getRyear() << endl; //int
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

struct tm Task::getDeadline() {
	return Deadline;
}
time_t Task::unixDeadline() {
	time_t output = mktime(&Deadline);
	return output;
}
std::string Task::disDeadline() {
	std::stringstream deadline;
	deadline << Deadline.tm_hour << ":" << Deadline.tm_min << " " << Deadline.tm_mday << "/" << Deadline.tm_mon << "/" << Deadline.tm_year;
	return deadline.str();
}

struct tm Task::getReminder() {
	return Reminder;
}
time_t Task::unixReminder() {
	time_t output = mktime(&Reminder);
	return output;
}
std::string Task::disReminder() {
	std::stringstream reminder;
	reminder << Reminder.tm_hour << ":" << Reminder.tm_min << " " << Reminder.tm_mday << "/" << Reminder.tm_mon << "/" << Reminder.tm_year;
	return reminder.str();
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
void Task::setDeadline(struct tm Deadline) {
	this->Deadline = Deadline;
}
void Task::setReminder(struct tm Reminder) {
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
