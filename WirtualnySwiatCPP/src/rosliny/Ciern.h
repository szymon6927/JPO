/*
 * Ciern.h
 *
 *  Created on: 03.01.2018
 *      Author: Szymon
 */

#include "../Roslina.h"

#ifndef ROSLINY_CIERN_H_
#define ROSLINY_CIERN_H_

namespace roslina {

class Ciern: public Roslina {
public:
	Ciern(int x, int y);
	~Ciern();
	void akcja();
	void rozmnazanie(int newX, int newY);
};

}



#endif /* ROSLINY_CIERN_H_ */
