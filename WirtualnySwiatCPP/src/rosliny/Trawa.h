/*
 * Trawa.h
 *
 *  Created on: 03.01.2018
 *      Author: Szymon
 */
#include "../Roslina.h"

#ifndef ROSLINY_TRAWA_H_
#define ROSLINY_TRAWA_H_

namespace roslina {

class Trawa: public Roslina {
public:
	Trawa(Swiat& swiat, int x, int y);
	virtual ~Trawa();
	void rozmnazanie(int newX, int newY);
	char getSymbol() const override;
};

}




#endif /* ROSLINY_TRAWA_H_ */
