#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "funkcije.h"

#define MULTIPLY_SCORE(bodoviPrije, multiplikator) (bodoviPrije * multiplikator)

void unesiPodatkeIgraca(Igrac* igrac) {
    printf("Unesite ime: ");
    scanf("%s", igrac->ime);
    printf("Unesite prezime: ");
    scanf("%s", igrac->prezime);
    printf("Unesite nadimak: ");
    scanf("%s", igrac->nadimak);
}

void unesiBodoveUDatoteku(Igrac igrac, int tezinaIgre, int brojKrugova, int bodoviPoslije) {
    FILE* file;
    file = fopen("ljestvica.txt", "a");

    if (file != NULL) {
        fprintf(file, "%s - %2s - %2s - %2d - %2d - %2d\n", igrac.ime, igrac.nadimak, igrac.prezime, tezinaIgre, brojKrugova, bodoviPoslije);
        fclose(file);
    }
    else {
        printf("Nije moguce otvoriti datoteku za pisanje.\n");
    }
}

void unesiPodatkeIgracaUDatoteku(Igrac igrac) {
    FILE* file;
    file = fopen("igrac.txt", "w");

    if (file != NULL) {
        fprintf(file, "Ime: %s\nPrezime: %s\nNadimak: %s\n", igrac.ime, igrac.prezime, igrac.nadimak);
        fclose(file);
    }
    else {
        printf("Nije moguce otvoriti datoteku za pisanje.\n");
    }
}

void prikaziLjestvicu() {
    FILE* file;
    char linija[200];

    file = fopen("ljestvica.txt", "r");

    if (file != NULL) {
        printf("\nLjestvica:\n");

        while (fgets(linija, sizeof(linija), file)) {
            printf("%s", linija);
        }

        fclose(file);
    }
    else {
        printf("Nema dostupnih rezultata u ljestvici.\n");
    }
}

void igrajIgru(int tezinaIgre, Igrac igrac) {
    int bodoviPrije = 0, bodoviPoslije = 0, brojKrugova = 0, maxBodovi = 0;
    int multiplikator;

    switch (tezinaIgre) {
    case 1:
        //5%
        maxBodovi = 19;
        multiplikator = 10;
        break;
    case 2:
        //10%
        maxBodovi = 9;
        multiplikator = 20;
        break;
    case 3:
        //25%
        maxBodovi = 3;
        multiplikator = 50;
        break;
    case 4:
        maxBodovi = 1;
        multiplikator = 100;
        break;
    default:
        printf("Nevazeca tezina.\n");
        return;
    }

    while (1) {
        int krugBodovi = rand() % (maxBodovi + 1);

        bodoviPrije = bodoviPrije + krugBodovi;
        brojKrugova++;

        printf("\nU %d. krugu ste osvojili %d ECTS bodova!\n", brojKrugova, krugBodovi);

        if (krugBodovi == 0) {
            bodoviPoslije = MULTIPLY_SCORE(bodoviPrije, multiplikator);
            printf("Ukupno ste osvojili %d ECTS bodova prije mnozenja!\n", bodoviPrije);
            printf("Ukupno ste osvojili %d ECTS bodova poslije mnozenja!\n", bodoviPoslije);
            break;
        }

        printf("Zelite li nastaviti s igrom? (1/0): ");
        int odgovor;
        scanf("%d", &odgovor);

        if (odgovor == 0) {
            bodoviPoslije = MULTIPLY_SCORE(bodoviPrije, multiplikator);
            printf("Ukupno ste osvojili %d ECTS bodova prije mnozenja!\n", bodoviPrije);
            printf("Ukupno ste osvojili %d ECTS bodova poslije mnozenja!\n", bodoviPoslije);
            break;
        }
    }
}

int usporediPoBrojuKrugova(const void* a, const void* b) {
    const Rezultat* rezultatA = (const Rezultat*)a;
    const Rezultat* rezultatB = (const Rezultat*)b;

    return rezultatA->brojKrugova - rezultatB->brojKrugova;
}

int usporediPoOsvojenimBodovima(const void* a, const void* b) {
    const Rezultat* rezultatA = (const Rezultat*)a;
    const Rezultat* rezultatB = (const Rezultat*)b;

    return rezultatA->bodoviPoslije - rezultatB->bodoviPoslije;
}

int usporediPoTeziniIgre(const void* a, const void* b) {
    const Rezultat* rezultatA = (const Rezultat*)a;
    const Rezultat* rezultatB = (const Rezultat*)b;

    return rezultatA->tezinaIgre - rezultatB->tezinaIgre;
}

void azurirajLjestvicuPoBrojuKrugova(Rezultat* rezultati, int brojRezultata) {
    // Sortiranje rezultata po broju osvojenih bodova
    qsort(rezultati, brojRezultata, sizeof(Rezultat), usporediPoBrojuKrugova);

    FILE* file;
    file = fopen("azuriranaLjestvica.txt", "w");

    if (file != NULL) {
        fprintf(file, "Ažurirana ljestvica:\n");
        for (int i = 0; i < brojRezultata; i++) {
            fprintf(file, "%s - %s - %s - %d - %d - %d\n",
                rezultati[i].igrac.ime,
                rezultati[i].igrac.nadimak,
                rezultati[i].igrac.prezime,
                rezultati[i].tezinaIgre,
                rezultati[i].brojKrugova,
                rezultati[i].bodoviPoslije);
        }
        fclose(file);
        printf("\Azurirana ljestvica zapisana u datoteku 'azuriranaLjestvica.txt'.\n");
    }
    else {
        printf("\nNije moguce otvoriti datoteku za pisanje.\n");
    }
}

void azurirajLjestvicuPoOsvojenimBodovima(Rezultat* rezultati, int brojRezultata) {
    // Sortiranje rezultata po broju osvojenih bodova
    qsort(rezultati, brojRezultata, sizeof(Rezultat), usporediPoOsvojenimBodovima);

    FILE* file;
    file = fopen("azuriranaLjestvica.txt", "w");

    if (file != NULL) {
        fprintf(file, "Ažurirana ljestvica:\n");
        for (int i = 0; i < brojRezultata; i++) {
            fprintf(file, "%s - %s - %s - %d - %d - %d\n",
                rezultati[i].igrac.ime,
                rezultati[i].igrac.nadimak,
                rezultati[i].igrac.prezime,
                rezultati[i].tezinaIgre,
                rezultati[i].brojKrugova,
                rezultati[i].bodoviPoslije);
        }
        fclose(file);
        printf("\Azurirana ljestvica zapisana u datoteku 'azuriranaLjestvica.txt'.\n");
    }
    else {
        printf("\nNije moguce otvoriti datoteku za pisanje.\n");
    }
}

void azurirajLjestvicuPoTeziniIgre(Rezultat* rezultati, int brojRezultata) {
    // Sortiranje rezultata po broju osvojenih bodova
    qsort(rezultati, brojRezultata, sizeof(Rezultat), usporediPoTeziniIgre);

    FILE* file;
    file = fopen("azuriranaLjestvica.txt", "w");

    if (file != NULL) {
        fprintf(file, "Azurirana ljestvica:\n");
        for (int i = 0; i < brojRezultata; i++) {
            fprintf(file, "%s - %s - %s - %d - %d - %d\n",
                rezultati[i].igrac.ime,
                rezultati[i].igrac.nadimak,
                rezultati[i].igrac.prezime,
                rezultati[i].tezinaIgre,
                rezultati[i].brojKrugova,
                rezultati[i].bodoviPoslije);
        }
        fclose(file);
        printf("\Azurirana ljestvica zapisana u datoteku 'azuriranaLjestvica.txt'.\n");
    }
    else {
        printf("\nNije moguce otvoriti datoteku za pisanje.\n");
    }
}
