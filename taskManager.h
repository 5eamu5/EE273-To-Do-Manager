#pragma once

class Task;

class taskManager
{

public:
	taskManager();
	taskManager(Task t); 
	~taskManager();

	std::vector<Task> general; 
	std::vector<Task> pushGeneral();

	Task createTask();
	Task editTask();
	Task sortTask(std::vector<Task> vec);
	Task deleteTask(std::vector<Task> vec);

	//editing func
	int selectTaskToEdit(std::vector<Task> vec);

	void editName(Task temp);
	void editDeadline(Task temp);
	void editReminder(Task temp);
	void editLocation(Task temp);
	void editSubject(Task temp);
	void editNote(Task temp);
	void editUrgent(Task temp);



private:

};

