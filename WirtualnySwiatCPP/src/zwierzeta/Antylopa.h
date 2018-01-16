/*
 * Antylopa.h
 *
 *  Created on: 28.12.2017
 *      Author: Szymon
 */
#include "../Zwierze.h"

#ifndef ZWIERZETA_ANTYLOPA_H_
#define ZWIERZETA_ANTYLOPA_H_

namespace zwierze {

class Antylopa: public Zwierze {
public:
	Antylopa(Swiat& swiat, int x, int y);
	virtual ~Antylopa();
	void rozmnazanie(Organizm& partner);
	void kolizja(Organizm& oponent);
	void akcja();
	char getSymbol() const override;
};
}



#endif /* ZWIERZETA_ANTYLOPA_H_ */
