#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string.h>

using namespace std;

struct Avis
{
    char Vardas[11];
    char DNR[21];
    int Panasumai=0;
};

struct TiriamaAvis
{
    int numeris;
    char Vardas[11];
    char DNR[21];
};

void Nuskaitymas(int& n, int& m, TiriamaAvis& tiriamaAvis, Avis*& avys);
int DviejuAviuPlayginimas(int m, Avis*& avis, TiriamaAvis tiriamaAvis);
void VisuAviuPalyginimas(int n, int m,  Avis*& avys, TiriamaAvis tiriamaAvis);
void Rikiavimas(int n, Avis*& avys);
void Isvedimas(int n, Avis*& avys, TiriamaAvis tiriamaAvis);

int main()
{
    int n, m;
    Avis* avys = nullptr;
    TiriamaAvis tiriamaAvis;

    Nuskaitymas(n, m, tiriamaAvis, avys);
    VisuAviuPalyginimas(n, m, avys, tiriamaAvis);
    Rikiavimas(n, avys);
    Isvedimas(n, avys, tiriamaAvis);

    delete[] avys;
    return 0;
}

void Nuskaitymas(int& n, int& m, TiriamaAvis& tiriamaAvis, Avis*& avys)
{
    ifstream duomenys("duomenys.txt");
    duomenys >> n >> m >> tiriamaAvis.numeris;
    avys = new Avis[n];
    tiriamaAvis.numeris--;
    for(int i=0; i<n; i++)
    {
        if(i!=tiriamaAvis.numeris)
        {
            duomenys.ignore(256, '\n');
            duomenys.get(avys[i].Vardas, 11);
            duomenys.get(avys[i].DNR, 21);
        }
        else
        {
            duomenys.ignore(256, '\n');
            duomenys.get(tiriamaAvis.Vardas, 11);
            duomenys.get(tiriamaAvis.DNR, 21);
        }
    }
    duomenys.close();
}

int DviejuAviuPlayginimas(int m, Avis& avis, TiriamaAvis tiriamaAvis)
{
    int panasumai=0;
    for(int i=0; i<m; i++)
    {
        if(tiriamaAvis.DNR[i]==avis.DNR[i])
        {
            panasumai++;
        }
    }

    return panasumai;
}

void VisuAviuPalyginimas(int n, int m,  Avis*& avys, TiriamaAvis tiriamaAvis)
{
    for(int i=0; i<n; i++)
    {
        avys[i].Panasumai = DviejuAviuPlayginimas(m, avys[i], tiriamaAvis);
    }
}

void Rikiavimas(int n, Avis*& avys)
{
    for(int i=0; i<n-1; i++)
    {
        int max=i;
        for(int j=i+1; j<n; j++)
        {
            if(avys[j].Panasumai>avys[max].Panasumai || (avys[j].Panasumai==avys[max].Panasumai && strcmp(avys[j].Vardas, avys[max].Vardas)<0))
            {
                max=j;
            }
        }
        if(max!=i)
        {
            swap(avys[i], avys[max]);
        }
    }
}

void Isvedimas(int n, Avis*& avys, TiriamaAvis tiriamaAvis)
{
    ofstream rezultatai("rezultatai.txt");
    rezultatai << tiriamaAvis.Vardas << endl;
    for(int i=0; i<n-1; i++)
    {
        rezultatai << avys[i].Vardas << " " << avys[i].Panasumai << endl;
    }
    rezultatai.close();
}
