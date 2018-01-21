#include "../Roslina.h"

#ifndef ROSLINY_CIERN_H_
#define ROSLINY_CIERN_H_

namespace roslina {

class Ciern: public Roslina {
public:
	Ciern(Swiat& swiat, int x, int y);
	virtual ~Ciern();
	void akcja() override;
	void rozmnazanie(int newX, int newY) override;
	char getSymbol() const override;
};

}



#endif /* ROSLINY_CIERN_H_ */
