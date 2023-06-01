#pragma once

//6

#define _CRT_SECURE_NO_WARNINGS

#ifndef LJESTVICA_H
#define LJESTVICA_H

//3

typedef struct ljestvica {
	char ime[50];
	char nadimak[50];
	char prezime[50];
	int nivo;
	int ectsBodovi;
} LJESTVICA;

void updateLeaderboard(const LJESTVICA* entry);
void displayLeaderboard();

#endif  // LJESTVICA_H
