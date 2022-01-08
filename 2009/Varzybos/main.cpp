#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Plaukikas
{
    char vardas[21];
    int minutes;
    int sekundes;
    int BendrasLaikasSekundemis=0;
};

void Nuskaitymas(int&a, Plaukikas plaukimas[]);
void SkaiciavimasSekundemis(int a, Plaukikas plaukimas[]);
void Rikiavimas(int a, Plaukikas plaukimas[]);
void Isvedimas(Plaukikas plaukimas[]);

int main()
{
    int k, a;
    Plaukikas plaukimas[50];
    Nuskaitymas(a, plaukimas);
    SkaiciavimasSekundemis(a, plaukimas);
    Rikiavimas(a, plaukimas);
    Isvedimas(plaukimas);
    return 0;
}

void Nuskaitymas(int&a, Plaukikas plaukimas[])
{
    int k, plaukikuSkaiciusGrupeje;
    ifstream duomenys("duomenys.txt");
    duomenys >> k;
    for(int i=0; i<k; i++)
    {
        duomenys >> plaukikuSkaiciusGrupeje;
        for(int j=0; j<plaukikuSkaiciusGrupeje; j++)
        {
            duomenys.ignore(256, '\n');
            duomenys.get(plaukimas[a].vardas, 21);
            duomenys >> plaukimas[a].minutes >> plaukimas[a].sekundes;
            a++;
        }
    }
    duomenys.close();
}

void SkaiciavimasSekundemis(int a, Plaukikas plaukimas[])
{
    for(int i=0; i<a; i++)
    {
        plaukimas[i].BendrasLaikasSekundemis = plaukimas[i].minutes*60+plaukimas[i].sekundes;
    }
}

void Rikiavimas(int a, Plaukikas plaukimas[])
{
    for(int i=0; i<a-1; i++)
    {
        int max = i;
        for(int j=i+1; j<a; j++)
        {
            if(plaukimas[j].BendrasLaikasSekundemis<plaukimas[max].BendrasLaikasSekundemis) max = j;
        }
        if(i!=max)
        {
            swap (plaukimas[i], plaukimas[max]);
        }
    }
}

void Isvedimas(Plaukikas plaukimas[])
{
    for(int i=0; i<5; i++)
    {
        cout << plaukimas[i].vardas << " " << plaukimas[i].minutes << " " << plaukimas[i].sekundes << endl;
    }
}
