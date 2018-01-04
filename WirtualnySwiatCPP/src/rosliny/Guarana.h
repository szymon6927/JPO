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
	Guarana(int x, int y);
	~Guarana();
	void kolizja(organizm::Organizm* oponent);
	void rozmnazanie(int newX, int newY);
};
}



#endif /* ROSLINY_GUARANA_H_ */
