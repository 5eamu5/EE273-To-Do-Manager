#pragma once

#include <iostream>
#include <string>
#include <vector>

//main page of UI
void contents();

//subtrees
void createTask();
void editTask();
void sortTask();
void deleteTask(); 

//editing subtree
void selectTaskToEdit(); 

void editName();
void editDeadline();
void editLocation();
void editSubject();
void editUrgent(); 

//sorting subtree 
//this is just the UI part of the sorting, not the algorithm itself
void UIsortName();
void UIsortDeadline();
void UIsortLocation();
void UIsortSubject();
void UIsortUrgent();

//delete task subtree
void selectTaskToDelete();