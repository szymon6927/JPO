#ifndef WartoscLiczbowa_h
#define WartoscLiczbowa_h

#include <ostream>

class WartoscLiczbowa
{
public:
	virtual double modul () = 0; //wartoœæ bezwzglêdna
	virtual void wypisz(std::ostream &out) = 0;
	virtual ~WartoscLiczbowa()
	{}
};

#endif
