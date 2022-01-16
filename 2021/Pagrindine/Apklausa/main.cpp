#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>

using namespace std;

struct Mokinys
{
    string vardas;
    string megstamiausiaPamoka;
    int pazymiuSkaicius;
    int pazymiai[9999];
    float vidurkis;
};

struct Pamoka
{
    string pavadinimas;
    int kiekisMokiniu=0;
    string mokiniai[50];
    float vidurkiai[50];
    int kiekVirs9=0;
};

void Nuskaitymas(int&m, Mokinys*& mokiniai);
void VidurkioSkaiciavimas(int m, Mokinys*& mokiniai);
void PamokuAtrinkimas(int m, Mokinys*& mokiniai, Pamoka*& pamokos, int& kiekPamoku);
void VidurkioPatikrinimas(int kiekPamoku, Pamoka*& pamokos);
void Rikiavimas(int kiekPamoku, Pamoka*& pamokos);
void Isvedimas(int kiekPamoku, Pamoka*& pamokos);

int main()
{
    int m, kiekPamoku=0;
    Mokinys* mokiniai = nullptr;
    Pamoka* pamokos = nullptr;

    Nuskaitymas(m, mokiniai);
    VidurkioSkaiciavimas(m, mokiniai);
    PamokuAtrinkimas(m, mokiniai, pamokos, kiekPamoku);
    VidurkioPatikrinimas(kiekPamoku, pamokos);
    Rikiavimas(kiekPamoku, pamokos);
    Isvedimas(kiekPamoku, pamokos);

    delete[] mokiniai;
    delete[] pamokos;
    return 0;
}

void Nuskaitymas(int&m, Mokinys*& mokiniai)
{
    ifstream duomenys("duomenys.txt");
    duomenys >> m;
    mokiniai = new Mokinys[m];
    for(int i=0; i<m; i++)
    {
        duomenys >> mokiniai[i].vardas >> mokiniai[i].megstamiausiaPamoka;
        duomenys >> mokiniai[i].pazymiuSkaicius;
        for(int j=0; j<mokiniai[i].pazymiuSkaicius; j++)
        {
            duomenys >> mokiniai[i].pazymiai[j];
        }
    }
    duomenys.close();
}

void VidurkioSkaiciavimas(int m, Mokinys*& mokiniai)
{
    for(int i=0; i<m; i++)
    {
        int suma=0;
        for(int j=0; j<mokiniai[i].pazymiuSkaicius; j++)
        {
            suma+=mokiniai[i].pazymiai[j];
        }
        mokiniai[i].vidurkis=suma*1.0/mokiniai[i].pazymiuSkaicius;
    }
}

void PamokuAtrinkimas(int m, Mokinys*& mokiniai, Pamoka*& pamokos, int& kiekPamoku)
{
    pamokos = new Pamoka[m];

    pamokos[kiekPamoku].pavadinimas = mokiniai[0].megstamiausiaPamoka;
    pamokos[kiekPamoku].mokiniai[pamokos[kiekPamoku].kiekisMokiniu] = mokiniai[0].vardas;
    pamokos[kiekPamoku].vidurkiai[pamokos[kiekPamoku].kiekisMokiniu++] = mokiniai[0].vidurkis;
    kiekPamoku++;
    for(int i=1; i<m; i++)
    {
        bool rasta=false;
        for(int j=0; j<kiekPamoku; j++)
        {
            if(mokiniai[i].megstamiausiaPamoka==pamokos[j].pavadinimas)
            {
                rasta=true;
                pamokos[j].mokiniai[pamokos[j].kiekisMokiniu] = mokiniai[i].vardas;
                pamokos[j].vidurkiai[pamokos[j].kiekisMokiniu] = mokiniai[i].vidurkis;
                pamokos[j].kiekisMokiniu++;
            }
        }
        if(rasta==false)
        {
            pamokos[kiekPamoku].pavadinimas = mokiniai[i].megstamiausiaPamoka;
            pamokos[kiekPamoku].mokiniai[pamokos[kiekPamoku].kiekisMokiniu] = mokiniai[i].vardas;
            pamokos[kiekPamoku].vidurkiai[pamokos[kiekPamoku].kiekisMokiniu] = mokiniai[i].vidurkis;
            pamokos[kiekPamoku].kiekisMokiniu++;
            kiekPamoku++;
        }
    }
}

void VidurkioPatikrinimas(int kiekPamoku, Pamoka*& pamokos)
{
    for(int i=0; i<kiekPamoku; i++)
    {
        for(int j=0; j<pamokos[i].kiekisMokiniu; j++)
        {
            if(pamokos[i].vidurkiai[j]>=9)
            {
                pamokos[i].kiekVirs9++;
            }
        }
    }
}

void Rikiavimas(int kiekPamoku, Pamoka*& pamokos)
{
    for(int i=0; i<kiekPamoku-1; i++)
    {
        int max=i;
        for(int j=i+1; j<kiekPamoku; j++)
        {
            if(pamokos[j].kiekVirs9>pamokos[max].kiekVirs9 || (pamokos[j].kiekVirs9==pamokos[max].kiekVirs9 && pamokos[j].pavadinimas<pamokos[max].pavadinimas))
            {
                max=j;
            }
        }
        if(max!=i)
        {
            swap(pamokos[i], pamokos[max]);
        }
    }
}

void Isvedimas(int kiekPamoku, Pamoka*& pamokos)
{
    int suma=0;
    for(int i=0; i<kiekPamoku; i++)
    {
        if(pamokos[i].kiekVirs9>0)
        {
            cout << pamokos[i].pavadinimas << " " << pamokos[i].kiekVirs9 << endl;
            for(int j=0; j<pamokos[i].kiekisMokiniu; j++)
            {
                if(pamokos[i].vidurkiai[j]>=9)
                {
                    cout << pamokos[i].mokiniai[j] << endl;
                }
            }
        }
    }
    for(int j=0; j<kiekPamoku; j++)
    {
        suma+=pamokos[j].kiekVirs9;
    }
    if(suma==0)
    {
        cout << "Neatitika vidurkis " << endl;
    }

    ofstream rezultatai("rezultatai.txt");
    int suma=0;
    for(int i=0; i<kiekPamoku; i++)
    {
        if(pamokos[i].kiekVirs9>0)
        {
            rezultatai << pamokos[i].pavadinimas << " " << pamokos[i].kiekVirs9 << endl;
            for(int j=0; j<pamokos[i].kiekisMokiniu; j++)
            {
                if(pamokos[i].vidurkiai[j]>=9)
                {
                    rezultatai << pamokos[i].mokiniai[j] << endl;
                }
            }
        }
    }
    for(int j=0; j<kiekPamoku; j++)
    {
        suma+=pamokos[j].kiekVirs9;
    }
    if(suma==0)
    {
        rezultatai << "Neatitika vidurkis " << endl;
    }
    rezultatai.close();
}
