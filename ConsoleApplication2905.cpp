


#include <iostream>
#include "demo.h"
using namespace std;

int main()
{
	//Fraction fr1(5);
	Fraction fr2(2, 3);
	fr2.printFraction();
	fr2.add(5);
	fr2.printFraction();
	fr2.sub(5);
	fr2.printFraction();
}

