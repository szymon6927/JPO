#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;
class VektorNd {
	int _wymiar; //wymiar wektora
	double *_liczby; //pole ze wskaünikiem liczb
public:
	VektorNd() :
			_wymiar(5), _liczby(new double[_wymiar]) {
	}

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

	VektorNd(VektorNd&& inny) :
			_wymiar(inny._wymiar), _liczby(inny._liczby) {
		inny._liczby = nullptr;
		inny._wymiar = 0;
	}

	VektorNd& operator=(VektorNd&& inny) {
		std::swap(*this, inny);
		return *this;
	}

	friend ostream& operator<<(ostream& left, const VektorNd& right);

	friend istream& operator>>(istream& left, VektorNd& right) {
		for (int i = 0; i < right._wymiar; i++) {
			left >> right._liczby[i];
		}
		return left;
	}

	void wypisz(ostream& out = cout) const {
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
	int getDim() { // pomocznicza metoda
		return _wymiar;
	}
};

ostream& operator<<(ostream& left, const VektorNd& right) {
	right.wypisz(left); // wolno wywo≥aÊ gdyø operator jest friend
	return left;
}

void wypisz(double tab[], int rozmiar) {
	for (int i = 0; i < rozmiar; i++)
		cout << tab[i] << '\t';
	cout << endl;
}

class VectorOfVectorsBezPointer {
private:
	array<VektorNd, 3> arr;
public:
	friend std::ostream& operator<<(std::ostream& out,
			const VectorOfVectorsBezPointer& v) {
		for (unsigned i = 0; i < v.arr.size(); i++) {
			out << v.arr[i] << '\n';
		}
		return out;
	}

	friend std::istream& operator>>(std::istream& in,
			VectorOfVectorsBezPointer& vec) {
		for (unsigned i = 0; i < vec.arr.size(); i++) {
			in >> vec.arr[i];
		}
		return in;
	}
};

class VectorOfVectorsPointery {
private:
	int size;
	VektorNd* vektory;
public:
	VectorOfVectorsPointery() :
		size(0), vektory(nullptr) {
	}

	VectorOfVectorsPointery(int size) :
			size(size), vektory(new VektorNd[size]) {

	}

	VectorOfVectorsPointery(const VectorOfVectorsPointery& other) :
			size(other.size), vektory(new VektorNd[size]) {
		std::copy(other.vektory, other.vektory + size, vektory);
	}

	VectorOfVectorsPointery& operator=(const VectorOfVectorsPointery& inny) {
		VectorOfVectorsPointery temp(inny);
		std::swap(*this, temp);
		return *this;
	}

	VectorOfVectorsPointery(VectorOfVectorsPointery&& inny) :
			size(inny.size), vektory(inny.vektory) {
		inny.vektory = nullptr;
		inny.size = 0;
	}

	VectorOfVectorsPointery& operator=(VectorOfVectorsPointery&& inny) {
		std::swap(*this, inny);
		return *this;
	}

	~VectorOfVectorsPointery() {
		delete[] vektory;
	}

	friend std::ostream& operator<<(std::ostream& out,
			const VectorOfVectorsPointery& vec) {

		for (int i = 0; i < vec.size; ++i) {
			out << vec.vektory[i] << '\n';
		}

		return out;
	}

	friend std::istream& operator>>(std::istream& in,
			VectorOfVectorsPointery& vec) {
		for (int i = 0; i < vec.size; ++i) {
			in >> vec.vektory[i];
		}

		return in;
	}
};

int main() {
//	const double wartosci1[] = { 1, 2, 3 };
//	const double wartosci2[] = { 4, 5, 6 };
//	const double wartosci3[] = { 7, 8, 9 };
//
//	const double wartosci11[] = { 11, 22, 33 };
//	const double wartosci22[] = { 44, 55, 66 };
//	const double wartosci33[] = { 77, 88, 99 };

	VectorOfVectorsPointery v(3);
	std::cin >> v;
	std::cout << v;

//	VektorNd v1(wartosci, 3);
//	ofstream file("E:\\plik.txt");
//	file << v1;
}
