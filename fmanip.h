
#pragma once
using namespace std;

class Task;

void wipeFile(vector<Task>& input, std::string filename);

void savetoFile(std::vector<Task>& input, std::string filename);

void readfromFile(std::vector<Task>& input, std::string filename);
