#pragma once

//main page of UI
void contents();


//primary branches
void createTask();
void editTask();
void sortTask();
void deleteTask();


//editing subtree
int selectTaskToEdit(std::vector<Task> general);

void editName(Task temp);
void editDeadline(Task temp);
void editReminder(Task temp);
void editLocation(Task temp);
void editSubject(Task temp);
void editNote(Task temp);
void editUrgent(Task temp);

//sorting subtree 
//this is just the UI part of the sorting, not the algorithm itself
void UIsortName();
void UIsortDeadline();
void UIsortLocation();
void UIsortSubject();
void UIsortUrgent();

//delete task subtree
void selectTaskToDelete();

//other
void returnToContents();
void returnToEdit();
void returnToSort();

void upperDivider();
void lowerDivider();
