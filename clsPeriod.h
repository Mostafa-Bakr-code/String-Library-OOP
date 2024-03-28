#pragma once
#include "clsDate.h"
#include "clsString.h"


class clsPeriod
{
public:

    clsDate StartDate;
    clsDate EndDate;

    clsPeriod(clsDate StartDate, clsDate DateTo)
    {
        this->StartDate = StartDate;
        this->EndDate = DateTo;

    }

    static bool IsOverlapPeriods(clsPeriod Period1, clsPeriod Period2)
    {

        if (
            clsDate::comparedates(Period2.EndDate, Period1.StartDate) == clsDate::encomparedates::Before
            ||
            clsDate::comparedates(Period2.StartDate, Period1.EndDate) == clsDate::encomparedates::After
            )
            return false;
        else
            return true;

    }

    bool IsOverLapWith(clsPeriod Period2)
    {
        return IsOverlapPeriods(*this, Period2);
    }

    static short periodLength(clsPeriod period) {

        return clsDate::diffbetween2dates(period.StartDate, period.EndDate);

    }

    static bool isDateInPeriod(clsPeriod period, clsDate date) {

        return !((clsDate::comparedates(period.StartDate, date) == clsDate::encomparedates::After) || (clsDate::comparedates(period.EndDate, date) == clsDate::encomparedates::Before));
    }

    static short overlapCountBetween2Periods(clsPeriod period1, clsPeriod period2) {

        int counter = 1;
        int v1length = periodLength(period1);
        int v2length = periodLength(period2);


        if (!IsOverlapPeriods(period1, period2)) {

            return 0;
        }



        if (v1length < v2length) {

            while (clsDate::comparedates(period1.StartDate, period1.EndDate) == clsDate::encomparedates::Before) {

                if (isDateInPeriod(period2, period1.StartDate)) {

                    counter++;
                }

                clsDate::increasedatebyoneday(period1.StartDate);
            }

            return counter;

        }

        else {

            while (clsDate::comparedates(period2.StartDate, period2.EndDate) == clsDate::encomparedates::Before) {

                if (isDateInPeriod(period1, period2.StartDate)) {

                    counter++;
                }

                clsDate::increasedatebyoneday(period2.StartDate);
            }

            return counter;

        }


    }

    void Print()
    {
        cout << "Period Start: ";
        StartDate.print();


        cout << "Period End: ";
        EndDate.print();


    }

};

