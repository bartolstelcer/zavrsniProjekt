#pragma once

//6

#define _CRT_SECURE_NO_WARNINGS

#ifndef IGRAC_H
#define IGRAC_H

//3

typedef struct igrac {
	char ime[50];
	char nadimak[50];
	char prezime[50];
} IGRAC;

//4

void savePlayerInfo(const IGRAC* player);
void playGame(IGRAC* player);
int checkPassword(const IGRAC* player, const char* password);

#endif  // IGRAC_H

