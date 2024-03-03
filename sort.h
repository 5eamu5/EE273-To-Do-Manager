#pragma once

class Task;

bool compareName(Task& prev, Task& next);
bool compareDeadline(Task& prev, Task& next);
bool compareLocation(Task& prev, Task& next);
bool compareSubject(Task& prev, Task& next);
bool compareUrgent(Task& prev, Task& next);

void vecSortName(std::vector<Task>& input);
void vecSortDeadline(std::vector<Task>& input);
void vecSortReminder(std::vector<Task>& input);
void vecSortLocation(std::vector<Task>& input);
void vecSortSubject(std::vector<Task>& input);
void vecSortUrgent(std::vector<Task>& input);