#include <iostream>
#include <fstream>

using namespace std;

const int FigureliuSkaicius[] = {8, 2, 2, 2, 1, 1};

void Nuskaitymas(int& N, int figureles[]);
int KomplektuSkaiciavimas(int figureles[]);

int main()
{
    int N, figureles[6]={0};
    Nuskaitymas(N, figureles);
    int komplektai=KomplektuSkaiciavimas(figureles);
    cout << komplektai << endl;

    return 0;
}

void Nuskaitymas(int& N, int figureles[])
{
    ifstream duomenys("duomenys.txt");
    duomenys >> N;
    int a;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<6; j++)
        {
            duomenys >> a;
            figureles[j]+=a;
        }
    }
    duomenys.close();
}

int KomplektuSkaiciavimas(int figureles[])
{
    int min=0;
    for(int i=0; i<6; i++)
    {
        if(figureles[i]<figureles[min]) min=i;
    }
    return figureles[min]/FigureliuSkaicius[min];
}
