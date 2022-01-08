#include <iostream>
#include <fstream>

using namespace std;

void Nuskaitymas(int&n, int vyriskaKaire[], int vyriskaDesine[], int moteriskaKaire[], int moteriskaDesine[]);
int Skaiciavimai(int Kaire[], int Desine[], int dydis);
void Isvedimas(int vyriskaKaire[], int vyriskaDesine[], int moteriskaKaire[], int moteriskaDesine[]);

int main()
{
    int n, vyriskaKaire[51]={0}, vyriskaDesine[51]={0}, moteriskaKaire[51]={0}, moteriskaDesine[51]={0};
    Nuskaitymas(n, vyriskaKaire, vyriskaDesine, moteriskaKaire, moteriskaDesine);
    Isvedimas(vyriskaKaire, vyriskaDesine, moteriskaKaire, moteriskaDesine);

    return 0;
}

void Nuskaitymas(int&n, int vyriskaKaire[], int vyriskaDesine[], int moteriskaKaire[], int moteriskaDesine[])
{
    ifstream duomenys("duomenys.txt");
    duomenys >> n;
    int a, b, c;
    for(int i=0; i<n; i++)
    {
        duomenys >> a >> b >> c;
        if(a==3&&b==1)
            vyriskaKaire[c]++;
        else if(a==3&&b==2)
            vyriskaDesine[c]++;
        else if(a==4&&b==2)
            moteriskaDesine[c]++;
        else moteriskaKaire[c]++;
    }
    duomenys.close();
}

int Skaiciavimai(int Kaire[], int Desine[], int dydis)
{
    if(Kaire[dydis]<Desine[dydis])
        return Kaire[dydis];
    return Desine[dydis];
}

void Isvedimas(int vyriskaKaire[], int vyriskaDesine[], int moteriskaKaire[], int moteriskaDesine[])
{
    for(int i=1; i<=50; i++)
    {
        int moteriskiSkaiciavimai=Skaiciavimai(moteriskaKaire, moteriskaDesine, i);
        int vyriskiSkaiciavimai=Skaiciavimai(vyriskaKaire, vyriskaDesine, i);
        if(moteriskiSkaiciavimai>0 || vyriskiSkaiciavimai>0)
        cout << i << " " << moteriskiSkaiciavimai << " " << vyriskiSkaiciavimai << endl;
    }

}
