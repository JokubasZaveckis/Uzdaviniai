#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void Nuskaitymas(int&n, int &m, int jurgioZaisliukai[], int linosZaisliukai[]);
void Rikiavimas(int n, int Zaisliukai[]);
void LinosSiulomiZaisliukai(int n, int linosZaisliukai[], int linosSiulomiZaisliukai[], int kiek);
void JurgiausSiulomiZaisliukai (int m, int jurgioZaisliukai[], int jurgioSiulomiZaisliukai[], int& kiekis);
void Isvedimas(int linosSiulomiZaisliukai[], int jurgioSiulomiZaisliukai[], int bendrasSarasas[], int bendras, int kiek, int kiekis);
void ZaisliukaiMainams(int SiulomiZaisliukai[], int ZaisliukaiMainams[], int& kiek, int Zaisliukai[], int m);
void Sarasas(int linosSiulomiZaisliukai[], int jurgioSiulomiZaisliukai[], int bendrasSarasas[], int& bendras, int m, int n);

int main()
{
    int n, m, jurgioZaisliukai[500], linosZaisliukai[500], linosSiulomiZaisliukai[500]={0}, jurgioSiulomiZaisliukai[500]={0}, linosMainuZaisliukai[100], jurgioMainuZaisliukai[100], kiek=0, kiekis=0, bendrasSarasas[500], bendras = 0;;
    Nuskaitymas(n, m, jurgioZaisliukai, linosZaisliukai);
    Rikiavimas(n, linosZaisliukai);
    Rikiavimas(m, jurgioZaisliukai);
    LinosSiulomiZaisliukai(n, linosZaisliukai, linosSiulomiZaisliukai, kiek);
    JurgiausSiulomiZaisliukai (m, jurgioZaisliukai, jurgioSiulomiZaisliukai, kiekis);
    ZaisliukaiMainams(linosSiulomiZaisliukai, linosMainuZaisliukai, kiek, jurgioZaisliukai, m);
    ZaisliukaiMainams(jurgioSiulomiZaisliukai, jurgioMainuZaisliukai, kiekis, linosZaisliukai, n);
    Sarasas(linosZaisliukai, jurgioZaisliukai, bendrasSarasas,  bendras, m, n);
    Isvedimas(linosMainuZaisliukai, jurgioMainuZaisliukai, bendrasSarasas, bendras, kiek, kiekis);
    return 0;
}

void Nuskaitymas(int&n, int &m, int jurgioZaisliukai[], int linosZaisliukai[])
{
    ifstream duomenys("U1duom.txt");
    duomenys >> n >> m;
    for(int i=0; i<n; i++)
    {
        duomenys >> linosZaisliukai[i];
    }
    for(int i=0; i<m; i++)
    {
        duomenys>> jurgioZaisliukai[i];
    }
    duomenys.close();
}

void Rikiavimas(int n, int Zaisliukai[])
{
    for (int i=0; i<n-1; i++)
    {
        int min = i;
        for(int j=i+1; j<n; j++)
        {
            if(Zaisliukai[min]>Zaisliukai[j])
                min = j;
        }
        if(i!=min)
        {
            int tmp = Zaisliukai[i];
            Zaisliukai[i] = Zaisliukai[min];
            Zaisliukai [min] = tmp;
        }
    }
}


void LinosSiulomiZaisliukai(int n, int linosZaisliukai[], int linosSiulomiZaisliukai[], int kiek)
{
    for(int i=0; i<n; i++)
    {
        linosSiulomiZaisliukai[linosZaisliukai[i]]++;
    }
}

void JurgiausSiulomiZaisliukai (int m, int jurgioZaisliukai[], int jurgioSiulomiZaisliukai[], int& kiekis)
{
    for(int i=0; i<m; i++)
    {
        jurgioSiulomiZaisliukai[jurgioZaisliukai[i]]++;
    }
}

void ZaisliukaiMainams(int SiulomiZaisliukai[], int ZaisliukaiMainams[], int& kiek, int Zaisliukai[], int m)
{
    for(int i=0; i<100; i++)
    {
        if(SiulomiZaisliukai[i] > 1)
        {
            int mainai = 0;
            for(int j=0; j<m; j++)
            {
                if(Zaisliukai[j] == i)
                    mainai++;
            }
            if(mainai==0)
                ZaisliukaiMainams[kiek++] = i;
        }
    }
}

void Sarasas(int linosSiulomiZaisliukai[], int jurgioSiulomiZaisliukai[], int bendrasSarasas[], int& bendras, int m, int n)
{
    for(int i=0; i<n; i++)
    {
        bendrasSarasas[bendras++] = linosSiulomiZaisliukai[i];
    }
    for(int i=0; i<m; i++)
    {
        bendrasSarasas[bendras++] = jurgioSiulomiZaisliukai[i];
    }
    Rikiavimas(bendras, bendrasSarasas);
    for(int i=0; i<bendras-1; i++)
    {
        if(bendrasSarasas[i]==bendrasSarasas[i+1])
        {
            for(int j=i; j<bendras-1; j++)
            {
                bendrasSarasas[j]=bendrasSarasas[j+1];
            }
            i--;
            bendras--;
        }
    }
}

void Isvedimas(int linosSiulomiZaisliukai[], int jurgioSiulomiZaisliukai[], int bendrasSarasas[], int bendras, int kiek, int kiekis)
{
    if(kiek ==0) cout << "0" ;
    for(int i=0; i<kiek; i++)
    {
        cout << linosSiulomiZaisliukai[i] << " ";
    }
    cout << endl;
    if(kiekis ==0) cout << " 0" << endl;
    for(int i=0; i<kiekis; i++)
    {
        cout << jurgioSiulomiZaisliukai[i] << " " ;
    }
    cout << endl;
    for(int i=0; i<bendras; i++)
    {
        cout << bendrasSarasas[i] << " ";
    }
}




