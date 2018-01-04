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
	Trawa(int x, int y);
	~Trawa();
	void rozmnazanie(int newX, int newY);
};

}




#endif /* ROSLINY_TRAWA_H_ */
