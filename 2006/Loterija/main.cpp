#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

struct Loterija{
    int pirkimai;
    int laimejimai;
};

void Nuskaitymas(int& N, Loterija loterija[]);
int PirkimoSuma(int N, Loterija loterija[]);
int LaimejimoSuma(int N, Loterija loterija[]);
int DidziausiasLaimejimas(int N, Loterija loterija[]);
int Nuostolis(int N, Loterija loterija[]);
void Isvedimas(int N, Loterija loterijos[]);

int main()
{
    int N, nuostolis, pirkimoSuma, laimejimoSuma, max;
    Loterija loterija[20];
    Nuskaitymas(N, loterija);
    Isvedimas(N, loterija);

    return 0;
}

void Nuskaitymas(int& N, Loterija loterija[])
{
    ifstream duomenys("Loterija.dat.txt");
    duomenys >> N;
    for (int i=0; i<N; i++)
    {
        duomenys >> loterija[i].pirkimai >> loterija[i].laimejimai;
    }
    duomenys.close();
}

int PirkimoSuma(int N, Loterija loterija[])
{
    int psuma=0;
    for(int i=0; i<N; i++)
    {
        psuma += loterija[i].pirkimai;
    }
    return psuma;
}

int LaimejimoSuma(int N, Loterija loterija[])
{
    int lsuma=0;
    for(int i=0; i<N; i++)
    {
        lsuma += loterija[i].laimejimai;
    }
    return lsuma;
}

int DidziausiasLaimejimas(int N, Loterija loterija[])
{
    int max=0;
    for (int i=1; i<N; i++)
    {
        if(loterija[i].laimejimai > loterija[max].laimejimai) max = i;
    }
    return loterija[max].laimejimai;
}

int Nuostolis(int N, Loterija loterija[])
{
    int nuostolis;
    nuostolis = PirkimoSuma(N, loterija) - LaimejimoSuma(N, loterija);
    return nuostolis;
}

void Isvedimas(int N, Loterija loterija[])
{
    int pirkimoSuma = PirkimoSuma(N, loterija);
    int laimejimoSuma = LaimejimoSuma(N, loterija);
    int max = DidziausiasLaimejimas( N, loterija);
    int nuostolis = Nuostolis(N, loterija);

    cout << pirkimoSuma << " " << laimejimoSuma << endl;
    cout << "Didziausias laimejimas " << max << endl;
    cout << "Nuostolis: " << nuostolis << endl;
}
