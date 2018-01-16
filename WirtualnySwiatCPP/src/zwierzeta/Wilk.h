/*
 * Wilk.h
 *
 *  Created on: 28.12.2017
 *      Author: Szymon
 */
#include "../Zwierze.h"

#ifndef ZWIERZETA_WILK_H_
#define ZWIERZETA_WILK_H_

namespace zwierze {
//class Swiat;

class Wilk: public Zwierze {

public:
	Wilk(Swiat& swiat, int x, int y);
	virtual ~Wilk();
	void rozmnazanie(organizm::Organizm& partner);
	char getSymbol() const override;
};
}

#endif /* ZWIERZETA_WILK_H_ */
