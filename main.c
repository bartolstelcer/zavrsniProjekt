#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "funkcije.h"

#define MULTIPLY_SCORE(bodoviPrije, multiplikator) (bodoviPrije * multiplikator)

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
        printf("5. Azuriranje rezultata\n");
        printf("6. Izlazak iz igre\n");
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
            printf("\nIzbornik:\n");
            printf("1. Azuriranje rezultata po krugovima\n");
            printf("2. Azuriranje rezultata po bodovima\n");
            printf("3. Azuriranje rezultata po tezini\n");
            printf("Odaberite opciju: ");

            int opcijaAzuriranja;
            scanf("%d", &opcijaAzuriranja);

            switch (opcijaAzuriranja) {
            case 1:
                int usporediPoBrojuKrugova(const void* a, const void* b);
                void azurirajLjestvicuPoBrojuKrugova(Rezultat * rezultati, int brojRezultata);
                break;
            case 2:
                int usporediPoOsvojenimBodovima(const void* a, const void* b);
                void azurirajLjestvicuPoOsvojenimBodovima(Rezultat * rezultati, int brojRezultata);
                break;
            case 3:
                int usporediPoTeziniIgre(const void* a, const void* b);
                void azurirajLjestvicuPoTeziniIgre(Rezultat * rezultati, int brojRezultata);
                break;
            default:
                printf("Nevazeci izbor za azuriranje rezultata.\n");
            }
            break;
        case 6:
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
