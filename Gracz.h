#pragma once

struct figury {
	char pionek;
	int rzad;
	int kolumna;
	int numer;
};


class Gracz {
protected:
	int punkty;
public:
	figury pionki[9];
	virtual void rozstaw(int x) {};
	virtual int ruch(int x) { return x; };
	void kratka(int poziom, int przesuniecie = 0);
	Gracz();
	void wypisz(bool x = 0);
	void czysc();
	bool bicie(char pionek1, char pionek2);
	int kontrola(int numergracza, figury &pion, int r, int k, bool c = 0);
	int getpunkt() { return punkty; };
	void setpunkt(int x) { punkty = x; };
	void podsumowanie(int numergracza);
};