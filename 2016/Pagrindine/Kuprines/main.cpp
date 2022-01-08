#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int SunkiausiosKuprinesPaieska();
int LengvesniuKupriniuPaieska(int sunkiausia);

int main()
{
    int sunkiausia = SunkiausiosKuprinesPaieska();
    int kiek = LengvesniuKupriniuPaieska(sunkiausia);


    ofstream rezultatai("rezultatai.txt");

    rezultatai << sunkiausia << " " << kiek << endl;
    rezultatai.close();

    return 0;
}

int SunkiausiosKuprinesPaieska()
{
    int x, a, max=0;
    ifstream duomenys("duomenys.txt");
    duomenys >> x;
    for(int i=0; i<x; i++)
    {
        duomenys >> a;
        if(a>max) max = a;
    }
    duomenys.close();
    return max;
}

int LengvesniuKupriniuPaieska(int sunkiausia)
{
    int x, a, kiek=0;
    ifstream duomenys("duomenys.txt");
    duomenys >> x;
    sunkiausia*=0.5;
    for(int i=0; i<x; i++)
    {
        duomenys >> a;
        if(a<=sunkiausia) kiek++;
    }
    duomenys.close();
    return kiek;
}
