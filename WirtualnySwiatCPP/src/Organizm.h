/*
 * Organizm.h
 *
 *  Created on: 28.12.2017
 *      Author: Szymon
 */

#include <iostream>
#include <cstdlib>
#include <vector>

#ifndef ORGANIZM_H_
#define ORGANIZM_H_

class Swiat;

namespace organizm {

class Organizm {

public:
	virtual void akcja()=0;
	virtual void kolizja(Organizm* oponent)=0;
	virtual void rysowanie() const;
	virtual void rozmnazanie(Organizm* partner)=0;
	virtual void rozmnazanie(int newX, int newY)=0;
	bool czyZywy() const;
	void setAlive(bool alive);
	int getInicjatywa() const;
	int getWiek() const;
	int getSila() const;
	char getSymbol() const;
	void setWiek();
	void setWiek(int wiek);
	void setSwiat(Swiat & world);
	void setSila(int oIle);
	virtual ~Organizm() = default;
	int getX() const;
	int getY() const;
	Organizm();

protected:
	int sila;
	int inicjatywa;
	int x;
	int y;
	int wiek;
	char symbol;
	bool alive;
	Organizm*** naMapie;
	Swiat* world;
	char** symbolNaMapie;
};
}

#endif /* ORGANIZM_H_ */
