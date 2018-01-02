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

namespace swiat {
class Swiat;
}

namespace organizm {

class Organizm {

public:
	virtual void akcja()=0;
	virtual void kolizja(Organizm* oponent)=0;
	virtual void rysowanie();
	virtual void rozmnazanie(Organizm* partner)=0;
	virtual void rozmnazanie(int newX, int newY)=0;
	bool isAlive();
	void setZolwniety(bool zolw);
	void setAlive(bool alive);
	int getInicjatywa();
	int getWiek();
	int getSila();
	char getSymbol();
	void setWiek();
	void setOgluszenie();
	void setOgluszenie(int ogluszenie);
	void setWiek(int wiek);
	int getOgluszenie();
	void setSwiat(swiat::Swiat & world);
	virtual ~Organizm();
	int getX();
	int getY();
	Organizm();

protected:
	int sila;
	int inicjatywa;
	int x;
	int y;
	int wiek;
	char symbol;
	bool alive;
	bool zolwniety;
	int ogluszenie;
	Organizm*** naMapie;
	swiat::Swiat* world;
	char** symbolNaMapie;
};
}

#endif /* ORGANIZM_H_ */
