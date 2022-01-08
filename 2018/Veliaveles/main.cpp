#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>

using namespace std;

struct Spalvos
{
    int Geltona = 0;
    int Zalia = 0;
    int Raudona = 0;
};

void Nuskaitymas(int&n, Spalvos& spalvos);
int VeliaveliuSkaiciavimas(int n, Spalvos& spalvos);
void Isvedimas(int n, Spalvos spalvos);

int main()
{
    int n;
    Spalvos spalvos;

    Nuskaitymas(n, spalvos);
    Isvedimas(n, spalvos);

    return 0;
}

void Nuskaitymas(int&n, Spalvos& spalvos)
{
    ifstream duomenys("duomenys.txt");
    duomenys >> n;
    int kiekis;
    string raide;
    for(int i=0; i<n; i++)
    {
        duomenys >> raide;
        duomenys >> kiekis;
        if(raide == "Z")
        {
            spalvos.Zalia+=kiekis;
        }
        else if(raide == "R")
        {
            spalvos.Raudona+=kiekis;
        }
        else spalvos.Geltona+=kiekis;
    }
    duomenys.close();
}

int VeliaveliuSkaiciavimas(int n, Spalvos& spalvos)
{
    int kiekVeliaveliu=0;

    while(spalvos.Raudona-2>=0 && spalvos.Zalia-2>=0 && spalvos.Geltona-2>=0)
    {
        kiekVeliaveliu++;
        spalvos.Raudona-=2;
        spalvos.Geltona-=2;
        spalvos.Zalia-=2;
    }
    return kiekVeliaveliu;
}

void Isvedimas(int n, Spalvos spalvos)
{
    ofstream rezultatai("rezultatai.txt");

    int kiekVeliaveliu = VeliaveliuSkaiciavimas(n, spalvos);

    rezultatai << kiekVeliaveliu << endl;
    rezultatai << "G = " << spalvos.Geltona << endl;
    rezultatai << "Z = " << spalvos.Zalia << endl;
    rezultatai << "R = " << spalvos.Raudona << endl;

    rezultatai.close();
}
