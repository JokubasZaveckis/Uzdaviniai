#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Valiuta
{
    char vardai[16];
    float uzsienioPinigai;
    float kursas;
    float pinigaiLitais;
};

void Nuskaitymas(int& n, Valiuta pinigai[]);
void vertimasiLitus(int n, Valiuta pinigai[]);
float Suma(int n, Valiuta pinigai[]);
float Vidurkis(int n, Valiuta pinigai[]);
int KiekZmoniuTuriDaugiauUzVidurki(int n, Valiuta pinigai[], float vidurkis);
void Isvedimas(int n, Valiuta pinigai[]);
void Isvedimas(int n, Valiuta pinigai[]);

int main()
{
    int n;
    Valiuta pinigai[500];
    Nuskaitymas(n, pinigai);
    vertimasiLitus(n, pinigai);
    Isvedimas(n, pinigai);
    return 0;
}

void Nuskaitymas(int& n, Valiuta pinigai[])
{
    ifstream duomenys("U2duom.txt");
    duomenys >> n;
    for(int i=0; i<n; i++)
    {
        duomenys.ignore(256, '\n');
        duomenys.get (pinigai[i].vardai, 16);
        duomenys >> pinigai[i].uzsienioPinigai >> pinigai[i].kursas;
    }
    duomenys.close();
}

void vertimasiLitus(int n, Valiuta pinigai[])
{
    for(int i=0; i<n; i++)
    {
        pinigai[i].pinigaiLitais = pinigai[i].uzsienioPinigai*pinigai[i].kursas;
    }
}

float Suma(int n, Valiuta pinigai[])
{
    float suma=0;
    for(int i=0; i<n; i++)
    {
        suma += pinigai[i].pinigaiLitais;
    }
    return suma;
}

float Vidurkis(int n, Valiuta pinigai[])
{
    float suma = Suma(n, pinigai);
    return suma/n;
}

int KiekZmoniuTuriDaugiauUzVidurki(int n, Valiuta pinigai[], float vidurkis)
{
    int kiek = 0;
    for(int i=0; i<n; i++)
    {
        if(pinigai[i].pinigaiLitais >= vidurkis)
            kiek++;
    }
    return kiek;
}

void Isvedimas(int n, Valiuta pinigai[])
{
    ofstream duomenys("U2rez.txt");
    float suma = Suma(n, pinigai);
    float vidurkis = Vidurkis(n, pinigai);
    int kiek = KiekZmoniuTuriDaugiauUzVidurki(n, pinigai, vidurkis);

    cout << suma << endl;
    cout << kiek << endl;
    for(int i=0; i<n; i++)
    {
        cout << fixed <<setprecision(2)<< pinigai[i].vardai << " " << pinigai[i].pinigaiLitais << endl;
    }

    duomenys << suma << endl;
    duomenys << kiek << endl;
    for(int i=0; i<n; i++)
    {
        duomenys << fixed <<setprecision(2)<< pinigai[i].vardai << " " << pinigai[i].pinigaiLitais << endl;
    }
    duomenys.close();

}


