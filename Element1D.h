#pragma once

class Element1D
{
private:
	int Numer;
	double *lewy_wsk;
	double *prawy_wsk;
public:
	void ustaw(int,double*, double*);
	void pobierzTemperature();
};

