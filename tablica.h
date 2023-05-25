//6

#define _CRT_SECURE_NO_WARNINGS

#ifndef TABLICA_H
#define TABLICA_H

//3

typedef struct {
    char ime[50];
    char nadimak[50];
    char prezime[50];
    int level;
    int ectsBodovi;
} LeaderboardEntry;

void updateLeaderboard(const LeaderboardEntry* entry);
void displayLeaderboard();

#endif  // TABLICA_H




