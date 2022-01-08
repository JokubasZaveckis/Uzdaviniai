#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct Gele
{
    int numeris;
    int pradziosMenuo, pradziosDiena;
    int pabaigosMenuo, pabaigosDiena;
};

void Nuskaitymas(int& n, Gele*& geles);
void DienuSuzymejimas(int n, Gele*& geles, int vasarosDienos[]);
int DaugiausiaiZydinciuGeliuPerDiena(int vasarosDienos[]);
int pabaigosIntervaloIeskojimas(int max, int vasarosDienos[]);
int intervaloIlgioPaieska(int max, int pabaiga);
void Isvedimas(int pradMenuo, int max, int pabMenuo, int pabaiga);

int main()
{
    int n, vasarosDienos[92]= {0};
    Gele* geles = nullptr;

    Nuskaitymas(n, geles);
    DienuSuzymejimas(n, geles, vasarosDienos);

    int max = DaugiausiaiZydinciuGeliuPerDiena(vasarosDienos);
    int pabaiga = pabaigosIntervaloIeskojimas(max, vasarosDienos);
    int ilgis = intervaloIlgioPaieska(max, pabaiga);

    int pradMenuo = max/30+6;
    int pabMenuo = pabaiga/30+6;

    Isvedimas(pradMenuo, max, pabMenuo, pabaiga);

    //Patikrinimas del ilgesniu intervalu

    delete[] geles;
    return 0;
}

void Nuskaitymas(int& n, Gele*& geles)
{
    ifstream duomenys("duomenys.txt");
    duomenys >> n;
    geles = new Gele[n];
    for(int i=0; i<n; i++)
    {
        duomenys >> geles[i].numeris >> geles[i].pradziosMenuo >> geles[i].pradziosDiena >> geles[i].pabaigosMenuo >> geles[i].pabaigosDiena;
    }
    duomenys.close();
}

void DienuSuzymejimas(int n, Gele*& geles, int vasarosDienos[])
{
    for(int i=0; i<n; i++)
    {
        if(geles[i].pradziosMenuo==6 && geles[i].pabaigosMenuo==6)
        {
            for(int j=geles[i].pradziosDiena; j<geles[i].pabaigosDiena; j++)
            {
                vasarosDienos[j]++;
            }
        }
        else if(geles[i].pradziosMenuo==6 && geles[i].pabaigosMenuo==7)
        {
            for(int j=geles[i].pradziosDiena; j<geles[i].pabaigosDiena+30; j++)
            {
                vasarosDienos[j]++;
            }
        }
        else if(geles[i].pradziosMenuo==6 && geles[i].pabaigosMenuo==8)
        {
            for(int j=geles[i].pradziosDiena; j<geles[i].pabaigosDiena+61; j++)
            {
                vasarosDienos[j]++;
            }
        }
        else if(geles[i].pradziosMenuo==7 && geles[i].pabaigosMenuo==7)
        {
            for(int j=geles[i].pradziosDiena+30; j<geles[i].pabaigosDiena+30; j++)
            {
                vasarosDienos[j]++;
            }
        }
        else if(geles[i].pradziosMenuo==7 && geles[i].pabaigosMenuo==8)
        {
            for(int j=geles[i].pradziosDiena+30; j<geles[i].pabaigosDiena+61; j++)
            {
                vasarosDienos[j]++;
            }
        }
        else
        {
            for(int j=geles[i].pradziosDiena+61; j<geles[i].pabaigosDiena+61; j++)
            {
                vasarosDienos[j]++;
            }
        }
    }
}

int DaugiausiaiZydinciuGeliuPerDiena(int vasarosDienos[])
{
    int max=0;
    for(int i=0; i<92; i++)
    {
        if(vasarosDienos[i]>vasarosDienos[max]) max=i;
    }
    return max;
}

int pabaigosIntervaloIeskojimas(int max, int vasarosDienos[])
{
    for(int i=max; i<92; i++)
    {
        if(vasarosDienos[i+1]!=vasarosDienos[max]) return i+1;
    }
}

int intervaloIlgioPaieska(int max, int pabaiga)
{
    int kiek=0;
    for(int i=max; i<=pabaiga; i++)
    {
        kiek++;
    }
    return kiek;
}

void Isvedimas(int pradMenuo, int max, int pabMenuo, int pabaiga)
{
    if(pradMenuo==6)
    {
        cout << pradMenuo << " " << max << endl;
    }
    else if(pradMenuo==7)
    {
        cout << pradMenuo << " " << max-30 << endl;
    }
    else cout << pradMenuo << " " << max-61 << endl;

    if(pabMenuo==6)
    {
        cout << pabMenuo << " " << pabaiga << endl;
    }
    else if(pabMenuo==7)
    {
        cout << pabMenuo << " " << pabaiga-30 << endl;
    }
    else cout << pabMenuo << " " << pabaiga-61 << endl;

    ofstream rezultatai("rezultatai.txt");

    if(pradMenuo==6)
    {
        rezultatai << pradMenuo << " " << max << endl;
    }
    else if(pradMenuo==7)
    {
        rezultatai << pradMenuo << " " << max-30 << endl;
    }
    else rezultatai << pradMenuo << " " << max-61 << endl;

    if(pabMenuo==6)
    {
        rezultatai << pabMenuo << " " << pabaiga << endl;
    }
    else if(pabMenuo==7)
    {
        rezultatai << pabMenuo << " " << pabaiga-30 << endl;
    }
    else rezultatai << pabMenuo << " " << pabaiga-61 << endl;

    rezultatai.close();
}

