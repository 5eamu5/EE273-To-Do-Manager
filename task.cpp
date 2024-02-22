#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "task.h" 

using namespace std;

Task::Task(std::string Name, std::string Note, int Deadline, int Reminder, std::string Location, std::string Subject, bool Urgent){
	this->Name = Name;
	this->Note = Note;
	this->Deadline = Deadline;
	this->Reminder = Reminder;
	this->Location = Location;
	this->Subject = Subject;
	this->Urgent = Urgent;
}


std::string Task::getName(){
	return Name;
}
std::string Task::getNote() {
	return Note;
}
int Task::getDeadline(){
	return Deadline;
}
int Task::getReminder(){
	return Reminder;
}
std::string Task::getLocation(){
	return Location;
}
std::string Task::getSubject(){
	return Subject;
}
bool Task::getUrgent(){
	return Urgent;
}

void Task::setName(std::string Name){
	this->Name = Name;
}
void Task::setNote(std::string Note){
	this->Note = Note;
}
void Task::setDeadline(int Deadline){
	this->Deadline = Deadline;
}
void Task::getReminder(int Reminder){
	this->Reminder = Reminder;
}
void Task::setLocation(std::string Location){
	this->Location = Location;
}
void Task::setSubject(std::string Subject){
	this->Subject = Subject;
}
void Task::setUrgent(bool Urgent){
	this->Urgent = Urgent;
}

Task::~Task() {

}