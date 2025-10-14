#include <iostream>
#include <string>
#include <cctype>

/* U�itajte jedan redak u std::string s (std::getline). Koriste�i range-based
for sva slova pretvorite u velika, znamenke zamijenite znakom '*', a
razmake i tabove znakom '_'. Ispi�ite dobiveni string.
Napomena: za std::string koristite #include <string>, a za std::toupper
koristite #include <cctype> */

int main1()
{
	std::string s;
	std::getline(std::cin, s);
	for (char &n : s) {
		n = std::toupper(n);
		if (n >= '0' && n <= '9')
			n = '*';
		if (n == ' ')
			n = '-';
	}
	std::cout << s << std::endl;

	return 0;
}