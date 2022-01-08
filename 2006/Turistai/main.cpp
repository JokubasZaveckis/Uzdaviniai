#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

struct Turistai
{
    char vardas[16];
    int banknotai;
    int vertes[10];
    int atskirai;
};

void Nuskaitymas(int&n, Turistai turizmas[]);
int BendraSuma(int n, Turistai turizmas[]);
void SumaAtskirai(int n, Turistai turizmas[]);
int Turtingiausias (int n, Turistai turizmas[]);
void Isvedimas(int n, Turistai turizmas[]);

int main()
{
    int n, suma, turtingiausias;
    Turistai turizmas[50];
    Nuskaitymas(n, turizmas);
    Isvedimas(n, turizmas);
    return 0;
}

void Nuskaitymas(int&n, Turistai turizmas[])
{
    ifstream duomenys("U2.txt");
    duomenys >> n;
    for(int i=0; i<n; i++)
    {
        duomenys.ignore(256,'\n');
        duomenys.get (turizmas[i].vardas, 16);
        duomenys >> turizmas[i].banknotai;
        for(int j=0; j<turizmas[i].banknotai; j++)
            duomenys >> turizmas[i].vertes[j];
    }
    duomenys.close();
}

int BendraSuma(int n, Turistai turizmas[])
{
    int suma = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<turizmas[i].banknotai; j++)
        {
            suma += turizmas[i].vertes[j];
        }
    }
    return suma;
}

void SumaAtskirai(int n, Turistai turizmas[])
{
    int suma = 0;
    for (int i=0; i<n; i++)
    {
        suma = 0;
        for(int j=0; j<turizmas[i].banknotai; j++)
        {
            suma += turizmas[i].vertes[j];
        }
        turizmas[i].atskirai=suma;
    }
}

int Turtingiausias (int n, Turistai turizmas[])
{
    int max = 0;
    for(int i=1; i<n; i++)
    {
        if(turizmas[i].atskirai>turizmas[max].atskirai)
            max = i;
    }
    return max;
}

void Isvedimas(int n, Turistai turizmas[])
{
    int suma = BendraSuma(n, turizmas);
    SumaAtskirai(n, turizmas);
    int max = Turtingiausias (n, turizmas);

    cout << suma << endl;
    cout << endl;
    for (int i=0; i<n; i++)
    {
        cout << turizmas[i].vardas << turizmas[i].atskirai << " " << endl;
    }
    cout << endl;
    cout << turizmas[max].vardas << " " << turizmas[max].atskirai << endl;
}








