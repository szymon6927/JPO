#include <iostream>
#include <cstdlib>
#include <vector>

#ifndef ORGANIZM_H_
#define ORGANIZM_H_

class Swiat;

class Organizm {

public:
	virtual void akcja()=0;
	virtual void kolizja(Organizm& oponent)=0;
	virtual char getSymbol() const=0;
	bool czyZywy() const;
	void setAlive(bool alive);
	int getInicjatywa() const;
	int getWiek() const;
	int getSila() const;
	void zwiekszWiek();
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
