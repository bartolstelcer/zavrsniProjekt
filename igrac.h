//6

#define _CRT_SECURE_NO_WARNINGS

#ifndef IGRAC_H
#define IGRAC_H

//3

typedef struct {
    char ime[50];
    char nadimak[50];
    char prezime[50];
    char lozinka[50];
} Igrac;

//4

void savePlayerInfo(const Igrac* player);
Igrac* loadPlayerInfo();
void playGame(Igrac* player);
int checkPassword(const Igrac* player, const char* password);

#endif  // IGRAC_H
