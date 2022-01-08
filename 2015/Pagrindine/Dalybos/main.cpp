#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void Nuskaitymas(int MergaiciuSuvalgytosSlyvos[]);
void LikusioSlyvos(int MergaiciuSuvalgytosSlyvos[], int Dubeneliai[10]);
void Skaiciavimai(int Dubeneliai[10], int MokiniuSuvalgytosSlyvos[]);
void Isvedimas(int MokiniuSuvalgytosSlyvos[], int MergaiciuSuvalgytosSlyvos[]);

int main()
{
    int MergaiciuSuvalgytosSlyvos[10], MokiniuSuvalgytosSlyvos[20]={0};

    int Dubeneliai[10];

    for(int i=0; i<10; i++)
    {
        Dubeneliai[i]=10;
    }

    Nuskaitymas(MergaiciuSuvalgytosSlyvos);
    LikusioSlyvos(MergaiciuSuvalgytosSlyvos, Dubeneliai);
    Skaiciavimai(Dubeneliai, MokiniuSuvalgytosSlyvos);
    Isvedimas(MokiniuSuvalgytosSlyvos, MergaiciuSuvalgytosSlyvos);

    return 0;
}

void Nuskaitymas(int MergaiciuSuvalgytosSlyvos[])
{
    ifstream duomenys("duomenys.txt");
    for(int i=0; i<10; i++)
    {
        duomenys >> MergaiciuSuvalgytosSlyvos[i];
    }
    duomenys.close();
}

void LikusioSlyvos(int MergaiciuSuvalgytosSlyvos[], int Dubeneliai[10])
{
    for(int i=0; i<10; i++)
    {
        Dubeneliai[i]-=MergaiciuSuvalgytosSlyvos[i];
    }
}

void Skaiciavimai(int Dubeneliai[10], int MokiniuSuvalgytosSlyvos[])
{
    int mokiniai = 20;
    for(int i=0; i<10; i++)
    {
        for(int j=i+1; j<mokiniai && Dubeneliai[i]!=0; j++)
        {
            MokiniuSuvalgytosSlyvos[j]++;
            Dubeneliai[i]--;
        }
    }
}

void Isvedimas(int MokiniuSuvalgytosSlyvos[], int MergaiciuSuvalgytosSlyvos[])
{
    ofstream rezultatai("rezultatai.txt");
    for(int i=0; i<20; i++)
    {
        if(i<10)
        {
            rezultatai << MokiniuSuvalgytosSlyvos[i]+MergaiciuSuvalgytosSlyvos[i] << " ";
        }
        else rezultatai << MokiniuSuvalgytosSlyvos[i] << " ";
    }
    rezultatai.close();
}
