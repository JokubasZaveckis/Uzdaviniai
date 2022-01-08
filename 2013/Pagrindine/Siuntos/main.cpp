#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

struct Uzsakovas
{
    char Pavadinimas[11];
    int X, Y;
    int Atstumas=0;
};

void Nuskaitymas(int&n, int&m, Uzsakovas*& uzsakovai);
void AtstumoSkaiciavimas(int n, Uzsakovas*& uzsakovai);
void Aptarnavimas(int n, int m, Uzsakovas*& uzsakovai, int& nuvaziuotasAtstumas, int& aptarnauti);
void Isvedimas(int n, int m, Uzsakovas*& uzsakovai, int nuvaziuotasAtstumas, int aptarnauti);


int main()
{
    int n, m, nuvaziuotasAtstumas=0, aptarnauti=0;
    Uzsakovas* uzsakovai=NULL;

    Nuskaitymas(n, m, uzsakovai);
    AtstumoSkaiciavimas(n, uzsakovai);
    Aptarnavimas(n, m, uzsakovai, nuvaziuotasAtstumas, aptarnauti);
    Isvedimas(n, m, uzsakovai, nuvaziuotasAtstumas, aptarnauti);

    delete[]uzsakovai;
    return 0;
}

void Nuskaitymas(int&n, int&m, Uzsakovas*& uzsakovai)
{
    ifstream duomenys("duomenys.txt");
    duomenys >> n >> m;
    uzsakovai = new Uzsakovas[n];

    for(int i=0; i<n; i++)
    {
        duomenys.ignore(256, '\n');
        duomenys.get(uzsakovai[i].Pavadinimas, 11);
        duomenys >> uzsakovai[i].X >> uzsakovai[i].Y;
    }
    duomenys.close();
}

void AtstumoSkaiciavimas(int n, Uzsakovas*& uzsakovai)
{
    for(int i=0; i<n; i++)
    {
        uzsakovai[i].Atstumas=abs(uzsakovai[i].X)*2+abs(uzsakovai[i].Y)*2;
    }
}

void Aptarnavimas(int n, int m, Uzsakovas*& uzsakovai, int& nuvaziuotasAtstumas, int& aptarnauti)
{
    while(nuvaziuotasAtstumas+uzsakovai[aptarnauti+1].Atstumas<=m && n!=0)
    {
        nuvaziuotasAtstumas+=uzsakovai[aptarnauti++].Atstumas;
        //cout << nuvaziuotasAtstumas << endl;
        n--;
    }
}

void Isvedimas(int n, int m, Uzsakovas*& uzsakovai, int nuvaziuotasAtstumas, int aptarnauti)
{
    cout << aptarnauti << " " << nuvaziuotasAtstumas << " " << uzsakovai[aptarnauti-1].Pavadinimas << endl;
}

