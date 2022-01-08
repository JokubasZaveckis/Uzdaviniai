#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>

using namespace std;

struct Sportininkas
{
    char vardas[21];
    int numeris;
    int laikas;
};

struct FinisavesSportininkas
{
    char vardas[21];
    int numeris;
    int laikas;
    int taiklusSuviai=0;
};

void Nuskaitymas(int& n, int& m, int& kiekVaikinu, int& kiekMerginu, int& finisavusiuMerginu, int& finisavusiuVaikinu, Sportininkas merginos[], Sportininkas vaikinai[], FinisavesSportininkas finisaveVaikinai[], FinisavesSportininkas finisavusiosMerginos[]);
void VaikinuRezultatai(int kiekVaikinu, int finisavusiuVaikinu, Sportininkas vaikinai[], FinisavesSportininkas finisaveVaikinai[]);
void MerginuRezultatai(int kiekMerginu, int finisavusiuMerginu, Sportininkas merginos[], FinisavesSportininkas finisavusiosMerginos[]);
void VaikinuRikiavimas(int finisavusiuVaikinu, FinisavesSportininkas finisaveVaikinai[]);
void MerginuRikiavimas(int finisavusiuMerginu, FinisavesSportininkas finisavusiosMerginos[]);
void Isvedimas(int finisavusiuMerginu, int finisavusiuVaikinu, FinisavesSportininkas finisaveVaikinai[], FinisavesSportininkas finisavusiosMerginos[]);

int main()
{
    int n, m, kiekVaikinu=0, kiekMerginu=0, finisavusiuMerginu=0, finisavusiuVaikinu=0;
    Sportininkas merginos[30];
    Sportininkas vaikinai[30];
    FinisavesSportininkas finisaveVaikinai[30];
    FinisavesSportininkas finisavusiosMerginos[30];

    Nuskaitymas(n, m, kiekVaikinu, kiekMerginu, finisavusiuMerginu=0, finisavusiuVaikinu=0, merginos, vaikinai, finisaveVaikinai, finisavusiosMerginos);
    VaikinuRezultatai(kiekVaikinu, finisavusiuVaikinu, vaikinai, finisaveVaikinai);
    MerginuRezultatai(kiekMerginu, finisavusiuMerginu, merginos, finisavusiosMerginos);
    VaikinuRikiavimas(finisavusiuVaikinu, finisaveVaikinai);
    MerginuRikiavimas(finisavusiuMerginu, finisavusiosMerginos);
    Isvedimas(finisavusiuMerginu, finisavusiuVaikinu, finisaveVaikinai, finisavusiosMerginos);

    /*cout << n << endl;
    cout << "Merginos: " << endl;
    for(int i=0; i<kiekMerginu; i++)
    {
        cout << merginos[i].vardas << " " << merginos[i].numeris << " " << merginos[i].laikas << endl;
    }
    cout << "Vaikinai: " << endl;
    for(int i=0; i<kiekVaikinu; i++)
    {
        cout << vaikinai[i].vardas << " " << vaikinai[i].numeris << " " << vaikinai[i].laikas << endl;
    }
    cout << endl;
    cout << m << endl;
    cout << "Merginos: " << endl;
    for(int i=0; i<finisavusiuMerginu; i++)
    {
        cout << finisavusiosMerginos[i].numeris << " " << finisavusiosMerginos[i].laikas <<  " " << finisavusiosMerginos[i].taiklusSuviai << endl;
    }
    cout << "Vaikinai: " << endl;
    for(int i=0; i<finisavusiuVaikinu; i++)
    {
        cout << finisaveVaikinai[i].numeris << " " << finisaveVaikinai[i].laikas << " " <<  finisaveVaikinai[i].taiklusSuviai << endl;
    }*/

}

void Nuskaitymas(int& n, int& m, int& kiekVaikinu, int& kiekMerginu, int& finisavusiuMerginu, int& finisavusiuVaikinu, Sportininkas merginos[], Sportininkas vaikinai[], FinisavesSportininkas finisaveVaikinai[], FinisavesSportininkas finisavusiosMerginos[])
{
    ifstream duomenys("duomenys.txt");
    duomenys >> n;
    char vardas[21];
    int numeris;
    int valandos, minutes, sekundes;
    for(int i=0; i<n; i++)
    {
        duomenys.ignore(256, '\n');
        duomenys.get(vardas, 21);
        duomenys >> numeris;
        duomenys >> valandos >> minutes >> sekundes;
        if(numeris-200<0)
        {
            strcpy(merginos[kiekMerginu].vardas, vardas);
            merginos[kiekMerginu].numeris = numeris;
            merginos[kiekMerginu].laikas = valandos*3600+minutes*60+sekundes;
            kiekMerginu++;
        }
        else
        {
            strcpy(vaikinai[kiekVaikinu].vardas, vardas);
            vaikinai[kiekVaikinu].numeris = numeris;
            vaikinai[kiekVaikinu].laikas = valandos*3600+minutes*60+sekundes;
            kiekVaikinu++;
        }
    }
    duomenys >> m;
    int a, b, c, d;
    for(int i=0; i<m; i++)
    {
        duomenys >> numeris;
        duomenys >> valandos >> minutes >> sekundes;
        if(numeris-200<0)
        {
            finisavusiosMerginos[finisavusiuMerginu].numeris=numeris;
            finisavusiosMerginos[finisavusiuMerginu].laikas=valandos*3600+minutes*60+sekundes;
            duomenys >> a >> b;
            finisavusiosMerginos[finisavusiuMerginu].taiklusSuviai+=a+b;
            finisavusiuMerginu++;
        }
        else
        {
            finisaveVaikinai[finisavusiuVaikinu].numeris=numeris;
            finisaveVaikinai[finisavusiuVaikinu].laikas=valandos*3600+minutes*60+sekundes;
            duomenys >> a >> b >> c >> d;
            finisaveVaikinai[finisavusiuVaikinu].taiklusSuviai+=a+b+c+d;
            finisavusiuVaikinu++;
        }
    }
    duomenys.close();
}

void VaikinuRezultatai(int kiekVaikinu, int finisavusiuVaikinu, Sportininkas vaikinai[], FinisavesSportininkas finisaveVaikinai[])
{
    for(int i=0; i<finisavusiuVaikinu; i++)
    {
        for(int j=0; j<kiekVaikinu; j++)
        {
            if(vaikinai[j].numeris==finisaveVaikinai[i].numeris)
            {
                strcpy(finisaveVaikinai[i].vardas, vaikinai[j].vardas);
                finisaveVaikinai[i].laikas-=vaikinai[j].laikas-(20-finisaveVaikinai[i].taiklusSuviai)*60;
            }
        }
    }
}

void MerginuRezultatai(int kiekMerginu, int finisavusiuMerginu, Sportininkas merginos[], FinisavesSportininkas finisavusiosMerginos[])
{
    for(int i=0; i<finisavusiuMerginu; i++)
    {
        for(int j=0; j<kiekMerginu; j++)
        {
            if(merginos[j].numeris==finisavusiosMerginos[i].numeris)
            {
                strcpy(finisavusiosMerginos[i].vardas, merginos[j].vardas);
                finisavusiosMerginos[i].laikas-=merginos[j].laikas-(10-finisavusiosMerginos[i].taiklusSuviai)*60;
            }
        }
    }
}

void VaikinuRikiavimas(int finisavusiuVaikinu, FinisavesSportininkas finisaveVaikinai[])
{
    for(int i=0; i<finisavusiuVaikinu; i++)
    {
        int max=i;
        for(int j=i+1; j<finisavusiuVaikinu-1; j++)
        {
            if(finisaveVaikinai[j].laikas<finisaveVaikinai[max].laikas || (strcmp(finisaveVaikinai[j].vardas, finisaveVaikinai[max].vardas)<0))
            {
                max=j;
            }
        }
        if(max!=i)
        {
            swap (finisaveVaikinai[i], finisaveVaikinai[max]);
        }
    }
}

void MerginuRikiavimas(int finisavusiuMerginu, FinisavesSportininkas finisavusiosMerginos[])
{
    for(int i=0; i<finisavusiuMerginu-1; i++)
    {
        int max=i;
        for(int j=i+1; j<finisavusiuMerginu; j++)
        {
            if(finisavusiosMerginos[j].laikas<finisavusiosMerginos[max].laikas || (strcmp(finisavusiosMerginos[j].vardas, finisavusiosMerginos[max].vardas)<0))
            {
                max=j;
            }
        }
        if(max!=i)
        {
            swap (finisavusiosMerginos[i], finisavusiosMerginos[max]);
        }
    }
}

void Isvedimas(int finisavusiuMerginu, int finisavusiuVaikinu, FinisavesSportininkas finisaveVaikinai[], FinisavesSportininkas finisavusiosMerginos[])
{
    cout << "Merginos: " << endl;
     for(int i=0; i<finisavusiuMerginu; i++)
    {
        cout << finisavusiosMerginos[i].numeris << " " << finisavusiosMerginos[i].vardas << " " << finisavusiosMerginos[i].laikas/3600 << " " << finisavusiosMerginos[i].laikas/60 << " " << finisavusiosMerginos[i].laikas%60 << endl;
    }
    cout << "Vaikinai: " << endl;
    for(int i=0; i<finisavusiuVaikinu; i++)
    {
        cout << finisaveVaikinai[i].numeris << " " << finisaveVaikinai[i].vardas << " " << finisaveVaikinai[i].laikas/3600 << " " << finisaveVaikinai[i].laikas/60 << " " << finisaveVaikinai[i].laikas%60 << endl;
    }
}
