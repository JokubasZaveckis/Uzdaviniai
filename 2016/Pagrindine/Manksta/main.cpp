#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>

using namespace std;

struct Eilute
{
    char pratimas[21];
    int suma;
};

void Nuskaitymas(int& n, Eilute*& eilutes);
void Rikiavimas(int n, Eilute*& eilutes);
void Skaiciavimai(int& n, Eilute*& eilutes);
void Rikiavimass(int n, Eilute*& eilutes);
void Isvedimas(int n, Eilute*& eilutes);

int main()
{
    int n;
    Eilute* eilutes = nullptr;

    Nuskaitymas(n, eilutes);
    Rikiavimas(n, eilutes);
    Skaiciavimai(n, eilutes);
    Rikiavimass(n, eilutes);
    Isvedimas(n, eilutes);

    ofstream rezultatai("rezultatai.txt");

    for(int i=0; i<n; i++)
    {
        rezultatai << eilutes[i].pratimas << " " << eilutes[i].suma << endl;
    }

    rezultatai.close();

    delete[] eilutes;

    return 0;
}

void Nuskaitymas(int& n, Eilute*& eilutes)
{
    ifstream duomenys("duomenys.txt");
    duomenys >> n;
    eilutes = new Eilute[n];
    for(int i=0; i<n; i++)
    {
        duomenys.ignore(256, '\n');
        duomenys.get(eilutes[i].pratimas, 21);
        duomenys >> eilutes[i].suma;
    }
    duomenys.close();
}

void Rikiavimas(int n, Eilute*& eilutes)
{
    for(int i=0; i<n-1; i++)
    {
        int max=i;
        for(int j=i+1; j<n; j++)
        {
            if(strcmp(eilutes[j].pratimas, eilutes[max].pratimas)<0)
            {
                max=j;
            }
        }
        if(max!=i)
        {
            swap(eilutes[i], eilutes[max]);
        }
    }
}

void Skaiciavimai(int& n, Eilute*& eilutes)
{
    for(int i=0; i<n-1; i++)
    {
        if(strcmp(eilutes[i].pratimas, eilutes[i+1].pratimas)==0)
        {
            eilutes[i].suma+=eilutes[i+1].suma;
            for(int j=i+1; j<n-1; j++)
            {
                eilutes[j]=eilutes[j+1];
            }
            i--;
            n--;
        }
    }
}

void Rikiavimass(int n, Eilute*& eilutes)
{
    for(int i=0; i<n-1; i++)
    {
        int max=i;
        for(int j=i+1; j<n; j++)
        {
            if(eilutes[j].suma > eilutes[max].suma || (eilutes[j].suma==eilutes[max].suma && strcmp(eilutes[j].pratimas, eilutes[j].pratimas)<0))
            {
                max=j;
            }
        }
        if(max!=i)
        {
            swap(eilutes[i], eilutes[max]);
        }
    }
}
