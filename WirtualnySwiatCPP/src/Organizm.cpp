/*
 * Organizm.cpp
 *
 *  Created on: 28.12.2017
 *      Author: Szymon
 */
#include "Organizm.h"
#include "Swiat.h"

namespace organizm {

Organizm::Organizm(Swiat& swiat, int sila, int inicjatywa, int x, int y) :
	swiat(swiat),
	sila(sila),
	inicjatywa(inicjatywa),
	x(x),
	y(y)
{}

bool Organizm::czyZywy() const {
	return alive;
}

void Organizm::setAlive(bool alive) {
	this->alive = alive;
}

int Organizm::getInicjatywa() const {
	return inicjatywa;
}

int Organizm::getWiek() const {
	return wiek;
}

void Organizm::setWiek() {
	this->wiek += 1;
}

void Organizm::zwiekszSile(int oIle) {
	sila = sila + oIle;
}

void Organizm::rysowanie() const {
	swiat.mapa[x][y] = getSymbol();
}

int Organizm::getX() const {
	return x;
}

int Organizm::getY() const {
	return y;
}

int Organizm::getSila() const {
	return sila;
}

void Organizm::setWiek(int wiek) {
    this->wiek = wiek;
}

}

