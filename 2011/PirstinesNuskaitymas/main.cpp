#include <iostream>
#include <fstream>

using namespace std;

struct Pirstine
{
    int vyriskaKaire[101]= {0};
    int vyriskaDesine[101]= {0};
    int moteriskaKaire[101]= {0};
    int moteriskaDesine[101]= {0};
};

void Nuskaitymas(int& n, int lytis[], int puse[], int dydis[]);
void Perkelimas(int n, int lytis[], int puse[], int dydis[], Pirstine& pirstines);
int PoruIeskojimas(int lytis, Pirstine pirstines);
int AtliekamosPirstines(int lytis, Pirstine pirstines);
void Isvedimas(Pirstine pirstines);

int main()
{
    int n, lytis[100], puse[100], dydis[100];
    Pirstine pirstines;

    Nuskaitymas(n, lytis, puse, dydis);
    Perkelimas(n, lytis, puse, dydis, pirstines);
    Isvedimas(pirstines);

    return 0;
}

void Nuskaitymas(int& n, int lytis[], int puse[], int dydis[])
{
    ifstream duomenys("duomenys.txt");
    duomenys >> n;
    for(int i=0; i<n; i++)
    {
        duomenys >> lytis[i] >>  puse[i] >> dydis[i];
        //cout << lytis[i] << " " << puse[i] << " " << dydis[i] << endl;
    }
    duomenys.close();
}

void Perkelimas(int n, int lytis[], int puse[], int dydis[], Pirstine& pirstines)
{
    for(int i=0; i<n; i++)
    {
        if(lytis[i]==3 && puse[i]==1)
            {pirstines.vyriskaKaire[dydis[i]]++;
            cout << pirstines.vyriskaKaire[dydis[i]] << " " << dydis[i] << endl;}

        else if (lytis[i]==3 && puse[i]==2)
            pirstines.vyriskaDesine[dydis[i]]++;

        else if (lytis[i]==4 && puse[i]==1)
            pirstines.moteriskaKaire[dydis[i]]++;

        else pirstines.moteriskaDesine[dydis[i]]++;
    }
}

int PoruIeskojimas(int lytis, Pirstine pirstines)
{
    int kiek=0;
    if(lytis==3)
    {
        for(int i=1; i<=100; i++)
        {
            if(pirstines.vyriskaDesine[i]<pirstines.vyriskaKaire[i])
                kiek+=pirstines.vyriskaDesine[i];
            else kiek+=pirstines.vyriskaKaire[i];
        }
    }
    if(lytis==4)
    {
        for(int i=1; i<=100; i++)
        {
            if(pirstines.moteriskaDesine[i]<pirstines.moteriskaKaire[i])
                kiek+=pirstines.moteriskaDesine[i];
            else kiek+=pirstines.moteriskaKaire[i];
        }
    }
    return kiek;
}

int AtliekamosPirstines(int lytis, Pirstine pirstines)
{
    int kiek=0;
    if(lytis==3)
    {
        for(int i=1; i<=100; i++)
        {
            if(pirstines.vyriskaDesine[i]>pirstines.vyriskaKaire[i])
                kiek+=pirstines.vyriskaDesine[i]-pirstines.vyriskaKaire[i];
            else kiek+=pirstines.vyriskaKaire[i]-pirstines.vyriskaDesine[i];
        }
    }
    if(lytis==4)
    {
        for(int i=1; i<=100; i++)
        {
            if(pirstines.moteriskaDesine[i]>pirstines.moteriskaKaire[i])
                kiek+=pirstines.moteriskaDesine[i]-pirstines.moteriskaKaire[i];
            else kiek+=pirstines.moteriskaKaire[i]-pirstines.moteriskaDesine[i];
        }
    }
    return kiek;
}

void Isvedimas(Pirstine pirstines)
{
    int a = PoruIeskojimas(4, pirstines);
    int b = PoruIeskojimas(3, pirstines);

    int c = AtliekamosPirstines(4, pirstines);
    int d = AtliekamosPirstines(3, pirstines);
    cout << a << " " << b << " " << c << " " << d << endl;
}

