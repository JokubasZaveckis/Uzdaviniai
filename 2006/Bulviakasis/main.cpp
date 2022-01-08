#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

void Nuskaitymas(int&n, int& m, int maisai[]);
int Reisai(int n, int m, int maisai[]);
int Daugiausiai(int n, int m, int maisai[]);
int KiekKartuVaziavo(int n, int m, int maisai[], int max);
void Isvedimas(int n, int m, int maisai[]);
int Funkcija(float n);

int main()
{
    int m, n, maisai[2000];
    Nuskaitymas(n, m, maisai);
    Isvedimas(n, m, maisai);
    return 0;

}

void Nuskaitymas(int&n, int& m, int maisai[])
{
    ifstream duomenys("duom1.txt");
    duomenys >> n >> m;
    for(int i=0; i<n; i++)
    {
        duomenys >> maisai[i];
    }
    duomenys.close();
}

//int Reisai(int n, int m, int maisai[])
//{
//    int reisai = 0;
//    for(int i=0; i<n; i++)
//    {
//        if(maisai[i]-m <=0)
//            reisai++;
//        else if (maisai[i]-m > m)
//        {
//            while(maisai[i]<m)
//            {
//                maisai[i]-m;
//                reisai++;
//            }
//        }
//    }
//    return reisai;
//}

int Reisai(int n, int m, int maisai[])
{
    int reisai = 0;
    for(int i=0; i<n; i++)
    {
        reisai += Funkcija(maisai[i]/(m*1.0));
    }
    return reisai;
}

int Daugiausiai(int n, int m, int maisai[])
{
    int max=0;
    for(int i=0; i<n; i++)
    {
        if(maisai[i]>maisai[max]) max = i;
    }
    return max;
}

int KiekKartuVaziavo(int n, int m, int maisai[], int max)
{
    int kiek;
    kiek = maisai[max]/m+1;
    return kiek;
}

void Isvedimas(int n, int m, int maisai[])
{
    ofstream duomenys("Rez1.txt");
    int max = Daugiausiai(n, m, maisai);
    int reisai = Reisai(n, m, maisai);
    int kiek = KiekKartuVaziavo(n, m, maisai, max);

    duomenys << reisai << endl;

    duomenys << maisai[max] << " " << kiek << endl;
    duomenys.close();
}

int Funkcija(float n)
{
    if(int(n)<n)
        return int(n)+1;
    else return int(n);
}

