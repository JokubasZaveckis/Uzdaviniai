#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct Marsaeigis
{
    int x0, y0;
    int x1, y1;
};

struct Komanda
{
    int k;
    int x=0, y=0;
    int funkcijos[30];
    int ivykdyta=0;
    int priezastis;
};

void Nuskaitymas(int& n, Marsaeigis& marsaeigis, Komanda*& komandos);
void Priezastis(int n, Marsaeigis& marsaeigis, Komanda*& komandos);
void Isvedimas(int n, Marsaeigis marsaeigis, Komanda* komandos);

int main()
{
    int n;

    Marsaeigis marsaeigis;
    Komanda* komandos = nullptr;

    Nuskaitymas(n, marsaeigis, komandos);
    Priezastis(n, marsaeigis, komandos);
    Isvedimas(n, marsaeigis, komandos);

    delete[] komandos;
    return 0;
}

void Nuskaitymas(int& n, Marsaeigis& marsaeigis, Komanda*& komandos)
{
    ifstream duomenys("duomenys.txt");
    duomenys >> marsaeigis.x0 >> marsaeigis.y0 >> marsaeigis.x1 >> marsaeigis.y1;
    duomenys >> n;
    komandos = new Komanda[n];
    for(int i=0; i<n; i++)
    {
        duomenys >> komandos[i].k;
        for(int j=0; j<komandos[i].k; j++)
        {
            duomenys >> komandos[i].funkcijos[j];
        }
    }
    duomenys.close();
}
void Priezastis(int n, Marsaeigis& marsaeigis, Komanda*& komandos)
{
    for(int i=0; i<n; i++)
    {
        komandos[i].x=marsaeigis.x0;
        komandos[i].y=marsaeigis.y0;
        for(int j=0; j<komandos[i].k; j++)
        {
            if(komandos[i].funkcijos[j]==1)
            {
                komandos[i].y++;
            }
            if(komandos[i].funkcijos[j]==2)
            {
                komandos[i].x++;
            }
            if(komandos[i].funkcijos[j]==3)
            {
                komandos[i].y--;
            }
            if(komandos[i].funkcijos[j]==4)
            {
                komandos[i].x--;
            }
            komandos[i].ivykdyta++;

            if(komandos[i].x==marsaeigis.x1 && komandos[i].y==marsaeigis.y1)
            {
                komandos[i].priezastis=0;
                break;
            }
            else komandos[i].priezastis=1;
        }
    }
}

void Isvedimas(int n, Marsaeigis marsaeigis, Komanda* komandos)
{
    ofstream rezultatai("rezultatai.txt");
    for(int i=0; i<n; i++)
    {
        if(komandos[i].priezastis==1)
        {
            rezultatai << setw(20) << left << "sekos pabaiga ";
            for(int j=0; j<komandos[i].ivykdyta; j++)
            {
                rezultatai << komandos[i].funkcijos[j] << " ";
            }
            rezultatai << komandos[i].ivykdyta << endl;
        }
        else
        {
            rezultatai << setw(20) << left << "pasiektas tiklas ";
            for(int j=0; j<komandos[i].ivykdyta; j++)
            {
                rezultatai << komandos[i].funkcijos[j] << " ";
            }
            rezultatai << komandos[i].ivykdyta << endl;
        }
    }
    rezultatai.close();
}
