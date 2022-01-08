#include <iostream>
#include <fstream>

using namespace std;

const int FigureliuSkaicius[] = {8, 2, 2, 2, 1, 1};

void Nuskaitymas(int&n, int Figureles[]);
int GalimiKomplektai(int Figureles[]);

int main()
{
    int n, Figureles[6];
    Nuskaitymas(n, Figureles);
    int komplektai = GalimiKomplektai(Figureles);
    cout << komplektai << endl;
    return 0;
}

void Nuskaitymas(int&n, int Figureles[])
{
    ifstream duomenys("duomenys.txt");
    duomenys >> n;
    int a;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<6; j++)
        {
            duomenys >> a;
            Figureles[j] += FigureliuSkaicius[j]-a;
        }
    }
    duomenys.close();
}

int GalimiKomplektai(int Figureles[])
{
    int min=0;
    for(int i=0; i<6; i++)
    {
        if(Figureles[i]<Figureles[min]) min=i;
    }
    return Figureles[min]/FigureliuSkaicius[min];
}
