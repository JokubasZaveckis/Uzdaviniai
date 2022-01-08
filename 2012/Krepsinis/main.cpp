#include <iostream>
#include <fstream>

using namespace std;

struct Zaidejas
{
    int numeris;
    int laikuSkaicius;
    int laikai[40];
    int prazaistaAiskteleje=0;
    int sedejoAntSuoliuko=0;

};

void Nuskaitymas(int&n, Zaidejas zaidejai[]);
void StartinioPenketoPaieska(int n, Zaidejas zaidejai[], int startinisPenketas[]);
void PrazaistoArPrasedetoLaikoSkaiciavimas(int n, Zaidejas zaidejai[]);
int IlgiausiaiZaidusioZaidejoPaieska(int n, Zaidejas zaidejai[]);
int IlgiausiaiSedejusioZaidejoPaieska(int n, Zaidejas zaidejai[]);
void Isvedimas(int n, int startinisPenketas[], Zaidejas zaidejai[]);
void Rikiavimas(int n, Zaidejas zaidejai[]);

int main()
{
    int n, startinisPenketas[5];
    Zaidejas zaidejai[12];

    Nuskaitymas(n, zaidejai);
    Rikiavimas(n, zaidejai);
    StartinioPenketoPaieska(n, zaidejai, startinisPenketas);
    PrazaistoArPrasedetoLaikoSkaiciavimas(n, zaidejai);
    Isvedimas(n, startinisPenketas, zaidejai);
}

void Nuskaitymas(int&n, Zaidejas zaidejai[])
{
    ifstream duomenys("duomenys.txt");
    duomenys >> n;
    for(int i=0; i<n; i++)
    {
        duomenys >> zaidejai[i].numeris >> zaidejai[i].laikuSkaicius;
        //cout << zaidejai[i].numeris << " " << zaidejai[i].laikuSkaicius << " ";
        for(int j=0; j<zaidejai[i].laikuSkaicius; j++)
        {
            duomenys >> zaidejai[i].laikai[j];
            //cout << zaidejai[i].laikai[j] << " ";
        }
        //cout << endl;
    }
    duomenys.close();
}

void Rikiavimas(int n, Zaidejas zaidejai[])
{
    for (int i=0; i<n-1; i++)
    {
        int min=i;
        for (int j=i+1; j<n; j++)
        {
            if(zaidejai[min].numeris>zaidejai[j].numeris)
            {
                min=j;
            }
        }
        if(min!=i)
        {
            swap(zaidejai[min], zaidejai[i]);
        }
    }
}

/*void Rikiavimas(int n, Zaidejas zaidejai[], int startinisPenketas[])
{
    for(int i=0; i<n-1; i++)
    {
        int min=i;
        for (int j=i+1; j<n; j++)
        {
            if(startinisPenketas[j]<startinisPenketas[min])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            swap(zaidejai[min].numeris, zaidejai[i].numeris);
        }
    }
}*/

void StartinioPenketoPaieska(int n, Zaidejas zaidejai[], int startinisPenketas[])
{
    int a=0;
    for(int i=0; i<n; i++)
    {
        if(zaidejai[i].laikai[0]>0)
        {
            startinisPenketas[a++]=zaidejai[i].numeris;
        }
    }
}

void PrazaistoArPrasedetoLaikoSkaiciavimas(int n, Zaidejas zaidejai[])
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<zaidejai[i].laikuSkaicius; j++)
        {
            if(zaidejai[i].laikai[j]>0)
            {
                zaidejai[i].prazaistaAiskteleje+=zaidejai[i].laikai[j];
            }
            else zaidejai[i].sedejoAntSuoliuko+=zaidejai[i].laikai[j];
        }
    }
}

int IlgiausiaiZaidusioZaidejoPaieska(int n, Zaidejas zaidejai[])
{
    int max=0;
    for(int i=0; i<n; i++)
    {
        if(zaidejai[i].prazaistaAiskteleje>zaidejai[max].prazaistaAiskteleje)
            max=i;
    }
    return max;
}

int IlgiausiaiSedejusioZaidejoPaieska(int n, Zaidejas zaidejai[])
{
    int min=0;
    for(int i=0; i<n; i++)
    {
        if(zaidejai[i].sedejoAntSuoliuko<zaidejai[min].sedejoAntSuoliuko)
            min=i;
    }
    return min;
}

void Isvedimas(int n, int startinisPeketas[], Zaidejas zaidejai[])
{
    ofstream rezultatai("rez.txt");
    for(int i=0; i<5; i++)
    {
        cout << startinisPeketas[i] << " ";
        rezultatai << startinisPeketas[i] << " ";
    }
    cout << endl;
    rezultatai << endl;

    int max=IlgiausiaiZaidusioZaidejoPaieska(n, zaidejai);
    cout << zaidejai[max].numeris << " " << zaidejai[max].prazaistaAiskteleje << endl;
    rezultatai << zaidejai[max].numeris << " " << zaidejai[max].prazaistaAiskteleje << endl;

    int min=IlgiausiaiSedejusioZaidejoPaieska(n, zaidejai);

    if(zaidejai[min].sedejoAntSuoliuko<0)
    {
        cout << zaidejai[min].numeris << " " << zaidejai[min].sedejoAntSuoliuko*-1 <<  endl;
        rezultatai << zaidejai[min].numeris << " " << zaidejai[min].sedejoAntSuoliuko*-1 <<  endl;
    }
    else cout << zaidejai[min].numeris << " " << zaidejai[min].sedejoAntSuoliuko <<  endl;
    else rezultatai << zaidejai[min].numeris << " " << zaidejai[min].sedejoAntSuoliuko <<  endl;

    rezultatai.close();
}
//abs();
