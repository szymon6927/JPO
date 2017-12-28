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

class Zwierze: public organizm::Organizm {

protected:
	virtual ~Zwierze();
	virtual void rozmnazanie(organizm::Organizm* partner)=0;
	virtual void rozmnazanie(int newX, int newY);
	virtual void kolizja(organizm::Organizm* oponent);
	virtual void akcja();
};
}

#endif /* ZWIERZE_H_ */
