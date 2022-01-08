#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include "Programa.h"

using namespace std;


int main()
{
    string Byla = "U1.txt";
    string Duomenys = "U1rez.txt";
    Programa programa;
    programa.Vykdyti(Byla, Duomenys);

    return 0;
}


