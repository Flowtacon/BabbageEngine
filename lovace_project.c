#include <stdio.h>

#define PAMET_VELIKOST 10

// Struktura reprezentuje Babbegeův stroj
typedef struct {
	int store[PAMET_VELIKOST]; // Mechanická paměť na čísla
} AnalyticalEngine;

// Funkce pro uložení čísla na adresu v paměti
void uloz(AnalyticalEngine* stroj, int adresa, int hodnota) {
	if (adresa >= 0 && adresa < PAMET_VELIKOST) {
		stroj->store[adresa] = hodnota;
	}
}

// Funkce mlecí jednotky (mill) pro sčítání dvou ozubených kol
void secti(AnalyticalEngine* stroj, int adr1, int adr2, int cil) {
	int cislo1 = stroj->store[adr1];
	int cislo2 = stroj->store[adr2];

	// Výpočet v jednotce mill a uložení zpět do store
	stroj->store[cil] = cislo1 + cislo2;
}


int main() {
	AnalyticalEngine stroj;

	//Vynulování paměti
	for (int i = 0; i < PAMET_VELIKOST; i++) {
		stroj.store[i] = 0;
	}

	//Vstup pro zadání hodnoty a adresy uživatelem:
	printf("Zadej ciselnou hodnotu pro adresu:\n");
	int adresa, hodnota;
	while (1) {
		printf("> ");
		if (scanf_s("%d %d", &adresa, &hodnota) != 2 || adresa < 0 || adresa >= PAMET_VELIKOST) {
			break;
		}
		uloz(&stroj, adresa, hodnota);
	}

	// Program: mechanické zadání čísel na hřídele
	printf("\nSčítám V0 + V1 -> v2\n");

	secti
	(&stroj, 0, 1, 2);

	// Výpis výsledku z cílové hřídele
	printf("Vysledek v pameti V2: %d\n", stroj.store[2]);

	return 0;
}