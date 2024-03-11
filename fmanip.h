#pragma once
using namespace std;

class Task;

void wipeFile();

void savetoFile(std::vector<Task>& input);

void readfromFile(std::vector<Task>& input);
