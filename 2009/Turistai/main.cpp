#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void Nuskaitymas(int &k, int& n, int gilijosSumos[], int egilijosNominalai[]);
int BendraSuma(int k, int gilijosSumos[]);
void Skaiciavimai(int n, int suma, int egilijosNominalai[], int monetuKiekis[]);
int MonetuSuma(int n, int monetuKiekis[]);
int LikePinigai(int n, int suma, int egilijosNominalai[], int monetuKiekis[]);
void Isvedimas(int n, int suma, int egilijosNominalai[], int monetuKiekis[]);

int main()
{
    int k, n, gilijosSumos[30], egilijosNominalai[15], monetuKiekis[15];
    Nuskaitymas(k, n, gilijosSumos, egilijosNominalai);
    int suma = BendraSuma(k, gilijosSumos);
    Skaiciavimai(n, suma, egilijosNominalai, monetuKiekis);
    Isvedimas(n, suma, egilijosNominalai, monetuKiekis);
    return 0;
}

void Nuskaitymas(int &k, int& n, int gilijosSumos[], int egilijosNominalai[])
{
    ifstream duomenys("U1.txt");
    duomenys >> k;
    for(int i=0; i<k; i++)
    {
        duomenys >> gilijosSumos[i];
    }
    duomenys >> n;
    for(int i=0; i<n; i++)
    {
        duomenys >> egilijosNominalai[i];
    }
    duomenys.close();
}

int BendraSuma(int k, int gilijosSumos[])
{
    int suma=0;
    for(int i=0; i<k; i++)
    {
        suma+=gilijosSumos[i];
    }
    return suma;
}

void Skaiciavimai(int n, int suma, int egilijosNominalai[], int monetuKiekis[])
{
    for(int i=0; i<n; i++)
    {
        monetuKiekis[i]=suma/egilijosNominalai[i];
        suma-=monetuKiekis[i]*egilijosNominalai[i];
    }
}

int MonetuSuma(int n, int monetuKiekis[])
{
    int monetuSuma=0;
    for(int i=0; i<n; i++)
    {
        monetuSuma+=monetuKiekis[i];
    }
    return monetuSuma;
}

int LikePinigai(int n, int suma, int egilijosNominalai[], int monetuKiekis[])
{
    for(int i=0; i<n; i++)
    {
        suma-=(egilijosNominalai[i]*monetuKiekis[i]);
    }
    return suma;
}

void Isvedimas(int n, int suma, int egilijosNominalai[], int monetuKiekis[])
{
    ofstream rezultatai("rez.txt");
    int monetos = MonetuSuma(n, monetuKiekis);
    int liko = LikePinigai(n, suma, egilijosNominalai, monetuKiekis);

    rezultatai << suma << endl;
    for(int i=0; i<n; i++)
    {
        rezultatai << egilijosNominalai[i] << " " << monetuKiekis[i] << endl;
    }
    rezultatai << monetos << endl;
    rezultatai << liko << endl;
    rezultatai.close();
}
