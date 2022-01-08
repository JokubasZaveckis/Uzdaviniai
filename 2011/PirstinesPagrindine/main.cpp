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

void Nuskaitymas(Pirstine& pirstines);
int PoruIeskojimas(Pirstine pirstines);
int PoruIeskojimas(int lytis, Pirstine pirstines);
int AtliekamosPirstines(int lytis, Pirstine pirstines);
void Isvedimas(Pirstine pirstines);

int main()
{
    Pirstine pirstines;

    Nuskaitymas(pirstines);
    Isvedimas(pirstines);
}

void Nuskaitymas(Pirstine& pirstines)
{
    ifstream duomenys("duomenys.txt");
    int n, a, b, c;
    duomenys >> n;
    for(int i=0; i<n; i++)
    {
        duomenys >> a >> b >> c;
        if(a==3 && b==1)
            pirstines.vyriskaKaire[c]++;

        else if (a==3 && b==2)
            pirstines.vyriskaDesine[c]++;

        else if (a==4 && b==1)
            pirstines.moteriskaKaire[c]++;

        else pirstines.moteriskaDesine[c]++;

    }
    duomenys.close();
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

