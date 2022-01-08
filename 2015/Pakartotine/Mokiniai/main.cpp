#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>

using namespace std;

struct Mokinys
{
    char vardas[11];
    char atsakymai[7];
    int teisingiAtsakymai=0;
};

struct Mokytojas
{
    char vardas[11];
    int numeris;
    char atsakymai[7];
};

void Nuskaitymas(int&n, int&m, Mokytojas& mokytojas, Mokinys*& mokiniai);
void TeisinguAtsakymuSkaiciavimas(int n, int m, Mokinys*& mokiniai, Mokytojas mokytojas);
void Rikiavimas(int n, Mokinys*& mokiniai);
void Isvedimas(int n, Mokytojas mokytojas, Mokinys*& mokiniai);

int main()
{
    int n, m;
    Mokinys* mokiniai = nullptr;
    Mokytojas mokytojas;

    Nuskaitymas(n, m, mokytojas, mokiniai);
    TeisinguAtsakymuSkaiciavimas(n, m, mokiniai, mokytojas);
    Rikiavimas(n, mokiniai);
    //Isvedimas(n, mokytojas, mokiniai);

    delete[] mokiniai;
    return 0;
}

void Nuskaitymas(int&n, int&m, Mokytojas& mokytojas, Mokinys*& mokiniai)
{
    ifstream duomenys("duomenys.txt");
    duomenys >> n >> m >> mokytojas.numeris;
    mokiniai = new Mokinys[n];
    mokytojas.numeris--;
    for(int i=0; i<n; i++)
    {
        if(i!=mokytojas.numeris)
        {
                duomenys.ignore(256, '\n');
                duomenys.get(mokiniai[i].vardas, 11);
                duomenys.get(mokiniai[i].atsakymai, 7);
                cout << mokiniai[i].vardas << " " << mokiniai[i].atsakymai << endl;
        }
        else
        {
                duomenys.ignore(256, '\n');
                duomenys.get(mokytojas.vardas, 11);
                duomenys.get(mokytojas.atsakymai, 7);
                cout << mokytojas.vardas << " " << mokytojas.atsakymai << endl;
        }
    }
    duomenys.close();
}

void TeisinguAtsakymuSkaiciavimas(int n, int m, Mokinys*& mokiniai, Mokytojas mokytojas)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(mokytojas.atsakymai[j]==mokiniai[i].atsakymai[j])
            {
                mokiniai[i].teisingiAtsakymai++;
            }
        }
    }
}

void Rikiavimas(int n, Mokinys*& mokiniai)
{
    for(int i=0; i<n-1; i++)
    {
        int max=i;
        for(int j=i+1; j<n; j++)
        {
            if(mokiniai[max].teisingiAtsakymai>mokiniai[j].teisingiAtsakymai) max=j;
        }
        if(max!=i)
        {
            swap(mokiniai[i], mokiniai[max]);
        }
    }
}

void Isvedimas(int n, Mokytojas mokytojas, Mokinys*& mokiniai)
{
    cout << mokytojas.vardas << endl;
    for(int i=1; i<n; i++)
    {
        cout << mokiniai[i].vardas << " " << mokiniai[i].teisingiAtsakymai << endl;
    }
}
