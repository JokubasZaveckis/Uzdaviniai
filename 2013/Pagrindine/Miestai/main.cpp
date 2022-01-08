#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>

using namespace std;

struct Miestas
{
    int zmones;
    char pavadinimas[21];
    char apskritiesPavadinimas[14];
};

struct Apskritis
{
    int zmones=0;
    char pavadinimas[14];
    int maziausiaiGyventoju=0;
};

void Nuskaitymas(int& n, Miestas*& miestai);
void ApskriciuSkaicius(int n, Miestas*& miestai, Apskritis apskritys[], int& apskriciuSkaicius);
void GyventojuSkaiciusApskrityje(int n, Miestas*& miestai, Apskritis apskritys[], int apskriciuSkaicius);
void Isvedimas(int n, Miestas*& miestai, Apskritis apskritys[], int apskriciuSkaicius);

int main()
{
    int n, apskriciuSkaicius=0;
    Miestas* miestai = NULL;
    Apskritis apskritys[10];

    Nuskaitymas(n, miestai);
    ApskriciuSkaicius(n, miestai, apskritys, apskriciuSkaicius);
    GyventojuSkaiciusApskrityje(n, miestai, apskritys, apskriciuSkaicius);
    Isvedimas(n, miestai, apskritys, apskriciuSkaicius);

    delete[] miestai;
    return 0;

}

void Nuskaitymas(int& n, Miestas*& miestai)
{
    ifstream duomenys("duomenys.txt");
    duomenys >> n;
    miestai = new Miestas[n];
    for(int i=0; i<n; i++)
    {
        duomenys.ignore(256, '\n');
        duomenys.get(miestai[i].pavadinimas, 21);
        duomenys.get(miestai[i].apskritiesPavadinimas, 14);
        duomenys >> miestai[i].zmones;
        //cout << miestai[i].pavadinimas << " " << miestai[i].apskritiesPavadinimas << " " << miestai[i].zmones << endl;
    }
    duomenys.close();
}

void ApskriciuSkaicius(int n, Miestas*& miestai, Apskritis apskritys[], int& apskriciuSkaicius)
{
    for(int i=0; i<n; i++)
    {
        bool rasta=false;
        for(int j=0; j<apskriciuSkaicius; j++)
        {
            if(strcmp(miestai[i].apskritiesPavadinimas, apskritys[j].pavadinimas)==0)
            {
                rasta=true;
            }
        }
        if(!rasta)
        {
            strcpy(apskritys[apskriciuSkaicius++].pavadinimas,miestai[i].apskritiesPavadinimas);
        }
    }
}

void GyventojuSkaiciusApskrityje(int n, Miestas*& miestai, Apskritis apskritys[], int apskriciuSkaicius)
{
    for(int i=0; i<apskriciuSkaicius; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(strcmp(miestai[j].apskritiesPavadinimas, apskritys[i].pavadinimas)==0)
            {
                if(miestai[j].zmones<apskritys[i].maziausiaiGyventoju || apskritys[i].maziausiaiGyventoju==0)
                {
                    apskritys[i].maziausiaiGyventoju=miestai[j].zmones;
                }
                apskritys[i].zmones+=miestai[j].zmones;
            }
        }
    }
}

void Isvedimas(int n, Miestas*& miestai, Apskritis apskritys[], int apskriciuSkaicius)
{
    cout << apskriciuSkaicius << endl;
    for(int i=0; i<apskriciuSkaicius; i++)
    {
        cout << apskritys[i].pavadinimas << " " << apskritys[i].maziausiaiGyventoju << " " << apskritys[i].zmones << endl;
    }
}

