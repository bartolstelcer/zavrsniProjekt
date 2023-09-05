#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MULTIPLY_SCORE(bodoviPrije, multiplikator) (bodoviPrije * multiplikator)

typedef struct {
    char ime[50];
    char prezime[50];
    char nadimak[50];
} Igrac;

void unesiPodatkeIgraca(Igrac* igrac) {
    printf("Unesite ime: ");
    scanf("%s", igrac->ime);
    printf("Unesite prezime: ");
    scanf("%s", igrac->prezime);
    printf("Unesite nadimak: ");
    scanf("%s", igrac->nadimak);
}

void unesiBodoveUDatoteku(Igrac igrac, int tezinaIgre, int bodoviPoslije) {
    FILE* file;
    file = fopen("ljestvica.txt", "a");

    if (file != NULL) {
        fprintf(file, "%s - %2s - %2s - %2d - %2d\n", igrac.ime, igrac.nadimak, igrac.prezime, tezinaIgre, bodoviPoslije);
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
        maxBodovi = 10;
        multiplikator = 1;
        break;
    case 2:
        maxBodovi = 7;
        multiplikator = 2;
        break;
    case 3:
        maxBodovi = 5;
        multiplikator = 5;
        break;
    case 4:
        maxBodovi = 3;
        multiplikator = 10;
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

    unesiBodoveUDatoteku(igrac, tezinaIgre, bodoviPoslije);
}

int main(void) {
    srand(time(NULL));

    Igrac igrac;

    unesiPodatkeIgraca(&igrac);
    unesiPodatkeIgracaUDatoteku(igrac);

    while (1) {
        printf("\nIzbornik:\n");
        printf("1. Zapocni igru\n");
        printf("2. Ljestvica\n");
        printf("3. Brisanje datoteka\n");
        printf("4. Preimenovanje datoteka\n");
        printf("5. Izlazak iz igre\n");
        printf("Odaberite opciju: ");

        int izbor;
        scanf("%d", &izbor);

        switch (izbor) {
        case 1: {
            printf("\nIzbornik:\n");
            printf("1. Easy mode\n");
            printf("2. Medium mode\n");
            printf("3. Hard mode\n");
            printf("4. Impossible mode\n");
            printf("Odaberite opciju: ");

            int tezina;
            scanf("%d", &tezina);

            igrajIgru(tezina, igrac);
            break;
        }
        case 2:
            prikaziLjestvicu();
            break;
        case 3:
            if (remove("igrac.txt") == 0) {
                printf("\nDatoteka 'igrac.txt' uspjesno obrisana.\n");
            }
            else {
                printf("\nNije moguce obrisati datoteku 'igrac.txt'.\n");
            }
            break;
        case 4:
            if (rename("igrac.txt", "prijasnjiIgrac.txt") == 0) {
                printf("\nDatoteka 'igrac.txt' uspjesno preimenovana.\n");
            }
            else {
                printf("\nNije moguce preimenovati datoteku 'igrac.txt'.\n");
            }
            break;
        case 5:
            printf("\nZelite li izaci iz igre? (1/0): ");
            int odgovor;
            scanf("%d", &odgovor);
            if (odgovor == 1) {
                return 0;
            }
            break;
        default:
            printf("Nevazeci izbor!\n");
        }
    }

    return 0;
}
