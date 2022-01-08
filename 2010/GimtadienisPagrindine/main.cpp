#include <iostream>
#include <fstream>

using namespace std;

struct Produktas
{
    char Pavadinimas[16];
    int reikalinguProduktuSarasas[10];
    int zmogausKaina=0;
};

void Nuskaitymas(int& N, int& P, int produktuKainos[], Produktas maistas[]);
int VienosSumosKaina(int P, int produktuKainos[], int reikalinguProduktuSarasas[]);
void SumosPerkelimasIMasyva(int N, int P, int produktuKainos[], Produktas maistas[]);
int BendraSuma(int N, Produktas maistas[]);
void Isvedimas(int N, int P, Produktas maistas[]);

int main()
{
    int N, P, produktuKainos[10];
    Produktas maistas[12];

    Nuskaitymas(N, P, produktuKainos, maistas);
    SumosPerkelimasIMasyva(N, P, produktuKainos, maistas);
    Isvedimas(N, P, maistas);

    return 0;
}

void Nuskaitymas(int& N, int& P, int produktuKainos[], Produktas maistas[])
{
    ifstream duomenys("duomenys.txt");
    duomenys >> N >> P;
    for(int i=0; i<N; i++)
    {
        duomenys >> produktuKainos[i];
    }
    for(int i=0; i<P; i++)
    {
        duomenys.ignore(256, '\n');
        duomenys.get(maistas[i].Pavadinimas, 16);
        for(int j=0; j<N; j++)
        {
            duomenys >> maistas[i].reikalinguProduktuSarasas[j];
        }
    }
    duomenys.close();
}

int VienosSumosKaina(int P, int produktuKainos[], int reikalinguProduktuSarasas[])
{
    int suma=0;
    for(int i=0; i<P; i++)
    {
        suma+= produktuKainos[i]*reikalinguProduktuSarasas[i];
    }
    return suma;
}

void SumosPerkelimasIMasyva(int N, int P, int produktuKainos[], Produktas maistas[])
{
    for(int i=0; i<N; i++)
    {
        maistas[i].zmogausKaina=VienosSumosKaina(N, produktuKainos, maistas[i].reikalinguProduktuSarasas);
    }
}

int BendraSuma(int N, Produktas maistas[])
{
    int suma=0;
    for(int i=0; i<N; i++)
    {
        suma+=maistas[i].zmogausKaina;
    }
    return suma;
}

void Isvedimas(int N, int P, Produktas maistas[])
{
    ofstream rezultatai("rezultatai.txt");
    for(int i=0; i<P; i++)
    {
        cout << maistas[i].Pavadinimas << " " << maistas[i].zmogausKaina << endl;
        rezultatai << maistas[i].Pavadinimas << " " << maistas[i].zmogausKaina << endl;
    }


    int suma = BendraSuma(P, maistas);
    cout << suma/100 << " " << suma%100 << endl;
    rezultatai << suma/100 << " " << suma%100 << endl;
    rezultatai.close();
}

