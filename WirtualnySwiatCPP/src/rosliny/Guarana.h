/*
 * Guarana.h
 *
 *  Created on: 03.01.2018
 *      Author: Szymon
 */

#include "../Roslina.h"

#ifndef ROSLINY_GUARANA_H_
#define ROSLINY_GUARANA_H_

namespace roslina {
class Guarana: public Roslina {
public:
	Guarana(Swiat& swiat, int x, int y);
	virtual ~Guarana();
	void kolizja(Organizm* oponent);
	void rozmnazanie(int newX, int newY);
	char getSymbol() const override;
};
}



#endif /* ROSLINY_GUARANA_H_ */
