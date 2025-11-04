#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
/*
Koristeći funkcije iz zadatka 1:
· unesite vektor cijelih brojeva
· pronađite sve jedinstvene elemente iz vektora
· sortirajte jedinstvene elemente po apsolutnoj vrijednosti (od najmanjeg do najvećeg)
· ispišite sortirane jedinstvene elemente zajedno s njihovim apsolutnim vrijednostima
*/


void input_vector(std::vector<int>& v)
{
	int br;
	std::cout << "Unesite broj: ";
	std::cin >> br;
	while (br != 0) {
		v.emplace_back(br);
		std::cout << "Unesite broj: ";
		std::cin >> br;
	}
}

std::vector<int> jedinstveni_brojevi(std::vector<int>& v)
{
	std::vector<int> novi_v;
	for (int broj : v) {
		if (std::find(novi_v.begin(), novi_v.end(), broj) == novi_v.end())
			novi_v.push_back(broj);
	}

	return novi_v;
}

void print_vector(const std::vector<int>& v)
{
	for (int x : v)
		std::cout << x << " abs: " << abs(x) << std::endl;
	
}
int main2()
{
	std::vector<int> v;
	input_vector(v);
	std::vector<int> novi = jedinstveni_brojevi(v);
	std::sort(novi.begin(), novi.end(), [](int a, int b) {return abs(a) < abs(b); });
	print_vector(novi);
	return 0;

}
