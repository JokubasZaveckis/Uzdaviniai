#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

const int NUMERIAI[8] = {4, 5, 6, 7, 8, 9, 10, 11};
//const int DIENU_SKAICIUS[9] = {30, 31, 30, 31, 31, 30, 31, 30};
const int DIENU_SUMA[8] = {0, 30, 61, 91, 122, 153, 183, 214};

struct Diena
{
    int numeris;
    int zydejimoPradziosMenuo;
    int zydejimoPradziosDiena;
    int kiekZydejo;
};

void Nuskaitymas(int&n, int zydejimoDienos[], Diena*& dienos);
void Skaiciavimai(int n, int zydejimoDienos[], Diena*& dienos);
int DaugiausiaiDienu(int zydejimoDienos[]);
int IntervaloPabaigosIeskojimas(int pradzia, int zydejimoDienos[]);
int MenesioIeskojimas(int data);
int DienosIeskojimas(int data, int menuo);
int IlgiausioIntervaloPradzia(int zydejimoDienos[]);
void Isvedimas(int pradzia, int zydejimoDienos[], int PradziosMenuo, int PradziosDiena, int PabaigosMenuo, int PabaigosDiena);

int main()
{
    int n, pradzia, pabaiga, PradziosMenuo, PradziosDiena, PabaigosMenuo, PabaigosDiena;
    int zydejimoDienos[244]= {0};
    Diena* dienos = nullptr;

    Nuskaitymas(n, zydejimoDienos, dienos);
    Skaiciavimai(n, zydejimoDienos, dienos);
    pradzia = DaugiausiaiDienu(zydejimoDienos);
    pradzia = IlgiausioIntervaloPradzia(zydejimoDienos);
    pabaiga = IntervaloPabaigosIeskojimas(pradzia, zydejimoDienos);
    PradziosMenuo = MenesioIeskojimas(pradzia);
    PabaigosMenuo = MenesioIeskojimas(pabaiga);
    PradziosDiena = DienosIeskojimas(pradzia, PradziosMenuo);
    PabaigosDiena = DienosIeskojimas(pabaiga, PabaigosMenuo);
    Isvedimas(pradzia, zydejimoDienos, NUMERIAI[PradziosMenuo], PradziosDiena, NUMERIAI[PabaigosMenuo], PabaigosDiena);

    delete[] dienos;
    return 0;
}

void Nuskaitymas(int&n, int zydejimoDienos[], Diena*& dienos)
{
    ifstream duomenys("duomenys.txt");
    duomenys >> n;
    dienos = new Diena[n];
    for(int i=0; i<n; i++)
    {
        duomenys >> dienos[i].numeris >> dienos[i].zydejimoPradziosMenuo >> dienos[i].zydejimoPradziosDiena >> dienos[i].kiekZydejo;
    }
    duomenys.close();
}

void Skaiciavimai(int n, int zydejimoDienos[], Diena*& dienos)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<8; j++)
        {
            if(dienos[i].zydejimoPradziosMenuo==NUMERIAI[j])
            {
                for(int k=DIENU_SUMA[j]+dienos[i].zydejimoPradziosDiena; k<DIENU_SUMA[j]+dienos[i].kiekZydejo+dienos[i].zydejimoPradziosDiena; k++)
                {
                    zydejimoDienos[k]++;
                }
            }
        }
    }
}

int DaugiausiaiDienu(int zydejimoDienos[])
{
    int max=0;
    for(int i=61; i<=153; i++)
    {
        if(zydejimoDienos[i]>zydejimoDienos[max]) max=i;
    }
    return max;
}

int IlgiausioIntervaloPradzia(int zydejimoDienos[])
{
    int a = DaugiausiaiDienu(zydejimoDienos);
    int max=0, maxID=0, max2=0;
    for(int i=a; i<=153; i++)
    {
        cout << zydejimoDienos[i] << " " << zydejimoDienos[a] << endl;
        if(zydejimoDienos[i]==zydejimoDienos[a])
        {
            max2++;
        }
        else
        {
            if(max2>max)
            {
                max = max2;
                maxID = i-max;
            }
        }
    }
    if(max2>max)
    {
        max = max2;
        maxID = 154-max;
    }
    cout << maxID << endl;
    return maxID;
}

int IntervaloPabaigosIeskojimas(int pradzia, int zydejimoDienos[])
{
    for(int i=pradzia; i<=153; i++)
    {
        if(zydejimoDienos[i]!=zydejimoDienos[pradzia])
        {
            return i-1;
        }
    }
    return 153;
}

int MenesioIeskojimas(int data)
{
    for(int i=2; i<=5; i++)
    {
        if(data<=DIENU_SUMA[i] && data>=DIENU_SUMA[i-1])
        {
            return i-1;
        }
    }
}

int DienosIeskojimas(int data, int menuo)
{
    return data-DIENU_SUMA[menuo];
}

void Isvedimas(int pradzia, int zydejimoDienos[], int PradziosMenuo, int PradziosDiena, int PabaigosMenuo, int PabaigosDiena)
{
    ofstream rezultatai("rezultatai.txt");

    rezultatai << zydejimoDienos[pradzia] << endl;
    rezultatai << PradziosMenuo << " " << PradziosDiena << endl;
    rezultatai << PabaigosMenuo << " " << PabaigosDiena << endl;

    rezultatai.close();

    cout << zydejimoDienos[pradzia] << endl;
    cout << PradziosMenuo << " " << PradziosDiena << endl;
    cout << PabaigosMenuo << " " << PabaigosDiena << endl;
}
