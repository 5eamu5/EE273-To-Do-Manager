#pragma once

class Task {
public:
	//Constructor and Destructor
	Task(std::string func_name, struct tm func_deadline, struct tm func_reminder, std::string func_location, std::string func_subject, bool func_urgent, std::string func_note);
	~Task();

	//toString
	std::string toString(); 

	//Getters
	std::string getName();
	std::string getNote();
	struct tm getDeadline();
	time_t unixDeadline();
	std::string disDeadline();
	struct tm getReminder();
	time_t unixReminder();
	std::string disReminder();
	std::string getLocation();
	std::string getSubject();
	bool getUrgent();

	//Setters
	void setName(std::string Name);
	void setNote(std::string Note);
	void setDeadline(struct tm Deadline);
	void setReminder(struct tm Reminder);
	void setLocation(std::string Location);
	void setSubject(std::string Subject);
	void setUrgent(bool Urgent);

private:
	//Variables
	std::string Name{ "default" };
	std::string Note{"default"};
	struct tm Deadline;
	struct tm Reminder;
	std::string Location{ "default" };
	std::string Subject{ "default" };
	bool Urgent{ 0 };
};
