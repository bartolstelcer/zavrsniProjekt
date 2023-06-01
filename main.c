//6

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "igrac.h"
#include "ljestvica.h"

int main(void) {

	//1
	//2

	int izbor, tezinaIgreIzbor, brisanjeIzbor, pretrazivanjeIzbor, sortiranjeIzbor;
	char povratakTezinaIgre, povratakBrisanje, povratakPretrazivanje, povratakSortiranje;
	char izlazakIzPrograma;

	//5

	static IGRAC* currentPlayer = NULL;

	//8

	do {
		printf("Izbornik:\n");
		printf("1. Zapocni igru\n");
		printf("2. Rang ljestvica\n");
		printf("3. Brisanje igraca na ljestvici\n");
		printf("4. Pretrazivanje igraca na ljestvici\n");
		printf("5. Sortiranje igraca na ljestvici\n");
		printf("6. Pravila igre\n");
		printf("7. Izlazak iz igre\n");
		printf("Unesite vas izbor: ");
		scanf("%d", &izbor);
		getchar();

		switch (izbor) {
		case 1:
			if (currentPlayer != NULL) {
				//14
				free(currentPlayer);
				currentPlayer = NULL;
			}

			//14

			currentPlayer = (IGRAC*)malloc(sizeof(IGRAC));
			if (currentPlayer == NULL) {
				printf("Dodjela memorije nije uspjela!\n");
				break;
			}

			printf("Ime: ");
			scanf("%s", currentPlayer->ime);
			printf("Prezime: ");
			scanf("%s", currentPlayer->prezime);
			printf("Nadimak: ");
			scanf("%s", currentPlayer->nadimak);

			savePlayerInfo(currentPlayer);

			//8

			printf("Izaberite tezinu igre:\n");
			printf("1. Easy mode\n");
			printf("2. Medium mode\n");
			printf("3. Hard mode\n");
			printf("4. Impossible mode\n");
			printf("5. Povratak\n");
			printf("Unesite vas izbor: ");
			scanf("%d", &tezinaIgreIzbor);
			getchar();

			switch (tezinaIgreIzbor) {
			case 1:
				printf("Pocetak igre u easy modu. . .\n");
				break;
			case 2:
				printf("Pocetak igre u medium modu. . .\n");
				break;
			case 3:
				printf("Pocetak igre u hard modu. . .\n");
				break;
			case 4:
				printf("Pocetak igre u impossible modu. . .\n");
				break;
			case 5:
				printf("Zelite li se vratiti na prijasnji izbornik? (da/ne): ");
				scanf("%c", &povratakTezinaIgre);
				break;
			default:
				printf("Nevazeca opcija!\n");
				break;
			}

			playGame(currentPlayer);
			break;

		case 2:
			displayLeaderboard();
			break;

		case 3:
			printf("1. Brisanje igraca po imenu\n");
			printf("2. Brisanje igraca po prezimenu\n");
			printf("3. Brisanje igraca po nadimku\n");
			printf("4. Brisanje igraca po broju osvojenih ECTS bodova\n");
			printf("5. Brisanje igraca po nivou na kojem je igrac zavrsio igru\n");
			printf("6. Povratak");
			printf("Unesite vas izbor: ");
			scanf("%d", &brisanjeIzbor);
			
			switch (brisanjeIzbor) {
			case 1:
				printf("Unesite ime igraca kojeg zelite obrisati: ");
				scanf();
				break;
			case 2:
				printf("Unesite prezime igraca kojeg zelite obrisati: ");
				scanf();
				break;
			case 3:
				printf("Unesite nadimak igraca kojeg zelite obrisati: ");
				scanf();
				break;
			case 4:
				printf("Unesite broj osvojenih ECTS bodova igraca kojeg zelite obrisati: ");
				scanf();
				break;
			case 5:
				printf("Unesite nivo na kojem je igrac zavrsio igru igraca kojeg zelite obrisati: ");
				scanf();
				break;
			case 6:
				printf("Zelite li se vratiti na prijasnji izbornik? (da/ne): ");
				scanf("%c", &povratakBrisanje);
				break;
			default:
				printf("Nevazeca opcija!\n");
				break;
			}
			break;
		
		case 4:
			printf("1. Pretrazivanje igraca po imenu\n");
			printf("2. Pretrazivanje igraca po prezimenu\n");
			printf("3. Pretrazivanje igraca po nadimku\n");
			printf("4. Pretrazivanje igraca po broju osvojenih ECTS bodova\n");
			printf("5. Pretrazivanje igraca po nivou na kojem je igrac zavrsio igru\n");
			printf("6. Povratak");
			printf("Unesite vas izbor: ");
			scanf("%d", &pretrazivanjeIzbor);

			switch (pretrazivanjeIzbor) {
			case 1:
				printf("Unesite ime igraca kojeg zelite pronaci: ");
				scanf();
				break;
			case 2:
				printf("Unesite prezime igraca kojeg zelite pronaci: ");
				scanf();
				break;
			case 3:
				printf("Unesite nadimak igraca kojeg zelite pronaci: ");
				scanf();
				break;
			case 4:
				printf("Unesite broj osvojenih ECTS bodova kojeg zelite pronaci: ");
				scanf();
				break;
			case 5:
				printf("Unesite nivo na kojem je igrac zavrsio igru igraca kojeg zelite pronaci: ");
				scanf();
				break;
			case 6:
				printf("Zelite li se vratiti na prijasnji izbornik? (da/ne): ");
				scanf("%c", &povratakPretrazivanje);
				break;
			default:
				printf("Nevazeca opcija!\n");
				break;
			}
			break;
		
		case 5:
				printf("1. Abecedno sortiranje igraca po imenu (A - Z)\n");
				printf("2. Abecedno sortiranje igraca po imenu (Z - A)\n");
				printf("3. Abecedno sortiranje igraca po prezimenu (A - Z)\n");
				printf("4. Abecedno sortiranje igraca po prezimenu (Z - A)\n");
				printf("5. Abecedno sortiranje igraca po nadimku (A - Z)\n");
				printf("6. Abecedno sortiranje igraca po nadimku (Z - A)\n");
				printf("7. Sortiranje igraca po najvise osvojenih ECTS bodova\n");
				printf("8. Sortiranje igraca po najmanje osvojenih ECTS bodova\n");
				printf("9. Sortiranje igraca po najvecem nivou na kojem je igrac zavrsio igru\n");
				printf("10. Sortiranje igraca po najmanjem nivou na kojem je igrac zavrsio igru\n");
				printf("11. Povratak");
				printf("Unesite vas izbor: ");
				scanf("%d", &sortiranjeIzbor);

				switch (sortiranjeIzbor) {
				case 1:
					printf("Abecedno sortiranje igraca po imenu (A - Z): ");
				case 2:
					printf("Abecedno sortiranje igraca po imenu (Z - A): ");
				case 3:
					printf("Abecedno sortiranje igraca po prezimenu (A - Z): ");
				case 4:
					printf("Abecedno sortiranje igraca po prezimenu (Z - A): ");
				case 5:
					printf("Abecedno sortiranje igraca po nadimku (A - Z): ");
				case 6:
					printf("Abecedno sortiranje igraca po nadimku (Z - A): ");
				case 7:
					printf("Sortiranje igraca po najvise osvojenih ECTS bodova: ");
				case 8:
					printf("Sortiranje igraca po najmanje osvojenih ECTS bodova: ");
				case 9:
					printf("Sortiranje igraca po najvecem nivou na kojem je igrac zavrsio igru: ");
				case 10:
					printf("Sortiranje igraca po najmanjem nivou na kojem je igrac zavrsio igru: ");
				case 11:
					printf("Zelite li se vratiti na prijasnji izbornik? (da/ne): ");
					scanf("%d", &povratakSortiranje);
				default:
					printf("Nevazeca opcija!\n");
					break;
				}
			break;
		case 6:
			printf("Pravila igre: \n");
			break;
		
		case 7:
			printf("Zelite li izaci iz igre? (da/ne): ");
			scanf("%c", &izlazakIzPrograma);

			if (izlazakIzPrograma == 'DA' || izlazakIzPrograma == "da" || izlazakIzPrograma == "Da" || izlazakIzPrograma == 'dA') {
				printf("Izlazak iz igre!\n");
				if (currentPlayer != NULL) {

					//14

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
	} while (izbor = !7);

	//15

	if (currentPlayer != NULL) {
		free(currentPlayer);
		currentPlayer = NULL;
	}

	return 0;
}
