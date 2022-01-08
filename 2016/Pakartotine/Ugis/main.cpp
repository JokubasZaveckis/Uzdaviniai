#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

int UgioSuma(int& n);
int Vidurkis(int n, int suma);
int Aukstesni(int suma, int vidurkis);
void Isvedimas(int kiek, int vidurkis);

int main()
{
   int n;
   int suma=UgioSuma(n);
   int vidurkis = Vidurkis(n, suma);
   int kiek = Aukstesni(suma, vidurkis);
   Isvedimas(kiek, vidurkis);

}

int UgioSuma(int& n)
{
    ifstream duomenys("duomenys.txt");
    duomenys >> n;
    int a, suma=0;
    for(int i=0; i<n; i++)
    {
        duomenys >> a;
        suma+=a;
    }
    duomenys.close();
    return suma;
}

int Vidurkis(int n, int suma)
{
    int vidurkis=0;
    while(suma>=n)
    {
        suma-=n;
        vidurkis++;
    }
    return vidurkis;
}

int Aukstesni(int suma, int vidurkis)
{
    ifstream duomenys("duomenys.txt");
    int n, a, kiek=0;
    duomenys >> n;
    for(int i=0; i<n; i++)
    {
        duomenys>>a;
        if(a>vidurkis) kiek++;
    }
    duomenys.close();
    return kiek;
}

void Isvedimas(int kiek, int vidurkis)
{
    ofstream rezultatai("rezultatai.close");
    cout << vidurkis << " " << kiek << endl;
    rezultatai << vidurkis << " " << kiek << endl;
    rezultatai.close();
}
