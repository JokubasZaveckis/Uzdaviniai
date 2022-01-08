#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

struct struktura
{
    char vardas[25];
    char pavarde[25];
    int valandos;
    int minutes;
    int suma;
    int skirtumas;
};

void Nuskaitymas(int&n, int&m, struktura strukturos[]);
int laikoVidurkis(int n, struktura strukturos[]);
void likesLaikas(int n, int m, struktura strukturos[]);
void prakalbetasLaikas(int n, int m, struktura strukturos[]);
int kiekis(int n, int t, struktura strukturos[]);
void rikiavimas(int n, int m, struktura strukturos[]);
int nuolaida(int n, int m, struktura strukturos[]);
void isvedimas(int n, int m, int t, struktura strukturos[], struktura masyvas[]);
void kopijavimas(int n, struktura strukturos[], struktura masyvas[]);


int main()
{
    int n, m, t;
    struktura strukturos[10], masyvas[10];
    Nuskaitymas(n, m, strukturos);
    prakalbetasLaikas(n, m, strukturos);
    likesLaikas(n, m, strukturos);
    kopijavimas(n, strukturos, masyvas);
    rikiavimas(n, m, masyvas);
    isvedimas(n, m, t, strukturos, masyvas);

    return 0;
}
void Nuskaitymas(int&n, int& m, struktura strukturos[])
{
    ifstream duomenys("duomenys.txt");
    duomenys >> n >> m;
    for(int i=0; i<n; i++)
    {
        duomenys.ignore(256,'\n');
        duomenys.get(strukturos[i].vardas, 20);
        duomenys.get(strukturos[i].pavarde, 20);
        duomenys >> strukturos[i].valandos >> strukturos[i].minutes;
        cout << strukturos[i].vardas << endl;
    }
    duomenys.close();
}

void kopijavimas(int n, struktura strukturos[], struktura masyvas[])
{
    for(int i=0; i<n; i++)
    {
        masyvas[i] = strukturos[i];
    }
}

void prakalbetasLaikas(int n, int m, struktura strukturos[])
{
    for(int i=0; i<n; i++)
    {
        strukturos[i].suma = strukturos[i].valandos*60 + strukturos[i].minutes;
    }
}

void likesLaikas(int n, int m, struktura strukturos[])
{
    for(int i=0; i<n; i++)
    {
        strukturos[i].skirtumas= abs(m-(strukturos[i].valandos*60 + strukturos[i].minutes));
    }
}

int laikoVidurkis(int n, struktura strukturos[])
{
    int suma=0;
    float vidurkis;
    for(int i=0; i<n; i++)
    {
        suma += strukturos[i].valandos*60 + strukturos[i].minutes;
    }
    vidurkis = suma/n;
    return vidurkis;
}

void rikiavimas(int n, int m, struktura strukturos[])
{
    for (int i=0; i<n-1; i++)
    {
        int min = i;
        for (int j=i+1; j<n; j++)
        {
            if (strukturos[min].skirtumas>strukturos[j].skirtumas) min = j;
        }
        if (min!=i)
        {
            struktura tmp = strukturos[i];
            strukturos[i] = strukturos[min];
            strukturos[min] = tmp;
        }
}
}

int kiekis(int n, int t, struktura strukturos[])
{
    int kiek=0;
    for (int i=0; i<n; i++)
    {
        if (t < strukturos[i].suma) kiek++;
    }
    return kiek;
}

void isvedimas(int n, int m, int t, struktura strukturos[], struktura masyvas[])
{
    cout << "ivesti minuciu riba " << endl;
    cin >> t;
    int kiek = kiekis(n, t, strukturos);
    float vidurkis = laikoVidurkis(n,strukturos);

    for(int i=0; i<n; i++)
    {
        cout << strukturos[i].vardas << " " << strukturos[i].pavarde << " " << strukturos[i].skirtumas << endl;
    }

    cout << masyvas[0].vardas << " " << masyvas[1].vardas << endl;
    cout << kiek << endl;
    cout << vidurkis << endl;
}
