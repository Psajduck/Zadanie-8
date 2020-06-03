#include "Element1D.h"
#include <iostream>

using namespace std;

void Element1D::ustaw(int nr, double *wsk1,double *wsk2)
{
	Numer = nr;
	lewy_wsk = wsk1;
	prawy_wsk = wsk2;
}

void Element1D::pobierzTemperature()
{
	cout <<(*lewy_wsk + *prawy_wsk)/2<<"\n";
}
