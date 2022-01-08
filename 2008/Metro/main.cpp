#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void Nuskaitymas(int& n, int stotiesNumeris[], int dienosNumeris[], int iejeKeleiviai[], int isejeKeleiviai[]);
void Sutraukimas(int& n, int stotiesNumeris[], int iejeKeleiviai[], int isejeKeleiviai[]);
void Isvedimas(int n, int stotiesNumeris[], int iejeKeleiviai[], int isejeKeleiviai[]);
int DaugiausiaiPraejo(int n, int stotiesNumeris[], int iejeKeleiviai[], int isejeKeleiviai[]);
int PraejeKeleiviai(int n, int stotiesNumeris[], int iejeKeleiviai[], int isejeKeleiviai[]);
void Rikiavimas (int n, int stotiesNumeris[], int dienosNumeris[], int iejeKeleiviai[], int isejeKeleiviai[]);

int main()
{
    int n;
    int stotiesNumeris[100], dienosNumeris[100], iejeKeleiviai[100], isejeKeleiviai[100];
    Nuskaitymas(n, stotiesNumeris, dienosNumeris, iejeKeleiviai, isejeKeleiviai);
    Rikiavimas (n, stotiesNumeris, dienosNumeris, iejeKeleiviai, isejeKeleiviai);
    Sutraukimas(n, stotiesNumeris, iejeKeleiviai, isejeKeleiviai);
    Isvedimas(n, stotiesNumeris, iejeKeleiviai, isejeKeleiviai);
}

void Nuskaitymas(int& n, int stotiesNumeris[], int dienosNumeris[], int iejeKeleiviai[], int isejeKeleiviai[])
{
    ifstream duomenys("U1.txt");
    duomenys >> n;
    for(int i=0; i<n; i++)
    {
        duomenys >> stotiesNumeris[i] >> dienosNumeris[i] >> iejeKeleiviai[i] >> isejeKeleiviai[i];
    }
    duomenys.close();
}

void Rikiavimas (int n, int stotiesNumeris[], int dienosNumeris[], int iejeKeleiviai[], int isejeKeleiviai[])
{
    for(int i=0; i<n-1; i++)
    {
        int max=i;
        for(int j=i+1; j<n; j++)
        {
            if(stotiesNumeris[max]>stotiesNumeris[j])
            max = j;
        }
        if(i!=max)
        {
        swap(stotiesNumeris[i], stotiesNumeris[max]);
        swap(iejeKeleiviai[i], iejeKeleiviai[max]);
        swap(isejeKeleiviai[i], isejeKeleiviai[max]);
        }
    }
}

void Sutraukimas(int& n, int stotiesNumeris[], int iejeKeleiviai[], int isejeKeleiviai[])
{
    for(int i=0; i<n-1; i++)
    {
        if(stotiesNumeris[i]==stotiesNumeris[i+1])
        {
            iejeKeleiviai[i]+=iejeKeleiviai[i+1];
            isejeKeleiviai[i]+=isejeKeleiviai[i+1];
            for(int j=i+1; j<n-1; j++)
            {
                stotiesNumeris[j]=stotiesNumeris[j+1];
                iejeKeleiviai[j]= iejeKeleiviai[j+1];
                isejeKeleiviai[j]=isejeKeleiviai[j+1];
            }
            i--;
            n--;
        }
    }
}

int DaugiausiaiPraejo(int n, int stotiesNumeris[], int iejeKeleiviai[], int isejeKeleiviai[])
{
    int max = 0;
    for(int i=0; i<n; i++)
    {
        if(iejeKeleiviai[i]+isejeKeleiviai[i]>isejeKeleiviai[max]+iejeKeleiviai[max]) max = i;
    }

    return max;
}

int PraejeKeleiviai(int n, int stotiesNumeris[], int iejeKeleiviai[], int isejeKeleiviai[])
{
    int suma = 0;
    for(int i=0; i<n; i++)
    {
        suma +=iejeKeleiviai[i];
    }
    return suma;
}

void Isvedimas(int n, int stotiesNumeris[], int iejeKeleiviai[], int isejeKeleiviai[])
{
    int max = DaugiausiaiPraejo(n, stotiesNumeris, iejeKeleiviai, isejeKeleiviai);
    int suma = PraejeKeleiviai(n, stotiesNumeris, iejeKeleiviai, isejeKeleiviai);

    for(int i=0; i<n; i++)
    {
        cout << stotiesNumeris[i] << " ";
    }
    cout << endl;
    for(int i=0; i<n; i++)
    {
        cout << iejeKeleiviai[i]+isejeKeleiviai[i] << " ";
    }
    cout << endl;
    cout << stotiesNumeris[max]<< endl;
    cout << suma << endl;
}

