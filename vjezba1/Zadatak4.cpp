#include <iostream>
#include <string>


/*Napi�ite funkciju at koja vra�a referencu na neki element C-niza. 
Koriste�i povratnu vrijednost funkcije kao lvalue uve�ajte i-ti element niza
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