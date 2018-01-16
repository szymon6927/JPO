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
	Leniwiec(Swiat& swiat, int x, int y);
	virtual ~Leniwiec();
	void rozmnazanie(organizm::Organizm& partner);
	void akcja();
	char getSymbol() const override;
private:
	int iloscRuchow=0; // przy utworzeniu leniwca jego ilosc ruchow to 0, jezeli bedzie w ciagu tury inn
};
}




#endif /* ZWIERZETA_LENIWIEC_H_ */
