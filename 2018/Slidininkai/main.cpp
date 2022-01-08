#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>

using namespace std;

struct DalyvaveSlidininkai
{
    char Vardas[21];
    int laikas;
};

struct FinisaveSlidininkai:DalyvaveSlidininkai
{
    /*char Vardas[21];
    int laikas;*/

    int trasojePraleistasLaikas;
};

void Nuskaitymas(int&n, int&m, DalyvaveSlidininkai*& dalyvave, FinisaveSlidininkai*& finisave);
void TrasojePraleistoLaikoSkaiciavimas(int n, int m, DalyvaveSlidininkai*& dalyvave, FinisaveSlidininkai*& finisave);
void Rikiavimas(int m, FinisaveSlidininkai*& finisave);
void Isvedimas(int m, FinisaveSlidininkai*& finisave);

int main()
{
    int n, m;
    DalyvaveSlidininkai* dalyvave = nullptr;
    FinisaveSlidininkai* finisave = nullptr;

    Nuskaitymas(n, m, dalyvave, finisave);
    TrasojePraleistoLaikoSkaiciavimas(n, m, dalyvave, finisave);
    Rikiavimas(m, finisave);
    Isvedimas(m, finisave);

    delete[] dalyvave;
    delete[] finisave;
    return 0;
}

void Nuskaitymas(int&n, int&m, DalyvaveSlidininkai*& dalyvave, FinisaveSlidininkai*& finisave)
{
    ifstream duomenys("duomenys.txt");
    duomenys >> n;
    dalyvave = new DalyvaveSlidininkai[n];
    int valanda, minutes, sekundes;
    for(int i=0; i<n; i++)
    {
        duomenys.ignore(256, '\n');
        duomenys.get(dalyvave[i].Vardas, 21);
        duomenys >> valanda >> minutes >> sekundes;
        dalyvave[i].laikas+=valanda*3600+minutes*60+sekundes;
    }
    duomenys >> m;
    finisave = new FinisaveSlidininkai[m];
    for(int i=0; i<m; i++)
    {
        duomenys.ignore(256, '\n');
        duomenys.get(finisave[i].Vardas, 21);
        duomenys >> valanda >> minutes >> sekundes;
        finisave[i].laikas+=valanda*60*60+minutes*60+sekundes;
    }
    duomenys.close();
}

void TrasojePraleistoLaikoSkaiciavimas(int n, int m, DalyvaveSlidininkai*& dalyvave, FinisaveSlidininkai*& finisave)
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(strcmp(dalyvave[j].Vardas, finisave[i].Vardas)==0)
            {
                finisave[i].laikas-=dalyvave[j].laikas;
            }
        }
    }
}

void Rikiavimas(int m, FinisaveSlidininkai*& finisave)
{
    for(int i=0; i<m-1; i++)
    {
        int max=i;
        for(int j=i+1; j<m; j++)
        {
            if(finisave[j].laikas<finisave[max].laikas || (finisave[j].laikas==finisave[max].laikas && strcmp(finisave[j].Vardas, finisave[max].Vardas)<0))
            {
                max=j;
            }
        }
        if(max!=i)
        {
            swap(finisave[i], finisave[max]);
        }
    }
}

void Isvedimas(int m, FinisaveSlidininkai*& finisave)
{
    ofstream rezultatai("rezultatai.txt");
    for(int i=0; i<m; i++)
    {
        rezultatai << finisave[i].Vardas << finisave[i].laikas/60 << " " << finisave[i].laikas%60 << endl;
    }
    rezultatai.close();
}
