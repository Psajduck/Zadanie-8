#pragma once
#include <string>
#include <vector>
using namespace std;

class Wezel1D
{
private:
	int Numer;
	double Temperatura;
public:
	void ustawTemperature(int, double);
	void pobierzTemperature();
};

