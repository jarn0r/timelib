/**
 *  @Author JR
 *  @description Schaltjahrberechnung und dessen Ausgabe
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include "bibliothek.h"


/**
 *
 *test
 **/


int main()
{
    struct Datum date;
    //int day ,*pday = &day;
    //int month ,*pmonth = &month;
    //int year ,*pyear = &year;
    int tage_pro_monat[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; //Menge der Tage in einem Monat
    date = input_date();
    is_leapyear(date.year);
    printf(is_leapyear(date.year));
    get_days_for_month(date.month,date.year,&tage_pro_monat);
    day_of_the_year(date.day,date.month,date.year);
    return 0;
}
