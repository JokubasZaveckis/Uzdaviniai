#include <iostream>
#include <fstream>

using namespace std;

struct Mokinys
{
    int p=0;
    int b=0;
    int z=0;
    int r=0;
    int k=0;
    int v=0;
};

void Nuskaitymas(int& n, Mokinys mokiniai[]);
int GalimiKomplektai(int n, Mokinys mokiniai[]);

int main()
{
    int n;
    Mokinys mokiniai[100];

    Nuskaitymas(n, mokiniai);

    int a = GalimiKomplektai(n, mokiniai);
    cout << a << endl;
}

void Nuskaitymas(int& n, Mokinys mokiniai[])
{
    ifstream duomenys ("duomenys.txt");
    duomenys >> n;
    for(int i=0; i<n; i++)
    {
        duomenys >> mokiniai[i].p >> mokiniai[i].b >> mokiniai[i].z >> mokiniai[i].r >> mokiniai[i].k >> mokiniai[i].v;
    }
    duomenys.close();
}

int GalimiKomplektai(int n, Mokinys mokiniai[])
{
    int suma=0;
    Mokinys visoFiguru;
    int galimiKomplektai[6];
    for(int i=0; i<n; i++)
    {
         visoFiguru.p+=mokiniai[i].p;
         visoFiguru.b+=mokiniai[i].b;
         visoFiguru.z+=mokiniai[i].z;
         visoFiguru.r+=mokiniai[i].r;
         visoFiguru.k+=mokiniai[i].k;
         visoFiguru.v+=mokiniai[i].v;
    }
    galimiKomplektai[0]=visoFiguru.p/8;
    galimiKomplektai[1]=visoFiguru.b/2;
    galimiKomplektai[2]=visoFiguru.z/2;
    galimiKomplektai[3]=visoFiguru.r/2;
    galimiKomplektai[4]=visoFiguru.k/1;
    galimiKomplektai[5]=visoFiguru.v/1;

    int min=0;
    for(int i=0; i<n; i++)
    {
        if(galimiKomplektai[i]<galimiKomplektai[min]) min=i;
    }
    return galimiKomplektai[min];
}

