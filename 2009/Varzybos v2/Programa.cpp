#include "Programa.h"

using namespace std;

void Programa::Nuskaitymas(string Byla)
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
}

void Programa::Rikiavimas()
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

void Programa::Isvedimas(string Duomenys)
{
    ofstream rezultatai("rez.txt");
    for(int i=0; i<5; i++)
    {
        rezultatai << plaukimas[i].vardas << " " << plaukimas[i].minutes << " " << plaukimas[i].sekundes << endl;
    }
    rezultatai.close();
}

void Programa::Vykdyti(string Byla, string Duomenys)
{
    Nuskaitymas(Byla);
    Skaiciavimai();
    Rikiavimas();
    Isvedimas(Duomenys);
}

void Programa::Skaiciavimai()
{
    for(int i=0; i<a; i++)
    {
        plaukimas[i].SkaiciavimasSekundemis();
    }
}
