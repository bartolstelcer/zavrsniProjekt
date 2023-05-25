//6

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tablica.h"

void updateLeaderboard(const LeaderboardEntry* entry) {
    FILE* file = fopen("tablica.txt", "a");
    if (file == NULL) {
        printf("Neuspjesno otvaranje datoteke!\n");
        return;
    }

    fprintf(file, "%s %s %s %d %d\n", entry->ime, entry->nadimak, entry->prezime, entry->level, entry->ectsBodovi);
    fclose(file);
}

void displayLeaderboard() {
    FILE* file = fopen("tablica.txt", "r");
    if (file == NULL) {
        printf("Neuspjesno otvaranje datoteke!\n");
        return 0;
    }

    LeaderboardEntry entry;
    printf("Tablica:\n");
    printf("-------------------------------------------------\n");
    printf("Ime    Nadimak     Prezime    Level    ECTS bodovi\n");
    printf("-------------------------------------------------\n");

    while (fscanf(file, "%s %s %s %d %d", entry.ime, entry.nadimak, entry.prezime, &entry.level, &entry.ectsBodovi) != EOF) {
        printf("%-14s%-13s%-13s%-9d%d\n", entry.prezime, entry.nadimak, entry.prezime, entry.level, entry.ectsBodovi);
    }

    printf("-------------------------------------------------\n");
    fclose(file);
}