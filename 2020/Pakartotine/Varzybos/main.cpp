#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>

using namespace std;

struct PagautaZuvis
{
    char Pavadinimas[21];
    int svoris;
    int kainaSuSvoriu;
};

struct Zvejys
{
    char Vardas[21];
    int kiekZuvu;
    int pelnas=0;
    PagautaZuvis pagautos[30];
};

struct VertinamaZuvis
{
    char Pavadinimas[21];
    int kaina;
    int kainuSuma=0;
};

void Nuskaitymas(int& k, int& n, Zvejys*& zvejai, VertinamaZuvis*& zuvys);
void PelnoSkaiciavimas(int k, int n, Zvejys*& zvejai, VertinamaZuvis*& zuvys);
void ZvejuRikiavimas(int n, Zvejys*& zvejai);
void ZuvuRikiavimas(int k, VertinamaZuvis*& zuvys);
void Isvedimas(int n, int k, Zvejys*& zvejai, VertinamaZuvis*& zuvys);

int main()
{
    int k, n;
    Zvejys* zvejai = nullptr;
    VertinamaZuvis* zuvys = nullptr;

    Nuskaitymas(k, n, zvejai, zuvys);
    PelnoSkaiciavimas(k, n, zvejai, zuvys);
    ZvejuRikiavimas(n, zvejai);
    ZuvuRikiavimas(k, zuvys);
    Isvedimas(n, k, zvejai, zuvys);

    delete[] zvejai;
    delete[] zuvys;
    return 0;
}

void Nuskaitymas(int& k, int& n, Zvejys*& zvejai, VertinamaZuvis*& zuvys)
{
    ifstream duomenys("duomenys.txt");
    duomenys >> k;
    zuvys = new VertinamaZuvis[k];
    for(int i=0; i<k; i++)
    {
        duomenys.ignore(256, '\n');
        duomenys.get(zuvys[i].Pavadinimas, 21);
        duomenys >> zuvys[i].kaina;
    }
    duomenys >> n;
    zvejai = new Zvejys[n];
    for(int i=0; i<n; i++)
    {
        duomenys.ignore(256, '\n');
        duomenys.get(zvejai[i].Vardas, 21);
        duomenys >> zvejai[i].kiekZuvu;
        for(int j=0; j<zvejai[i].kiekZuvu; j++)
        {
            duomenys.ignore(256, '\n');
            duomenys.get(zvejai[i].pagautos[j].Pavadinimas, 21);
            duomenys >> zvejai[i].pagautos[j].svoris;
        }
    }
    duomenys.close();
}

void PelnoSkaiciavimas(int k, int n, Zvejys*& zvejai, VertinamaZuvis*& zuvys)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<zvejai[i].kiekZuvu; j++)
        {
            for(int a=0; a<k; a++)
            {
                if(strcmp(zvejai[i].pagautos[j].Pavadinimas, zuvys[a].Pavadinimas)==0)
                {
                    zvejai[i].pagautos[j].kainaSuSvoriu=zvejai[i].pagautos[j].svoris*2*zuvys[a].kaina;
                    zuvys[a].kainuSuma+=zvejai[i].pagautos[j].kainaSuSvoriu;
                    zvejai[i].pelnas+=zvejai[i].pagautos[j].kainaSuSvoriu;
                    break;
                }
            }
        }
    }
}

void ZvejuRikiavimas(int n, Zvejys*& zvejai)
{
    for(int i=0; i<n-1; i++)
    {
        int max=i;
        for(int j=i+1; j<n; j++)
        {
            if(zvejai[j].pelnas>zvejai[max].pelnas || (zvejai[j].pelnas==zvejai[max].pelnas && strcmp(zvejai[j].Vardas,zvejai[max].Vardas)<0))
            {
                max=j;
            }
        }
        if(max!=i)
        {
            swap(zvejai[i], zvejai[max]);
        }
    }
}

void ZuvuRikiavimas(int k, VertinamaZuvis*& zuvys)
{
    for(int i=0; i<k-1; i++)
    {
        int max=i;
        for(int j=i+1; j<k; j++)
        {
            if(zuvys[j].kainuSuma>zuvys[max].kainuSuma || (zuvys[j].kainuSuma==zuvys[max].kainuSuma && strcmp(zuvys[j].Pavadinimas,zuvys[max].Pavadinimas)<0))
            {
                max=j;
            }
        }
        if(max!=i)
        {
            swap(zuvys[i], zuvys[max]);
        }
    }
}

void Isvedimas(int n, int k, Zvejys*& zvejai, VertinamaZuvis*& zuvys)
{
    ofstream rezultatai("rezultatai.txt");
    rezultatai << "Dalyviai " << endl;
    for(int i=0; i<n; i++)
    {
        rezultatai << zvejai[i].Vardas << " " << zvejai[i].pelnas/100 << " " << zvejai[i].pelnas%100 << endl;
    }
    rezultatai << "Laimikis " << endl;
    for(int i=0; i<k; i++)
    {
        rezultatai << zuvys[i].Pavadinimas << " " << zuvys[i].kainuSuma/100 << " " << zuvys[i].kainuSuma%100 << endl;
    }
    rezultatai.close();
}




