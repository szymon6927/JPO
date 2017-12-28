/*
 * Roslina.h
 *
 *  Created on: 28.12.2017
 *      Author: Szymon
 */

#include "Organizm.h"

#ifndef ROSLINA_H_
#define ROSLINA_H_

namespace roslina {

class Roslina: public organizm::Organizm {

public:
	Roslina();
	virtual ~Roslina();
	virtual void kolizja(organizm::Organizm* oponent);
	virtual void rozmnazanie(organizm::Organizm* partner);
	virtual void rozmnazanie(int newX, int newY)=0;
	virtual void akcja();
};
}

#endif /* ROSLINA_H_ */
