#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<time.h>
#include<cstring>
#include<string>
#include<fstream>
#include<Windows.h>
#include"Gracz.h"
#include"Czlowiek.h"
#include"Komputer.h"
using namespace std;

char plansza[21][96];

void zapisz(Gracz** gracze) {
	FILE* plik = NULL;
	plik = fopen("plikP.txt", "w");
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 96; j++) {
			fprintf(plik, "%c", plansza[i][j]);
		}
		fprintf(plik, "%c", '\n');
	}
	
	for(int i=0;i<3;i++)
		fprintf(plik, "%d %c",gracze[i]->getpunkt(),'\n');
	cout << "gra zapisana" << endl;
	fclose(plik);
}
void wczytaj(Gracz** gracze) {

	ifstream plik;
	plik.open("plikP.txt");
	string linia;
	char y[100];

	for (int i = 0; i < 21; i++) {
		getline(plik, linia, '\n');
		strcpy(plansza[i], linia.c_str());
		
	}

	int tabpom[3] = { 0,0,0 };
	for (int i = 0; i < 21; i++)
		for (int j = 0; j < 95; j++) {
			for (int m = 0; m < 3; m++) {
				if (plansza[i][j + 1] == '1' + m) {
					gracze[m]->pionki[tabpom[m]].pionek = plansza[i][j];
					gracze[m]->pionki[tabpom[m]].rzad = i;
					gracze[m]->pionki[tabpom[m]].kolumna = j;
					gracze[m]->pionki[tabpom[m]].numer = m + 1;
					tabpom[m]++;
				}
			}
		}

	for(int i=0;i<3;i++)
		for(int j=0;j<9;j++)
			if (tabpom[i] <= j) {
				gracze[i]->pionki[tabpom[i]].pionek = '*';
				tabpom[i]++;
			}

	int tab[3] = { 0,0,0 };
	for (int i = 0; i < 3; i++) {
		getline(plik, linia, '\n');
		tab[i] = stoi(linia);
		gracze[i]->setpunkt(tab[i]);
	}





	for (int i = 0; i < 21; i++) 
		for (int j = 0; j < 96; j++) {
			if (i < 3 || i>17)
				plansza[i][j] = '\0';
			if (i >= 3 && i <= 17) {
				if (j < 5)
					plansza[i][j] = '\0';
				if (j > 29 && j < 35)
					plansza[i][j] = '\0';
				if (j > 59 && j < 65)
					plansza[i][j] = '\0';
				if (j > 89)
					plansza[i][j] = '\0';
			}
		}


	plik.close();
}

int main(){

	srand(time(NULL));
	cout << "Autor:" << '\t' << "Igor Litner" << endl << "Gra Talat" << endl << endl;

	int liczba_komputerow;
	cout << "podaj ilosc graczy komputerowych (0,1,2,3)" << endl;
	while (scanf("%d", &liczba_komputerow) != 1 || getchar() != '\n' || liczba_komputerow < 0 || liczba_komputerow > 3) {
		printf("blad\n");
		while (getchar() != '\n');
	}

	Gracz *g[3];
	switch (liczba_komputerow) {
	case 0:
		g[0] = &Czlowiek(1);
		g[1] = &Czlowiek(2);
		g[2] = &Czlowiek(3);
		break;
	case 1:
		g[0] = &Czlowiek(1);
		g[1] = &Czlowiek(2);
		g[2] = &Komputer(3);
		break;
	case 2:
		g[0] = &Czlowiek(1);
		g[1] = &Komputer(2);
		g[2] = &Komputer(3);
		break;
	case 3:
		g[0] = &Komputer(1);
		g[1] = &Komputer(2);
		g[2] = &Komputer(3);
		break;
	}

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 3; j++)
			g[j]->rozstaw(j + 1);

	g[0]->czysc();

	int tab[3] = { 1,1,1 };

	while (!(tab[0] == 0 && tab[1] == 0 && tab[2] == 0))
		for (int i = 0; i < 3; i++) {
			tab[i] = g[i]->ruch(i + 1);
			if (tab[i] == 200) {
				zapisz(g);
				i--;
				continue;
			}
			if (tab[i] == 300) {
				wczytaj(g);
				i--;
				continue;
			}
			if (tab[i] < 0) {
				for (int j = 0; j < 9; j++) {
					for (int k = 0; k < 9; k++) {
						if (g[i]->pionki[j].kolumna == g[(i + 1) % 3]->pionki[k].kolumna && g[i]->pionki[j].rzad == g[(i + 1) % 3]->pionki[k].rzad) {
							g[(i + 1) % 3]->pionki[k].pionek = '*';
							g[(i + 1) % 3]->pionki[k].rzad = 100;
							break;
						}
						if (g[i]->pionki[j].kolumna == g[(i + 2) % 3]->pionki[k].kolumna && g[i]->pionki[j].rzad == g[(i + 2) % 3]->pionki[k].rzad) {
							g[(i + 2) % 3]->pionki[k].pionek = '*';
							g[(i + 2) % 3]->pionki[k].rzad = 100;
							break;
						}
					}

				}
			}
		}

	g[0]->wypisz(1);

	for (int i = 0; i < 3; i++) {
		g[i]->podsumowanie(i + 1);
		cout << "gracz " << i + 1 << " ma " << g[i]->getpunkt() << "punktow" << endl;
	}

	system("pause");

	return 0;

}
