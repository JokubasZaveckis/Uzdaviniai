#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

struct struktura
{
    char vardas[8];
    char pavarde [10];
    int ivertinimas;
    int pazymiai[10];
};
void nuskaitymas (int &n, int &k, float ivertinimodalis[], struktura strukturos[]);
void galutinisIvertinimas(int n, int k, struktura strukturos[], float ivertinimodalis[]);
int auskciausiasPazimys(int n, struktura strukturos[]);
int maziausiasPazimys(int n, struktura strukturos[]);
void Isvedimas(int n, int k, struktura strukturos[], float ivertinimodalis[], struktura geri[], struktura blogi[], int ng, int nb);
int galutinisPazimys(int k, float ivertinimodalis[], struktura vaikas);
void blogiausi(int n, struktura blogi[], struktura strukturos[], int& nb);
void geriausi(int n, struktura geri[], struktura strukturos[], int& ng);


int main()
{
    int n, k, ng=0, nb=0;
    float ivertinimodalis[10], vidurkis;
    struktura strukturos[10], geri[10], blogi[10];
    nuskaitymas(n, k, ivertinimodalis, strukturos);
    galutinisIvertinimas(n, k, strukturos, ivertinimodalis);
    blogiausi(n, blogi, strukturos, nb);
    geriausi(n, geri, strukturos, ng);
    Isvedimas(n, k,  strukturos, ivertinimodalis, geri, blogi, ng, nb);
    return 0;
}


void nuskaitymas (int &n, int &k, float ivertinimodalis[], struktura strukturos[])
{
    ifstream failas ("failas.txt");
    failas>>n>>k;
    for (int i=0; i<k; i++)
    {
        failas>>ivertinimodalis[i];
    }
    for (int i=0; i<n; i++)
    {
        failas >> strukturos[i].vardas >> strukturos[i].pavarde;
        for (int j=0; j<k; j++)
        {
            failas >> strukturos[i].pazymiai[j];
        }
    }
    failas.close();
}

void galutinisIvertinimas(int n, int k, struktura strukturos[], float ivertinimodalis[])
{

    for (int i=0; i<n; i++)
    {
        strukturos[i].ivertinimas = galutinisPazimys(k, ivertinimodalis, strukturos[i]);
    }
}

int galutinisPazimys(int k, float ivertinimodalis[], struktura vaikas)
{
        float suma=0;
        for (int j=0; j<k; j++)
        {
            suma += vaikas.pazymiai[j]*ivertinimodalis[j];
        }
    return round(suma);
}


int auskciausiasPazimys(int n, struktura strukturos[])
{
    int max = 0;
    for (int i=1; i<n; i++)
    {
        if (strukturos[i].ivertinimas > strukturos[max].ivertinimas)
            max = i;
    }
    return strukturos[max].ivertinimas;
}

int maziausiasPazimys(int n, struktura strukturos[])
{
    int min = 0;
    for (int i=1; i<n; i++)
    {
        if (strukturos[i].ivertinimas < strukturos[min].ivertinimas)
            min = i;
    }
    return strukturos[min].ivertinimas;
}

void geriausi(int n, struktura geri[], struktura strukturos[], int& ng)
{
    int max = auskciausiasPazimys(n, strukturos);
    for (int i=0; i<n; i++)
    {
        if (max == strukturos[i].ivertinimas)
            geri[ng++] = strukturos[i];
    }

}

void blogiausi(int n, struktura blogi[], struktura strukturos[], int& nb)
{
    int min = maziausiasPazimys(n, strukturos);
    for(int i=n-1; i>=0; i--)
    {
    if (min == strukturos[i].ivertinimas)
        blogi[nb++] = strukturos[i];
    }
}

void Isvedimas(int n, int k, struktura strukturos[], float ivertinimodalis[], struktura geri[], struktura blogi[], int ng, int nb)
{
    int max = auskciausiasPazimys(n, strukturos);
    int min = maziausiasPazimys(n, strukturos);

    cout << "VISI " << endl;
    cout << " " << endl;
    for (int i=0; i<n; i++)
    {
        cout << strukturos[i].vardas << strukturos[i].pavarde << " " << strukturos[i].ivertinimas << endl;
    }


    cout << "Geriausi" << endl;
    cout << " " << endl;
    for (int i=0; i<ng; i++)
    {
        cout << geri[i].vardas << geri[i].pavarde << " " << geri[i].ivertinimas << endl;
    }


    cout << "BLOGIAUSI" << endl;
    cout << " " << endl;
    for (int i=0; i<nb; i++)
    {
        cout << blogi[i].vardas << blogi[i].pavarde << " " << blogi[i].ivertinimas << endl;
    }
}

