#include <iostream>
#include <string>
#include "task.h"

using namespace std;

//Task Constructor
Task::Task(string Name, string Note, int Deadline, int Reminder, string Location, string Subject, bool Urgent){
	this->Name = Name;
	this->Note = Note;
	this->Deadline = Deadline;
	this->Reminder = Reminder;
	this->Location = Location;
	this->Subject = Subject;
	this->Urgent = Urgent;
}

//Task Getters
string Task::getName(){
	return Name;
}
string Task::getNote() {
	return Note;
}
int Task::getDeadline(){
	return Deadline;
}
int Task::getReminder(){
	return Reminder;
}
string Task::getLocation(){
	return Location;
}
string Task::getSubject(){
	return Subject;
}
bool Task::getUrgent(){
	return Urgent;
}

//Task Setters
string Task::setName(string Name){
	this->Name = Name;
}
string Task::setNote(string Note){
	this->Note = Note;
}
int Task::setDeadline(int Deadline){
	this->Deadline = Deadline;
}
int Task::getReminder(int Reminder){
	this->Reminder = Reminder;
}
string Task::setLocation(string Location){
	this->Location = Location;
}
string Task::setSubject(string Subject){
	this->Subject = Subject;
}
bool Task::setUrgent(bool Urgent){
	this->Urgent = Urgent;
}
