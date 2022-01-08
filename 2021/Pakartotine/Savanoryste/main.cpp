#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

struct Diena
{
    int numeris;
    int praleistasLaikasMinutemis;
    int suvenyrai[5];
    int skirtinguSuvenyruSuma = 0;
    int h0, m0, h, m; //Isejimo ir atejimo laikas
    int kiekSkirtinguSuvenyru = 0;
};

void Nuskaitymas(int& n, Diena*& dienos);
int LaikasMinutemisPerDiena(int h0, int h, int m0, int m);
void Skaiciavimai(int n, Diena*& dienos);
int DaugiausiaiSkirtinguSuvenyru(int n, Diena*& dienos);
int DaugiausiaiSkirtinguSuvenyruSuma(int n, Diena*& dienos, int max);
void Isvedimas(int n, Diena*& dienos, int max, int maxSuma);

int main()
{
    int n;
    Diena* dienos = nullptr;

    Nuskaitymas(n, dienos);

    for(int i=0; i<n; i++)
    {
        dienos[i].praleistasLaikasMinutemis = LaikasMinutemisPerDiena(dienos[i].h0, dienos[i].h, dienos[i].m0, dienos[i].m);
    }

    Skaiciavimai(n, dienos);
    int max = DaugiausiaiSkirtinguSuvenyru(n, dienos);
    int maxSuma = DaugiausiaiSkirtinguSuvenyruSuma(n, dienos, max);

    Isvedimas(n, dienos, max, maxSuma);


    delete[] dienos;
    return 0;
}

void Nuskaitymas(int& n, Diena*& dienos)
{
    ifstream duomenys("duomenys.txt");
    duomenys >> n;
    dienos = new Diena[n];
    for(int i = 0; i < n; i++)
    {
        duomenys >> dienos[i].numeris;
        duomenys >> dienos[i].h0 >> dienos[i].m0 >> dienos[i].h >> dienos[i].m;
        for(int j = 0; j < 5; j++)
        {
            duomenys >> dienos[i].suvenyrai[j];
        }
    }
    duomenys.close();
}

int LaikasMinutemisPerDiena(int h0, int h, int m0, int m)
{
    return (h*60+m)-(h0*60+m0);
}

void Skaiciavimai(int n, Diena*& dienos)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(dienos[i].suvenyrai[j]!=0)
            {
                dienos[i].kiekSkirtinguSuvenyru++;
                dienos[i].skirtinguSuvenyruSuma+=dienos[i].suvenyrai[j];
            }
        }
    }
}

int DaugiausiaiSkirtinguSuvenyru(int n, Diena*& dienos)
{
    int max = 0;
    for(int i = 0; i < n; i++)
    {
        if(dienos[i].kiekSkirtinguSuvenyru > dienos[max].kiekSkirtinguSuvenyru) max=i;
    }
    return max;
}

int DaugiausiaiSkirtinguSuvenyruSuma(int n, Diena*& dienos, int max)
{
    int maxSuma = 0;
    for(int i = 0; i < n; i++)
    {
        if(dienos[i].kiekSkirtinguSuvenyru==dienos[max].kiekSkirtinguSuvenyru && dienos[i].skirtinguSuvenyruSuma > dienos[maxSuma].skirtinguSuvenyruSuma)
        {
            maxSuma=i;
        }
    }
    return maxSuma;
}

void Isvedimas(int n, Diena*& dienos, int max, int maxSuma)
{
    ofstream rezultatai("rezultatai.txt");
    for(int i = 0; i < n; i++)
    {
        if(dienos[i].kiekSkirtinguSuvenyru==dienos[max].kiekSkirtinguSuvenyru && dienos[i].skirtinguSuvenyruSuma == dienos[maxSuma].skirtinguSuvenyruSuma)
        {
            rezultatai << dienos[i].numeris << " " << dienos[i].praleistasLaikasMinutemis << endl;
        }
    }
    rezultatai.close();
}



