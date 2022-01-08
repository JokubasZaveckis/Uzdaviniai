#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Elektra
{
    int dalis;
    int varza[50];
    float daliesVarza;
};

void Nuskaitymas(int&n, Elektra grandine[]);
void DaliesVarza(int n, Elektra grandine[]);
float BendraVarza(int n, Elektra grandine[]);
void Isvedimas(int n, Elektra grandine[]);

int main()
{
    Elektra grandine[100];
    int n;
    Nuskaitymas(n, grandine);
    DaliesVarza(n, grandine);
    Isvedimas(n, grandine);
    return 0;
}

void Nuskaitymas(int&n, Elektra grandine[])
{
    ifstream duomenys("duom1.txt");
    duomenys >> n;
    for(int i=0; i<n; i++)
    {
        duomenys >> grandine[i].dalis;
        for(int j=0; j<grandine[i].dalis; j++)
        {
            duomenys >> grandine[i].varza[j];
        }
    }
    duomenys.close();
}

void DaliesVarza(int n, Elektra grandine[])
{
    for(int i=0; i<n; i++)
    {
        float suma=0;
        for(int j=0; j<grandine[i].dalis; j++)
        {
            suma += 1.0/grandine[i].varza[j];
        }
        grandine[i].daliesVarza = suma;
    }
}

float BendraVarza(int n, Elektra grandine[])
{
    float suma =0;
    for(int i=0; i<n; i++)
    {
        suma += 1.0/grandine[i].daliesVarza;
    }
    return suma;
}

void Isvedimas(int n, Elektra grandine[])
{
    float suma = BendraVarza(n, grandine);
    cout << fixed << setprecision(2) << suma << endl;
}

