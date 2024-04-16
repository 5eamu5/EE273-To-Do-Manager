#pragma once
using namespace std;

class Task;

void updateTime(vector<Task>& input);

void reminderCheck(vector<Task>& input);

void reminderMessage(Task input);

void overdueMessage(Task input);