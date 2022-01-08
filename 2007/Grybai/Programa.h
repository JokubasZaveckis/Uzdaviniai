#include "grybavimas.h"
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

struct Programa
{
    Grybavimas grybavimai[100];
    int n;
    void Vykdyti(string Byla, string Duomenys);
    private:
    void Nuskaitymas(string Byla);
    void Isvedimas(string Duomenys);
    void Rikiavimas();
    void Sutraukimas();
    void SumosSkaiciavimas();
    int DaugiausiaiGrybu();
};
