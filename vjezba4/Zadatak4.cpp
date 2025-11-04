#include <iostream>
#include <string>
#include <algorithm>

/*
Napišite funkciju std::string word_to_pig_latin(const std::string& word) koja:
· ako riječ počinje samoglasnikom: dodaje ”hay”
· ako počinje suglasnikom: premješta prvo slovo na kraj i dodaje ”ay”
Primjer: "apple" -> "applehay"
"hello" -> "ellohay"
*/

std::string word_to_pig_latin(const std::string& word)
{
	std::string novi;
	novi = word;
	if (novi.front() == 'a' || novi.front() == 'e' || novi.front() == 'i' || novi.front() == 'o' || novi.front() == 'u') {
		novi += "hey"; 


	}
	else {
		char c = novi.front();
		novi.erase(0, 1);
		novi.push_back(c);
		novi += "ay";
		

	}
	return novi;
}

int main4()
{
	std::string word1("apple");
	std::string word2("hello");
	std::string sa_samoglasnikom = word_to_pig_latin(word1);
	std::string bez_samoglasnika = word_to_pig_latin(word2);

	std::cout << "Rijec koja je sa samoglasnikom: " << sa_samoglasnikom << std::endl;
	std::cout << "Rijec koja nije sa samoglasnikom: " << bez_samoglasnika << std::endl;
	return 0;
}
