#pragma once
#include <iostream>
#include <string>

using namespace std;

//functions for UI

//main page of UI
void contents();

//subtrees
void createTask();
void editTask();
void sortTask();
void deleteTask(); 

//sorting functions
//leaving as void for now, probably need to change type later
void sortName();
void sortDeadline();
void sortLocation();
void sortSubject();
void sortUrgent();
