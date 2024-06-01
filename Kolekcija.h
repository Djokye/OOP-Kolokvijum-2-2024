#pragma once
#include"iostream"
#include"ostream"
#include"Ispit.h"
using namespace std;
template <class T>
class Kolekcija
{
	T** collection;
	int tren, max;

public:
	Kolekcija()
	{
		tren = 0;
		max = 0;
		collection = new T * [1];
	}
	Kolekcija(int maxi)
	{
		tren = 0;
		max = maxi;
		collection = new T * [max];
	}
	~Kolekcija()
	{
		if (collection!=nullptr)
		{
			for (int i = 0; i < tren; i++)
			{
				delete collection[i];
			}
			delete[] collection;
			collection = nullptr;
		}
	}

	void DodajPodatak(T& e)
	{
		if (tren<max)
		{
			collection[tren] = e;
			tren++;
		}
		else
		{
			cout << "kolekcija je puna";
		}
	}

	void Ispisi()
	{
		for (int i = 0; i < tren; i++)
		{
			cout << *collection[i] << endl;
		}
	}

	void Obrisi(int element)
	{
		for (int i = 0; i < tren; i++)
		{
			if (i == element)
			{
				for (int j = i; j < tren-1; j+1++)
				{
					collection[j] = collection[j + 1];
				}
				tren--;
				i = tren;
			}
		}
	}

	float OdrediProsek()
	{
		float prosek = 0;
		for (int i = 0; i < tren; i++)
		{
			prosek += collection[i];
		}
		return prosek / tren;
	}

	int NajveciPodatak()
	{
		int najjaki = collection[0];
		for (int i = 0; i < tren; i++)
		{
			if (collection[i] > najjaki)
			{
				najjaki = collection[i];
			}
		}
		return najjaki;
	}

	void Sacuvaj(const string& fajl) {
		ofstream izlaz(fajl);
		if (izlaz.is_open()) {
			izlaz << tren << endl;
			for (int i = 0; i < tren; i++)
			{
				for (int j = 0; j < tren; j++)
					izlaz << *collection[i] << endl;
			}
			izlaz.close();
		}
		else {
			cout << "Greska pri otvaranju fajla!" << endl;
		}
	}

	void Ucitaj(const string& fajl) {
		ifstream ulaz(fajl);
		if (ulaz.is_open()) {
			int tren;
			ulaz >> tren;
			for (int i = 0; i < tren; i++)
					ulaz >> collection[i];
			ulaz.close();
		}
		else
			cout << "Greska pri otvaranju fajla!" << endl;
	}
};

