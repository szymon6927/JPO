/*
 * Zwierze.cpp
 *
 *  Created on: 28.12.2017
 *      Author: Szymon
 */

#include "Zwierze.h"

namespace zwierze {

Zwierze::~Zwierze() {

}

void Zwierze::akcja() {
    //zwykle poruszanie sie

    if (ogluszenie == 0) {

        int kierunek = rand() % 4;
        const int wymiar = 20;

        int tmp_x = x;
        int tmp_y = y;

        if ((kierunek == 0) && (y > 0)) {
            //ruch w gore
            tmp_y -= 1;
        }
        else if ((kierunek == 1) && (x < wymiar - 1)) {
            //ruch w prawo
            tmp_x += 1;
        }
        else if ((kierunek == 2) && (y < wymiar - 1)) {
            //ruch w dol
            tmp_y += 1;
        }
        else if ((kierunek == 3) && (x > 0)) {
            //ruch w lewo
            tmp_x -= 1;
        }

        if (zolwniety) {
            zolwniety = false;
        }

        if (naMapie[tmp_x][tmp_y] == nullptr) {
            naMapie[tmp_x][tmp_y] = naMapie[x][y];
            naMapie[x][y] = nullptr;
            x = tmp_x;
            y = tmp_y;
        }
        else if (naMapie[tmp_x][tmp_y]->getSymbol() == symbol &&
                 naMapie[tmp_x][tmp_y] != &*this) {
            rozmnazanie(naMapie[tmp_x][tmp_y]); //sprawdz to
        }
        else if (naMapie[tmp_x][tmp_y] != &*this) {
            naMapie[tmp_x][tmp_y]->kolizja(&*this);
            kolizja(naMapie[tmp_x][tmp_y]);
            if (isAlive() && !zolwniety) {
                naMapie[tmp_x][tmp_y] = naMapie[x][y];
                naMapie[x][y] = nullptr;
                x = tmp_x;
                y = tmp_y;
            }
            else if (!isAlive()) {
                naMapie[x][y] = nullptr;
            }
        }
    }
    else {
        ogluszenie--;
    }
    if (zolwniety) {
        zolwniety = false;
    }
}

void Zwierze::kolizja(organizm::Organizm* oponent) {
    //jezeli zwierzaki te same = rozmnazanie
    int tmp_sila = oponent->getSila();

    if (sila < 5 && zolwniety) {
        //nic =D
    }
    else if (sila > tmp_sila) {
        oponent->setAlive(false);
    }
    else if (sila < tmp_sila) {
        setAlive(false);

    }
    else if (alive) {
        setAlive(false);
    }

}

void Zwierze::rozmnazanie(int newX, int newY) {
    //dummy
}

}
