#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

struct Turnyras
{
    char pavadinimai[16];
    int zioguTaskai;
    int varzovuTaskai;
    int skirtumai;
};

void Nuskaitymas (int& n, Turnyras komandos[]);
int Maziausiai(int n, Turnyras komandos[]);
void Skirtumas(int n, Turnyras komandos[]);
int Daugiausiai(int n, Turnyras komandos[]);
void Vidurkis(int n, Turnyras komandos[], int& suma, float& vidurkis);
int TaskuSuma (int n, Turnyras komandos[]);
void Isvedimas(int n, Turnyras komandos[]);

int main()
{
    int n;
    Turnyras komandos[100];
    Nuskaitymas (n, komandos);
    Skirtumas(n, komandos);
    Isvedimas(n, komandos);
    return 0;
}

void Nuskaitymas (int& n, Turnyras komandos[])
{
    ifstream duomenys("U2duom.txt");
    duomenys >> n;
    for(int i=0; i<n; i++)
    {
        duomenys.ignore(256,'\n');
        duomenys.get (komandos[i].pavadinimai, 16);
        duomenys >> komandos[i].zioguTaskai >> komandos[i].varzovuTaskai;
    }
    duomenys.close();
}

int Maziausiai(int n, Turnyras komandos[])
{
    int min = 0;
    for(int i=1; i<n; i++)
    {
        if(komandos[i].zioguTaskai<komandos[min].zioguTaskai)
            min = i;
    }
    return komandos[min].zioguTaskai;
}

void Skirtumas(int n, Turnyras komandos[])
{
    for(int i=0; i<n; i++)
    {
        komandos[i].skirtumai = komandos[i].zioguTaskai - komandos[i].varzovuTaskai;
    }
}

int Daugiausiai(int n, Turnyras komandos[])
{
    int max = 0;
    for(int i=0; i<n; i++)
    {
        if(komandos[i].skirtumai > komandos[max].skirtumai)
            max = i;
    }
    return komandos[max].skirtumai;
}
float Vidurkis(int n, Turnyras komandos[], float& vidurkis)
{
    int suma = 0;
    for(int i=0; i<n; i++)
    {
        suma += komandos[i].zioguTaskai;
    }
    return vidurkis = float(suma)/n;
}

int TaskuSuma (int n, Turnyras komandos[])
{
    int suma = 0;
    for(int i=0; i<n; i++)
    {
        suma += komandos[i].zioguTaskai;
    }
    return suma;
}
void Isvedimas(int n, Turnyras komandos[])
{
    ofstream duomenys("U2rez.txt");
    int min = Maziausiai(n, komandos);
    int max = Daugiausiai(n, komandos);

    for(int i=0; i<n; i++)
    {
        if(komandos[i].zioguTaskai == min)
            cout << komandos[i].zioguTaskai << " " << komandos[i].varzovuTaskai;
    }
    cout << endl;
    for(int i=0; i<n; i++)
    {
        if(komandos[i].skirtumai == max)
            cout << komandos[i].skirtumai << " ";
    }

    float vidurkis = Vidurkis(n, komandos, vidurkis);
    cout <<fixed << setprecision(2) << vidurkis << endl;
    duomenys << vidurkis << endl;
    int suma = TaskuSuma (n, komandos);
    cout << suma << endl;
    duomenys << suma << endl;

    duomenys.close();
}


