#include <iostream>
#include <string>


/*Napišite funkciju at koja vraæa referencu na neki element C-niza. 
Koristeæi povratnu vrijednost funkcije kao lvalue uveæajte i-ti element niza
za jedan.*/

char& at(std::string& s, int i)
{
	return s[i];
}

int main()
{
	std::string s("012345");
	at(s, 3) += 1;
	std::cout << s << std::endl;
	return 0;

}