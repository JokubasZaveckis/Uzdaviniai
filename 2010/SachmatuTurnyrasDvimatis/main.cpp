#include <iostream>
#include <fstream>

using namespace std;

const int FigureliuKiekis[]={8, 2, 2, 2, 1, 1};

void Nuskaitymas(int n, int figureles[100][6]);
int Skaiciavimai(int n, int figureles[100][6]);

int main()
{
    int n, figureles[100][6];

    Nuskaitymas(n, figureles);
    int a = Skaiciavimai(n, figureles);
    cout << a << endl;
    return 0;
}

void Nuskaitymas(int n, int figureles[100][6])
{
    ifstream duomenys ("duomenys.txt");
    duomenys >> n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<6; j++)
        {
            duomenys >> figureles[i][j];
        }
    }
    duomenys.close();
}

int Skaiciavimai(int n, int figureles[100][6])
{
    int figureliuSkaicius[6];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<6; j++)
        {
            figureliuSkaicius[j]+=figureles[i][j];
        }
    }
    for(int i=0; i<6; i++)
    {
        figureliuSkaicius[i]/=FigureliuKiekis[i];
    }

    int min=0;
    for(int i=0; i<6; i++)
    {
        if(figureliuSkaicius[i]>figureliuSkaicius[min]) min = i;
    }
    return min;

}
