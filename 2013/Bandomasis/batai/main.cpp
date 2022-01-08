#include <iostream>
#include <fstream>

using namespace std;

struct Batai
{
    int vyriskaDesine[100]={0};
    int vyriskaKaire[100]={0};
    int moteriskaDesine[100]={0};
    int moteriskaKaire[100]={0};
};

void Nuskaitymas(int&n, Batai& bateliai);
int PoruIeskojimas(int kaire[], int desine[], int dydis);
void PoruSkaiciausIeskojimas(Batai bateliai, int& kiekVyru, int& kiekMoteru);
void Isvedimas(Batai bateliai, int kiekVyru, int kiekMoteru);

int main()
{
    int n, kiekVyru=0, kiekMoteru=0;
    Batai bateliai;

    Nuskaitymas(n, bateliai);
    PoruSkaiciausIeskojimas(bateliai, kiekVyru, kiekMoteru);
    Isvedimas(bateliai, kiekVyru, kiekMoteru);

    return 0;
}

void Nuskaitymas(int&n, Batai& bateliai)
{
    ifstream duomenys("duomenys.txt");
    int a, b, c;
    duomenys >> n;
    for(int i=0; i<n; i++)
    {
        duomenys >> a >> b >> c;
        if(a==3 && b==2)
        {
            bateliai.vyriskaDesine[c]++;
        }
        if(a==3 && b==1)
        {
            bateliai.vyriskaKaire[c]++;
        }
        if(a==4 && b==2)
        {
            bateliai.moteriskaDesine[c]++;
        }
        else
        {
            bateliai.moteriskaKaire[c]++;
        }
    }
    duomenys.close();
}

int PoruIeskojimas(int kaire[], int desine[], int dydis)
{
    if(kaire[dydis]>desine[dydis])
        return desine[dydis];
    return kaire[dydis];
}

void PoruSkaiciausIeskojimas(Batai bateliai, int& kiekVyru, int& kiekMoteru)
{
    for(int i=5; i<=60; i++)
    {
        int moteriskosPoros=PoruIeskojimas(bateliai.moteriskaKaire, bateliai.moteriskaDesine, i);
        int vyriskosPoros=PoruIeskojimas(bateliai.vyriskaKaire, bateliai.vyriskaDesine, i);
        kiekVyru+=vyriskosPoros;
        kiekMoteru+=moteriskosPoros;
    }
}

void Isvedimas(Batai bateliai, int kiekVyru, int kiekMoteru)
{
    ofstream rezultatai("rezultatai.txt");
    cout << kiekMoteru << endl;
    rezultatai << kiekVyru << endl;
    rezultatai.close();
}
