#include <iostream>
#include <string>
#include <algorithm>
/*
Napišite funkciju void fix_spaces(std::string& text) koja:
· uklanja višestruke razmake (ostavlja samo jedan razmak između riječi),
· uklanja razmake prije zareza i točke, a dodaje, ako već nema, razmak nakon zareza.
Napomena: Koristite funkcije STL-a za pronalaženje, brisanje i dodavanje znakova.
Primjer: "Puno razmaka ,i tocka ." -> "Puno razmaka, i tocka."
*/

void fix_spaces(std::string& text)
{
	
	for (size_t i = 0; i < text.size(); i++) {
		if (text[i] == ' ' && i + 1 < text.size() && text[i + 1] == ' ') {
			text.erase(i, 1);
			i--; 
		}

	}
	

	for (size_t i = 0; i < text.size(); i++) {
		if ((text[i] == ',' || text[i] == '.') && i > 0 && text[i - 1] == ' ') {
			text.erase(i - 1, 1); 
			i--; 
		}
	}

	for (size_t i = 0; i < text.size(); i++) {
		if (text[i] == ',' && i + 1 < text.size() && text[i + 1] != ' ') {
			text.insert(i + 1, " "); 
			i++; 
		}
	}
}

int main3()
{
	std::string text("Puno razmaka  ,i tocka .");
	fix_spaces(text);
	std::cout << text << std::endl;
	
	return 0;
}
