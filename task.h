#pragma once

class Task {
public:
	//Constructor and Destructor
	Task(std::string func_name, int func_deadline, int func_reminder, std::string func_location, std::string func_subject, bool func_urgent, std::string func_note);
	Task();
	Task(std::string Name);
	~Task();

	//toString
	std::string toString(); 

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
	void setReminder(int Reminder);
	void setLocation(std::string Location);
	void setSubject(std::string Subject);
	void setUrgent(bool Urgent);

private:
	//Variables
	std::string Name;
	std::string Note;
	int Deadline;
	int Reminder;
	std::string Location;
	std::string Subject;
	bool Urgent;
};
