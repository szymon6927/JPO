/*
 * Owca.cpp
 *
 *  Created on: 28.12.2017
 *      Author: Szymon
 */

#include "Owca.h"
#include "../Swiat.h"

namespace zwierze {

Owca::Owca(int x, int y) {
    this->x = x;
    this->y = y;
    inicjatywa = 4;
    sila = 4;
    symbol = 'O';
}

Owca::~Owca() {
    world->logger.push_back("Owca umiera!");
}

void Owca::rozmnazanie(organizm::Organizm* partner) {

    int tx = partner->getX();
    int ty = partner->getY();
    int j = 0;
    bool miejsceWgospodzie = false;

    int nx[] = {    x,     x, x + 1, x - 1,     tx,     tx, tx + 1, tx - 1};
    int ny[] = {y + 1, y - 1,     y,     y, ty + 1, ty - 1,     ty,     ty};

    for (unsigned j; j < 8; j++ ) {
        if (nx[j] >= 0 && nx[j] < 20 &&
            ny[j] >= 0 && ny[j] < 20 &&
            naMapie[nx[j]][ny[j]] == nullptr) {
            miejsceWgospodzie = true;
            break;
        }
    }

    if (miejsceWgospodzie) {
        naMapie[nx[j]][ny[j]] = new Owca(nx[j], ny[j]);
        naMapie[nx[j]][ny[j]]->setSwiat(*world);
        world->organizmy.push_back(naMapie[nx[j]][ny[j]]);
        world->logger.push_back("Narodziny Owcy! baaaaaa!");
    }
}

}

