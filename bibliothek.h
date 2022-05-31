#include <stdio.h>
#include <stdlib.h>

struct Datum{
    int day;
    int month;
    int year;
};

struct Datum input_date();
int is_leapyear(int year);
int get_days_for_month(int month,int year, int *month_array);
int day_of_the_year(int day,int month,int year);
