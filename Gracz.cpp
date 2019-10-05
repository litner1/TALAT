#pragma once

#include<iostream>
#include<Windows.h>
#include"Gracz.h"
#define Gracz1 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6)//zolty
#define Gracz2 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2)//zielony
#define Gracz3 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4)//czerwony
#define domyslny SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7)//bialy
#define czarny SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0)//czarny
using namespace std;

extern char plansza[21][96];

void Gracz::podsumowanie(int numergracza) {
	for (int i = 0; i < 90; i++) {
		if (numergracza == 1)
			if (plansza[4][i] == '1')
				punkty += 3;
		if (numergracza == 3)
			if (plansza[16][i] == '3')
				punkty += 3;
		if (numergracza == 2) {
			if (i < 50) {
				if (plansza[16][i] == '2')
					punkty += 3;
			}
			else
				if (plansza[4][i] == '2')
					punkty += 3;
		}
	}

}
void Gracz::kratka(int poziom, int przesuniecie) {
	char skladowe[3][6] = { " ___ " ,"|   |" , "|___|" };
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 5; j++)
			plansza[i + 3 * poziom][j + przesuniecie * 5] = skladowe[i][j];
	domyslny;
}
Gracz::Gracz()
	:
	punkty(0)
{
	for (int i = 0; i < 21; i++)
		for (int j = 0; j < 96; j++)
			plansza[i][j] = '\0';
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) {
			kratka(1 + i, 1 + j);
			kratka(1 + i, 7 + j);
			kratka(1 + i, 13 + j);
		}
	for (int i = 0; i < 10; i++) {
		if (i < 5) {
			plansza[4][i * 5 + 7] = ' 0' + i;
			plansza[4][i * 5 + 37] = ' 0' + i;
			plansza[16][i * 5 + 7] = ' 0' + i;
		}
		else {
			plansza[4][i * 5 + 42] = ' 0' + i;
			plansza[16][i * 5 + 12] = ' 0' + i;
			plansza[16][i * 5 + 42] = ' 0' + i;
		}
	}
	pionki[0].pionek = '+';
	pionki[1].pionek = 't';
	pionki[2].pionek = 'T';
	pionki[3].pionek = '<';
	pionki[4].pionek = 'k';
	pionki[5].pionek = 'K';
	pionki[6].pionek = 's';
	pionki[7].pionek = 'S';
	pionki[8].pionek = '$';
}
void Gracz::wypisz(bool x) {
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 95; j++) {
			if (i > 2 && i < 6 && j<30)
				Gracz2;
			if (i > 2 && i < 6 && j>30)
				Gracz3;
			if (i > 14 && i < 18 && j < 60)
				Gracz1;
			if (i > 14 && i < 18 && j > 60)
				Gracz2;
			if (x == 1) {
				if (plansza[i][j + 1] == '1') {
					Gracz1;
					cout << plansza[i][j];
					j++;
					czarny;
				}
				if (plansza[i][j + 1] == '2') {
					Gracz2;
					cout << plansza[i][j];
					j++;
					czarny;
				}
				if (plansza[i][j + 1] == '3') {
					Gracz3;
					cout << plansza[i][j];
					j++;
					czarny;
				}
			}

			cout << plansza[i][j];
			domyslny;
		}
		cout << endl;
	}
}
void Gracz::czysc() {
	for (int i = 0; i < 21; i++)
		for (int j = 0; j < 96; j++)
			for (int k = 0; k < 10; k++)
				if (plansza[i][j] == k + '0')
					plansza[i][j] = ' ';
	for (int i = 0; i < 21; i++)
		for (int j = 0; j < 95; j++) {
			if (!(plansza[i][j] == ' ' || plansza[i][j] == '|' || plansza[i][j] == '_' || plansza[i][j] == '\0' || plansza[i][j] == '1' || plansza[i][j] == '2' || plansza[i][j] == '3')) {
				if (i > 2 && i < 6 && j < 30)
					plansza[i][j + 1] = '2';
				if (i > 2 && i < 6 && j>30)
					plansza[i][j + 1] = '3';
				if (i > 14 && i < 18 && j < 60)
					plansza[i][j + 1] = '1';
				if (i > 14 && i < 18 && j > 60)
					plansza[i][j + 1] = '2';
			}
		}
}
bool Gracz::bicie(char pionek1, char pionek2) {
	if (pionek1 == '$') {
		if (pionek2 == 'K' || pionek2 == 'T' || pionek2 == 'S' || pionek2 == 'k' || pionek2 == 't' || pionek2 == ' ')
			return 1;
		else
			return 0;
	}
	if (pionek1 == 'K') {
		if (pionek2 == 'T' || pionek2 == 'S' || pionek2 == 'k' || pionek2 == 't' || pionek2 == ' ')
			return 1;
		else
			return 0;
	}
	if (pionek1 == 'T') {
		if (pionek2 == 'S' || pionek2 == 'k' || pionek2 == 't' || pionek2 == ' ')
			return 1;
		else
			return 0;
	}
	if (pionek1 == 'S') {
		if (pionek2 == 'k' || pionek2 == 't' || pionek2 == 's' || pionek2 == '<' || pionek2 == '+' || pionek2 == ' ')
			return 1;
		else
			return 0;
	}
	if (pionek1 == 'k') {
		if (pionek2 == 't' || pionek2 == 's' || pionek2 == '<' || pionek2 == '+' || pionek2 == ' ')
			return 1;
		else
			return 0;
	}
	if (pionek1 == 't') {
		if (pionek2 == 's' || pionek2 == '<' || pionek2 == '+' || pionek2 == ' ')
			return 1;
		else
			return 0;
	}
	if (pionek1 == 's') {
		if (pionek2 == '<' || pionek2 == '+' || pionek2 == ' ')
			return 1;
		else
			return 0;
	}
	if (pionek1 == '<') {
		if (pionek2 == '+' || pionek2 == ' ')
			return 1;
		else
			return 0;
	}
	if (pionek1 == '+') {
		if (pionek2 == '$' || pionek2 == ' ')
			return 1;
		else
			return 0;
	}
}
int Gracz::kontrola(int numergracza, figury &pion, int r, int k, bool c) {
	if (plansza[pion.rzad + r][pion.kolumna + k] == '\0') {
		if (c == 0)
			cout << "bledny ruch, sproboj jeszcze raz" << endl;
		return 0;
	}
	if ((plansza[pion.rzad + r][pion.kolumna + k + 1]) == numergracza + '0') {
		if (c == 0)
			cout << "bledny ruch, sproboj jeszcze raz" << endl;
		return 0;
	}
	if (bicie(pion.pionek, plansza[pion.rzad + r][pion.kolumna + k]) == 0) {
		if (c == 0)
			cout << "bledny ruch, sproboj jeszcze raz" << endl;
		return 0;
	}


	int czybicie = 0;
	if (plansza[pion.rzad + r][pion.kolumna + k] != ' ')
		czybicie++;


	plansza[pion.rzad + r][pion.kolumna + k] = pion.pionek;
	plansza[pion.rzad + r][pion.kolumna + k + 1] = numergracza + '0';
	plansza[pion.rzad][pion.kolumna] = ' ';
	plansza[pion.rzad][pion.kolumna + 1] = ' ';
	pion.rzad += r;
	pion.kolumna += k;
	if (czybicie == 1)
		return 2;
	return 1;
}

