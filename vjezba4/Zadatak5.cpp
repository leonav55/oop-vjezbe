#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
/*
Napišite funkciju void reverse_strings(vector<string>& words) koja svaki string u vektoru
okrene naopako. Inicijalizirajte vektor stringova s nekoliko riječi. Ispišite vektor
prije i nakon okretanja.
Primjer: ["hello", "world", "c++"] -> ["olleh", "dlrow", "++c"]
Napomena: Koristite std::reverse za okretanje stringova.
*/

void reverse_strings(std::vector<std::string>& words)
{
	for (auto it = words.begin(); it != words.end(); it++) {
		std::reverse(it->begin(), it->end());
	}
}

void print_vector(const std::vector<std::string>& words) {
	for (const std::string& word : words) {
		std::cout << word << " ";
	}
	std::cout << std::endl;
}
int main()
{
	std::vector<std::string> words{ "hello", "world", "c++" };
	print_vector(words);
	reverse_strings(words);
	print_vector(words);
	
	return 0;
}
