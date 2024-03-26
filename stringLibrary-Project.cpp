
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <math.h>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cctype>
#include "clsString.h";
#include "clsDate.h";


using namespace std;


int main() {
	
	clsDate date;

	clsDate date2;
	date2.day = 26;
	date2.month = 3;
	date2.year = 2024;

	
	
	cout << "\n";
	cout << date.comparedates(date2);
	
    system("pause>0");
	return 0;
}