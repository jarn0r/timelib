/**
 *  @Author JR
 *  @description Schaltjahrberechnung und dessen Ausgabe
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include "bibliothek.h"

int main()
{
    struct Datum date;  //Erstellung des Structs
    int tage_pro_monat[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; //Menge der Tage in einem Monat
    date = input_date();    //date wird initialistiert mit den Daten aus der Input Funktion
    is_leapyear(date.year); //Berechnung ob es ein Schaltjahr ist
    printf(is_leapyear(date.year)); //Ausgabe ob es ein Schaltjahr ist
    get_days_for_month(date.month,date.year,&tage_pro_monat);   //Bearbeitung des Monats Arrays, um den Februar im falle eines Schaltjahres richtig zu haben
    day_of_the_year(date.day,date.month,date.year); //Ausgabe des Tages im Jahr
    return 0;
}
