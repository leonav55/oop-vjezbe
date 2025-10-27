#include <iostream>
 /* Napišite sljedeće lambda izraze:
· za provjeru parnosti i neparnosti broja (lambde bez capture)
· za udvostručiti i prepoloviti broj (lambde bez capture)
· za dodavanje broja u sumu (lambda sa capture [&])
· za dodavanje broja u produkt (lambda sa capture [&])
· za dodavanje broja u sumu ako je veći od nekog praga (lambda sa capture [prag, &s])
Koristeći gornje lambda izraze napišite funkcije koje za niz cijelih brojeva
· funkcija koja parne elemente prepolovi, a neparne udvostruči,
· funkcija koja računa sumu i produkt članova niza,
· funkcija koja računa sumu brojeva većih od nekog praga.*/

template<typename Fparnost, typename Fudvostruci, typename Fprepolovi>
void funk1(int* niz, int l, Fparnost parnost, Fudvostruci udovostruci, Fprepolovi prepolovi)
{
	for (int i = 0; i < l; i++) {
		if (parnost(niz[i]))
			niz[i] = prepolovi(niz[i]);
		else
			niz[i] = udovostruci(niz[i]);
	}
}

template<typename Fsuma, typename Fprodukt>
void funk2(int* niz, int l, Fsuma suma, Fprodukt produkt)
{
	for (int i = 0; i < l; i++) {
		suma(niz[i]);
		produkt(niz[i]);
	}
}

template<typename Fdodaj>
void funk3(int* niz, int l, Fdodaj dodaj)
{
	for (int i = 0; i < l; i++) {
		dodaj(niz[i]);
	}
}
int main3()
{
	int s = 0;
	int pr = 1;
	int prag = 4;
	int niz[] = { 1,2,3,4,5,6,7,8,9 }; 
	int l = sizeof(niz) / sizeof(niz[0]);
	auto parnost = [](int n) { return n % 2 == 0;};
	auto udvostruci = [](int n) { return n * 2;};
	auto prepolovi = [](int n) { return n / 2;};
	auto suma = [&s](int n) { return s += n;};
	auto produkt = [&pr](int n) { return pr = pr * n;};
	auto dodaj = [prag, &s](int n) { if (n > prag) return s += n;};
	
	funk1(niz, l, parnost, udvostruci, prepolovi);
	for (int i = 0; i < l; i++) {
		std::cout << niz[i] << " ";
	}
	std::cout << std::endl;

	funk2(niz, l, suma, produkt);
	std::cout << "Suma: " << s << std::endl;
	std::cout << "Produkt: " << pr << std::endl;

	funk3(niz, l, dodaj);
	std::cout << "Suma nakon dodaj: " << s << std::endl;

	return 0;
}

