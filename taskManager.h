#pragma once

class Task;

class taskManager
{

public:
	taskManager();
	taskManager(Task t); 
	~taskManager();

	Task createTask();
	Task editTask(std::vector<Task> &general);
	void sortTask(std::vector<Task> general, std::vector<Task> overdue_tasks);
	void deleteTask(std::vector<Task>& general); 

private:
};

//other
void printVector(std::vector<Task> general, std::vector<Task> overdue);

//editing
int selectTaskToEdit(std::vector<Task>& vec);

void editName(Task& temp);
void editDeadline(Task& temp);
void editReminder(Task& temp);
void editLocation(Task& temp);
void editSubject(Task& temp);
void editNote(Task& temp);
void editUrgent(Task& temp); 


//sorting
int selectMethodToSort();

bool compareName(Task& prev, Task& next);
bool compareDeadline(Task& prev, Task& next);
bool compareReminder(Task& prev, Task& next);
bool compareLocation(Task& prev, Task& next);
bool compareSubject(Task& prev, Task& next);
bool compareUrgent(Task& prev, Task& next);

std::vector<Task> vecSortName(std::vector<Task>& general);
std::vector<Task> vecSortDeadline(std::vector<Task>& general);
std::vector<Task> vecSortReminder(std::vector<Task>& general);
std::vector<Task> vecSortLocation(std::vector<Task>& general);
std::vector<Task> vecSortSubject(std::vector<Task>& general);
std::vector<Task> vecSortUrgent(std::vector<Task>& general);


//deleting
int selectTaskToDelete(std::vector<Task> general);


