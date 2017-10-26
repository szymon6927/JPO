#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class VektorNd {
	double *_liczby; //pole ze wskaünikiem liczb
	int _wymiar; //wymiar wektora
public:
	VektorNd(const double liczby[], int wymiar) { //konstruktor
		_liczby = new double[wymiar];
		_wymiar = wymiar;
		for (int i = 0; i < _wymiar; i++)
			_liczby[i] = liczby[i];
	}
	VektorNd(const VektorNd& oryginal) { //konstruktor kopiujπcy
		cout << "Wywoluje copy construcotr \n";
		_liczby = new double[oryginal._wymiar];
		_wymiar = oryginal._wymiar;
		for (int i = 0; i < _wymiar; i++)
			_liczby[i] = oryginal._liczby[i];
	}
	~VektorNd() {
		cout << "VektorNd zwalniam pamiec pod adresem: " << this << endl;
		delete[] _liczby;
	}
	VektorNd& operator=(const VektorNd& right) { //implementacja operatora przypisania
		cout << "Operator = \n";
		if (_wymiar != right._wymiar) { //gdy zgodne wymiary nie potrzeba realokowaÊ pamiÍci
			delete[] _liczby;
			_liczby = new double[right._wymiar]; //alokacja pamiÍci dla nowego wymiaru
			_wymiar = right._wymiar;
		}
		for (int i = 0; i < _wymiar; i++)
			_liczby[i] = right._liczby[i];
		return *this;
	}
	friend ostream& operator<<(ostream& left, VektorNd& right);
	void wypisz(ostream& out = cout) {
		out << "|-------------------------BEGIN------------------------------|"
				<< endl;
		out << "Jestem wektorem pod adresem: " << this << endl;
		out << "Moj wymiar to: " << _wymiar << endl;
		out << "A elementy:" << endl;
		for (int i = 0; i < _wymiar; i++)
			out << "[" << i << "] = \t" << _liczby[i] << endl;
		out << "|--------------------------END-------------------------------|"
				<< endl;
	}
	void getCoefs(double liczby[]) { //metoda publiczna
		for (int i = 0; i < _wymiar; i++)
			liczby[i] = _liczby[i];
	}
	void setCoef(double wartosc, int index) {
		_liczby[index] = wartosc;
	}
	double getCoef(int index) { //pomocznicza metoda
		return _liczby[index];
	}
	int getDim() { //pomocznicza metoda
		return _wymiar;
	}
};

ostream& operator<<(ostream& left, VektorNd& right) {
	right.wypisz(left); //wolno wywo≥aÊ gdyø operator jest friend
	return left;
}

void wypisz(double tab[], int rozmiar) {
	for (int i = 0; i < rozmiar; i++)
		cout << tab[i] << '\t';
	cout << endl;
}

void wypiszV1(VektorNd v) {
	cout << "|----------BEGIN------------------------------|" << endl;
	cout << "Jestem wektorem pod adresem: " << &v << endl;
	int wymiar = v.getDim();
	cout << "MÛj wymiar to: " << wymiar << endl;
	cout << "A elementy:" << endl;
	for (int i = 0; i < wymiar; i++)
		cout << "[" << i << "] = \t" << v.getCoef(i) << endl;
	cout << "|-----------END-------------------------------|" << endl;
}

void wypiszV2(VektorNd& v) {
	cout << "|----------BEGIN------------------------------|" << endl;
	cout << "Jestem wektorem pod adresem: " << &v << endl;
	int wymiar = v.getDim();
	cout << "MÛj wymiar to: " << wymiar << endl;
	cout << "A elementy:" << endl;
	for (int i = 0; i < wymiar; i++)
		cout << "[" << i << "] = \t" << v.getCoef(i) << endl;
	cout << "|-----------END-------------------------------|" << endl;
}

class VectorOfVectors {
private:
	vector<VektorNd> vec;
public:
	VectorOfVectors() { // konstruktor
		cout << "VectorOfVectors constructor \n";
	}
	~VectorOfVectors() {
		cout << "Destroy VectorOfVectors \n";
		vec.clear();
	}
//	friend ostream& operator<<();
	void add(const double wartosci[], int ilosc) {
		cout << "ADD! \n";
		vec.push_back(VektorNd(wartosci, ilosc));
	}
	void setValue(double wartosc, int whichVecotor, int index) {
		vec[whichVecotor].setCoef(wartosc, index);
	}
	void printAll() {
		cout << "Print all: ! \n";
		for(unsigned i=0; i<vec.size();i++) {
			vec[i].wypisz();
		}
	}
//	void print(ostream& out = cout) {
//		out << "|------------------VectorOfVectors << ------------------------| \n";
//		out << *this;
//	}
};


int main() {
	const double wartosci1[] = { 1, 2, 3 };
	const double wartosci2[] = { 4, 5, 6 };
	const double wartosci3[] = { 7, 8, 9 };

	const double wartosci11[] = { 11, 22, 33 };
	const double wartosci22[] = { 44, 55, 66 };
	const double wartosci33[] = { 77, 88, 99 };

	VectorOfVectors vv1;
	vv1.add(wartosci1, 3);
	vv1.add(wartosci2, 3);
	vv1.add(wartosci3, 3);
	vv1.printAll();

	VectorOfVectors vv2;
	vv2.add(wartosci11, 3);
	vv2.add(wartosci22, 3);
	vv2.add(wartosci33, 3);
	vv2.printAll();

	vv1 = vv2;
//	cout << "\n\n VV1 po zamianie z VV2 \n\n";
//	vv1.printAll();

	vv1.setValue(100.0, 0, 0); // wartosc 100.00 na 0 wektorze w VectorsOfVecotr, na indexie 0
	vv2.setValue(110.0, 0, 0);

	cout << "\n\n";
	vv1.printAll();
	cout << "\n\n vv2 \n\n";
	vv2.printAll();

//	cout << vv1;

//	VektorNd v1(wartosci, 3);
//	ofstream file("E:\\plik.txt");
//	file << v1;
}
