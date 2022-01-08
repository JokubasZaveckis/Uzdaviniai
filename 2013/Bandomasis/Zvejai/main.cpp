#include <iostream>
#include <fstream>

using namespace std;

struct Zvejys
{
    char vardas[11];
    int karosai=0;
    int karpiai=0;
    int kuojos=0;
    int visoZuvu=0;
};

void Nuskaitymas(int&n, Zvejys zvejai[]);
void ZuvuSumosSkaiciavimas(int n, Zvejys zvejai[]);
int DaugiausiaiPagavesZvejys(int n, Zvejys zvejai[]);
void Isvedimas(int n, Zvejys zvejai[]);

int main()
{
    int n;
    Zvejys zvejai[101];

    Nuskaitymas(n, zvejai);
    ZuvuSumosSkaiciavimas(n, zvejai);
    Isvedimas(n, zvejai);
}

void Nuskaitymas(int&n, Zvejys zvejai[])
{
    ifstream duomenys("duomenys.txt");
    duomenys >> n;
    int a, b, c, zvejojimuSkaicius;
    for(int i=0; i<n; i++)
    {
        duomenys.ignore(256, '\n');
        duomenys.get(zvejai[i].vardas, 11);
        duomenys >> zvejojimuSkaicius;
        for(int j=0; j<zvejojimuSkaicius; j++)
        {
            duomenys >> a >> b >> c;
            zvejai[i].karosai+=a;
            zvejai[i].karpiai+=b;
            zvejai[i].kuojos+=c;
        }
    }
    duomenys.close();
}

void ZuvuSumosSkaiciavimas(int n, Zvejys zvejai[])
{
    for(int i=0; i<n; i++)
    {
        zvejai[i].visoZuvu+=zvejai[i].karosai+zvejai[i].karpiai+zvejai[i].kuojos;
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
    int max=DaugiausiaiPagavesZvejys(n, zvejai);
    for(int i=0; i<n; i++)
    {
        cout << zvejai[i].vardas << " " << zvejai[i].karosai << " " << zvejai[i].karpiai << " " << zvejai[i].kuojos << endl;
    }
    cout << zvejai[max].vardas << " " << zvejai[max].visoZuvu << endl;
}

