#include <iostream>

/*Definirati strukturu koja opisuje vektor. Struktura se sastoji od niza int
elemenata, logičke i fizičke veličine niza.
· Logička veličina - stvarni broj elemenata u vektoru,
· Fizička veličina - alocirani kapacitet memorije.
Fizička veličina je inicijalno init, a kada se ta veličina napuni vrijednostima,
alocira se duplo.
Napisati funkcije:
· vector_new - kreira novi vektor s početnim kapacitetom,
· vector_delete - oslobađa memoriju vektora,
· vector_push_back - dodaje element na kraj vektora (ako logička veličina
prelazi kapacitet, alocira se duplo),
· vector_pop_back - uklanja element s kraja vektora,
· vector_front - vraća prvi element vektora,
· vector_back - vraća zadnji element vektora,
· vector_size - vraća logičku veličinu vektora.
Funkcije nisu članovi strukture.*/

typedef struct {
	int* niz_elementa;
	int logval;
	int phval;
} vector;

vector vector_new(int n)
{
	vector novi;
	novi.niz_elementa = new int[n]();
	novi.logval = 0;
	novi.phval = n;
	return novi;
}

void vector_delete(vector* v)
{
	delete[] v->niz_elementa;
	v ->niz_elementa= nullptr;

}

void vector_push_back(vector* v, int el)
{
	if (v->logval == v->phval) {
		int* novi_niz = new int[2 * v->phval];
		for (int i = 0; i < v->logval; i++)
			novi_niz[i] = v->niz_elementa[i];
		delete[] v->niz_elementa;
		v->niz_elementa = novi_niz;
		v->phval = 2 * v->phval;
	}
	v->niz_elementa[v->logval] = el;
	v->logval++;
}

void vector_pop_back(vector* v)
{
	v->logval--;
}

int vector_front(vector* v)
{
	int prvi = v->niz_elementa[0];
	return prvi;
	
}

int vector_back(vector* v)
{
	int zadnji = v->niz_elementa[v->logval - 1];
	return zadnji;
}

int vector_size(vector* v)
{
	return v->logval;
}

int main()
{
	int pocetni_kapacitet = 3;
	vector v = vector_new(pocetni_kapacitet);
	vector_push_back(&v, 2);
	vector_push_back(&v, 5);
	vector_push_back(&v, 9);

	std::cout << "Prvi: " << vector_front(&v) << std::endl;
	std::cout << "Zadnji: " << vector_back(&v) << std::endl;
	std::cout << "Logicna velicina: " << vector_size(&v) << std::endl;

	vector_pop_back(&v);
	std::cout << "Logicka velicina nakon pop_backa: " << vector_size(&v) << std::endl;

	vector_delete(&v);
	return 0;
}
