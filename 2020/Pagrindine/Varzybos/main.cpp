#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>

using namespace std;

struct Bazine
{
    char Pavadinimas[21];
    int suma = 0;
};

struct Zuvis : Bazine
{
    int svoris;
    int taskai;
};

struct Zvejys : Bazine
{
    int kiekZuvu = 0;

    Zuvis pagautosZuvys[5];
};

void Nuskaitymas(int&n, int&k, Zvejys*& zvejai, Zuvis*& zuvys);
void TaskaiPagalSvori(int n, Zvejys*& zvejai);
void TaskaiPagalPavadinima(int n, int k, Zvejys*& zvejai, Zuvis*& zuvys);
void Rikiavimas(int kiek, Bazine* duomenys);
void Isvedimas(int n, int k, Zvejys*& zvejai, Zuvis*& zuvys);

int main()
{
    int n, k;

    Zvejys* zvejai;
    Zuvis* zuvys;

    Nuskaitymas(n, k, zvejai, zuvys);
    TaskaiPagalSvori(n, zvejai);
    TaskaiPagalPavadinima(n, k, zvejai, zuvys);
    Rikiavimas(n, zvejai);
    //Rikiavimas(k, zuvys);
    Isvedimas(n, k, zvejai, zuvys);

    delete[] zvejai;
    delete[] zuvys;
    return 0;
}

void Nuskaitymas(int&n, int&k, Zvejys*& zvejai, Zuvis*& zuvys)
{
    ifstream duomenys("duomenys.txt");
    duomenys >> n;
    zvejai = new Zvejys[n];
    for(int i=0; i<n; i++)
    {
        duomenys.ignore(256, '\n');
        duomenys.get(zvejai[i].Pavadinimas, 21);
        duomenys >> zvejai[i].kiekZuvu;
        for(int j=0; j<zvejai[i].kiekZuvu; j++)
        {
            duomenys.ignore(256, '\n');
            duomenys.get(zvejai[i].pagautosZuvys[j].Pavadinimas, 21);
            duomenys >> zvejai[i].pagautosZuvys[j].svoris;
        }
    }
    duomenys >> k;
    zuvys = new Zuvis[k];
    for(int i=0; i<k; i++)
    {
        duomenys.ignore(256, '\n');
        duomenys.get(zuvys[i].Pavadinimas, 21);
        duomenys >> zuvys[i].taskai;
    }
    duomenys.close();
}

void TaskaiPagalSvori(int n, Zvejys*& zvejai)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<zvejai[i].kiekZuvu; j++)
        {
            if(zvejai[i].pagautosZuvys[j].svoris<200)
            {
                zvejai[i].suma+=10;
            }
            else
            {
                zvejai[i].suma+=30;
            }
        }
    }
}

void TaskaiPagalPavadinima(int n, int k, Zvejys*& zvejai, Zuvis*& zuvys)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<zvejai[i].kiekZuvu; j++)
        {
            for(int a=0; a<k; a++)
            {
                if(strcmp(zvejai[i].pagautosZuvys[j].Pavadinimas, zuvys[a].Pavadinimas)==0)
                {
                    zvejai[i].suma+=zuvys[a].taskai;
                    zuvys[a].suma+=zvejai[i].pagautosZuvys[j].svoris;
                }
            }
        }
    }
}

void Rikiavimas(int kiek, Bazine* duomenys)
{
    for(int i=0; i<kiek-1; i++)
    {
        int max=i;
        for(int j=i+1; j<kiek; j++)
        {
            if(duomenys[j].suma<duomenys[max].suma || (strcmp(duomenys[j].Pavadinimas, duomenys[max].Pavadinimas)<0 && duomenys[j].suma==duomenys[max].suma))
            {
                max=j;
            }
        }
        if(max!=i)
        {
            swap(duomenys[i], duomenys[max]);
            cout << ((Zvejys)duomenys[i]).Pavadinimas << duomenys[i].suma << endl;
            cout << duomenys[max].Pavadinimas << duomenys[max].suma << endl;
            cout << i << " " << max << endl;
            cout << "A" << endl;
        }
    }
}

void Isvedimas(int n, int k, Zvejys*& zvejai, Zuvis*& zuvys)
{
    cout << "Dalyviai" << endl;
    for(int i=0; i<n; i++)
    {
        cout << zvejai[i].Pavadinimas << zvejai[i].suma << endl;
    }
    cout << "Laimikis" << endl;
    for(int i=0; i<k; i++)
    {
        cout << zuvys[i].Pavadinimas << zuvys[i].suma << endl;
    }
}






