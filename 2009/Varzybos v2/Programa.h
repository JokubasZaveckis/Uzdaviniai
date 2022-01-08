#include "Plaukimas.h"
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

struct Programa
{
    Plaukikas plaukimas[50];
    int k, a;
    void Vykdyti(string Byla, string Duomenys);
private:
    void Nuskaitymas(string Byla);
    void Isvedimas(string Duomenys);
    void Rikiavimas();
    void Skaiciavimai();
};

