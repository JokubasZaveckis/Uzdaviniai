#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

struct Uzsakovas
{
    int X, Y;
    int Atstumas=0;
};

void Nuskaitymas(int&n, int&m, Uzsakovas*& uzsakovai);
int AtstumoSkaiciavimasUzsakovui(int n, Uzsakovas uzsakovas);
void AtstumoSkaiciavimas(int n, Uzsakovas*& uzsakovai);
void Aptarnavimas(int n, int m, Uzsakovas*& uzsakovai, int& nuvaziuotasAtstumas, int& klientai);
void Isvedimas(int n, int m, Uzsakovas*& uzsakovai, int nuvaziuotasAtstumas, int klientai);

int main()
{
    int n, m, nuvaziuotasAtstumas=0, klientai=0;
    Uzsakovas* uzsakovai=NULL;

    Nuskaitymas(n, m, uzsakovai);
    AtstumoSkaiciavimas(n, uzsakovai);
    Aptarnavimas(n, m, uzsakovai, nuvaziuotasAtstumas, klientai);
    Isvedimas(n, m, uzsakovai, nuvaziuotasAtstumas, klientai);

    delete []uzsakovai;
    return 0;
}

void Nuskaitymas(int&n, int&m, Uzsakovas*& uzsakovai)
{
    ifstream duomenys("duomenys.txt");
    duomenys >> n >> m;
    uzsakovai = new Uzsakovas[n];

    for(int i=0; i<n; i++)
    {
        duomenys >> uzsakovai[i].X >> uzsakovai[i].Y;
        //cout << uzsakovai[i].X << " " <<  uzsakovai[i].Y << endl;
    }
    duomenys.close();
}

int AtstumoSkaiciavimasUzsakovui(int n, Uzsakovas uzsakovas)
{
    return abs(uzsakovas.X)*2+abs(uzsakovas.Y)*2;
}

void AtstumoSkaiciavimas(int n, Uzsakovas*& uzsakovai)
{
    for(int i=0; i<n; i++)
    {
        uzsakovai[i].Atstumas=AtstumoSkaiciavimasUzsakovui(n, uzsakovai[i]);
    }
}

void Aptarnavimas(int n, int m, Uzsakovas*& uzsakovai, int& nuvaziuotasAtstumas, int& klientai)
{
    while(nuvaziuotasAtstumas<=m && n!=0)
    {
        nuvaziuotasAtstumas+=uzsakovai[klientai++].Atstumas;
        n--;
        //cout << n << " " << nuvaziuotasAtstumas << endl;
    }
}

void Isvedimas(int n, int m, Uzsakovas*& uzsakovai, int nuvaziuotasAtstumas, int klientai)
{
    int likeKlientai=n-klientai;
    cout << likeKlientai << " " << nuvaziuotasAtstumas << endl;

}

