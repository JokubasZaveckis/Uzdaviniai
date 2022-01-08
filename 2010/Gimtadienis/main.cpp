#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct Mokinys
{
    char vardas[16];
    int uzsakymai[30];
    int uzsisakymoSuma=0;
};

void Nuskaitymas(int&P, int& N, int patiekaluKainos[], Mokinys mokinys[]);
int UzsisakymoSumaAtskirai(int P, int N, int patiekaluKainos[], int uzsisakymai[]);
void UzsisakymoSumosPerkelimas(int P, int N, int patiekaluKainos[], Mokinys mokinys[]);
int UzsisakymoSuma(int N, Mokinys mokinys[]);
void Isvedimas(int N, Mokinys mokinys[]);

int main()
{
    Mokinys mokinys[100];
    int P, N, patiekaluKainos[30];

    Nuskaitymas(P, N, patiekaluKainos, mokinys);
    UzsisakymoSumosPerkelimas(P, N, patiekaluKainos, mokinys);
    Isvedimas(N, mokinys);

    return 0;
}

void Nuskaitymas(int&P, int& N, int patiekaluKainos[], Mokinys mokinys[])
{
    ifstream duomenys("duomenys.txt");
    duomenys >> P;
    for(int i=0; i<P; i++)
    {
        duomenys >> patiekaluKainos[i];
    }
    duomenys >> N;
    for(int i=0; i<N; i++)
    {
        duomenys.ignore(256, '\n');
        duomenys.get(mokinys[i].vardas, 16);
        for(int j=0; j<P; j++)
        {
            duomenys >> mokinys[i].uzsakymai[j];
        }
    }
    duomenys.close();
}

int UzsisakymoSumaAtskirai(int P, int N, int patiekaluKainos[], int uzsisakymai[])
{
    int suma=0;
        for(int i=0; i<P; i++)
        {
            suma+=patiekaluKainos[i]*uzsisakymai[i];
        }
    return suma;
}

void UzsisakymoSumosPerkelimas(int P, int N, int patiekaluKainos[], Mokinys mokinys[])
{
    for(int i=0; i<N; i++)
    {
            mokinys[i].uzsisakymoSuma= UzsisakymoSumaAtskirai(P, N, patiekaluKainos, mokinys[i].uzsakymai);
    }
}

int UzsisakymoSuma(int N, Mokinys mokinys[])
{
    int suma=0;
    for(int i=0; i<N; i++)
    {
        suma += mokinys[i].uzsisakymoSuma;
    }
    return suma;
}

void Isvedimas(int N, Mokinys mokinys[])
{
    ofstream rezultatai("rezultatai.txt");
    int suma = UzsisakymoSuma(N, mokinys);
    for(int i=0; i<N; i++)
    {
        cout << mokinys[i].vardas << " " << mokinys[i].uzsisakymoSuma << endl;
        rezultatai << mokinys[i].vardas << " " << mokinys[i].uzsisakymoSuma << endl;
    }
    cout << suma/100 << " " << suma%100 << endl;

    rezultatai << suma/100 << " " << suma%100 << endl;

    rezultatai.close();
}
