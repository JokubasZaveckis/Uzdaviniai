#include <iostream>
#include <fstream>

using namespace std;

struct Grybautojai
{
    char vardai[16];
    int dienos;
    int baravykai[50];
    int raudonikiai[50];
    int lepsiai[50];
    int grybuSuma = 0;
    int baravykuSuma;
    int raudonikiuSuma;
    int lepsiuSuma;
};

void Nuskaitymas(int&n, Grybautojai grybai[]);
void AtskiruGrybuSuma(int n, Grybautojai grybai[]);
void GrybuSuma(int n, Grybautojai grybai[]);
int DaugiausiaiGrybu(int n, Grybautojai grybai[]);
void Isvedimas(int n, Grybautojai grybai[]);

int main()
{
    int n;
    Grybautojai grybai[100];
    Nuskaitymas(n, grybai);
    AtskiruGrybuSuma(n, grybai);
    GrybuSuma(n, grybai);
    Isvedimas(n, grybai);
    //cout << n;
    cout << endl;
    //for(int i=0; i<n; i++)
    /*{
        cout << grybai[i].vardai << " " << grybai[i].dienos;
        cout << endl;
        cout << grybai[i].baravykuSuma << " " << grybai[i].raudonikiuSuma << " " << grybai[i].lepsiuSuma;
        cout << endl;
    }*/
}

void Nuskaitymas(int&n, Grybautojai grybai[])
{
    ifstream duomenys("U2.txt");
    duomenys >> n;
    for(int i=0; i<n; i++)
    {
        duomenys.ignore(256, '\n');
        duomenys.get(grybai[i].vardai, 16);
        duomenys >> grybai[i].dienos;
        for(int j=0; j<grybai[i].dienos; j++)
        {
            duomenys >> grybai[i].baravykai[j] >> grybai[i].raudonikiai[j] >> grybai[i].lepsiai[j];
        }
    }
    duomenys.close();
}

void AtskiruGrybuSuma(int n, Grybautojai grybai[])
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<grybai[i].dienos; j++)
        {
            grybai[i].baravykuSuma+=  grybai[i].baravykai[j];
            grybai[i].raudonikiuSuma += grybai[i].raudonikiai[j];
            grybai[i].lepsiuSuma += grybai[i].lepsiai[j];
        }
    }
}

void GrybuSuma(int n, Grybautojai grybai[])
{
    for(int i=0; i<n; i++)
    {
        grybai[i].grybuSuma += grybai[i].baravykuSuma + grybai[i].raudonikiuSuma + grybai[i].lepsiuSuma;
    }
}

int DaugiausiaiGrybu(int n, Grybautojai grybai[])
{
    int max = 0;
    for(int i=0; i<n; i++)
    {
        if(grybai[i].grybuSuma>grybai[max].grybuSuma)
            max = i;
    }
    return max;
}
void Isvedimas(int n, Grybautojai grybai[])
{
    ofstream duomenys("U2rez.txt");
    for(int i=0; i<n; i++)
    {
        cout << grybai[i].vardai << " " << grybai[i].baravykuSuma << " " << grybai[i].raudonikiuSuma << " " << grybai[i].lepsiuSuma << endl;
        duomenys << grybai[i].vardai << " " << grybai[i].baravykuSuma << " " << grybai[i].raudonikiuSuma << " " << grybai[i].lepsiuSuma << endl;
    }
    int max = DaugiausiaiGrybu(n, grybai);
    cout << grybai[max].vardai << " " << grybai[max].grybuSuma;
    duomenys << grybai[max].vardai << " " << grybai[max].grybuSuma;
    duomenys.close();
}

