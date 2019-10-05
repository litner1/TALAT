#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Gracz.h"
#include"Czlowiek.h"
using namespace std;

extern char plansza[21][96];

template<class T1, class T2>
T1 kontorladanych(T2* napis, T2* napis2, T1 rodzaj) {
	int x = strlen(napis);
	if (rodzaj == 1) {
		for (int i = 0; i < 9; i++)
			if (napis[0] == napis2[i] && napis[1] == '\0')
				return 1;
	}
	if (rodzaj == 2) {
		for (int i = 0; i < 10; i++)
			if (napis[0] == napis2[i] && napis[1] == '\0')
				return 1;
	}
	if (rodzaj == 3) {
		for (int i = 0; i < 5; i++)
			if (napis[0] == napis2[i] && napis[1] == '\0')
				return 1;
	}
	while (getchar() != '\n');
	return 0;
}

void Czlowiek::rozstaw(int numerGracza) {
	wypisz();
	char wybor;
	char pole;
	cout << "Gracz " << numerGracza << " pozostale pionki:" << endl;
	for (int i = 0; i < 9; i++)
		if (tabc[i] == 1)
			cout << pionki[i].pionek << " ";


	int poprawne = 0;
	char y[10];
	do {
		cout << "wybierz pionka" << endl;
		scanf("%s", &y);
		poprawne = kontorladanych(y, poprawnepionki, 1);
		if (poprawne == 1) {
			wybor = y[0];
			for (int j = 0; j < 9; j++) {
				if (y[0] == poprawnepionki[j])
					poprawnepionki[j] = '\0';
			}
		}
		else
			cout << "bledne dane" << endl;
	} while (poprawne == 0);


	int k = -1;
	for (int i = 0; i < 9; i++)
		if (pionki[i].pionek == wybor) {
			tabc[i] = 0;
			k = i;
		}

	poprawne = 0;
	do {
		cout << "wybierz pole" << endl;
		scanf("%s", &y);
		poprawne = kontorladanych(y, poprawnepola, 2);
		if (poprawne == 1) {
			pole = y[0];
			for (int j = 0; j < 10; j++) {
				if (y[0] == poprawnepola[j])
					poprawnepola[j] = '\0';
			}
		}
		else
			cout << "bledne dane" << endl;
	} while (poprawne == 0);


	if (numerGracza == 1) {
		for (int i = 0; i < 10; i++)
			if (i < 5) {
				if (plansza[16][i * 5 + 7] == pole) {
					plansza[16][i * 5 + 7] = wybor;
					pionki[k].rzad = 16;
					pionki[k].kolumna = i * 5 + 7;
				}
			}
			else {
				if (plansza[16][i * 5 + 12] == pole) {
					plansza[16][i * 5 + 12] = wybor;
					pionki[k].rzad = 16;
					pionki[k].kolumna = i * 5 + 12;
				}
			}
	}
	if (numerGracza == 2) {
		for (int i = 0; i < 10; i++)
			if (i < 5) {
				if (plansza[4][i * 5 + 7] == pole) {
					plansza[4][i * 5 + 7] = wybor;
					pionki[k].rzad = 4;
					pionki[k].kolumna = i * 5 + 7;
				}
			}
			else {
				if (plansza[16][i * 5 + 42] == pole) {
					plansza[16][i * 5 + 42] = wybor;
					pionki[k].rzad = 16;
					pionki[k].kolumna = i * 5 + 42;
				}
			}
	}

	if (numerGracza == 3) {
		for (int i = 0; i < 10; i++)
			if (i < 5) {
				if (plansza[4][i * 5 + 37] == pole) {
					plansza[4][i * 5 + 37] = wybor;
					pionki[k].rzad = 4;
					pionki[k].kolumna = i * 5 + 37;
				}
			}
			else {
				if (plansza[4][i * 5 + 42] == pole) {
					plansza[4][i * 5 + 42] = wybor;
					pionki[k].rzad = 4;
					pionki[k].kolumna = i * 5 + 42;
				}
			}
	}
}
int Czlowiek::ruch(int numerGracza) {
	int ruchy = 0;
	int licznik = 0;
	while (licznik == 0) {
		ruchy = 0;
		wypisz(1);
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

		cout << endl << "gracz " << numergracza << " masz do wyboru " << ruchy << " ruchow" << endl;
		cout << endl << "gracz " << numergracza << " zostaly ci nastepujace pionki:" << endl;
		for (int i = 0; i < 9; i++)
			cout << pionki[i].pionek << "  ";
		cout << endl << "ktroym pionkiem chcesz sie ruszyc:" << endl;

		char wybor;
		int pole;
		int poprawne = 0;
		char bufor[10];
		for (int i = 0; i < 9; i++)
			poprawnepionki[i] = pionki[i].pionek;
		do {
			cout << "wybierz pionka" << endl;
			scanf("%s", &bufor);
			poprawne = kontorladanych(bufor, poprawnepionki, 1);
			if (bufor[0] == '*')
				poprawne = 0;
			if (poprawne == 1)
				wybor = bufor[0];
			else
				cout << "bledne dane" << endl;
		} while (poprawne == 0);

		poprawne = 0;
		char poprawnepola[6] = "12345";
		do {
			cout << "wybierz pole" << endl;
			cout << endl << "jesli chcesz sie ruszyc w lewo i do przodu (wzgledem pionka) wybierz 1";
			cout << endl << "jesli chcesz sie ruszyc do przodu (wzgledem pionka) wybierz 2";
			cout << endl << "jesli chcesz sie ruszyc w prawo i do przodu (wzgledem pionka) wybierz 3";
			cout << endl << "jesli chcesz zapisac gre wybierz 4";
			cout << endl << "jesli chcesz wczytac gre wybierz 5" << endl;
			scanf("%s", &bufor);
			poprawne = kontorladanych(bufor, poprawnepola, 3);
			if (poprawne == 1)
				pole = bufor[0];
			else
				cout << "bledne dane" << endl;
		} while (poprawne == 0);

		int x;
		for (int i = 0; i < 9; i++)
			if (pionki[i].pionek == wybor)
				x = i;
		pole -= '0';

		if (pole == 4)
			return 200;
		if (pole == 5)
			return 300;

		switch (numerGracza) {
		case 1:
			if (pole == 1)
				licznik = kontrola(1, pionki[x], -3, -5);
			if (pole == 2)
				licznik = kontrola(1, pionki[x], -3, 0);
			if (pole == 3)
				licznik = kontrola(1, pionki[x], -3, 5);
			break;
		case 2:
			if (pole == 1)
				if (pionki[x].kolumna < 50)
					licznik = kontrola(2, pionki[x], 3, 5);
				else
					licznik = kontrola(2, pionki[x], -3, -5);
			if (pole == 2)
				if (pionki[x].kolumna < 50)
					licznik = kontrola(2, pionki[x], 3, 0);
				else
					licznik = kontrola(2, pionki[x], -3, 0);
			if (pole == 3)
				if (pionki[x].kolumna < 50)
					licznik = kontrola(2, pionki[x], 3, -5);
				else
					licznik = kontrola(2, pionki[x], -3, 5);
			break;
		case 3:
			if (pole == 1)
				licznik = kontrola(3, pionki[x], 3, 5);
			if (pole == 2)
				licznik = kontrola(3, pionki[x], 3, 0);
			if (pole == 3)
				licznik = kontrola(3, pionki[x], 3, -5);
			break;
		}
	}
	if (licznik == 2) {
		punkty += 5;
		ruchy -= 100;
	}
	return ruchy;
}
