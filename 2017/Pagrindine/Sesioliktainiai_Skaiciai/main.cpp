#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>

using namespace std;

struct Piesinys
{
    int DesimtainisSkaicius[3];
    char* SesioliktainisSkaicius=nullptr;
    string Sesioliktainis;


    ~Piesinys()
    {
        delete[] SesioliktainisSkaicius;
    }
};

void Nuskaitymas(int& a, int&b, Piesinys*& skaiciai);
char* VienoDesimtainioKonvertavimas(char DesimtainisSkaicius[]);
void Skaiciavimai(int a, int b, Piesinys*& skaiciai);
void Isvedimas(int a, int b, Piesinys*& skaiciai);
string Konvertavimas(int DesimtainisSkaicius);
char RaidesGrazinimas(int skaicius);

int main()
{
    int a, b;
    Piesinys* skaiciai=nullptr;

    Nuskaitymas(a, b, skaiciai);
    Skaiciavimai(a, b, skaiciai);
    Isvedimas(a, b, skaiciai);

    delete[] skaiciai;
    return 0;
}

void Nuskaitymas(int& a, int&b, Piesinys*& skaiciai)
{
    ifstream duomenys("duomenys.txt");
    duomenys >> a >> b;
    skaiciai = new Piesinys[a*b];
    for(int i=0; i<a*b; i++)
    {
        for(int j=0; j<3; j++)
        {
            duomenys >> skaiciai[i].DesimtainisSkaicius[j];
        }
    }
    duomenys.close();
}

char RaidesGrazinimas(int skaicius)
{
    if(skaicius>=10)
    {
        if(skaicius==10)
        {
            return'A';
        }
        if(skaicius==11)
        {
            return'B';
        }
        if(skaicius==12)
        {
            return'C';
        }
        if(skaicius==13)
        {
            return'D';
        }
        if(skaicius==14)
        {
            return'E';
        }
        if(skaicius==15)
        {
            return'F';
        }
    }
    else return skaicius+48;
}

string Konvertavimas(int DesimtainisSkaicius)
{
    int pirmas, antras;
    pirmas=DesimtainisSkaicius/16;
    antras=DesimtainisSkaicius%16;
    string h;

    h+=RaidesGrazinimas(pirmas);
    h+=RaidesGrazinimas(antras);

    /*h.push_back(RaidesGrazinimas(pirmas));
    h.push_back(RaidesGrazinimas(antras));*/


    /*h[0]=RaidesGrazinimas(pirmas);
    h[1]=RaidesGrazinimas(antras);
    h[2]='\0';*/

    return h;
}


char* VienoDesimtainioKonvertavimas(int DesimtainisSkaicius[])
{
    char* Sesioliktainis = new char[7];

    Sesioliktainis[0]=DesimtainisSkaicius[0]/16;
    Sesioliktainis[1]=DesimtainisSkaicius[0]%16;
    Sesioliktainis[2]=DesimtainisSkaicius[1]/16;
    Sesioliktainis[3]=DesimtainisSkaicius[1]%16;
    Sesioliktainis[4]=DesimtainisSkaicius[2]/16;
    Sesioliktainis[5]=DesimtainisSkaicius[2]%16;

    for(int i=0; i<6; i++)
    {
        if(Sesioliktainis[i]>=10)
        {
            if(Sesioliktainis[i]==10)
            {
                Sesioliktainis[i]='A';
            }
            if(Sesioliktainis[i]==11)
            {
                Sesioliktainis[i]='B';
            }
            if(Sesioliktainis[i]==12)
            {
                Sesioliktainis[i]='C';
            }
            if(Sesioliktainis[i]==13)
            {
                Sesioliktainis[i]='D';
            }
            if(Sesioliktainis[i]==14)
            {
                Sesioliktainis[i]='E';
            }
            if(Sesioliktainis[i]==15)
            {
                Sesioliktainis[i]='F';
            }
        }
    }
    return Sesioliktainis;
}

void Skaiciavimai(int a, int b, Piesinys*& skaiciai)
{
    for(int i=0; i<a*b; i++)
    {
        //skaiciai[i].SesioliktainisSkaicius = VienoDesimtainioKonvertavimas(skaiciai[i].DesimtainisSkaicius);
        for(int j=0; j<3; j++)
        {
            skaiciai[i].Sesioliktainis+=Konvertavimas(skaiciai[i].DesimtainisSkaicius[j]);
        }
    }
}

void Isvedimas(int a, int b, Piesinys*& skaiciai)
{

    for(int i=0; i<a*b; i++)
    {
        cout << skaiciai[i].Sesioliktainis << endl;
    }
    /*for(int i=0; i<a*b; i++)
    {
        for(int j=0; j<6; j++)
        {
            if((int)skaiciai[i].SesioliktainisSkaicius[j]<=10)
            {
                cout << (int)skaiciai[i].SesioliktainisSkaicius[j];
            }
            else cout << skaiciai[i].SesioliktainisSkaicius[j];
        }
        cout << endl;
    }*/
}









