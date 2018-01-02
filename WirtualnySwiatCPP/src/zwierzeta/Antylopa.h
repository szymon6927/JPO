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
	Antylopa(int x, int y);
	~Antylopa();

	void rozmnazanie(organizm::Organizm* partner);
	void kolizja(organizm::Organizm* oponent);
	void akcja();
};
}



#endif /* ZWIERZETA_ANTYLOPA_H_ */
