#include <iostream>
using namespace std;

template <class Tip>
struct BSCvor
{
	Tip value;
	BSCvor<Tip> *lijevoDijete;
	BSCvor<Tip> *desnoDijete;

	BSCvor(Tip value)
	{
		this->value = value;
		lijevoDijete = nullptr;
		desnoDijete = nullptr;
	}

};

template <class Kljuc>
class BinarnoStablo
{
	BSCvor<Kljuc>* korijen;
	
	void rekurzija_Recikliraj(BSCvor<Kljuc>*& cvor)
	{
		if (cvor != nullptr)
		{
			rekurzija_Recikliraj(cvor->lijevoDijete);
			rekurzija_Recikliraj(cvor->desnoDijete);
			delete cvor;
			cvor = nullptr;
		}
	}

	BSCvor<Kljuc>* rekurzija_Trazi(BSCvor<Kljuc>*& cvor, const Kljuc& value)
	{
		if (cvor == nullptr)
			return nullptr;
		if (value == cvor->value)
			return cvor;
		else if (value < cvor->value)
			return rekurzija_Trazi(cvor->lijevoDijete, value);
		else
			return rekurzija_Trazi(cvor->desnoDijete, value);
	}

	bool rekurzija_Dodaj(BSCvor<Kljuc>*& cvor, const Kljuc& value)
	{
		if (value == cvor->value)
			return false;
		else if (value < cvor->value)
			if (cvor->lijevoDijete == nullptr)
				cvor->lijevoDijete = new BSCvor<Kljuc>(value);
			else
				rekurzija_Dodaj(cvor->lijevoDijete, value);
		
		if(cvor->desnoDijete == nullptr)
			cvor->desnoDijete = new BSCvor<Kljuc>(value);
		else 
			rekurzija_Dodaj(cvor->desnoDijete, value);

		return true;
	}

public:
	BinarnoStablo() { korijen = nullptr; }

	bool dodaj(Kljuc value) 
	{ 
		if (korijen == nullptr)
		{
			korijen = new BSCvor<Kljuc>(value);
			return false;
		}

		return rekurzija_Dodaj(korijen, value);
	}

	void reciklirajStablo() { rekurzija_Recikliraj(korijen); }

	BSCvor<Kljuc>* trazi(Kljuc value) { return rekurzija_Trazi(korijen, value); }
};

int main()
{
	BinarnoStablo<int> stablo;
	stablo.dodaj(5);
	stablo.dodaj(10);
	stablo.dodaj(2);
	stablo.dodaj(8);
	stablo.dodaj(40);

	if (stablo.trazi(40))
		cout << "Broj 40 je pronadjen." << endl;
	if (!stablo.trazi(3))
		cout << "Broj 3 nije pronadjen." << endl;
	if (stablo.trazi(2))
		cout << "Broj 2 je pronadjen." << endl;

	system("PAUSE>0");
}