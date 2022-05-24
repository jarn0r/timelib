/**
 *  @Author JR
 *  @description Schaltjahrberechnung und dessen Ausgabe
 *
 **/

#include <stdio.h>
#include <stdlib.h>

/**
 *
 *test
 **/


void input_date(int *zeiger_Tag, int *zeiger_Monat,  int *zeiger_Jahr)
{
    //*zeiger_Tag;
    //*zeiger_Monat;
    //*zeiger_Jahr;
    printf("Geben Sie einen Tag ein\n");
    scanf("%i",zeiger_Tag);
    printf("Geben Sie einen Monat ein\n");
    scanf("%i",zeiger_Monat);
    printf("Geben Sie ein Jahr ein\n");
    scanf("%i",zeiger_Jahr);
}

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
int day_of_the_year(int day,int month,int year)
{
    int tage_pro_monat[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; //Menge der Tage in einem Monat
    int ausgabe = 0;    //ausgabe des gerechneten TAges
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

int main()
{
    int day ,*pday = &day;
    int month ,*pmonth = &month;
    int year ,*pyear = &year;
    int tage_pro_monat[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; //Menge der Tage in einem Monat
    input_date(pday,pmonth,pyear);
    is_leapyear(pyear);
    printf(is_leapyear(pyear));
    get_days_for_month(pmonth,pyear,&tage_pro_monat);
    day_of_the_year(pday,pmonth,pyear);
    return 0;
}
