#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "fmanip.h"
#include "task.h"
using namespace std;


string const filename = "savedata.txt";

void wipeFile(vector<Task>& input) {
    ofstream file(filename, std::ofstream::trunc);
    input.clear();
    if (file.is_open()) {
        file.close();
    }
    else {
        cout << "Error: Unable to open file " << filename << " for writing." << std::endl;
    }
}

void savetoFile(vector<Task>& input) {
    ofstream file(filename);
    if (file.is_open()) {
        for (auto i : input) {
            file << i.getName() << "," << i.getDhour() << "," << i.getDmin() << "," << i.getDday() << "," << i.getDmonth() << "," << i.getDyear() << "," << i.getRhour() << "," << i.getRmin() << "," << i.getRday() << "," << i.getRmonth() << "," << i.getRyear() << "," << i.getLocation() << "," << i.getSubject() << "," << i.getUrgent() << "," << i.getNote() <<  endl;
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

                string name = objAttributes[0];
                int dhour= stoi(objAttributes[1]);
                int dmin = stoi(objAttributes[2]);
                int dday = stoi(objAttributes[3]);
                int dmonth = stoi(objAttributes[4]);
                int dyear = stoi(objAttributes[5]);
                int rhour = stoi(objAttributes[6]);
                int rmin = stoi(objAttributes[7]);
                int rday = stoi(objAttributes[8]);
                int rmonth = stoi(objAttributes[9]);
                int ryear = stoi(objAttributes[10]);
                string location = objAttributes[11];
                string subject = objAttributes[12];
                bool urgent = stoi(objAttributes[13]);
                string note = objAttributes[14];

                Task temp(name, dhour, dmin, dday, dmonth, dyear, rhour, rmin, rday, rmonth, ryear, location, subject, urgent, note);
                input.push_back(temp);
            }
        }
    }
    else {
        cout << "Error: Unable to open file." << endl;
    }
}

void readfromFile(vector<Task>& input, string filename) {

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

                string name = objAttributes[0];
                int dhour = stoi(objAttributes[1]);
                int dmin = stoi(objAttributes[2]);
                int dday = stoi(objAttributes[3]);
                int dmonth = stoi(objAttributes[4]);
                int dyear = stoi(objAttributes[5]);
                int rhour = stoi(objAttributes[6]);
                int rmin = stoi(objAttributes[7]);
                int rday = stoi(objAttributes[8]);
                int rmonth = stoi(objAttributes[9]);
                int ryear = stoi(objAttributes[10]);
                string location = objAttributes[11];
                string subject = objAttributes[12];
                bool urgent = stoi(objAttributes[13]);
                string note = objAttributes[14];

                Task temp(name, dhour, dmin, dday, dmonth, dyear, rhour, rmin, rday, rmonth, ryear, location, subject, urgent, note);
                input.push_back(temp);
            }
        }
    }
    else {
        cout << "Error: Unable to open file." << endl;
    }
}