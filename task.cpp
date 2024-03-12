#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include "task.h" 

using namespace std;

//constructors/destructors
Task::Task(std::string func_name, int func_dhour, int func_dmin, int func_dday, int func_dmonth, int func_dyear, int func_rhour, int func_rmin, int func_rday, int func_rmonth, int func_ryear, std::string func_location, std::string func_subject, bool func_urgent, std::string func_note) {
	Name = func_name;
	Dhour = func_dhour;
	Dmin = func_dmin;
	Dday = func_dday;
	Dmonth = func_dmonth;
	Dyear = func_dyear;
	Rhour = func_rhour;
	Rmin = func_rmin;
	Rday = func_rday;
	Rmonth = func_rmonth;
	Ryear = func_ryear;
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
std::string Task::getDeadline() {
	std::stringstream deadline;
	deadline << getDhour() << ":" << getDmin() << " " << getDday() << "/" << getDmonth() << "/" << getDyear();
	return deadline.str();
}
int Task::getDhour() {
	return Dhour;
}
int Task::getDmin() {
	return Dmin;
}
int Task::getDday() {
	return Dday;
}
int Task::getDmonth() {
	return Dmonth;
}
int Task::getDyear() {
	return Dyear;
}
std::string Task::getReminder() {
	std::stringstream reminder;
	reminder << getRhour() << ":" << getRmin() << " " << getRday() << "/" << getRmonth() << "/" << getRyear();
	return reminder.str();
}
int Task::getRhour() {
	return Rhour;
}
int Task::getRmin() {
	return Rmin;
}
int Task::getRday() {
	return Rday;
}
int Task::getRmonth() {
	return Rmonth;
}
int Task::getRyear() {
	return Ryear;
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
void Task::setDhour(int func_dhour) {
	Dhour = func_dhour;
}
void Task::setDmin(int func_dmin) {
	Dmin = func_dmin;
}
void Task::setDday(int func_dday) {
	Dday = func_dday;
}
void Task::setDmonth(int func_dmonth) {
	Dmonth = func_dmonth;
}
void Task::setDyear(int func_dyear) {
	Dyear = func_dyear;
}
void Task::setRhour(int func_rhour) {
	Rhour = func_rhour;
}
void Task::setRmin(int func_rmin) {
	Rmin = func_rmin;
}
void Task::setRday(int func_rday) {
	Rday = func_rday;
}
void Task::setRmonth(int func_rmonth) {
	Rmonth = func_rmonth;
}
void Task::setRyear(int func_ryear) {
	Ryear = func_ryear;
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
