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

Organizm::~Organizm() {

}

bool Organizm::isAlive() {
	return alive;
}

void Organizm::setAlive(bool alive) {
	this->alive = alive;
}

int Organizm::getInicjatywa() {
	return inicjatywa;
}

int Organizm::getWiek() {
	return wiek;
}

void Organizm::setWiek() {
	this->wiek += 1;
}

void Organizm::setSwiat(swiat::Swiat & world) {
	this->world = &world;
	this->naMapie = world.mapaOrganizmow;
	this->symbolNaMapie = world.mapa;
}

void Organizm::setSila(int oIle) {
	sila = sila + oIle;
}

void Organizm::rysowanie() {
	symbolNaMapie[x][y] = symbol;
}

int Organizm::getX() {
	return x;
}

int Organizm::getY() {
	return y;
}

int Organizm::getSila() {
	return sila;
}

char Organizm::getSymbol() {
	return symbol;
}

void Organizm::setWiek(int wiek) {
    this->wiek = wiek;
}

}

