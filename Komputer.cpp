#pragma once
#include"Komputer.h"
#include<iostream>
using namespace std;

extern char plansza[21][96];


void Komputer::rozstaw(int numerGracza) {
	char wybor;
	int pole;
	int los;

	do {
		los = rand() % 10;
		pole = tab[los];
	} while (pole == '*');
	tab[los] = '*';

	do {
		los = rand() % 9;
		wybor = pionki[los].pionek;
	} while (tab2[los] == 0);
	tab2[los] = 0;


	if (numerGracza == 1) {
		for (int i = 0; i < 10; i++)
			if (i < 5) {
				if (plansza[16][i * 5 + 7] == pole + '0') {
					plansza[16][i * 5 + 7] = wybor;
					pionki[los].rzad = 16;
					pionki[los].kolumna = i * 5 + 7;
				}
			}
			else {
				if (plansza[16][i * 5 + 12] == pole + '0') {
					plansza[16][i * 5 + 12] = wybor;
					pionki[los].rzad = 16;
					pionki[los].kolumna = i * 5 + 12;
				}
			}
	}
	if (numerGracza == 2) {
		for (int i = 0; i < 10; i++)
			if (i < 5) {
				if (plansza[4][i * 5 + 7] == pole + '0') {
					plansza[4][i * 5 + 7] = wybor;
					pionki[los].rzad = 4;
					pionki[los].kolumna = i * 5 + 7;
				}
			}
			else {
				if (plansza[16][i * 5 + 42] == pole + '0') {
					plansza[16][i * 5 + 42] = wybor;
					pionki[los].rzad = 16;
					pionki[los].kolumna = i * 5 + 42;
				}
			}
	}

	if (numerGracza == 3) {
		for (int i = 0; i < 10; i++)
			if (i < 5) {
				if (plansza[4][i * 5 + 37] == pole + '0') {
					plansza[4][i * 5 + 37] = wybor;
					pionki[los].rzad = 4;
					pionki[los].kolumna = i * 5 + 37;
				}
			}
			else {
				if (plansza[4][i * 5 + 42] == pole + '0') {
					plansza[4][i * 5 + 42] = wybor;
					pionki[los].rzad = 4;
					pionki[los].kolumna = i * 5 + 42;
				}
			}
	}


}
int Komputer::ruch(int numerGracza) {
	int ruchy = 0;
	int licznik = 0;
	while (licznik == 0) {
		ruchy = 0;
		for (int i = 0; i < 9; i++) {
			if (numergracza == 1) {
				for (int j = -1; j < 2; j++) {
					if (pionki[i].pionek == '*')
						break;
					if ((plansza[pionki[i].rzad - 3][pionki[i].kolumna + 5 * j]) == '\0')
						continue;
					if ((plansza[pionki[i].rzad - 3][pionki[i].kolumna + 5 * j + 1]) == numerGracza + '0')
						continue;
					if (bicie(pionki[i].pionek, plansza[pionki[i].rzad - 3][pionki[i].kolumna + 5 * j]) == 0)
						continue;
					ruchy++;
				}
			}
			if (numergracza == 2) {
				for (int j = -1; j < 2; j++) {
					if (pionki[i].kolumna < 50) {
						if (pionki[i].pionek == '*')
							break;
						if ((plansza[pionki[i].rzad + 3][pionki[i].kolumna + 5 * j]) == '\0')
							continue;
						if ((plansza[pionki[i].rzad + 3][pionki[i].kolumna + 5 * j + 1]) == numerGracza + '0')
							continue;
						if (bicie(pionki[i].pionek, plansza[pionki[i].rzad + 3][pionki[i].kolumna + 5 * j]) == 0)
							continue;
						ruchy++;
					}
					else {
						if (pionki[i].pionek == '*')
							break;
						if ((plansza[pionki[i].rzad - 3][pionki[i].kolumna + 5 * j]) == '\0')
							continue;
						if ((plansza[pionki[i].rzad - 3][pionki[i].kolumna + 5 * j + 1]) == numerGracza + '0')
							continue;
						if (bicie(pionki[i].pionek, plansza[pionki[i].rzad - 3][pionki[i].kolumna + 5 * j]) == 0)
							continue;
						ruchy++;
					}
				}
			}
			if (numergracza == 3) {
				for (int j = -1; j < 2; j++) {
					if (pionki[i].pionek == '*')
						break;
					if ((plansza[pionki[i].rzad + 3][pionki[i].kolumna + 5 * j]) == '\0')
						continue;
					if ((plansza[pionki[i].rzad + 3][pionki[i].kolumna + 5 * j + 1]) == numerGracza + '0')
						continue;
					if (bicie(pionki[i].pionek, plansza[pionki[i].rzad + 3][pionki[i].kolumna + 5 * j]) == 0)
						continue;
					ruchy++;
				}
			}
		}

		if (ruchy == 0) {
			cout << "brak mozliwych ruchow dla gracza " << numergracza << endl;
			return ruchy;
		}

		char wybor;
		int pole;
		do {
			wybor = pionki[rand() % 9].pionek;
		} while (wybor == '*');
		int x;
		for (int i = 0; i < 9; i++) {
			if (pionki[i].pionek == wybor)
				x = i;
		}
		pole = rand() % 3 + 1;

		switch (numerGracza) {
		case 1:
			if (pole == 1)
				licznik = kontrola(1, pionki[x], -3, -5, 1);
			if (pole == 2)
				licznik = kontrola(1, pionki[x], -3, 0, 1);
			if (pole == 3)
				licznik = kontrola(1, pionki[x], -3, 5, 1);
			break;
		case 2:
			if (pole == 1)
				if (pionki[x].kolumna < 50)
					licznik = kontrola(2, pionki[x], 3, 5, 1);
				else
					licznik = kontrola(2, pionki[x], -3, -5, 1);
			if (pole == 2)
				if (pionki[x].kolumna < 50)
					licznik = kontrola(2, pionki[x], 3, 0, 1);
				else
					licznik = kontrola(2, pionki[x], -3, 0, 1);
			if (pole == 3)
				if (pionki[x].kolumna < 50)
					licznik = kontrola(2, pionki[x], 3, -5, 1);
				else
					licznik = kontrola(2, pionki[x], -3, 5, 1);
			break;
		case 3:
			if (pole == 1)
				licznik = kontrola(3, pionki[x], 3, 5, 1);
			if (pole == 2)
				licznik = kontrola(3, pionki[x], 3, 0, 1);
			if (pole == 3)
				licznik = kontrola(3, pionki[x], 3, -5, 1);
			break;
		}
	}
	if (licznik == 2) {
		punkty += 5;
		ruchy -= 100;
	}
	return ruchy;


}
