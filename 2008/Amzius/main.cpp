#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int Menesiai[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct Zmogus
{
    char vardas[26];
    int gimimoMetai;
    int gimimoMenuo;
    int gimimoDiena;
    int mirtiesMetai;
    int mirtiesMenuo;
    int mirtiesDiena;
    int pragyventaDienu=0;

    void PragyventosDienos();
};

void Nuskaitymas(int&n, Zmogus amzius[]);
void Isvedimas(int n, Zmogus amzius[]);

int main()
{
    int n;
    Zmogus amzius[100];

    Nuskaitymas(n, amzius);
    Isvedimas(n, amzius);
    return 0;
}

void Nuskaitymas(int&n, Zmogus amzius[])
{
    ifstream duomenys("duomenys.txt");
    duomenys >> n;
    for(int i=0; i<n; i++)
    {
        duomenys.ignore(256, '\n');
        duomenys.get(amzius[i].vardas, 26);
        duomenys >> amzius[i].gimimoMetai >> amzius[i].gimimoMenuo >> amzius[i].gimimoDiena >> amzius[i].mirtiesMetai >> amzius[i].mirtiesMenuo >> amzius[i].mirtiesDiena;
    }
    duomenys.close();
}

void Zmogus::PragyventosDienos()
{
    if(mirtiesMenuo>=gimimoMenuo || (mirtiesMenuo == gimimoMenuo && mirtiesDiena>=gimimoDiena))
    {
        pragyventaDienu += (mirtiesMetai-gimimoMetai)*365;
        if(gimimoMenuo == mirtiesMenuo)
        {
            pragyventaDienu += mirtiesDiena-gimimoDiena;
        }
        else
        {
            pragyventaDienu += Menesiai[gimimoMenuo-1]-gimimoDiena;
            for(int i=gimimoMenuo+1; i<mirtiesMenuo; i++)
            {
                pragyventaDienu+=Menesiai[i-1];
            }
            pragyventaDienu+=mirtiesDiena;
        }
    }
    else
    {
        pragyventaDienu += (mirtiesMetai-gimimoMetai-1)*365;
        if(gimimoMenuo == mirtiesMenuo)
        {
            pragyventaDienu += mirtiesDiena-gimimoDiena;
        }
        else
        {
            pragyventaDienu += Menesiai[gimimoMenuo-1]-gimimoDiena;
            for(int i=gimimoMenuo+1; i<mirtiesMenuo; i++)
            {
                pragyventaDienu+=Menesiai[i-1];
            }
            pragyventaDienu+=mirtiesDiena;
        }
    }
}

void Isvedimas(int n, Zmogus amzius[])
{
    for(int i=0; i<n; i++)
    {
        amzius[i].PragyventosDienos();
        cout << amzius[i].vardas << " " << amzius[i].gimimoMetai << " " << amzius[i].gimimoMenuo << " " << amzius[i].gimimoDiena << " " << amzius[i].mirtiesMetai << " " << amzius[i].mirtiesMenuo << " " << amzius[i].mirtiesDiena << " " << amzius[i].pragyventaDienu << " " << endl;
    }
}



