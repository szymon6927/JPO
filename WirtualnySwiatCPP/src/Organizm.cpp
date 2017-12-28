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
	ogluszenie = 0;
	alive = true;
	zolwniety = false;
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

int Organizm::getOgluszenie() {
	return ogluszenie;
}

void Organizm::setOgluszenie() {
	this->ogluszenie += 2;
}

void Organizm::setZolwniety(bool zolw) {
	this->zolwniety = true;
}

void Organizm::setOgluszenie(int ogluszenie) {
	this->ogluszenie = ogluszenie;
}

void Organizm::setWiek(int wiek) {
	this->wiek = wiek;
}

}

