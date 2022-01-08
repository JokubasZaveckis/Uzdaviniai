#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string.h>
#include <stdlib.h>

using namespace std;

const char ATITIKMENYS[]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

struct Piesinys
{
    char SesioliktainisSkaicius[7];
    int DesimtainisSkaicius[3]= {0};
};


void Nuskaitymas(int& a, int&b, Piesinys*& kodai);
int Konvertavimas(char kodas[]);
void Skaiciavimai(int a, int b, Piesinys*& kodas);
char* substr(char str[], int pos, int count);
void Isvedimas(int a, int b, Piesinys*& kodas);

int main()
{
    int a, b;
    Piesinys* kodai=nullptr;

    Nuskaitymas(a, b, kodai);
    Skaiciavimai(a, b, kodai);
    Isvedimas(a, b, kodai);

    delete[] kodai;
    return 0;
}

void Nuskaitymas(int& a, int&b, Piesinys*& kodai)
{
    ifstream duomenys("duomenys.txt");
    duomenys >> a >> b;
    kodai = new Piesinys[a*b];
    for(int i=0; i<a*b; i++)
    {
        duomenys >> kodai[i].SesioliktainisSkaicius;
        //cout << kodai[i].SesioliktainisSkaicius << endl;
    }
    duomenys.close();
}

int Konvertavimas(char SesioliktainisSkaicius[])
{
    int c, d=0;
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<16; j++)
        {
            if(SesioliktainisSkaicius[i]==ATITIKMENYS[j])
            {
                c=j;
                j=15;
            }
        }
        if(i==0)
        {
            d=c*16;
        }
        else
        {
            d+=c;
        }
        //cout << SesioliktainisSkaicius[i] << " ";
        //cout << d << endl;
    }
    return d;
}

void Skaiciavimai(int a, int b, Piesinys*& kodai)
{
    for(int i=0; i<a*b; i++)
    {
        for(int j=0; j<3; j++)
        {
            kodai[i].DesimtainisSkaicius[j]=Konvertavimas(substr(kodai[i].SesioliktainisSkaicius, j*2, 2));
        }
    }
}

char* substr(char str[], int pos, int count)
{
    char* Masyvas = new char[count];
    int a=0;
    for(int i=pos; i<pos+count; i++)
    {
        Masyvas[a++]=str[i];
    }
    return Masyvas;

}

/*void Skaiciavimai(int a, int b, Piesinys*& kodai)
{
    for(int i=0; i<a*b; i++)
    {
        for(int j=0; j<3; j++)
        {
            kodai[i].DesimtainisSkaicius[j]=Konvertavimas(kodai[i].SesioliktainisSkaicius.substr(j*2,2));
        }
    }
}*/

void Isvedimas(int a, int b, Piesinys*& kodas)
{
    for(int i=0; i<a*b; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout << kodas[i].DesimtainisSkaicius[j] << " ";
        }
        if((i+1)%b==0)
        {
            cout << endl;
        }
        else cout << "; ";
    }
}

