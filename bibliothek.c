#include "bibliothek.h"
/**
 *  @author Jarno
 *  @description Funktionen für das timelib Projekt
 *  @date May 2022
 */

//Eingabe der Datumsdaten vom User, return als Struct aus bibliothek.h
struct Datum input_date()
{
    struct Datum date;
    printf("Geben Sie einen Tag ein\n");
    scanf("%i",&date.day);
    printf("Geben Sie einen Monat ein\n");
    scanf("%i",&date.month);
    printf("Geben Sie ein Jahr ein\n");
    scanf("%i",&date.year);
    return date;
}
//Prüft ob das gegebene Jahr ein Schaltjahr ist oder nicht
int is_leapyear(int year)
{
    int leap;
    if(year%4 == 0)     //Falls das Jahr durch 4 Teilbar ist
    {
        leap = 0;

        if (year%100 ==0)  //Falls das Jahr durch 100 Teilbar ist
        {
            leap = 1;

            if(year%400 == 0)    //Falls das JAhr durch 400 Teilbar ist
            {
                leap = 1;
            }
        }
    }else{
        leap=0;
    }
    return leap;
}
//Berechnet die menge der Tage in einem Monat, anhand eines Arrays
int get_days_for_month(int month,int year, int *month_array)
{
    int eingabe_monat;
    eingabe_monat = month-1;
    printf(eingabe_monat);
    printf(month_array);
    if(is_leapyear(year)==1){
        month_array[1] = 29;
    }
    printf("\n");
    printf(month_array);
    return month_array[eingabe_monat];
}
//Ändert in einem Array(Tage_pro_monat) den Februar ab, falls das Jahr ein Schaltjahr ist
int day_of_the_year(int day,int month,int year)
{
    int tage_pro_monat[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; //Menge der Tage in einem Monat
    int ausgabe = 0;  //ausgabe des gerechneten TAges
    int *pTage_pro_monat = &month;
    int monats_tage = get_days_for_month(month,year,tage_pro_monat);

    while(day>monats_tage)    //Der TAg muss im Array liegen
    {
        printf("Tag zu gro� f�r Monat \n");
        scanf("%i", &day);  //Erneute eingabe bis der Tag im Monat liegt
    }
    for(int i = 0; i<(month-1); i++)    //Hoch addieren der Zahlen bis alle Monate drin sind
    {
        ausgabe = ausgabe + pTage_pro_monat[i];
    }
    ausgabe = ausgabe + monats_tage;    //Tag wird addiert
    printf("Das ist der %i . Tag des Jahres", ausgabe); //Ausgabe der gesamten TAge
    return ausgabe;
}
