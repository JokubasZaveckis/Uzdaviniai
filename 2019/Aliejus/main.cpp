#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct Indai
{
    int litrai_5=0;
    int litrai_3=0;
    int litras_1=0;
};

void Nuskaitymas(int& isspaustas, int& islaidos, Indai& tusti, Indai& kaina);
void Skaiciavimai(int& isspaustas, Indai& tusti, Indai& pilni);
void KiekInduTruksta(int isspaustas, Indai& tusti, Indai& truksta);
int PelnoSkaiciavimas(int& islaidos, Indai& kaina, Indai& truksta, Indai& pilni);
void Isvedimas(int pelnas, int islaidos, int isspaustas, Indai& pilni, Indai& tusti, Indai& truksta);


int main()
{
    int isspaustas, islaidos;
    Indai tusti;
    Indai pilni;
    Indai kaina;
    Indai truksta;

    Nuskaitymas(isspaustas, islaidos, tusti, kaina);
    Skaiciavimai(isspaustas, tusti, pilni);
    KiekInduTruksta(isspaustas, tusti, truksta);
    int pelnas = PelnoSkaiciavimas(islaidos, kaina, truksta, pilni);
    Isvedimas(pelnas, islaidos, isspaustas, pilni, tusti, truksta);

    return 0;
}

void Nuskaitymas(int& isspaustas, int& islaidos, Indai& tusti, Indai& kaina)
{
    ifstream duomenys("duomenys.txt");

    duomenys >> tusti.litras_1 >> tusti.litrai_3 >> tusti.litrai_5;
    duomenys >> isspaustas;
    duomenys >> islaidos;
    duomenys >> kaina.litras_1 >> kaina.litrai_3 >> kaina.litrai_5;

    duomenys.close();
}

void Skaiciavimai(int& isspaustas, Indai& tusti, Indai& pilni)
{
        while(isspaustas-5>=0 && tusti.litrai_5>0)
        {
            tusti.litrai_5--;
            isspaustas-=5;
            pilni.litrai_5++;
        }

        while(isspaustas-3>=0 && tusti.litrai_3>0)
        {
            tusti.litrai_3--;
            isspaustas-=3;
            pilni.litrai_3++;
        }

        while(isspaustas-1>=0 && tusti.litras_1>0)
        {
            tusti.litras_1--;
            isspaustas--;
            pilni.litras_1++;
        }
}

void KiekInduTruksta(int isspaustas, Indai& tusti, Indai& truksta)
{
        while(isspaustas-5>0)
        {
            isspaustas-=5;
            truksta.litrai_5++;
        }

        while(isspaustas-3>0)
        {
            isspaustas-=3;
            truksta.litrai_3++;
        }

        while(isspaustas-1>=0)
        {
            isspaustas--;
            truksta.litras_1++;
        }
}

int PelnoSkaiciavimas(int& islaidos, Indai& kaina, Indai& truksta, Indai& pilni)
{
    int pelnas = 0;

    pelnas+=pilni.litrai_5*kaina.litrai_5;
    pelnas+=pilni.litrai_3*kaina.litrai_3;
    pelnas+=pilni.litras_1*kaina.litras_1;
    pelnas+=truksta.litrai_5*kaina.litrai_5;
    pelnas+=truksta.litrai_3*kaina.litrai_3;
    pelnas+=truksta.litras_1*kaina.litras_1;

    return pelnas;
}

void Isvedimas(int pelnas, int islaidos, int isspaustas, Indai& pilni, Indai& tusti, Indai& truksta)
{
    ofstream rezultatai("rezultatai.txt");

    rezultatai << pilni.litras_1 << " " << pilni.litrai_3 << " " << pilni.litrai_5 << " " << isspaustas << endl;
    rezultatai << tusti.litras_1 << " " << tusti.litrai_3 << " " << tusti.litrai_5 << endl;
    rezultatai << truksta.litras_1 << " " << truksta.litrai_3 << " " << truksta.litrai_5 << endl;
    rezultatai << pelnas-islaidos << endl;

    rezultatai.close();
}

