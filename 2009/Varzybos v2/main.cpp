#include <iostream>
#include <fstream>
#include <iomanip>
#include "Programa.h"

using namespace std;

int main()
{
    string Byla= "duomenys.txt";
    string Duomenys = "rez.txt";
    Programa programa;
    programa.Vykdyti(Byla, Duomenys);
    return 0;
}
