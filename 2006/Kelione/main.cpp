#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

void Nuskaitymas(int& n, int& valandos, int& minutes, float& greitis, float atstumas[], char miestai[100][16]);
void Skaiciavimai(int n, int valandos, int minutes, float greitis, float atstumas[], char miestai[100][16], int atvykimoLaikas[]);
void Isvedimas (int n, int valandos, int minutes, float greitis, float atstumas[], char miestai[100][16], int atvykimoLaikas[]);

int main()
{
    int n, valandos, minutes, atvykimoLaikas[100];
    float greitis, atstumas[100];
    char miestai[100][16];

    Nuskaitymas(n, valandos, minutes, greitis, atstumas, miestai);
    Skaiciavimai(n, valandos, minutes, greitis, atstumas, miestai, atvykimoLaikas);
    Isvedimas (n, valandos, minutes, greitis, atstumas, miestai, atvykimoLaikas);

    /*cout << n << " " << greitis << " " << valandos << " " << minutes << endl;
    for(int i=0; i<n; i++)
    {
        cout << miestai[i] << " " << atstumas[i] << endl;
    }*/
    return 0;
}

void Nuskaitymas(int& n, int& valandos, int& minutes, float& greitis, float atstumas[], char miestai[100][16])
{
    ifstream duomenys("duom2.txt");
    duomenys >> n >> greitis >> valandos >> minutes;
    for(int i=0; i<n; i++)
    {
        duomenys.ignore(256, '\n');
        duomenys.get (miestai[i], 16);
        duomenys >> atstumas[i];
    }
    duomenys.close();
}

int Laikas (float atstumas, float greitis)
{
    return round(atstumas/greitis*60);
}

void Skaiciavimai(int n, int valandos, int minutes, float greitis, float atstumas[], char miestai[100][16], int atvykimoLaikas[])
{
    int isvykimoLaikas;
    isvykimoLaikas = valandos*60+minutes;
    atvykimoLaikas[0] = isvykimoLaikas + Laikas (atstumas[0], greitis);
    for(int i=1; i<n; i++)
    {
        atvykimoLaikas[i] = atvykimoLaikas[i-1] + Laikas (atstumas[i], greitis);
    }
}

void Isvedimas (int n, int valandos, int minutes, float greitis, float atstumas[], char miestai[100][16], int atvykimoLaikas[])
{
    for(int i=0; i<n; i++)
    {
        cout << fixed << setprecision(2) <<  miestai[i] << " " << atvykimoLaikas[i]/60 << "val." << " " << atvykimoLaikas[i]%60 << "min." << endl;
    }
}









