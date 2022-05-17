/**
 *  @Author JR
 *  @description Schaltjahrberechnung und dessen Ausgabe
 *
 **/

#include <stdio.h>
#include <stdlib.h>

/**
 *
 *
 **/
int day_of_the_year(int day, int month, int year)
{
    int tage_pro_monat[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; //Menge der Tage in einem Monat
    int tag = 0; //Eingabe des Tages im Monat
    int monat = 0;  //Eingabe des Monats im Jahr
    int jahr = 0;   //Eingabe des gewünschten Jahres
    int ausgabe = 0;    //ausgabe des gerechneten TAges

    printf("Geben Sie das Jahr ein \n");
    scanf("%i", &jahr); //Eingabe des gewünschten Jahres
    if(jahr%4 == 0)     //Falls das Jahr durch 4 Teilbar ist
    {
        //tage_pro_monat[1] = 28;    //Kein Schaltjahr

        if (jahr%100 ==0)  //Falls das Jahr durch 100 Teilbar ist
        {
            //tage_pro_monat[1] = 29;    //Schlatjahr

            if(jahr%400 == 0)    //Falls das JAhr durch 400 Teilbar ist
            {
                tage_pro_monat[1] = 29;    //Schaltjahr
            }
        }
    }
    printf("Geben Sie bitte den Monat ein (als Zahl) \n");
    scanf("%i", &monat);    //Eingabe des Monats
    monat = monat-1;    //Für das Array wird -1 gerechnet
    printf("Geben Sie bitte den Tag ein \n");
    scanf("%i", &tag);  //Eingabe des Tages
    while(tag>tage_pro_monat[monat])    //Der TAg muss im Array liegen
    {
        printf("Tag zu groß für Monat \n");
        scanf("%i", &tag);  //Erneute eingabe bis der Tag im Monat liegt
    }
    for(int i = 0; i<monat; i++)    //Hoch addieren der Zahlen bis alle Monate drin sind
    {
        ausgabe = ausgabe + tage_pro_monat[i];
    }
    ausgabe = ausgabe + tag;    //Tag wird addiert
    printf("Das ist der %i . Tag des Jahres", ausgabe); //Ausgabe der gesamten TAge
    return 0;
}

int main()
{
    day_of_the_year(1,1,1);
    return 0;
}
