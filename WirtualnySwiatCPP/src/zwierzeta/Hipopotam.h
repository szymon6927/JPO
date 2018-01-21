#include "../Zwierze.h"

#ifndef ZWIERZETA_HIPOPOTAM_H_
#define ZWIERZETA_HIPOPOTAM_H_

namespace zwierze {

class Hipopotam: public Zwierze {
public:
	Hipopotam(Swiat& swiat, int x, int y);
	virtual ~Hipopotam();
	void rozmnazanie(Organizm& partner);
	char getSymbol() const override;
};

}

#endif /* ZWIERZETA_HIPOPOTAM_H_ */
