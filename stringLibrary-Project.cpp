
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
#include "clsPeriod.h";


using namespace std;


int main() {
	

    clsPeriod Period1(clsDate(1, 1, 2022), clsDate(10, 1, 2022));
    Period1.Print();

    clsPeriod Period2(clsDate(1, 1, 2022), clsDate(5, 1, 2022));
    Period2.Print();

    cout << "\n";

    cout << clsPeriod::overlapCountBetween2Periods(Period1, Period2);
    
    

    system("pause>0");
	return 0;
}