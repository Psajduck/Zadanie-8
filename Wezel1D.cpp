#include "Wezel1D.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;


void Wezel1D::ustawTemperature(int nr,double t)
{
	Numer = nr;
	Temperatura = t;
}

void Wezel1D::pobierzTemperature()
{
	cout << Numer << ".\t" << Temperatura << "\n";
}
