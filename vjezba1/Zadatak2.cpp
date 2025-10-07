#include <iostream>
int lowhigh(int n)
{
	int low(1);
	int high(9999);
	if (n < low) {
		return low;
	}
	if (n > high) {
		return high;
	}
	else return n;
}
double lowhigh(double n)
{
	int low(1.0);
	int high(9999.9);
	if (n < low) {
		return low;
	}
	if (n > high) {
		return high;
	}
	else return n;

}
int main()
{
	std::cout << lowhigh(-2) << std::endl;
	std::cout << lowhigh(13.2) << std::endl;

}