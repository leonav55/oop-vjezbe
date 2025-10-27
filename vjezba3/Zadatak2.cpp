#include <iostream>

/*Funkciju sort iz prvog zadatka napišite kao template funkciju. Testirajte za int i double
nizove.
*/

template<typename T>
bool cmp_a(T a, T b)
{
	return a < b;
}

template<typename T>
bool cmp_d(T a, T b)
{
	return a > b;
}

template<typename T>
void sortt(T* niz, std::size_t n, bool(*cmp)(T, T))
{
	for (std::size_t i = 0; i < n - 1; i++) {
		for (std::size_t j = 0; j < n - i - 1; j++) {
			if ((*cmp)(niz[j + 1], niz[j])) {
				T temp = niz[j];
				niz[j] = niz[j + 1];
				niz[j + 1] = temp;
			}
		}
	}
}



int main2()
{
	std::cout << "Za int:" << std::endl;
	int niz[] = { 4,6,8,3,2,1,9 };
	std::size_t n = sizeof(niz) / sizeof(niz[0]);
	sortt(niz, n, cmp_a<int>);
	for (std::size_t i = 0; i < n; i++)
		std::cout << niz[i] << " ";
	std::cout << std::endl;
	sortt(niz, n, cmp_d<int>);
	for (std::size_t i = 0; i < n; i++) {
		std::cout << niz[i] << " ";
	}
	std::cout << std::endl;


	std::cout << "Za double" << std::endl;
	double niz1[] = { 4.5, 6.7, 8.2, 3.4, 2.9, 1.8, 9.2 };
	std::size_t n1 = sizeof(niz1) / sizeof(niz1[0]);
	sortt(niz1, n1, cmp_a<double>);
	for (std::size_t i = 0; i < n1; i++) {
		std::cout << niz1[i] << " ";
	}
	std::cout << std::endl;
	sortt(niz1, n1, cmp_d<double>);
	for (std::size_t i = 0; i < n1; i++) {
		std::cout << niz1[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}
