
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "fmanip.h"
#include "task.h"
using namespace std;


void wipeFile(vector<Task>& input, std::string filename) {
    ofstream file(filename, std::ofstream::trunc);
    input.clear();
    if (file.is_open()) {
        file.close();
    }
    else {
        cout << "Error: Unable to open file " << filename << " for writing." << std::endl;
    }
}

void savetoFile(vector<Task>& input, std::string filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (auto i : input) {
            file << i.getName() << "," << i.getDeadline().tm_hour << "," << i.getDeadline().tm_min << "," << i.getDeadline().tm_mday << "," << i.getDeadline().tm_mon << "," << i.getDeadline().tm_year << "," << i.getReminder().tm_hour << "," << i.getReminder().tm_min << "," << i.getReminder().tm_mday << "," << i.getReminder().tm_mon << "," << i.getReminder().tm_year << "," << i.getLocation() << "," << i.getSubject() << "," << i.getUrgent() << "," << i.getNote() << endl;
        }
        cout << endl << "Data Saved" << endl;
        file.close();
    }
    else {
        cout << "Error: Unable to open " << filename << " for writing." << endl;
    }
}

void readfromFile(vector<Task>& input, std::string filename) {

    ifstream file(filename);
    if (file.is_open()) {

        // Read data from the file and input into class objects
        std::string line;
        while (getline(file, line)) {

            istringstream iss(line);
            std::string info;
            vector<std::string> objAttributes;

            while (getline(iss, info, ',')) {
                objAttributes.push_back(info);
            }
            if (objAttributes.size() == 15) {

                struct tm deadline;
                struct tm reminder;

                string name = objAttributes[0];
                deadline.tm_hour = stoi(objAttributes[1]);
                deadline.tm_min = stoi(objAttributes[2]);
                deadline.tm_mday = stoi(objAttributes[3]);
                deadline.tm_mon = stoi(objAttributes[4]);
                deadline.tm_year = stoi(objAttributes[5]);
                reminder.tm_hour = stoi(objAttributes[6]);
                reminder.tm_min = stoi(objAttributes[7]);
                reminder.tm_mday = stoi(objAttributes[8]);
                reminder.tm_mon = stoi(objAttributes[9]);
                reminder.tm_year = stoi(objAttributes[10]);
                string location = objAttributes[11];
                string subject = objAttributes[12];
                bool urgent = stoi(objAttributes[13]);
                string note = objAttributes[14];

                Task temp(name, deadline, reminder, location, subject, urgent, note);
                input.push_back(temp);
            }
        }
    }
    else {
        cout << "Error: Unable to open file." << endl;
    }
}

