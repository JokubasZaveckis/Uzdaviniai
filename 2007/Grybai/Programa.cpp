#include "programa.h"


using namespace std;
void Programa::Nuskaitymas(string Byla)
{
    ifstream duomenys(Byla);
    duomenys >> n;
    for(int i=0; i<n; i++)
    {
        duomenys >> grybavimai[i].diena >> grybavimai[i].baravykai >> grybavimai[i].raudonikiai >> grybavimai[i].lepsiai;
    }
    duomenys.close();
}

void Programa::Rikiavimas()
{
    for(int i=0; i<n-1; i++)
    {
        int max=i;
        for(int j=i+1; j<n; j++)
        {
            if(grybavimai[max].diena>grybavimai[j].diena)
            max = j;
        }
        if(i!=max)
        swap(grybavimai[i], grybavimai[max]);
    }
}

void Programa::Sutraukimas()
{
    for(int i=0; i<n-1; i++)
    {
        if(grybavimai[i].diena==grybavimai[i+1].diena)
        {
            grybavimai[i].Prideti(grybavimai[i+1]);
            for(int j=i+1; j<n-1; j++)
            {
                grybavimai[j] = grybavimai[j+1];
            }
            n--;
            i--;
        }
    }
}


void Programa::SumosSkaiciavimas()
{
    for(int i=0; i<n; i++)
    {
        grybavimai[i].Suma();
    }
}

int Programa::DaugiausiaiGrybu()
{
    int max = 0;
    for(int i=1; i<n; i++)
    {
        if(grybavimai[i].bendraSuma > grybavimai[max].bendraSuma)
            max = i;
    }
    return max;
}

void Programa::Isvedimas(string Duomenys)
{
    ofstream duomenys(Duomenys);
    int max = DaugiausiaiGrybu();
    for(int i=0; i<n; i++)
    {
        duomenys << grybavimai[i].diena << " " << grybavimai[i].baravykai << " " << grybavimai[i].raudonikiai << " " << grybavimai[i].lepsiai << endl;
    }
    duomenys << grybavimai[max].diena << " " << grybavimai[max].bendraSuma << endl;
}

void Programa::Vykdyti(string Byla, string Duomenys)
{
    Nuskaitymas(Byla);
    Rikiavimas();
    Sutraukimas();
    SumosSkaiciavimas();
    DaugiausiaiGrybu();
    Isvedimas(Duomenys);

}
