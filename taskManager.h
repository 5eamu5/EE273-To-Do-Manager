#pragma once

class Task;

class taskManager
{

public:
	taskManager();
	taskManager(Task t); 
	~taskManager();

	//std::vector<Task> general; 
	//std::vector<Task> pushGeneral();

	Task createTask();
	Task editTask(std::vector<Task> &general);
	std::vector<Task> sortTask(std::vector<Task> general);
	Task deleteTask(std::vector<Task> &general);





private:

};

