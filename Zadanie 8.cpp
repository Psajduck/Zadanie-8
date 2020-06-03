#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Wezel1D.h"
#include "Element1D.h"

using namespace std;

vector<double> wczytaj_siatke(string,double);
vector<double> wczytaj_temperature(string,vector <double>);


int main()
{
    int n;
    double d;// = 10; 
    string nazwa;// = "siatka.txt";
    string nazwa_tem; //="temperatura.txt";

    cout << "Nazwa pliku z rozszerzeniem (siatka): ";
    getline(cin, nazwa);
    cout << "Odleglosc miedzy wezlami: ";
    cin >> d;
    cout << "Nazwa pliku z rozszerzeniem (temperatury): ";
    getline(cin, nazwa);

    vector<double> siatka=wczytaj_siatke(nazwa,d);
    vector<double> temp=wczytaj_temperature(nazwa_tem,siatka);
    n = size(siatka);
    vector<Wezel1D>vec1(n);
    vector<Element1D>vec2(n-1);
    for (int i=0;i < n;i++)
    {
        vec1[i].ustawTemperature(i+1, temp[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        vec2[i].ustaw(i + 1, &temp[i], &temp[i + 1]);
    }
    for (int i =0;i<n-1;i++)
    {
        vec1[i].pobierzTemperature();
        cout << '\n';
        cout << "sr: ";
        vec2[i].pobierzTemperature();
        cout << '\n';
    }
    vec1[n - 1].pobierzTemperature();
    
    return 0;
}

vector<double> wczytaj_siatke(string name,double odleglosc)
{
    string linia;
    fstream plik;
    vector<double> A,B;
    double a, b;

    plik.open(name, ios::in);
    if (plik.good() == true)
    {
        getline(plik,linia);
        while (!plik.eof())
        {
            plik >> a >> b;
            A.push_back(b);
        }
    }
    else
    {
        cout << "Blad otwarcia pliku z siatka\n";
        system("pause");
        exit(0);
    }
    plik.close();

    for (double i=0;i<=A[size(A)-1];i+=odleglosc)
    {
        B.push_back(i);
    }

    return B;
}
vector<double> wczytaj_temperature(string name, vector<double> B)
{
    fstream plik;
    vector<double> A;
    double a;

    plik.open(name, ios::in);
    if (plik.good() == true)
    {
        while (!plik.eof())
        {
            plik >> a;
            A.push_back(a);
        }
    }
    else
    {
        cout << "Blad otwarcia pliku z temperatura\n";
        system("pause");
        exit(0);
    }
    plik.close();
    if (size(A)<size(B))
    {
        cout << "Wczytano mniejsza ilosc temeratur niz ilosc wezlow.\n";
        cout << "Pozostale wezly otrzymaja temperature 0.\n";
        while (size(A) < size(B))//wyrównanie ilości elementów tablicy z temp
        {
            A.push_back(0);
        }
    }
    else if (size(A) > size(B))
    {
        cout << "Wczytana ilosc temperatur jest wieksza niz ilosc wezlow\n";
        cout << "Nie wszystkie temperatury zostana uzyte\n";
    }

    return A;
}