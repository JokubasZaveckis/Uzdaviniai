#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

struct Stotele
{
    char miestai[16];
    float atstumas;
    int atvykimoLaikas;
};

void Nuskaitymas(int&n, float& greitis, int&valandos, int& minutes, Stotele marsrutai[]);
void Skaiciavimai(int n, float greitis, int valandos, int minutes, Stotele marsrutai[]);
void Isvedimas(int n, float greitis, int valandos, int minutes, Stotele marsrutai[]);

int main()
{
    int n, valandos, minutes;
    float greitis;
    Stotele marsrutai[100];

    Nuskaitymas(n, greitis, valandos, minutes, marsrutai);
    Skaiciavimai(n, greitis, valandos, minutes, marsrutai);
    Isvedimas(n, greitis, valandos, minutes, marsrutai);

    return 0;
}

void Nuskaitymas(int&n, float& greitis, int&valandos, int& minutes, Stotele marsrutai[])
{
    ifstream duomenys("duom2.txt");
    duomenys >> n >> greitis >> valandos >> minutes;
    for(int i=0; i<n; i++)
    {
        duomenys.ignore (256, '\n');
        duomenys.get (marsrutai[i].miestai, 16);
        duomenys >> marsrutai[i].atstumas;

    }
    duomenys.close();
}

int Laikas (float atstumas, float greitis)
{
    return round(atstumas/greitis*60);
}

void Skaiciavimai(int n, float greitis, int valandos, int minutes, Stotele marsrutai[])
{
    int isvykimoLaikas;
    isvykimoLaikas = valandos*60+minutes;
    marsrutai[0].atvykimoLaikas = isvykimoLaikas + Laikas (marsrutai[0].atstumas, greitis);
    for(int i=1; i<n; i++)
    {
        marsrutai[i].atvykimoLaikas = marsrutai[i-1].atvykimoLaikas + Laikas(marsrutai[i].atstumas, greitis);
    }
}

void Isvedimas(int n, float greitis, int valandos, int minutes, Stotele marsrutai[])
{
    for(int i=0; i<n; i++)
    {
        cout << fixed << setprecision(2) << marsrutai[i].miestai << " " << marsrutai[i].atvykimoLaikas/60 << "val." << " " << marsrutai[i].atvykimoLaikas%60 << "min." << endl;
    }
}





