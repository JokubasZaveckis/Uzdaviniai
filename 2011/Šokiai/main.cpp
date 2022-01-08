#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Sokejas
{
    char vardas[21];
    int technikosBalai[10];
    int artistiskumoBalai[10];
    int balai=0;
    int maziausiasTechnikosBalas;
    int didziausiasTenchinkosBalas;
    int maziausiasArtistiskumoBalas;
    int didziausiasArtistiskumoBalas;
};

void Nuskaitymas(int& n, int&k, int& m, Sokejas sokejai[]);
int VisuBaluSkaiciavimas(int teisejuSkaicius, int taskai[]);
void MaziausiuBaluSkaiciavimas(int n, int k, int m, Sokejas sokejai[]);
void DidziausiuBaluSkaiciavimas(int n, int k, int m, Sokejas sokejai[]);
void GalutiniuPorosBaluSkaiciavimas(int n, int k, int m, Sokejas sokejai[]);
void Rikiavimas(int n, Sokejas sokejai[]);
void Isvedimas (int n, Sokejas sokejai[]);

int main()
{
    int n, k, m;
    Sokejas sokejai[50];

    Nuskaitymas(n, k, m, sokejai);
    MaziausiuBaluSkaiciavimas(n, k, m, sokejai);
    DidziausiuBaluSkaiciavimas(n, k, m, sokejai);
    GalutiniuPorosBaluSkaiciavimas(n, k, m, sokejai);
    Rikiavimas(n, sokejai);
    Isvedimas (n, sokejai);

    return 0;

}

void Nuskaitymas(int& n, int&k, int& m, Sokejas sokejai[])
{
    ifstream duomenys("duomenys.txt");
    duomenys >> n >> k >> m;
    for(int i=0; i<n; i++)
    {
        duomenys.ignore(256, '\n');
        duomenys.get(sokejai[i].vardas, 21);
        for(int j=0; j<k; j++)
        {
            duomenys >> sokejai[i].technikosBalai[j];
        }
        for(int j=0; j<m; j++)
        {
            duomenys >> sokejai[i].artistiskumoBalai[j];
        }
    }
    duomenys.close();
}

int VisuBaluSkaiciavimas(int teisejuSkaicius, int taskai[])
{
    int suma=0;
    for(int i=0; i<teisejuSkaicius; i++)
    {
        suma+=taskai[i];
    }
    return suma;
}

void MaziausiuBaluSkaiciavimas(int n, int k, int m, Sokejas sokejai[])
{
    for(int i=0; i<n; i++)
    {
        int min=0;
        for(int j=0; j<k; j++)
        {
            if(sokejai[i].technikosBalai[j]<sokejai[i].technikosBalai[min]) min=j;

            sokejai[i].maziausiasTechnikosBalas=sokejai[i].technikosBalai[min];
        }
        int min2=0;
        for(int j=0; j<k; j++)
        {
            if(sokejai[i].artistiskumoBalai[j]<sokejai[i].artistiskumoBalai[min2]) min2=j;

            sokejai[i].maziausiasArtistiskumoBalas=sokejai[i].artistiskumoBalai[min2];
        }
    }
}

void DidziausiuBaluSkaiciavimas(int n, int k, int m, Sokejas sokejai[])
{
    for(int i=0; i<n; i++)
    {
        int max=0;
        for(int j=0; j<m; j++)
        {
            if(sokejai[i].technikosBalai[j]>sokejai[i].technikosBalai[max]) max=j;

            sokejai[i].didziausiasTenchinkosBalas=sokejai[i].technikosBalai[max];
        }
        int max2=0;
        for(int j=0; j<m; j++)
        {
            if(sokejai[i].artistiskumoBalai[j]>sokejai[i].artistiskumoBalai[max2]) max2=j;

            sokejai[i].didziausiasArtistiskumoBalas=sokejai[i].artistiskumoBalai[max2];
        }
    }
}

void GalutiniuPorosBaluSkaiciavimas(int n, int k, int m, Sokejas sokejai[])
{
    for(int i=0; i<n; i++)
    {
        int a = VisuBaluSkaiciavimas(k, sokejai[i].technikosBalai);
        int b = VisuBaluSkaiciavimas(m, sokejai[i].artistiskumoBalai);

        sokejai[i].balai=a-sokejai[i].didziausiasTenchinkosBalas-sokejai[i].maziausiasTechnikosBalas+b-sokejai[i].didziausiasArtistiskumoBalas-sokejai[i].maziausiasArtistiskumoBalas;
    }
}

void Rikiavimas(int n, Sokejas sokejai[])
{
    for (int i=0; i<n-1; i++)
    {
        int max=i;
        for (int j=i+1; j<n; j++)
        {
            if(sokejai[max].balai<sokejai[j].balai)
            {
                max=j;
            }
        }
        if (max!=i)
        {
            swap (sokejai[max], sokejai[i]);
        }
    }
}

void Isvedimas (int n, Sokejas sokejai[])
{
    ofstream rezultatai("rezultatai.txt");
    for(int i=0; i<n; i++)
    {
        cout << sokejai[i].vardas << " " << sokejai[i].balai << endl;
        rezultatai << sokejai[i].vardas << " " << sokejai[i].balai << endl;
    }
    rezultatai.close();
}
