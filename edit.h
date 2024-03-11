#pragma once

class Task;

int selectTaskToEdit(std::vector<Task> &vec);

void editName(Task &temp);
void editDeadline(Task &temp);
void editReminder(Task &temp);
void editLocation(Task &temp);
void editSubject(Task &temp);
void editNote(Task &temp);
void editUrgent(Task &temp);

