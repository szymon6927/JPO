/*
 * Owca.h
 *
 *  Created on: 28.12.2017
 *      Author: Szymon
 */

#include "../Zwierze.h"

#ifndef ZWIERZETA_OWCA_H_
#define ZWIERZETA_OWCA_H_

namespace zwierze {

class Owca: public Zwierze {

public:
	Owca(int x, int y);
	~Owca();
	void rozmnazanie(organizm::Organizm* partner);
};
}

#endif /* ZWIERZETA_OWCA_H_ */
