#include <iostream>
#include <fstream>

using namespace std;

struct Dievas
{
    char vardas[11];
    int taskai[10];
    int taskuSuma=0;
    int lyginiai=0;
};

void Nuskaitymas(int&n, int&k, Dievas dievai[]);
void TaskuSumosSkaiciavimas(int n, int k, Dievas dievai[]);
int DaugiausiaiTaskuSurinkusioDievoRinkimas(int n, Dievas dievai[]);
void Isvedimas(int n, Dievas dievai[]);

int main()
{
    int n, k;
    Dievas dievai[50];

    Nuskaitymas(n, k, dievai);
    TaskuSumosSkaiciavimas(n, k, dievai);
    Isvedimas(n, dievai);

    return 0;
}

void Nuskaitymas(int&n, int&k, Dievas dievai[])
{
    ifstream duomenys("duomenys.txt");
    duomenys >> n >> k;
    for(int i=0; i<n; i++)
    {
        duomenys.ignore(256, '\n');
        duomenys.get(dievai[i].vardas, 11);
        for(int j=0; j<k; j++)
        {
            duomenys >> dievai[i].taskai[j];
        }
    }
    duomenys.close();
}

void TaskuSumosSkaiciavimas(int n, int k, Dievas dievai[])
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<k; j++)
        {
            if(dievai[i].taskai[j]%2==0)
            {
                dievai[i].taskuSuma+=dievai[i].taskai[j];
                dievai[i].lyginiai++;
            }
            else dievai[i].taskuSuma-=dievai[i].taskai[j];
        }
    }
}

int DaugiausiaiTaskuSurinkusioDievoRinkimas(int n, Dievas dievai[])
{
    int max=0;
    for(int i=1; i<n; i++)
    {
        if(dievai[max].taskuSuma<dievai[i].taskuSuma)
            max=i;
        else if(dievai[max].taskuSuma==dievai[i].taskuSuma && dievai[max].lyginiai<dievai[i].lyginiai)
            max=i;
    }
    return max;
}

void Isvedimas(int n, Dievas dievai[])
{
    ofstream rezultatai("rezultatai.txt");
    int max = DaugiausiaiTaskuSurinkusioDievoRinkimas(n, dievai);

    cout << dievai[max].vardas << " " << dievai[max].taskuSuma << endl;
    rezultatai << dievai[max].vardas << " " << dievai[max].taskuSuma << endl;

    rezultatai.close();
}
