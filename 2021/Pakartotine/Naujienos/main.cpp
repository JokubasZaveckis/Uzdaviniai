#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>

using namespace std;

struct Portalas
{
    string Pavadinimas;
    string Kategorija;
    int straipsniuSkaicius;
    int melagienuSkaicius=0;
    int melagienuProcentas;
};

struct SutrauktosMelagienos : Portalas
{
    int kiekis=1;
};



void Nuskaitymas(int& n, Portalas*& portalai);
void PatikrinimasDelMelagingosKategorijos(int n, Portalas*& portalai, int& kiekMelaginguKategoriju, Portalas*& melagienuKategorijos);
void Sutraukimas(int kiekMelaginguKategoriju, Portalas*& melagienuKategorijos, SutrauktosMelagienos*& melagienos);
void Rikiavimas(int kiekMelaginguKategoriju, SutrauktosMelagienos*& melagienos);
void Isvedimas(int kiekMelaginguKategoriju, SutrauktosMelagienos*& melagienos);

int main()
{
    int n, kiekMelaginguKategoriju=0;
    Portalas* portalai = nullptr;
    Portalas* melagienuKategorijos = nullptr;
    SutrauktosMelagienos* melagienos = nullptr;

    Nuskaitymas(n, portalai);
    melagienuKategorijos = new Portalas[n];
    PatikrinimasDelMelagingosKategorijos(n, portalai, kiekMelaginguKategoriju, melagienuKategorijos);
    melagienos = new SutrauktosMelagienos[kiekMelaginguKategoriju];
    cout << kiekMelaginguKategoriju << endl;
    for(int i=0; i<kiekMelaginguKategoriju; i++)
    {
        cout << melagienuKategorijos[i].Pavadinimas << " " << melagienuKategorijos[i].Kategorija << " " << melagienuKategorijos[i].melagienuProcentas << endl;
    }


    Sutraukimas(kiekMelaginguKategoriju, melagienuKategorijos, melagienos);
    //Rikiavimas(kiekMelaginguKategoriju, melagienos);
    //Isvedimas(kiekMelaginguKategoriju, melagienos);


    delete[] portalai;
    return 0;
}

void Nuskaitymas(int& n, Portalas*& portalai)
{
    ifstream duomenys("duomenys.txt");
    duomenys >> n;
    portalai = new Portalas[n];

    string straipsnis;
    for(int i=0; i<n; i++)
    {
        duomenys.ignore(256, '\n');
        duomenys >> portalai[i].Pavadinimas >> portalai[i].Kategorija >> portalai[i].straipsniuSkaicius;
        for(int j=0; j<portalai[i].straipsniuSkaicius; j++)
        {
            duomenys >> straipsnis;
            if(straipsnis=="M")
            {
                portalai[i].melagienuSkaicius++;
            }
        }
    }
    duomenys.close();
}

void PatikrinimasDelMelagingosKategorijos(int n, Portalas*& portalai, int& kiekMelaginguKategoriju, Portalas*& melagienuKategorijos)
{
    melagienuKategorijos = new Portalas[n];
    for(int i=0; i<n; i++)
    {
        portalai[i].melagienuProcentas = portalai[i].melagienuSkaicius*100/portalai[i].straipsniuSkaicius;
        if(portalai[i].melagienuProcentas>=75)
        {
            melagienuKategorijos[kiekMelaginguKategoriju].Pavadinimas=portalai[i].Pavadinimas;
            melagienuKategorijos[kiekMelaginguKategoriju].Kategorija=portalai[i].Kategorija;
            melagienuKategorijos[kiekMelaginguKategoriju].melagienuProcentas=portalai[i].melagienuProcentas;
            kiekMelaginguKategoriju++;
        }
    }
}

void Sutraukimas(int kiekMelaginguKategoriju, Portalas*& melagienuKategorijos, SutrauktosMelagienos*& melagienos)
{
    for(int i=0; i<kiekMelaginguKategoriju-1; i++)
    {
        for(int j=i+1; j<kiekMelaginguKategoriju; j++)
        {
            if(melagienuKategorijos[i].Pavadinimas==melagienuKategorijos[j].Pavadinimas)
            {
                cout << "a" << endl;
            }
        }
    }
}

void Rikiavimas(int kiekMelaginguKategoriju, SutrauktosMelagienos*& melagienos)
{
    for(int i=0; i<kiekMelaginguKategoriju-1; i++)
    {
        int max=i;
        for(int j=i+1; j<kiekMelaginguKategoriju; j++)
        {
            if(melagienos[j].kiekis>melagienos[max].kiekis || (melagienos[j].kiekis==melagienos[max].kiekis && melagienos[j].Kategorija>melagienos[max].Kategorija))
                max=j;
        }
        if(max!=i)
        {
            swap(melagienos[i], melagienos[max]);
        }
    }
}

void Isvedimas(int kiekMelaginguKategoriju, SutrauktosMelagienos*& melagienos)
{

}
