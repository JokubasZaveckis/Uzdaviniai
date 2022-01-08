#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>

using namespace std;

struct Savivaldybe
{
    int mokyklos;
    char pavadinimas[21];
    char apskritiesPavadinimas[14];
};

struct Apskritis
{
    int savivaldybes=0;
    int mokyklos=0;
    char pavadinimas[14];
    int daugiausiaMokyklu=0;
};

void Nuskaitymas(int& k, Savivaldybe*& savivaldybes);
void ApskriciuSkaicius(int n, Savivaldybe*& savivaldybes, Apskritis apskritys[], int& apskriciuSkaicius);
void Skaiciavimai(int k, Savivaldybe*& savivaldybes, Apskritis apskritys[], int apskriciuSkaicius);
void Rikiavimas(Savivaldybe*& savivaldybes, Apskritis apskritys[], int apskriciuSkaicius);
void Isvedimas(int apskriciuSkaicius, Savivaldybe*& savivaldybes, Apskritis apskritys[]);

int main()
{
    int k, apskriciuSkaicius=0;
    Apskritis apskritys[10];
    Savivaldybe* savivaldybes = NULL;

    Nuskaitymas(k, savivaldybes);
    ApskriciuSkaicius(k, savivaldybes, apskritys, apskriciuSkaicius);
    Skaiciavimai(k, savivaldybes, apskritys, apskriciuSkaicius);
    Rikiavimas(savivaldybes, apskritys, apskriciuSkaicius);
    //Isvedimas(apskriciuSkaicius, savivaldybes, apskritys);

    for(int i=0; i<15; i++)
    {
        cout << apskritys[i].mokyklos << endl;
    }


    delete []apskritys;
    return 0;

}

void Nuskaitymas(int& k, Savivaldybe*& savivaldybes)
{
    ifstream duomenys("duomenys.txt");
    duomenys >> k;

    savivaldybes = new Savivaldybe[k];

    for(int i=0; i<k; i++)
    {
        duomenys.ignore(256, '\n');
        duomenys.get(savivaldybes[i].pavadinimas, 21);
        duomenys.get(savivaldybes[i].apskritiesPavadinimas, 14);
        duomenys >> savivaldybes[i].mokyklos;

        //cout << savivaldybes[i].pavadinimas << endl;

    }

    duomenys.close();
}

void ApskriciuSkaicius(int n, Savivaldybe*& savivaldybes, Apskritis apskritys[], int& apskriciuSkaicius)
{
    for(int i=0; i<n; i++)
    {
        bool rasta=false;
        for(int j=0; j<apskriciuSkaicius; j++)
        {
            if(strcmp(savivaldybes[i].apskritiesPavadinimas, apskritys[j].pavadinimas)==0)
            {
                rasta=true;
            }
        }
        if(!rasta)
        {
            strcpy(apskritys[apskriciuSkaicius++].pavadinimas,savivaldybes[i].apskritiesPavadinimas);
        }
    }
}

void Skaiciavimai(int k, Savivaldybe*& savivaldybes, Apskritis apskritys[], int apskriciuSkaicius)
{
    for(int i=0; i<apskriciuSkaicius; i++)
    {
        for(int j=0; j<k; j++)
        {
            if(strcmp(savivaldybes[j].apskritiesPavadinimas, apskritys[i].pavadinimas)==0)
            {
                if(savivaldybes[j].mokyklos>apskritys[i].mokyklos)
                {
                    apskritys[j].mokyklos=savivaldybes[j].mokyklos;
                }
                apskritys[i].savivaldybes++;
            }
        }
    }
}

void Rikiavimas(Savivaldybe*& savivaldybes, Apskritis apskritys[], int apskriciuSkaicius)
{
    for(int i=0; i<apskriciuSkaicius-1; i++)
    {
        int max=i;
        for(int j=i+1; j<apskriciuSkaicius; j++)
        {
            if(apskritys[j].savivaldybes>apskritys[max].mokyklos)
            {
                max=j;
            }
            if(i!=max)
            {
                swap(apskritys[i], apskritys[max]);
            }
        }
    }
}

void DaugiausiaVienosSavivaldybesMokyklu(int n, int apskriciuSkaicius, Savivaldybe*& savivaldybes, Apskritis apskritys[])
{
    for(int i=0; i<apskriciuSkaicius; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(apskritys[j].mokyklos>savivaldybes[j].mokyklos)
            {
                apskritys[i].daugiausiaMokyklu=apskritys[j].mokyklos;
            }
        }
    }
}

void Isvedimas(int apskriciuSkaicius, Savivaldybe*& savivaldybes, Apskritis apskritys[])
{
    cout << apskriciuSkaicius << endl;
    for(int i=0; i<apskriciuSkaicius; i++)
    {
        cout << apskritys[i].pavadinimas << " " << apskritys[i].savivaldybes << " " <<  apskritys[i].mokyklos << endl;
    }
}
//surasti apskriti su daugiausiai mokyklu
