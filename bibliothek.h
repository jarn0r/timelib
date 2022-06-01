#include <stdio.h>
#include <stdlib.h>
/**
 *  @author Jarno
 *  @description Auflistung der Funktionen und Aufbau des Struct, welches für die Datums Berechnungen genutzt wird
 *  @date May 2022
 */
struct Datum{
    int day;
    int month;
    int year;
};

struct Datum input_date();
int is_leapyear(int year);
int get_days_for_month(int month,int year, int *month_array);
int day_of_the_year(int day,int month,int year);
