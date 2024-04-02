#include <iostream>
#include <string>
#include <vector>
#include "task.h"
#include "consoleUI.h"
#include "fmanip.h"
#include <ctime>
using namespace std;

int main() {

	time_t ttime = time(0);
	struct tm buf;
	localtime_s(&buf, &ttime);
	time_t current = mktime(&buf);
	cout << buf.tm_year << endl;
	cout << current << endl;

	contents();

	return 0;
}
