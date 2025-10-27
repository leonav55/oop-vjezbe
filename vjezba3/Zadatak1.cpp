#include <iostream>
#include <cstddef>

/*Definirajte funkciju sort sa prototipom
void sortt(int[], std::size_t, bool (*cmp)(int, int));
Definirajte inline funkcije ascending i descending za usporedbu dva elementa koje primaju dva int-a i vraćaju bool.
U main funkciji inicijalizirajte niz i pozovite funkciju sort prvo za uzlazno, a zatim za
silazno sortiranje.
Napomena: std::size_t je definiran u headeru #include <cstddef>.*/

inline bool cmp_a(int a, int b)
{
	return a < b;
}

inline bool cmp_d(int a, int b)
{
	return a > b;
}

void sort(int* niz, std::size_t n, bool(*cmp)(int, int))
{
	for (std::size_t i = 0; i < n - 1; i++) {    
		for (std::size_t j = 0; j < n - i - 1; j++) {
			if ((*cmp)(niz[j + 1], niz[j])) {
				int temp = niz[j];
				niz[j] = niz[j + 1];
				niz[j + 1] = temp;
			}
		}
	}
}

int main1()
{
	int niz[] = { 1,5,4,3,8,9,6,2 };
	std::size_t n = sizeof(niz) / sizeof(niz[0]);
	sort(niz, n, cmp_a);
	for (std::size_t i = 0; i < n; i++) {
		std::cout << niz[i] << " ";
	}
	std::cout << std::endl;
	sort(niz, n, cmp_d);
	for (std::size_t i = 0; i < n; i++) {
		std::cout << niz[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}
