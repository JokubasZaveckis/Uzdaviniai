#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct Pavasaris
{
    int dienosNumeris;
    int ryte;
    int diena;
    int vakare;
};

struct Programa
{
    Pavasaris temperaturos[100];
    int n;
    void Vykdyti(string Byla, string Duomenys);
    private:
    void Nuskaitymas(string Byla);
    int DidziausiaTemperatura();
    void Isvedimas1(string Byla);
    void Isvedimas2(string Byla);
};

int main()
{
    string Byla = "U1duom.txt";
    string Duomenys = "U1rez.txt";
    Programa programa;
    programa.Vykdyti(Byla, Duomenys);
    return 0;
}

void Programa::Nuskaitymas(string Byla)
{
    ifstream duomenys(Byla);
    duomenys >> n;
    for(int i=0; i<n; i++)
    {
        duomenys >> temperaturos[i].dienosNumeris >> temperaturos[i].ryte >> temperaturos[i].diena >> temperaturos[i].vakare;
    }
    duomenys.close();
}

int Programa::DidziausiaTemperatura()
{
    int max = INT_MIN;
    for(int i=0; i<n; i++)
    {
        if(temperaturos[i].ryte>temperaturos[i].diena && temperaturos[i].ryte > temperaturos[i].vakare)
            max = temperaturos[i].ryte;
        else if (temperaturos[i].diena>temperaturos[i].vakare && temperaturos[i].diena > max)
            max = temperaturos[i].diena;
        else if (temperaturos[i].vakare>max)
            max = temperaturos[i].vakare;
    }
    return max;
}

void Programa::Isvedimas1(string Byla)
{
    ofstream duomenys(Byla);
    int max = DidziausiaTemperatura();
    for(int i=0; i<n; i++)
    {
        if(temperaturos[i].ryte==max || temperaturos[i].diena==max || temperaturos[i].vakare==max)
        {
            cout << temperaturos[i].dienosNumeris << " ";
            duomenys << temperaturos[i].dienosNumeris << " ";
        }
    }
    cout << endl;
    duomenys << endl;
    duomenys.close();
}

void Programa::Isvedimas2(string Byla)
{
    ofstream duomenys(Byla, std::fstream::app);
    for(int i=0; i<n; i++)
    {
        if(temperaturos[i].ryte>=20 && temperaturos[i].diena>=20 && temperaturos[i].vakare>=20)
        {
            cout << temperaturos[i].dienosNumeris << " ";
            duomenys << temperaturos[i].dienosNumeris << " ";
        }
    }
    duomenys.close();
}

void Programa::Vykdyti(string Byla, string Duomenys)
{
    Nuskaitymas(Byla);
    DidziausiaTemperatura();
    Isvedimas1(Duomenys);
    Isvedimas2(Duomenys);
}
