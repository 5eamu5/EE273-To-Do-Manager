#pragma once

class Task {
public:
	//Constructor and Destructor
	Task(std::string func_name, int func_dhour, int func_dmin, int func_dday, int func_dmonth, int func_dyear, int func_rhour, int func_rmin, int func_rday, int func_rmonth, int func_ryear, std::string func_location, std::string func_subject, bool func_urgent, std::string func_note);
	Task();
	Task(std::string Name);
	~Task();

	//toString
	std::string toString(); 

	//Getters
	std::string getName();
	std::string getNote();
	std::string getDeadline();
	int getDhour();
	int getDmin();
	int getDday();
	int getDmonth();
	int getDyear();
	std::string getReminder();
	int getRhour();
	int getRmin();
	int getRday();
	int getRmonth();
	int getRyear();
	std::string getLocation();
	std::string getSubject();
	bool getUrgent();

	//Setters
	void setName(std::string Name);
	void setNote(std::string Note);
	void setDhour(int func_dhour);
	void setDmin(int func_dmin);
	void setDday(int func_dday);
	void setDmonth(int func_dmonth);
	void setDyear(int func_dyear);
	void setRhour(int func_rhour);
	void setRmin(int func_rmin);
	void setRday(int func_rday);
	void setRmonth(int func_rmonth);
	void setRyear(int func_ryear);
	void setLocation(std::string Location);
	void setSubject(std::string Subject);
	void setUrgent(bool Urgent);

private:
	//Variables
	std::string Name{ "default" };
	std::string Note{"default"};
	int Dhour{ 0 };
	int Dmin{ 0 };
	int Dday{ 0 };
	int Dmonth{ 0 };
	int Dyear{ 0 };
	int Rhour{ 0 };
	int Rmin{ 0 };
	int Rday{ 0 };
	int Rmonth{ 0 };
	int Ryear{ 0 };
	std::string Location{ "default" };
	std::string Subject{ "default" };
	bool Urgent{ 0 };
};
