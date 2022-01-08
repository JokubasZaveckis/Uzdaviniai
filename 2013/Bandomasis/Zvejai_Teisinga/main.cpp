#include <iostream>
#include <fstream>

using namespace std;

struct Zvejys
{
    char vardas[11];
    int kiekKartuZvejojo;

    int karosai[301];
    int karpiai[301];
    int kuojos[301];

    int karosu=0;
    int karpiu=0;
    int kuoju=0;

    int visoZuvu=0;
};

void Nuskaitymas(int&n, Zvejys zvejai[]);
void SugautuZuvuSkaiciusAtsikiraiSkaiciavimas(int n, Zvejys zvejai[]);
void ZuvuSumosSkaiciavimas(int n, Zvejys zvejai[]);
int DaugiausiaiPagavesZvejys(int n, Zvejys zvejai[]);
void Isvedimas(int n, Zvejys zvejai[]);

int main()
{
    int n;
    Zvejys zvejai[101];

    Nuskaitymas(n, zvejai);
    SugautuZuvuSkaiciusAtsikiraiSkaiciavimas(n, zvejai);
    ZuvuSumosSkaiciavimas(n, zvejai);
    Isvedimas(n, zvejai);

    return 0;

}

void Nuskaitymas(int&n, Zvejys zvejai[])
{
    ifstream duomenys("duomenys.txt");
    duomenys >> n;
    for(int i=0; i<n; i++)
    {
        duomenys.ignore(256, '\n');
        duomenys.get(zvejai[i].vardas, 11);
        duomenys >> zvejai[i].kiekKartuZvejojo;
        for(int j=0; j<zvejai[i].kiekKartuZvejojo; j++)
        {
            duomenys>>zvejai[i].karosai[j];
            duomenys>>zvejai[i].karpiai[j];
            duomenys>>zvejai[i].kuojos[j];
        }
    }
    duomenys.close();
}

void SugautuZuvuSkaiciusAtsikiraiSkaiciavimas(int n, Zvejys zvejai[])
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<zvejai[i].kiekKartuZvejojo; j++)
        {
            zvejai[i].karosu+=zvejai[i].karosai[j];
            zvejai[i].karpiu+=zvejai[i].karpiai[j];
            zvejai[i].kuoju+=zvejai[i].kuojos[j];
        }
    }
}

void ZuvuSumosSkaiciavimas(int n, Zvejys zvejai[])
{
    for(int i=0; i<n; i++)
    {
        zvejai[i].visoZuvu+=zvejai[i].karosu+zvejai[i].karpiu+zvejai[i].kuoju;
    }
}

int DaugiausiaiPagavesZvejys(int n, Zvejys zvejai[])
{
    int max=0;
    for(int i=0; i<n; i++)
    {
        if(zvejai[i].visoZuvu>zvejai[max].visoZuvu) max=i;
    }
    return max;
}

void Isvedimas(int n, Zvejys zvejai[])
{
    ofstream rezultatai("rezultatai.txt");
    int max=DaugiausiaiPagavesZvejys(n, zvejai);
    for(int i=0; i<n; i++)
    {
        rezultatai << zvejai[i].vardas << " " << zvejai[i].karosu << " " << zvejai[i].karpiu << " " << zvejai[i].kuoju << endl;
    }
    rezultatai << zvejai[max].vardas << " " << zvejai[max].visoZuvu << endl;

    rezultatai.close();
}


