#include <iostream>

/*Napisati funkciju koja vraća niz int vrijednosti veličine n u kojem je svaki
element zbroj svoja dva prethodnika (Fibonacci). Prvi i drugi element u nizu
su jedinice. U main funkciji ispisati dobiveni niz i osloboditi memoriju.
*/

int* Fibonacci(int n)
{
	int* niz = new int[n] {1, 1};
	for (int i = 2; i < n; i++) {
		niz[i] = niz[i - 2] + niz[i - 1];
	}
	return niz;
}

void print_niz(int* niz, int n)
{
	for (int i = 0; i < n; ++i)
		std::cout << niz[i] << " ";
	std::cout << std::endl;
}
int main()
{
	int n;
	std::cin >> n;
	int* niz = Fibonacci(n);
	print_niz(niz, n);
	delete [] niz;
	niz = nullptr;
	return 0;
}
