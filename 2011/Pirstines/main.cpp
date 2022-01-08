#include <iostream>
#include <fstream>

using namespace std;

void Nuskaitymas(int&n, int lytis[], int dydis[], int puse[]);
int Skaiciavimai(int& n, int dydziai[], int lytys[], int puses[], int dydis, int lytis);
void Trinimas(int n, int istrinti, int masyvas[]);
void Isvedimas(int n, int dydziai[], int lytys[], int puses[]);

int main()
{
    int n, lytis[100], dydis[100], puse[100];

    Nuskaitymas(n, lytis, dydis, puse);
    Isvedimas(n, dydis, lytis, puse);


    return 0;
}

void Nuskaitymas(int&n, int lytis[], int dydis[], int puse[])
{
    ifstream duomenys("duomenys.txt");
    duomenys >> n;
    for(int i=0; i<n; i++)
    {
        duomenys >> lytis[i] >>  puse[i] >> dydis[i];
    }
    duomenys.close();
}

int Skaiciavimai(int& n, int dydziai[], int lytys[], int puses[], int dydis, int lytis)
{
    int kiek=0;
    for(int i=0; i<n-1; i++)
    {
        if(dydziai[i]==dydis && lytys[i]==lytis)
        {
            for(int j=i+1; j<n; j++)
            {
                if(dydziai[j]==dydis && lytys[j]==lytis && puses[i]!=puses[j])
                {
                    //cout << endl;
                    //cout << "|" << dydis << " " << dydziai[j] << " " << lytis << " " << lytys[j] << " " << puses[j] << " " << puses[i] << "|" << endl;
                    Trinimas(n, i, dydziai);
                    Trinimas(n, j-1, dydziai);
                    Trinimas(n, i, lytys);
                    Trinimas(n, j-1, lytys);
                    Trinimas(n, i, puses);
                    Trinimas(n, j-1, puses);
                    kiek++;
                    n-=2;
                    j--;
                }
            }
        }
    }
    return kiek;
}

void Trinimas(int n, int istrinti, int masyvas[])
{
    for(int i=istrinti; i<n-1; i++)
    {
        masyvas[i]=masyvas[i+1];
    }
}

void Isvedimas(int n, int dydziai[], int lytys[], int puses[])
{
    for(int i=0; i<n; i++)
    {
        int dydis=dydziai[i];
        cout << dydis << " " <<  Skaiciavimai(n, dydziai, lytys, puses, dydis, 4) << " " <<  Skaiciavimai(n, dydziai, lytys, puses, dydis, 3) << endl;
    }
}
