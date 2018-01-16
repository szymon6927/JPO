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

/**
 * 1. value - Foo foo
 * 2. (const) reference - const Foo& foo
 * 3. smart pointer - std::unique_ptr<Foo> foo_ptr = std::make_unique<Foo>()
 * 4. (cosnt) raw pointer - const Foo*
 *
 * Note: raw pointers should never be owners
 */

class Swiat;

class Organizm {

public:
	virtual void akcja()=0;
	virtual void kolizja(Organizm& oponent)=0;
	virtual void rysowanie() const;
	virtual char getSymbol() const=0;
	bool czyZywy() const;
	void setAlive(bool alive);
	int getInicjatywa() const;
	int getWiek() const;
	int getSila() const;
	void setWiek();
	void setWiek(int wiek);
	void zwiekszSile(int oIle);
	int getX() const;
	int getY() const;
	void setX(int posX);
	void setY(int posY);

	Organizm(Swiat& swiat, int sila, int inicjatywa, int x, int y);
	virtual ~Organizm() = default;

protected:
	Swiat& swiat;
	int sila;
	int inicjatywa;
	int wiek = 0;
	bool alive = true;
	int x;
	int y;
};

#endif /* ORGANIZM_H_ */
