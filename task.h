#pragma once

class Task {
public:
	//Constructor and Destructor
	Task(std::string Name, std::string note, int Deadline, int Reminder, std::string Location, std::string Subject, bool Urgent);

	//Getters
	std::string getName();
	std::string getNote();
	int getDeadline();
	int getReminder();
	std::string getLocation();
	std::string getSubject();
	bool getUrgent();

	//Setters
	void setName(std::string Name);
	void setNote(std::string Note);
	void setDeadline(int Deadline);
	void getReminder(int Reminder);
	void setLocation(std::string Location);
	void setSubject(std::string Subject);
	void setUrgent(bool Urgent);

private:
	//Unwanted Constructors
	Task();
	Task(std::string Name);
	~Task();
	
	//Variables
	std::string Name;
	std::string Note;
	int Deadline;
	int Reminder;
	std::string Location;
	std::string Subject;
	bool Urgent;
};