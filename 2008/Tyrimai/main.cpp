#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

void Nuskaitymas(int&n, int marsrutoNumeris[], int keleiviuSkaicius[]);
void Rikiavimas(int n, int marsrutoNumeris[], int keleiviuSkaicius[]);
void Sutraukimas(int& n, int marsrutoNumeris[], int keleiviuSkaicius[], int islipo[]);
void Islipo(int n, int marsrutoNumeris[], int keleiviuSkaicius[], int islipo[]);
int DaugiausiaKeleiviu(int n, int keleiviuSkaicius[]);
void Isvedimas(int n, int marsrutoNumeris[], int keleiviuSkaicius[], int islipo[]);


int main()
{
    int n, marsrutoNumeris[100], keleiviuSkaicius[100], islipo[100]= {0};
    Nuskaitymas(n, marsrutoNumeris, keleiviuSkaicius);
    Rikiavimas(n, marsrutoNumeris, keleiviuSkaicius);
    Islipo(n, marsrutoNumeris, keleiviuSkaicius, islipo);
    Sutraukimas(n, marsrutoNumeris, keleiviuSkaicius, islipo);
    Isvedimas(n, marsrutoNumeris, keleiviuSkaicius, islipo);
    return 0;
}

void Nuskaitymas(int&n, int marsrutoNumeris[], int keleiviuSkaicius[])
{
    ifstream duomenys("U1.txt");
    duomenys >> n;
    for(int i=0; i<n; i++)
    {
        duomenys >> marsrutoNumeris[i] >> keleiviuSkaicius[i];
    }
    duomenys.close();
}

void Rikiavimas(int n, int marsrutoNumeris[], int keleiviuSkaicius[])
{
    for(int i=0; i<n-1; i++)
    {
        int min = i;
        for(int j=i+1; j<n; j++)
        {
            if(marsrutoNumeris[min]>marsrutoNumeris[j]) min = j;
        }
        if(i!=min)
        {
            swap(marsrutoNumeris[i], marsrutoNumeris[min]);
            swap(keleiviuSkaicius[i], keleiviuSkaicius[min]);
        }
    }
}

void Sutraukimas(int& n, int marsrutoNumeris[], int keleiviuSkaicius[], int islipo[])
{
    for(int i=0; i<n-1; i++)
    {
        if(marsrutoNumeris[i]== marsrutoNumeris[i+1])
        {
            keleiviuSkaicius[i]+=keleiviuSkaicius[i+1];
            islipo[i]+=islipo[i+1];
            for(int j=i+1; j<n-1; j++)
            {

                marsrutoNumeris[j] = marsrutoNumeris[j+1];
                keleiviuSkaicius[j] = keleiviuSkaicius[j+1];
                islipo[j] = islipo[j+1];
            }
            i--;
            n--;
        }
    }
}

int DaugiausiaKeleiviu(int n, int keleiviuSkaicius[])
{
    int max = 0;
    for(int i=0; i<n; i++)
    {
        if(keleiviuSkaicius[i]>keleiviuSkaicius[max]) max = i;
    }
    return max;
}

void Islipo(int n, int marsrutoNumeris[], int keleiviuSkaicius[], int islipo[])
{
    for(int i=0; i<n; i++)
    {
        if(keleiviuSkaicius[i]<0)
        {
            islipo[i]+= keleiviuSkaicius[i];
            keleiviuSkaicius[i]=0;
        }
    }
}

void Isvedimas(int n, int marsrutoNumeris[], int keleiviuSkaicius[], int islipo[])
{
    for(int i=0; i<n; i++)
    {
        cout << marsrutoNumeris[i] << " " ;
    }
    cout << endl;
    for(int i=0; i<n; i++)
    {
        cout << keleiviuSkaicius[i] << " ";
    }
    cout << endl;
    for(int i=0; i<n; i++)
    {
        cout << islipo[i] << " ";
    }
    cout << endl;
    int max = DaugiausiaKeleiviu(n, keleiviuSkaicius);
    cout << marsrutoNumeris[max] << endl;
}

// abs() moduliui (absoliutine reiksme)
<string.h> = strcmp (String compare), strcpy(a<-b);
