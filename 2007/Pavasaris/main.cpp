#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>


using namespace std;

void Nuskaitymas(int&n, int dienos[], int tRyte[], int tDiena[], int tVakare[]);
int AuksciausiaTemperatura(int n, int temperatura[]);
int AuksciausiaTemperatura(int n, int tRyte[], int tDiena[], int tVakare[]);
int Rikiavimas(int n, int masyvas[]);
void PasikartojanciosDienos(int n, int dienos[], int pasikartojanciosDienos[], int& kiek, int tRyte[], int tDiena[], int tVakare[]);
void DaugiauNei20(int n, int tRyte[], int tDiena[], int tVakare[], int dienosDaugiauNei20[], int& kiek, int dienos[]);
void Isvedimas(int pasikartojanciosDienos[], int kiek20, int kiek, int dienosDaugiauNei20[]);


int main()
{
    int n, dienos[31], tRyte[100], tDiena[100], tVakare[100], dienosDaugiauNei20[100], pasikartojanciosDienos[100], kiek20 = 0, kiek = 0;

    Nuskaitymas(n, dienos, tRyte, tDiena, tVakare);
    PasikartojanciosDienos(n, dienos, pasikartojanciosDienos, kiek, tRyte, tDiena, tVakare);
    DaugiauNei20(n, tRyte, tDiena, tVakare, dienosDaugiauNei20, kiek20, dienos);
    Isvedimas(pasikartojanciosDienos, kiek20, kiek, dienosDaugiauNei20);
    return 0;
}
void Nuskaitymas(int&n, int dienos[], int tRyte[], int tDiena[], int tVakare[])
{
    ifstream duomenys("U1duom.txt");
    duomenys >> n;
    for(int i=0; i<n; i++)
    {
        duomenys >> dienos[i] >> tRyte[i] >> tDiena[i] >> tVakare[i];
    }
    duomenys.close();
}

int AuksciausiaTemperatura(int n, int temperatura[])
{
    int max = 0;
    for(int i=0; i<n; i++)
    {
        if(temperatura[i]>temperatura[max])
            max = i;
    }
    return temperatura[max];
}

int AuksciausiaTemperatura(int n, int tRyte[], int tDiena[], int tVakare[])
{
    int maxRyte = AuksciausiaTemperatura(n, tRyte);
    int maxDiena = AuksciausiaTemperatura(n, tDiena);
    int maxVakare = AuksciausiaTemperatura(n, tVakare);
    if(maxRyte>maxDiena && maxRyte > maxVakare)
        return maxRyte;
    else if(maxDiena>maxVakare)
        return maxDiena;
    return maxVakare;
}

void PasikartojanciosDienos(int n, int dienos[], int pasikartojanciosDienos[], int& kiek, int tRyte[], int tDiena[], int tVakare[])
{
    int didziausiaTemperatura = AuksciausiaTemperatura(n, tRyte, tDiena, tVakare);

    for(int i=0; i<n; i++)
    {
        if(didziausiaTemperatura==tRyte[i] || didziausiaTemperatura==tDiena[i] || didziausiaTemperatura==tVakare[i])
        pasikartojanciosDienos[kiek++]=dienos[i];
    }
}

void DaugiauNei20(int n, int tRyte[], int tDiena[], int tVakare[], int dienosDaugiauNei20[], int& kiek, int dienos[])
{
    for(int i=0; i<n; i++)
    {
        if(tRyte[i]>=20 && tDiena[i]>=20 && tRyte[i]>=20)
            dienosDaugiauNei20[kiek++]=dienos[i];
    }
}

void Isvedimas(int pasikartojanciosDienos[], int kiek20, int kiek, int dienosDaugiauNei20[])
{
    for(int i=0; i<kiek; i++)
    {
        cout << pasikartojanciosDienos[i] << " ";
    }
    cout << endl;
    for(int i=0; i<kiek20; i++)
    {
        cout << dienosDaugiauNei20[i] << " ";
    }
}
