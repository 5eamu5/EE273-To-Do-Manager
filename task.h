#pragma once

class Task {
public:
	//Constructor and Destructor
	Task(string Name, string note, int Deadline, int Reminder, string Location, string Subject, bool Urgent);

	//Getters
	string getName();
	string getNote();
	int getDeadline();
	int getReminder();
	string getLocation();
	string getSubject();
	bool getUrgent();

	//Setters
	string setName(string Name);
	string setNote(string Note);
	int setDeadline(int Deadline);
	int getReminder(int Reminder);
	string setLocation(string Location);
	string setSubject(string Subject);
	bool setUrgent(bool Urgent);

private:
	//Unwanted Constructors
	Task();
	Task(string Name);
	~Task();
	
	//Variables
	string Name;
	string Note;
	int Deadline;
	int Reminder;
	string Location;
	string Subject;
	bool Urgent;
};
