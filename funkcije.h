#ifndef FUNKCIJE_H
#define FUNKCIJE_H

typedef struct {
    char ime[50];
    char prezime[50];
    char nadimak[50];
} Igrac;

typedef struct {
    Igrac igrac;
    int tezinaIgre;
    int brojKrugova;
    int bodoviPoslije;
} Rezultat;

void unesiPodatkeIgraca(Igrac* igrac);
void unesiBodoveUDatoteku(Igrac igrac, int tezinaIgre, int brojKrugova, int bodoviPoslije);
void unesiPodatkeIgracaUDatoteku(Igrac igrac);
void prikaziLjestvicu();
void igrajIgru(int tezinaIgre, Igrac igrac);
int usporediPoBrojuKrugova(const void* a, const void* b);
int usporediPoOsvojenimBodovima(const void* a, const void* b);
int usporediPoTeziniIgre(const void* a, const void* b);
void azurirajLjestvicuPoBrojuKrugova(Rezultat* rezultati, int brojRezultata);
void azurirajLjestvicuPoOsvojenimBodovima(Rezultat* rezultati, int brojRezultata);
void azurirajLjestvicuPoTeziniIgre(Rezultat* rezultati, int brojRezultata);

#endif
