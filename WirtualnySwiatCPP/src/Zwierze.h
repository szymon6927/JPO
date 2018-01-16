/*
 * Zwierze.h
 *
 *  Created on: 28.12.2017
 *      Author: Szymon
 */

#include "Organizm.h"

#ifndef ZWIERZE_H_
#define ZWIERZE_H_

namespace zwierze {

class Zwierze: public Organizm {

protected:
	Zwierze(Swiat& swiat, int sila, int inicjatywa, int x, int y);
	virtual void rozmnazanie(Organizm& partner) = 0;
	virtual void kolizja(Organizm& oponent);
	virtual void akcja();
};
}

#endif /* ZWIERZE_H_ */
