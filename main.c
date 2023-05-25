//6

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "igrac.h"
#include "tablica.h"

int main(void) {
    int izbor;
    char lozinka[50];

    //5

    static Igrac* currentPlayer = NULL;

    //8

    do {
        printf("Welcome to the Game!\n");
        printf("Menu:\n");
        printf("1. Zapocni igru\n");
        printf("2. Ucitaj igru\n");
        printf("3. Rang ljestvica\n");
        printf("4. Izlazak iz programa\n");
        printf("Unesite vas izbor: ");
        scanf("%d", &izbor);
        getchar();

        switch (izbor) {
        case 1:
            if (currentPlayer != NULL) {
                free(currentPlayer);
                currentPlayer = NULL;
            }

            //14

            currentPlayer = (Igrac*)malloc(sizeof(Igrac));
            if (currentPlayer == NULL) {
                printf("Dodjela memorije nije uspjela!\n");
                break;
            }

            printf("Ime: ");
            scanf("%s", currentPlayer->ime);
            printf("Nadimak: ");
            scanf("%s", currentPlayer->nadimak);
            printf("Prezime: ");
            scanf("%s", currentPlayer->prezime);
            printf("Lozinka: ");
            scanf("%s", currentPlayer->lozinka);

            savePlayerInfo(currentPlayer);

            //8

            int levelOption;
            printf("Choose the game difficulty:\n");
            printf("1. Easy mode\n");
            printf("2. Medium mode\n");
            printf("3. Hard mode\n");
            printf("Enter your option: ");
            scanf("%d", &levelOption);
            getchar();  

            switch (levelOption) {
            case 1:
                printf("Starting the game in Easy mode...\n");
                break;
            case 2:
                printf("Starting the game in Medium mode...\n");
                break;
            case 3:
                printf("Starting the game in Hard mode...\n");
                break;
            default:
                printf("Nevazeca opcija!\n");
                break;
            }

            playGame(currentPlayer);
            break;

        case 2:
            if (currentPlayer != NULL) {
                free(currentPlayer);
                currentPlayer = NULL;
            }

            currentPlayer = loadPlayerInfo();
            if (currentPlayer == NULL) {
                printf("Player information not found\n");
                break;
            }

            printf("Unesite lozinku: ");
            scanf("%s", lozinka);

            if (checkPassword(currentPlayer, lozinka)) {
                playGame(currentPlayer);
            }
            else {
                printf("Pogresna lozinka!!\n");
            }

            break;

        case 3:
            displayLeaderboard();
            break;

        case 4:
            char exitOption;
            printf("Zelite li izaci iz programa (da/ne): ");
            scanf("%c", &exitOption);

            if (exitOption == 'da') {
                printf("Izlazak iz programa!\n");
                if (currentPlayer != NULL) {
                    free(currentPlayer);
                    currentPlayer = NULL;
                }
                return 0;
            }
            break;

        default:
            printf("Nevazeca opcija!\n");
            break;
        }

        printf("\n");
    } while (izbor != 4);

    //15

    if (currentPlayer != NULL) {
        free(currentPlayer);
        currentPlayer = NULL;
    }

    return 0;
}


