#pragma once
#include"Gracz.h"
class Komputer :public Gracz {
	int tab[10];
	bool tab2[9];
	int numergracza;
public:
	Komputer()
		:
		numergracza(0),
		Gracz() {
		for (int i = 0; i < 10; i++)
			tab[i] = i;
		for (int i = 0; i < 9; i++)
			tab2[i] = 1;
	}
	Komputer(int x) :
		numergracza(x),
		Gracz() {
		for (int i = 0; i < 10; i++)
			tab[i] = i;
		for (int i = 0; i < 9; i++)
			tab2[i] = 1;
	}
	void rozstaw(int numerGracza);
	int ruch(int numerGracza);
};