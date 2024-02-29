#pragma once

//main page of UI
void contents();

//primary branches
void createTaskUI();
void editTaskUI();
void sortTaskUI();
void deleteTaskUI();

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
void returnToDelete();

void upperDivider();
void lowerDivider();
