#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Sportininkas
{
    char vardas[21];
    int minutes;
    int sekundes;
    int laikasSekundemis;

    void LaikoSkaiciavimasSekundemis();
};

struct Grupe
{
    int sportininkuSkaiciusGrupeje;
    Sportininkas sportininkai[8];

    Sportininkas* GeriausiSportininkai();
};

void Nuskaitymas(int&k, Grupe grupes[]);
void LaikasMinutemis(int k, Sportininkas sportininkas[]);
void Atrinkimas(Grupe grupes[], int k, Sportininkas sportininkai[], int& sportininkuSkaicius);
void Isvedimas(int sportininkuSkaicius, Sportininkas sportininkas[]);

int main()
{
    int k, sportininkuSkaicius=0;
    Grupe grupes[25];
    Sportininkas sportininkai[25];
    Nuskaitymas(k, grupes);
    Atrinkimas(grupes, k, sportininkai, sportininkuSkaicius);
    Isvedimas(sportininkuSkaicius, sportininkai);
    return 0;
}

void Nuskaitymas(int&k, Grupe grupes[])
{
    ifstream duomenys("duomenys.txt");
    duomenys >> k;
    for(int i=0; i<k; i++)
    {
        duomenys >> grupes[i].sportininkuSkaiciusGrupeje;
        for(int j=0; j<grupes[i].sportininkuSkaiciusGrupeje; j++)
        {
            duomenys.ignore(256, '\n');
            duomenys.get(grupes[i].sportininkai[j].vardas, 21);
            duomenys >> grupes[i].sportininkai[j].minutes >> grupes[i].sportininkai[j].sekundes;
            grupes[i].sportininkai[j].LaikoSkaiciavimasSekundemis();
        }
    }

    duomenys.close();
}

void Sportininkas::LaikoSkaiciavimasSekundemis()
{
    laikasSekundemis=minutes*60+sekundes;
}

void Rikiavimas(int k, Sportininkas sportininkas[])
{
    for(int i=0; i<k-1; i++)
    {
        int max=i;
        for(int j=i+1; j<k; j++)
        {
            if(sportininkas[max].laikasSekundemis>sportininkas[j].laikasSekundemis)
                max=j;
        }
        if(i!=max)
        {
            swap(sportininkas[i], sportininkas[max]);
        }
    }
}

void Atrinkimas(Grupe grupes[], int k, Sportininkas sportininkai[], int& sportininkuSkaicius)
{
    for(int i=0; i<k; i++)
    {
        Rikiavimas(grupes[i].sportininkuSkaiciusGrupeje, grupes[i].sportininkai);
    }
    for(int i=0; i<k; i++)
    {
        Sportininkas* geriausi=grupes[i].GeriausiSportininkai();
        for(int j=0; j<grupes[i].sportininkuSkaiciusGrupeje/2; j++)
        {
            sportininkai[sportininkuSkaicius++]=geriausi[j];
        }
    }
}

Sportininkas* Grupe::GeriausiSportininkai()
{
    static Sportininkas sportininkai[4];
    for(int i=0; i<sportininkuSkaiciusGrupeje/2; i++)
    {
        sportininkai[i]=this->sportininkai[i];
    }
    return sportininkai;
}



void Isvedimas(int sportininkuSkaicius, Sportininkas sportininkas[])
{
    Rikiavimas(sportininkuSkaicius, sportininkas);
    for(int i=0; i<sportininkuSkaicius; i++)
    {
        cout << sportininkas[i].vardas << endl;
    }
}
