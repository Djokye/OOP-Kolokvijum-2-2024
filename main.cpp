#include"iostream"
#include"ostream"
#include"Kolekcija.h"
#include"Ispit.h"
using namespace std;
void main() {
	int maxPodataka = 8, brojPodataka = 5;
	int test[] = { 23, 37, 28, 31, 34 };
	const char* naziv[] = { "AIP", "UUR", "FIZ", "MAT", "EKM" };
	int ocena[] = { 10, 10, 6, 7, 8 };
	int espb[] = { 3, 5, 6, 5, 5 };
	// 3 boda
	// postavljanje i prihvatanje izuzetaka
	try
	{
		// 1 bod
		Kolekcija<int> kolekcijaA(maxPodataka);
		// 1 bod
		for (int i = 0; i < brojPodataka; i++)
			kolekcijaA.DodajPodatak(test[i]);
		// 1 bod
		//cout << kolekcijaA << endl; 
		kolekcijaA.Ispisi();
		// 1 bod
		kolekcijaA.Obrisi(4);
		//cout << kolekcijaA << endl; 
		kolekcijaA.Ispisi();
		// 1 bod
		float prosecnaOcena = kolekcijaA.OdrediProsek();
		cout << prosecnaOcena << endl;
		// 1 bod
		int najveciPodatak = kolekcijaA.NajveciPodatak();
		cout << najveciPodatak << endl;
		// 1 bod
		kolekcijaA.Sacuvaj("KolekcijaA.txt");
		// 2 boda
		Kolekcija<int> kolekcijaATest(maxPodataka);
		kolekcijaATest.Ucitaj("KolekcijaA.txt");
		//cout << kolekcijaATest << endl; 
		kolekcijaATest.Ispisi();
	}
	catch (const char* c) {
		cout << c << endl;
	}
	catch (exception ex) {
		cout << ex.what() << endl;
	}
	catch (...) {
		cout << "Doslo je do neke greske!" << endl;
	}
	try
	{
		// 1 bod
		Kolekcija<Ispit> kolIspit(maxPodataka);
		// 1 bod
		for (int i = 0; i < brojPodataka; i++) {
			Ispit tmp(naziv[i], ocena[i], espb[i]);
			kolIspit.DodajPodatak(tmp);
		}
		// 1 bod
		//cout << kolIspit << endl; 
		kolIspit.Ispisi();
		// 0 bodova
		kolIspit.Obrisi(4);
		//cout << kolIspit << endl; 
		kolIspit.Ispisi();
		// 2 boda
		float prosecnaOcena2 = kolIspit.OdrediProsek();
		cout << prosecnaOcena2 << endl;
		// 2 boda
		Ispit najveci = kolIspit.NajveciPodatak();
		//cout << najveci << endl;
		kolIspit.Ispisi();
		// 0 bod
		kolIspit.Sacuvaj("Ispiti.txt");
		// 1 bod
		Kolekcija<Ispit> kolIspitTest(maxPodataka);
		kolIspitTest.Ucitaj("Ispiti.txt");
		//cout << kolIspitTest << endl; 
		kolIspitTest.Ispisi();
	}
	catch (const char* c) {
		cout << c << endl;
	}
	catch (exception ex) {
		cout << ex.what() << endl;
	}
	catch (...) {
		cout << "Doslo je do neke greske!" << endl;
	}
}