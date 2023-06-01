//6

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "igrac.h"

//16

void savePlayerInfo(const IGRAC* player) {
	FILE* file = fopen("igrac.txt", "w");
	if (file == NULL) {
		printf("Neuspjesno otvaranje datoteke!\n");
		return 0;
	}

	fprintf(file, "%s %s %s %s\n", player->ime, player->nadimak, player->prezime);
	fclose(file);
}

//16

IGRAC* loadPlayerInfo() {
	FILE* file = fopen("igrac.txt", "r");
	if (file == NULL) {
		printf("Neuspjesno otvaranje datoteke!\n");
		return 0;
	}

	//14

	IGRAC* player = (IGRAC*)malloc(sizeof(IGRAC));
	if (player == NULL) {
		printf("Dodjela memorije nije uspjela!\n");
		fclose(file);
		return NULL;
	}

	fscanf(file, "%s %s %s %s", player->ime, player->nadimak, player->prezime);
	fclose(file);

	return player;
}

void playGame(IGRAC* player) {

}
