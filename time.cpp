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

    char hour[26];
    char min[26];
    char day[26];
    char month[26];
    char year[26];

    struct tm buf;

    localtime_s(&buf, &ttime);
    strftime(hour, sizeof hour, "%H", &buf);
    strftime(min, sizeof min, "%M", &buf);
    strftime(day, sizeof day, "%d", &buf);
    strftime(month, sizeof month, "%m", &buf);
    strftime(year, sizeof year, "%Y", &buf);

    int ihour = stoi(hour);
    int imin = stoi(min);
    int iday = stoi(day);
    int imonth = stoi(month);
    int iyear = stoi(year);

    for (auto i : input) {
        if (i.getDyear() < iyear) {
            file << i.getName() << "," << i.getDhour() << "," << i.getDmin() << "," << i.getDday() << "," << i.getDmonth() << "," << i.getDyear() << "," << i.getRhour() << "," << i.getRmin() << "," << i.getRday() << "," << i.getRmonth() << "," << i.getRyear() << "," << i.getLocation() << "," << i.getSubject() << "," << i.getUrgent() << "," << i.getNote() << endl;
            //input delete
        }
        else if (i.getDyear() > iyear) {
        }
        else {
            if (i.getDmonth() < imonth) {
                file << i.getName() << "," << i.getDhour() << "," << i.getDmin() << "," << i.getDday() << "," << i.getDmonth() << "," << i.getDyear() << "," << i.getRhour() << "," << i.getRmin() << "," << i.getRday() << "," << i.getRmonth() << "," << i.getRyear() << "," << i.getLocation() << "," << i.getSubject() << "," << i.getUrgent() << "," << i.getNote() << endl;
                //input delete
            }
            else if (i.getDmonth() > imonth) {
            }
            else {
                if (i.getDday() < iday) {
                    file << i.getName() << "," << i.getDhour() << "," << i.getDmin() << "," << i.getDday() << "," << i.getDmonth() << "," << i.getDyear() << "," << i.getRhour() << "," << i.getRmin() << "," << i.getRday() << "," << i.getRmonth() << "," << i.getRyear() << "," << i.getLocation() << "," << i.getSubject() << "," << i.getUrgent() << "," << i.getNote() << endl;
                    //input delete
                }
                else if (i.getDday() > iday) {
                }
                else {
                    if (i.getDhour() < ihour) {
                        file << i.getName() << "," << i.getDhour() << "," << i.getDmin() << "," << i.getDday() << "," << i.getDmonth() << "," << i.getDyear() << "," << i.getRhour() << "," << i.getRmin() << "," << i.getRday() << "," << i.getRmonth() << "," << i.getRyear() << "," << i.getLocation() << "," << i.getSubject() << "," << i.getUrgent() << "," << i.getNote() << endl;
                        //input delete
                    }
                    else if (i.getDhour() > ihour) {
                    }
                    else {
                        if (i.getDmin() <= imin) {
                            file << i.getName() << "," << i.getDhour() << "," << i.getDmin() << "," << i.getDday() << "," << i.getDmonth() << "," << i.getDyear() << "," << i.getRhour() << "," << i.getRmin() << "," << i.getRday() << "," << i.getRmonth() << "," << i.getRyear() << "," << i.getLocation() << "," << i.getSubject() << "," << i.getUrgent() << "," << i.getNote() << endl;
                            //input delete
                        }
                    }
                }
            }
        }
    }
}