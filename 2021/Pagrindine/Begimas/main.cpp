#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct Begimas
{
    int dienosNumeris;
    int isbegimoValanda, isbegimoMinutes;
    int parbegimoValanda, parbegimoMinutes;
    int laikoPrabegta = 0;
};

void Nuskaitymas(int&n, Begimas*& begimasRytais, Begimas*& begimasVakarais);
int BegimoMinutesPerDiena(int isbegimoValanda, int isbegimoMinutes, int parbegimoValanda, int parbegimoMinutes);
void BegimasKiekvienaDiena(int n, Begimas*& begimasRytais, Begimas*& begimasVakarais);
void PrabegtaLaikoPerDiena(int n, Begimas*& begimasRytais, Begimas*& begimasVakarais, int laikai[], int& kiekLaiku, int dienos[]);
int maziausiaiLaikoPrabegta(int n, int laikai[], int kiekLaiku);
void Isvedimas(int n, int maziausiasLaikas, int laikai[], Begimas*& begimasRytais, int kiekLaiku, int dienos[]);

int main()
{
    int n;
    Begimas* begimasRytais = nullptr;
    Begimas* begimasVakarais = nullptr;

    Nuskaitymas(n, begimasRytais, begimasVakarais);
    BegimasKiekvienaDiena(n, begimasRytais, begimasVakarais);
    int laikai[n], kiekLaiku=0, dienos[n];
    PrabegtaLaikoPerDiena(n, begimasRytais, begimasVakarais, laikai, kiekLaiku, dienos);
    int maziausiasLaikas = maziausiaiLaikoPrabegta(n, laikai, kiekLaiku);
    Isvedimas(n, maziausiasLaikas, laikai, begimasRytais, kiekLaiku, dienos);

    delete[] begimasRytais;
    delete[] begimasVakarais;
    return 0;

}

void Nuskaitymas(int&n, Begimas*& begimasRytais, Begimas*& begimasVakarais)
{
    ifstream duomenys("duomenys.txt");
    duomenys >> n;
    begimasRytais = new Begimas[n];
    begimasVakarais = new Begimas[n];
    for(int i=0; i<n; i++)
    {
        duomenys >> begimasRytais[i].dienosNumeris;
        begimasVakarais[i].dienosNumeris = begimasRytais[i].dienosNumeris;
        duomenys >> begimasRytais[i].isbegimoValanda >> begimasRytais[i].isbegimoMinutes >> begimasRytais[i].parbegimoValanda >> begimasRytais[i].parbegimoMinutes;
        duomenys >> begimasVakarais[i].isbegimoValanda >> begimasVakarais[i].isbegimoMinutes >> begimasVakarais[i].parbegimoValanda >> begimasVakarais[i].parbegimoMinutes;
    }
    duomenys.close();
}

int BegimoMinutesPerDiena(int isbegimoValanda, int isbegimoMinutes, int parbegimoValanda, int parbegimoMinutes)
{
    return (parbegimoValanda*60+parbegimoMinutes)-(isbegimoValanda*60+isbegimoMinutes);
}

void BegimasKiekvienaDiena(int n, Begimas*& begimasRytais, Begimas*& begimasVakarais)
{
    for(int i=0; i<n; i++)
    {
        begimasRytais[i].laikoPrabegta=BegimoMinutesPerDiena(begimasRytais[i].isbegimoValanda, begimasRytais[i].isbegimoMinutes, begimasRytais[i].parbegimoValanda, begimasRytais[i].parbegimoMinutes);
        begimasVakarais[i].laikoPrabegta=BegimoMinutesPerDiena(begimasVakarais[i].isbegimoValanda, begimasVakarais[i].isbegimoMinutes, begimasVakarais[i].parbegimoValanda, begimasVakarais[i].parbegimoMinutes);
    }

}

void PrabegtaLaikoPerDiena(int n, Begimas*& begimasRytais, Begimas*& begimasVakarais, int laikai[], int& kiekLaiku, int dienos[])
{
    for(int i=0; i<n; i++)
    {
        if(begimasRytais[i].laikoPrabegta>0 && begimasVakarais[i].laikoPrabegta>0)
        {
            laikai[kiekLaiku]=begimasRytais[i].laikoPrabegta+begimasVakarais[i].laikoPrabegta;
            dienos[kiekLaiku++]=begimasRytais[i].dienosNumeris;
        }
    }
}

int maziausiaiLaikoPrabegta(int n, int laikai[], int kiekLaiku)
{
    int min=0;
    for(int i=0; i<kiekLaiku; i++)
    {
        if(laikai[i]<laikai[min]) min=i;
    }
    return laikai[min];
}

void Isvedimas(int n, int maziausiasLaikas, int laikai[], Begimas*& begimasRytais, int kiekLaiku, int dienos[])
{
    ofstream rezultatai("rezultatai.txt");
    rezultatai << "Minimalus laikas" << endl;
    rezultatai << maziausiasLaikas << endl;
    rezultatai << "Dienos" << endl;
    for(int i=0; i<kiekLaiku; i++)
    {
        if(laikai[i]==maziausiasLaikas)
        {
            rezultatai << dienos[i] << " ";
        }
    }
    rezultatai.close();
}
