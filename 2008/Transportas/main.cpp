#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Stotele
{
    char pavadinimas[21];
    int numeriuSkaicius;
    int marsrutuNumeriai[100];
};

void Nuskaitymas(int& n, Stotele stotele[]);
void Kopijavimas(Stotele stotele[], int n, int bendrasMasyvas[], int& kiek);
int IlgiausiasMarsrutas(int kiek, int bendrasMasyvas[]);
bool ArTuriMarsruta(int max, Stotele stotele);
void Isvedimas(int kiek, int n, Stotele stoteles[], int bendrasMasyvas[]);
void Rikiavimas(int kiek, int bendrasMasyvas[]);
void Sutraukimas(int kiek, int bendrasMasyvas[], int stoteliuKiekis[]);

int main()
{
    Stotele stotele[100];
    int n, bendrasMasyvas[10000], kiek=0;;
    Nuskaitymas(n, stotele);
    Kopijavimas(stotele, n, bendrasMasyvas, kiek);
    Isvedimas(kiek, n, stotele, bendrasMasyvas);
    return 0;

}

void Nuskaitymas(int& n, Stotele stotele[])
{
    ifstream duomenys("U2.txt");
    duomenys >> n;
    for(int i=0; i<n; i++)
    {
        duomenys.ignore(256, '\n');
        duomenys.get(stotele[i].pavadinimas, 21);
        duomenys >> stotele[i].numeriuSkaicius;
        for(int j=0; j<stotele[i].numeriuSkaicius; j++)
        {
            duomenys >> stotele[i].marsrutuNumeriai[j];
        }
    }
    duomenys.close();
}

void Kopijavimas(Stotele stotele[], int n, int bendrasMasyvas[], int& kiek)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<stotele[i].numeriuSkaicius; j++)
        {
            bendrasMasyvas[kiek++]= stotele[i].marsrutuNumeriai[j];
        }
    }
}

void Rikiavimas(int kiek, int bendrasMasyvas[])
{
    for(int i=0; i<kiek-1; i++)
    {
        int min = i;
        for(int j=i+1; j<kiek; j++)
        {
            if(bendrasMasyvas[min]>bendrasMasyvas[j])
            min = j;
        }
        if(min!=i)
        {
            swap(bendrasMasyvas[i], bendrasMasyvas[min]);
        }
    }
}

void Sutraukimas(int kiek, int bendrasMasyvas[], int stoteliuKiekis[])
{
    for(int i=0; i<kiek-1; i++)
    {
        if(bendrasMasyvas[i]==bendrasMasyvas[i+1])
        {
            stoteliuKiekis[i]++;
            for(int j=i+1; j<kiek-1; j++)
            {
                bendrasMasyvas[j]=bendrasMasyvas[j+1];
            }
            i--;
            kiek--;
        }
    }
}
int IlgiausiasMarsrutas(int kiek, int bendrasMasyvas[])
{
    Rikiavimas(kiek, bendrasMasyvas);
    int stoteliuKiekis[10000]={0};
    Sutraukimas(kiek, bendrasMasyvas, stoteliuKiekis);
    int max=0;
    for(int i=0; i<kiek; i++)
    {
        if(stoteliuKiekis[i]>stoteliuKiekis[max])
            max = i;
    }
    return bendrasMasyvas[max];
}

bool ArTuriMarsruta(int max, Stotele stotele)
{
    for(int i=0; i<stotele.numeriuSkaicius; i++)
    {
        if(stotele.marsrutuNumeriai[i]==max)
            return true;
    }
    return false;
}


void Isvedimas(int kiek, int n, Stotele stoteles[], int bendrasMasyvas[])
{
    int max = IlgiausiasMarsrutas(kiek, bendrasMasyvas);
    cout << max << endl;
    for(int i=0; i<kiek; i++)
    {
        if(ArTuriMarsruta(max, stoteles[i]))
        {
            cout << stoteles[i].pavadinimas << endl;
        }
    }
}
