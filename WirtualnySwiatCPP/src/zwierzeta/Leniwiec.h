/*
 * Leniwiec.h
 *
 *  Created on: 28.12.2017
 *      Author: Szymon
 */

#include "../Zwierze.h"

#ifndef ZWIERZETA_LENIWIEC_H_
#define ZWIERZETA_LENIWIEC_H_

namespace zwierze {

class Leniwiec: public Zwierze {
public:
	Leniwiec(int x, int y);
	~Leniwiec();

	void rozmnazanie(organizm::Organizm* partner);
	void akcja();
private:
	int iloscRuchow;
};
}




#endif /* ZWIERZETA_LENIWIEC_H_ */
