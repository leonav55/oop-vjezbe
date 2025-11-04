#include <iostream>
#include <vector>
/*
Napišite funkcije:
· void input_vector(vector<int>& v) - unosi brojeve dok se ne unese 0
· void print_vector(const vector<int>& v) - ispisuje vektor
*/

void Input_vector(std::vector<int>& v)
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

void Print_vector(const std::vector<int>& v)
{
	for (int x : v)
		std::cout << x << " ";
	std::cout << std::endl;
}
int main1()
{
	std::vector<int> v;
	Input_vector(v);
	Print_vector(v);
	return 0;

}
