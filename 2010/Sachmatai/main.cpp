#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int FigureliuSkaicius[] = {8, 2, 2, 2, 1, 1};

void Nuskaitymas(int& n, int trukstaPestininku[], int trukstaBokstu[], int trukstaZirgu[], int trukstaRikiu[], int trukstaKaraliu[], int trukstaVladoviu[]);
void TurimosFigureles(int n, int truksta[], int kiekFigureliuKomplektui);
int FigureliuSuma(int n, int turimosFigureles[]);
void GalimiKomplektai(int figureles[], int kiekFigureliuKomplektui, int komplektai[]);
int KomplektuSuradimas(int galimiKomplektai[]);
void Isvedimas(int n, int galimiKomplektai[]);


int main()
{
    int n, trukstaPestininku[100], trukstaBokstu[100], trukstaZirgu[100], trukstaRikiu[100], trukstaKaraliu[100], trukstaVladoviu[100];
    int esamuFigureliuMasyvas[100], galimiKomplektai[100];
    Nuskaitymas(n, trukstaPestininku, trukstaBokstu, trukstaZirgu, trukstaRikiu, trukstaKaraliu, trukstaVladoviu);

    TurimosFigureles(n, trukstaPestininku, FigureliuSkaicius[0]);
    TurimosFigureles(n, trukstaBokstu, FigureliuSkaicius[1]);
    TurimosFigureles(n, trukstaZirgu, FigureliuSkaicius[2]);
    TurimosFigureles(n, trukstaRikiu, FigureliuSkaicius[3]);
    TurimosFigureles(n, trukstaVladoviu, FigureliuSkaicius[4]);
    TurimosFigureles(n, trukstaKaraliu, FigureliuSkaicius[5]);

    esamuFigureliuMasyvas[0]=FigureliuSuma(n, trukstaPestininku);
    esamuFigureliuMasyvas[1]=FigureliuSuma(n, trukstaBokstu);
    esamuFigureliuMasyvas[2]=FigureliuSuma(n, trukstaZirgu);
    esamuFigureliuMasyvas[3]=FigureliuSuma(n, trukstaRikiu);
    esamuFigureliuMasyvas[4]=FigureliuSuma(n, trukstaVladoviu);
    esamuFigureliuMasyvas[5]=FigureliuSuma(n, trukstaKaraliu);

    GalimiKomplektai(esamuFigureliuMasyvas, FigureliuSkaicius[0], galimiKomplektai);
    GalimiKomplektai(esamuFigureliuMasyvas, FigureliuSkaicius[1], galimiKomplektai);
    GalimiKomplektai(esamuFigureliuMasyvas, FigureliuSkaicius[2], galimiKomplektai);
    GalimiKomplektai(esamuFigureliuMasyvas, FigureliuSkaicius[3], galimiKomplektai);
    GalimiKomplektai(esamuFigureliuMasyvas, FigureliuSkaicius[4], galimiKomplektai);
    GalimiKomplektai(esamuFigureliuMasyvas, FigureliuSkaicius[5], galimiKomplektai);

    Isvedimas(n, galimiKomplektai);

    return 0;

}

void Nuskaitymas(int& n, int trukstaPestininku[], int trukstaBokstu[], int trukstaZirgu[], int trukstaRikiu[], int trukstaKaraliu[], int trukstaVladoviu[])
{
    ifstream duomenys("duomenys.txt");
    duomenys >> n;
    for(int i=0; i<n; i++)
    {
        duomenys >> trukstaPestininku[i] >> trukstaBokstu[i] >> trukstaZirgu[i] >> trukstaRikiu[i] >> trukstaKaraliu[i] >> trukstaVladoviu[i];
    }
    duomenys.close();
}

void TurimosFigureles(int n, int truksta[], int kiekFigureliuKomplektui)
{
    for(int i=0; i<n; i++)
    {
        truksta[i]=kiekFigureliuKomplektui-truksta[i];
    }
}

int FigureliuSuma(int n, int turimosFigureles[])
{
    int suma=0;
    for(int i=0; i<n; i++)
    {
        suma+=turimosFigureles[i];
    }
    return suma;
}

void GalimiKomplektai(int figureles[], int kiekFigureliuKomplektui, int komplektai[])
{
    for(int i=0; i<6; i++)
    {
        komplektai[i]=figureles[i]/FigureliuSkaicius[i];
    }
}

int KomplektuSuradimas(int galimiKomplektai[])
{
    int min=galimiKomplektai[0];
    for(int i=1; i<6; i++)
    {
        if(galimiKomplektai[i]<galimiKomplektai[min])
            min=i;
    }
    return min;
}

void Isvedimas(int n, int galimiKomplektai[])
{
    int min=KomplektuSuradimas(galimiKomplektai);
    cout << min << endl;
}




