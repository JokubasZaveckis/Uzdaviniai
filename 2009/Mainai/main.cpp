#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void Nuskaitymas(int& gilijosNominalai, int gilijosNominaluSarasas[], int gilijosStudentoTurimosMonetos[], int& egilijosNominalai, int egilijosNominaluSarasas[], int egilijosStudentoTurimosMonetos[]);
int TurimuPiniguSuma(int nominalai, int nominaluSarasas[], int turimiPinigai[]);
void MonetuKiekis(int nominalai, int nominaluSarasas[], int suma, int monetuKiekis[]);
int MonetuSuma(int nominalai, int monetuKiekis[]);
void Isvedimas(int gilijosNominalai, int gilijosNominaluSarasas[], int egilijosNominalai, int egilijosNominaluSarasas[], int gilijiecioMonetos[], int egilijiecioMonetos[], int gilijosStudentoTurimosMonetos[], int egilijosStudentoTurimosMonetos[]);

int main()
{
    int gilijosNominalai, gilijosNominaluSarasas[50], gilijosStudentoTurimosMonetos[50], egilijosNominalai, egilijosNominaluSarasas[50], egilijosStudentoTurimosMonetos[50], gilijiecioMonetos[50], egilijiecioMonetos[50];

    Nuskaitymas(gilijosNominalai, gilijosNominaluSarasas, gilijosStudentoTurimosMonetos, egilijosNominalai, egilijosNominaluSarasas, egilijosStudentoTurimosMonetos);
    Isvedimas(gilijosNominalai, gilijosNominaluSarasas, egilijosNominalai, egilijosNominaluSarasas, gilijiecioMonetos, egilijiecioMonetos, gilijosStudentoTurimosMonetos, egilijosStudentoTurimosMonetos);

    return 0;
}

void Nuskaitymas(int& gilijosNominalai, int gilijosNominaluSarasas[], int gilijosStudentoTurimosMonetos[], int& egilijosNominalai, int egilijosNominaluSarasas[], int egilijosStudentoTurimosMonetos[])
{
    ifstream duomenys("duomenys.txt");
    duomenys >> gilijosNominalai;
    for(int i=0; i<gilijosNominalai; i++)
    {
        duomenys >> gilijosNominaluSarasas[i];
    }
    for(int i=0; i<gilijosNominalai; i++)
    {
        duomenys >> gilijosStudentoTurimosMonetos[i];
    }

    duomenys >> egilijosNominalai;
    for(int i=0; i<egilijosNominalai; i++)
    {
        duomenys >> egilijosNominaluSarasas[i];
    }
    for(int i=0; i<egilijosNominalai; i++)
    {
        duomenys >> egilijosStudentoTurimosMonetos[i];
    }
    duomenys.close();
}

int TurimuPiniguSuma(int nominalai, int nominaluSarasas[], int turimiPinigai[])
{
    int suma=0;
    for(int i=0; i<nominalai; i++)
    {
        suma+=nominaluSarasas[i]*turimiPinigai[i];
    }
    return suma;
}

void MonetuKiekis(int nominalai, int nominaluSarasas[], int suma, int monetuKiekis[])
{
    for(int i=0; i<nominalai; i++)
    {
        monetuKiekis[i]=suma/nominaluSarasas[i];
        suma-=monetuKiekis[i]*nominaluSarasas[i];
    }
}

int MonetuSuma(int nominalai, int monetuKiekis[])
{
    int suma=0;
    for(int i=0; i<nominalai; i++)
    {
        suma+=monetuKiekis[i];
    }
    return suma;
}

void Isvedimas(int gilijosNominalai, int gilijosNominaluSarasas[], int egilijosNominalai, int egilijosNominaluSarasas[], int gilijiecioMonetos[], int egilijiecioMonetos[], int gilijosStudentoTurimosMonetos[], int egilijosStudentoTurimosMonetos[])
{
    int gilijosStudentoPiniguSuma = TurimuPiniguSuma(gilijosNominalai, gilijosNominaluSarasas, gilijosStudentoTurimosMonetos);
    int egilijosStudentoPiniguSuma = TurimuPiniguSuma(egilijosNominalai, egilijosNominaluSarasas, egilijosStudentoTurimosMonetos);

    MonetuKiekis(egilijosNominalai, egilijosNominaluSarasas, gilijosStudentoPiniguSuma, gilijiecioMonetos);
    MonetuKiekis(gilijosNominalai, gilijosNominaluSarasas, egilijosStudentoPiniguSuma, egilijiecioMonetos);

    int gilijiecioMonetuSuma = MonetuSuma(egilijosNominalai, gilijiecioMonetos);
    int egilijiecioMonetuSuma = MonetuSuma(egilijosNominalai, egilijiecioMonetos);

    ofstream rezultatai("rezultatai.txt");

    for(int i=0; i<egilijosNominalai; i++)
    {
        rezultatai << egilijosNominaluSarasas[i] << " " << gilijiecioMonetos[i] << endl;
        cout << egilijosNominaluSarasas[i] << " " << gilijiecioMonetos[i] << endl;
    }
    rezultatai << gilijiecioMonetuSuma << endl;
    cout << gilijiecioMonetuSuma << endl;

    for(int i=0; i<gilijosNominalai; i++)
    {
        rezultatai << gilijosNominaluSarasas[i] << " " << egilijiecioMonetos[i] << endl;
        cout << gilijosNominaluSarasas[i] << " " << egilijiecioMonetos[i] << endl;
    }
    rezultatai << egilijiecioMonetuSuma << endl;
    cout << egilijiecioMonetuSuma << endl;

    rezultatai.close();
}

