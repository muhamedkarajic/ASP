#include <iostream>
using namespace std;

class ciklicniNiz
{
	int _pocetak = 0;
	int _maxSize = 5;
	int _kraj = 0;
	int* _niz = new int[_maxSize];
	int _brojac = 0;

	int getSljedeci(const int &lokacija) const {
		if (lokacija + 1 == _maxSize)
			return 0;
		return lokacija + 1;
	}

public:
	bool jelPun() { return _brojac == _maxSize; }
	bool jelPrazan() { return _brojac == 0; }
	
	void Ukloni()
	{
		_pocetak = getSljedeci(_pocetak);
		_brojac--;
	}

	void Dodaj(const int &elemenet) {

		if (!jelPun()) {
			_niz[_kraj] = elemenet;
			_kraj = getSljedeci(_kraj);
			_brojac++;
		}
		else
			cout << "Niz je pun." << endl;
	}
	
	void Ispis()
	{
		if (!jelPrazan())
			do
			{
				cout << _niz[_pocetak] << ", ";
				_pocetak = getSljedeci(_pocetak);
			} while (_pocetak != _kraj);
	}
	
};

int main()
{
	ciklicniNiz niz;
	niz.Dodaj(5);
	niz.Dodaj(4);
	niz.Dodaj(3);
	niz.Dodaj(2);
	niz.Dodaj(1);
	niz.Ukloni();
	niz.Dodaj(50);
	niz.Ukloni();
	niz.Dodaj(40);
	niz.Ukloni();
	niz.Dodaj(30);

	niz.Ispis();

	system("PAUSE>0");
}