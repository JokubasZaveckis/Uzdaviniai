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
    int kiekis=0;
    string kategorijos[30];
    int procentai[30];
};



void Nuskaitymas(int& n, Portalas*& portalai);
void PatikrinimasDelMelagingosKategorijos(int n, Portalas*& portalai, int& kiekMelaginguKategoriju, Portalas*& melagienuKategorijos);
void Sutraukimas(int kiekMelaginguKategoriju, Portalas*& melagienuKategorijos, SutrauktosMelagienos*& melagienos, int& kiekMelagienu);
void Rikiavimas(int kiekMelagienu, SutrauktosMelagienos*& melagienos);
void Isvedimas(int kiekMelagienu, SutrauktosMelagienos*& melagienos);

int main()
{
    int n, kiekMelaginguKategoriju=0, kiekMelagienu=0;
    Portalas* portalai = nullptr;
    Portalas* melagienuKategorijos = nullptr;
    SutrauktosMelagienos* melagienos = nullptr;

    Nuskaitymas(n, portalai);
    melagienuKategorijos = new Portalas[n];
    PatikrinimasDelMelagingosKategorijos(n, portalai, kiekMelaginguKategoriju, melagienuKategorijos);
    melagienos = new SutrauktosMelagienos[kiekMelaginguKategoriju];

    /*for(int i=0; i<kiekMelaginguKategoriju; i++)
    {
        cout << melagienuKategorijos[i].Pavadinimas << " " << melagienuKategorijos[i].Kategorija << endl;
    }*/

    Sutraukimas(kiekMelaginguKategoriju, melagienuKategorijos, melagienos, kiekMelagienu);
    Rikiavimas(kiekMelagienu, melagienos);
    Isvedimas(kiekMelagienu, melagienos);


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

void Sutraukimas(int kiekMelaginguKategoriju, Portalas*& melagienuKategorijos, SutrauktosMelagienos*& melagienos, int& kiekMelagienu)
{
    melagienos[kiekMelagienu].Pavadinimas = melagienuKategorijos[0].Pavadinimas;
    melagienos[kiekMelagienu].kategorijos[melagienos[kiekMelagienu].kiekis] = melagienuKategorijos[0].Kategorija;
    melagienos[kiekMelagienu].procentai[melagienos[kiekMelagienu].kiekis++] = melagienuKategorijos[0].melagienuProcentas;
    kiekMelagienu++;
    for(int i=1; i<kiekMelaginguKategoriju; i++)
    {
        bool arRastas=false;
        for(int j=0; j<kiekMelagienu; j++)
        {
            //cout << kiekMelagienu << " " << melagienuKategorijos[j].Pavadinimas << " " << melagienuKategorijos[j].Kategorija << " " << j << " " << i << endl;
            //cout << melagienuKategorijos[i].Pavadinimas << " " << melagienuKategorijos[j].Pavadinimas << endl;
            if(melagienuKategorijos[i].Pavadinimas==melagienos[j].Pavadinimas)
            {
                melagienos[j].Pavadinimas = melagienuKategorijos[i].Pavadinimas;
                melagienos[j].kategorijos[melagienos[j].kiekis] = melagienuKategorijos[i].Kategorija;
                melagienos[j].procentai[melagienos[j].kiekis++] = melagienuKategorijos[i].melagienuProcentas;
                arRastas=true;
                /*cout << melagienuKategorijos[i].Pavadinimas << " " << melagienos[j].Pavadinimas << endl;
                cout << arRastas << endl;*/
            }
        }
        if(arRastas==false)
        {
            melagienos[kiekMelagienu].Pavadinimas = melagienuKategorijos[i].Pavadinimas;
            melagienos[kiekMelagienu].kategorijos[melagienos[kiekMelagienu].kiekis] = melagienuKategorijos[i].Kategorija;
            melagienos[kiekMelagienu].procentai[melagienos[kiekMelagienu].kiekis++] = melagienuKategorijos[i].melagienuProcentas;
            kiekMelagienu++;
        }
    }
}

void Rikiavimas(int kiekMelagienu, SutrauktosMelagienos*& melagienos)
{
    for(int i=0; i<kiekMelagienu-1; i++)
    {
        int max=i;
        for(int j=i+1; j<kiekMelagienu; j++)
        {
            if(melagienos[j].kiekis>melagienos[max].kiekis || (melagienos[j].kiekis==melagienos[max].kiekis && melagienos[j].Pavadinimas>melagienos[max].Pavadinimas))
                max=j;
        }
        if(max!=i)
        {
            swap(melagienos[i], melagienos[max]);
        }
    }
}

void Isvedimas(int kiekMelagienu, SutrauktosMelagienos*& melagienos)
{
    for(int i=0; i<kiekMelagienu; i++)
    {
        cout << melagienos[i].Pavadinimas << " " << melagienos[i].kiekis << endl;
        for(int j=0; j<melagienos[i].kiekis; j++)
        {
            cout << melagienos[i].kategorijos[j] << " " << melagienos[i].procentai[j] << endl;
        }
    }
}
