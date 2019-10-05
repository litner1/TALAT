#pragma once
#include"Gracz.h"
class Czlowiek : public Gracz {
	char poprawnepionki[10] = "+tT<kKsS$";
	char poprawnepola[11] = "0123456789";
	bool tabc[10];
	int numergracza;
public:
	Czlowiek() :
		numergracza(0),
		Gracz() {
		for (int i = 0; i < 9; i++)
			tabc[i] = 1;
	}
	Czlowiek(int x) :
		numergracza(x),
		Gracz() {
		for (int i = 0; i < 9; i++)
			tabc[i] = true;
	}
	void rozstaw(int numerGracza);
	int ruch(int numerGracza);
};