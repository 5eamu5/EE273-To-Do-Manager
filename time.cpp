#include <iostream>
#include <time.h>
#include <vector>
#include <string>
#include <fstream>
#include "time.h"
#include "task.h"
#include "fmanip.h"
using namespace std;

void updateTime(vector<Task>& input) {

    std::ofstream file("overdue.txt", std::ios::app);
    
    time_t ttime = time(0);

    struct tm buf;

    localtime_s(&buf, &ttime);
    time_t current = mktime(&buf);

    int taskcount{0};

    //checks task in overdue
    for (Task i : input) { 
        if (i.unixDeadline() < current) {
            file << i.getName() << "," << i.getDeadline().tm_hour << "," << i.getDeadline().tm_min << "," << i.getDeadline().tm_mday << "," << i.getDeadline().tm_mon << "," << i.getDeadline().tm_year << "," << i.getReminder().tm_hour << "," << i.getReminder().tm_min << "," << i.getReminder().tm_mday << "," << i.getReminder().tm_mon << "," << i.getReminder().tm_year << "," << i.getLocation() << "," << i.getSubject() << "," << i.getUrgent() << "," << i.getNote() << endl;
            input.erase(input.begin() + taskcount);
            overdueMessage(i);
        }
    taskcount++;
    }
}

void reminderCheck(vector<Task>& input) {

    time_t ttime = time(0);
    struct tm buf;
    localtime_s(&buf, &ttime);
    time_t current = mktime(&buf);

    for (Task i : input) {
        if (i.unixReminder() < current) {
            reminderMessage(i);
        }
    }
}

void reminderMessage(Task input) {
    string x = "";
    cout << "============================================" << endl;
    cout << "             Task Reminder Alert            " << endl;
    cout << "Name:     " << input.getName() << endl;
    cout << "Deadline: " << input.disDeadline() << endl;
    cout << "Subject:  " << input.getSubject() << endl;
    cout << "Location: " << input.getLocation() << endl;
    cout << "Note:     " << input.getNote() << endl;
    cout << "============================================" << endl;
    cout << "          Enter anything to dismiss        " << endl;
    cin >> x;
    cout << endl;
}

void overdueMessage(Task input) {
    string x = "";
    cout << "============================================" << endl;
    cout << "             Task Overdue Alert            " << endl;
    cout << "Name:     " << input.getName() << endl;
    cout << "Deadline: " << input.disDeadline() << endl;
    cout << "Subject:  " << input.getSubject() << endl;
    cout << "Location: " << input.getLocation() << endl;
    cout << "Note:     " << input.getNote() << endl;
    cout << "============================================" << endl;
    cout << "          Enter anything to dismiss        " << endl;
    cin >> x;
    cout << endl;
}
