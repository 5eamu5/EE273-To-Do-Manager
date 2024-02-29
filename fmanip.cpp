#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "fmanip.h"
#include "task.h"
using namespace std;

std::string filename = "savedata.txt";

void wipeFile() {
    ofstream file(filename, std::ios::out | std::ios::trunc);
    if (file.is_open()) {
        file.close();
    }
    else {
        cout << "Error: Unable to open " << filename << " for wiping." << endl;
    }
}

void savetoFile(vector<Task>& input) {
    ofstream file(filename);
    if (file.is_open()) {
        for (auto i : input) {
            file << i.getName() <<","<< i.getNote() << "," << i.getDeadline() << "," << i.getReminder() << "," << i.getLocation() << "," << i.getSubject() << "," << i.getUrgent() << endl;
        }
        cout << "Data Saved" << filename << endl;
        file.close();
    }
    else {
        cout << "Error: Unable to open " << filename << " for writing." << endl;
    }
}

void readfromFile(vector<Task>& input) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open file." << endl;
        return;
    }

    // Read data from the file and input into class objects
    std::string line;
    while (getline(file, line)) {
        istringstream iss(line);
        std::string info;
        vector<std::string> objAttributes;
        while (getline(iss, info, ',')) {
            objAttributes.push_back(info);
        }
        if (objAttributes.size() == 7) {
            string name = objAttributes[0];
            int deadline = stoi(objAttributes[1]);
            int reminder = stoi(objAttributes[2]);
            string location = objAttributes[3];
            string subject = objAttributes[4];
            bool urgent = stoi(objAttributes[5]);
            string note = objAttributes[6];

            Task temp(name, deadline, reminder, location, subject, urgent, note);
            input.push_back(temp);
        }
    }

    // Close the file
    file.close();
}