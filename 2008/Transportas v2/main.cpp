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
void Skaiciavimai(int bendrasMasyvas[], Stotele stotele[], int& kiek, int n);
int Ilgiausias(int kiek, int bendrasMasyvas[]);
bool ArTuriMarsruta(int max, Stotele stotele);
void Isvedimas(int kiek, int bendrasMasyvas[], Stotele stotele[], int n);

int main()
{
    Stotele stotele[100];
    int n, bendrasMasyvas[10000]= {0}, kiek=0;
    Nuskaitymas(n, stotele);
    Skaiciavimai(bendrasMasyvas, stotele, kiek, n);
    Isvedimas(kiek, bendrasMasyvas, stotele, n);
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

void Skaiciavimai(int bendrasMasyvas[], Stotele stotele[], int& kiek, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<stotele[i].numeriuSkaicius; j++)
        {
            bendrasMasyvas[stotele[i].marsrutuNumeriai[j]]++;
            if(stotele[i].marsrutuNumeriai[j]>kiek) kiek=stotele[i].marsrutuNumeriai[j];
        }
    }
}

int Ilgiausias(int kiek, int bendrasMasyvas[])
{
    int max = 0;
    for(int i=0; i<kiek; i++)
    {
        if(bendrasMasyvas[i]>bendrasMasyvas[max]) max = i;
    }
    return max;
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


void Isvedimas(int kiek, int bendrasMasyvas[], Stotele stotele[], int n)
{
    int max = Ilgiausias(kiek, bendrasMasyvas);
    cout << max << endl;
    for(int i=0; i<n; i++)
    {
        if(ArTuriMarsruta(max, stotele[i]))
        {
            cout << stotele[i].pavadinimas << endl;
        }
    }

}
