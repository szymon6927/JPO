#include "Organizm.h"

#ifndef ROSLINA_H_
#define ROSLINA_H_

namespace roslina {

class Roslina: public Organizm {

public:
	Roslina(Swiat& swiat, int sila, int x, int y);
	void kolizja(Organizm& oponent) override;
	virtual void rozmnazanie(int newX, int newY) = 0;
	void akcja() override;
};
}

#endif /* ROSLINA_H_ */
