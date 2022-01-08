#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Mokiniai
{
    char vardas[21];
    int pazymiai[15];
    float vidurkis;
};

void Nuskaitymas(int& n, int &p, float& v, Mokiniai mokykla[]);
void Vidurkiai (int n, float v, int p, Mokiniai mokykla[]);
void Isvedimas(int n, float v, int p, Mokiniai mokykla[]);
int Pirmunai(int n, float v, Mokiniai mokykla[]);
float Vidurkis(int p, int pazymiai[]);

int main()
{
    int n, p;
    float v;
    Mokiniai mokykla[100];
    Nuskaitymas(n, p, v, mokykla);
    Vidurkiai (n, v, p, mokykla);
    Isvedimas(n, v, p, mokykla);
    return 0;
}

void Nuskaitymas(int& n, int &p, float& v, Mokiniai mokykla[])
{
    ifstream duomenys("duom2.txt");
    duomenys >> n >> p >> v;
    for(int i=0; i<n; i++)
    {
        duomenys.ignore(256,'\n');
        duomenys.get (mokykla[i].vardas, 21);
        for(int j=0; j<p; j++)
        {
            duomenys >> mokykla[i].pazymiai[j];
        }
    }
    duomenys.close();
}

void Vidurkiai (int n, float v, int p, Mokiniai mokykla[])
{
    for(int i=0; i<n; i++)
    {
        mokykla[i].vidurkis = Vidurkis(p, mokykla[i].pazymiai);
    }
}

void Isvedimas(int n, float v, int p, Mokiniai mokykla[])
{
    ofstream duomenys("Rez2.txt");
    for (int i=0; i<n; i++)
    {
        duomenys << fixed << setprecision(1) << mokykla[i].vardas << " " << mokykla[i].vidurkis << endl;
    }
    duomenys << Pirmunai(n, v, mokykla) << endl;

    duomenys.close();
}

int Pirmunai(int n, float v, Mokiniai mokykla[])
{
    int kiek =0;
    for(int i=0; i<n; i++)
    {
        if(mokykla[i].vidurkis>=v) kiek++;
    }
    return kiek;
}

float Vidurkis(int p, int pazymiai[])
{
    float vidurkis;
    int suma=0;
    for(int i=0; i<p; i++)
    {
        suma += pazymiai[i];
    }
    vidurkis = suma*1.0/p;
    return vidurkis;
}

/*int Laikas(float atstumas, float greitis){
return trunc(atstumas / greitis *60) trunc pakaitalioti
http://www.cplusplus.com/reference/cmath/round/
}




