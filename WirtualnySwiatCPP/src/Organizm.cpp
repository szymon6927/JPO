/*
 * Organizm.cpp
 *
 *  Created on: 28.12.2017
 *      Author: Szymon
 */
#include "Organizm.h"
#include "Swiat.h"

namespace organizm {

Organizm::Organizm() {
	wiek = 0;
	alive = true;
}

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

void Organizm::setSwiat(Swiat& world) {
	this->world = &world;
	this->naMapie = world.mapaOrganizmow;
	this->symbolNaMapie = world.mapa;
}

void Organizm::setSila(int oIle) {
	sila = sila + oIle;
}

void Organizm::rysowanie() const {
	symbolNaMapie[x][y] = symbol;
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

char Organizm::getSymbol() const {
	return symbol;
}

void Organizm::setWiek(int wiek) {
    this->wiek = wiek;
}

}

