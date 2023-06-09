//6

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ljestvica.h"

void updateLeaderboard(const LJESTVICA* entry) {
	FILE* file = fopen("ljestvica.txt", "a");
	if (file == NULL) {
		printf("Neuspjesno otvaranje datoteke!\n");
		return;
	}

	fprintf(file, "%s %s %s %d %d\n", entry->ime, entry->nadimak, entry->prezime, entry->nivo, entry->ectsBodovi);
	fclose(file);
}

void displayLeaderboard() {
	FILE* file = fopen("ljestvica.txt", "r");
	if (file == NULL) {
		printf("Neuspjesno otvaranje datoteke!\n");
		return 0;
	}

	LJESTVICA entry;
	printf("Ljestvica:\n");
	printf("-------------------------------------------------\n");
	printf("Ime    Nadimak     Prezime    Nivo    ECTS bodovi\n");
	printf("-------------------------------------------------\n");

	while (fscanf(file, "%s %s %s %d %d", entry.ime, entry.nadimak, entry.prezime, &entry.nivo, &entry.ectsBodovi) != EOF) {
		printf("%-14s''%-13s''%-13s%-9d%d\n", entry.ime, entry.nadimak, entry.prezime, entry.nivo, entry.ectsBodovi);
	}

	printf("-------------------------------------------------\n");
	fclose(file);
}
