#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>

using namespace std;

struct Uzrasas
{
    char vieta[21];
    int minutesVietoje;
};

void Nuskaitymas(int& n, Uzrasas*& janina);
/*void SkirtingosVietos(int n, int& kiek, Uzrasas*& janina, Atsakymai*& atsakymai);
void Skaiciavimai(int n, int kiek,  Uzrasas*& janina,  Atsakymai*& atsakymai);
void Isvedimas(int n, int kiek, Uzrasas*& janina, Atsakymai*& atsakymai);*/
void RikiavimasPagalPavadinima(int n, Uzrasas*& uzrasai);
void Skaiciavimas(int& n, Uzrasas*& uzrasai);
void Isvedimass(int n, Uzrasas*& uzrasai);


int main()
{
    int n, kiek=0;
    Uzrasas* uzrasai = nullptr;

    Nuskaitymas(n, uzrasai);
    /*SkirtingosVietos(n, kiek, uzrasai, atsakymai);
    Skaiciavimai(n, kiek, uzrasai, atsakymai);*/
    //Isvedimas(n, kiek, uzrasai, atsakymai);

    RikiavimasPagalPavadinima(n, uzrasai);
    Skaiciavimas(n, uzrasai);
    Isvedimass(n, uzrasai);

    delete[] uzrasai;
    return 0;
}

void Nuskaitymas(int& n, Uzrasas*& janina)
{
    ifstream duomenys("duomenys.txt");
    duomenys  >> n;
    janina = new Uzrasas[n];
    for(int i=0; i<n; i++)
    {
        duomenys.ignore(256, '\n');
        duomenys.get(janina[i].vieta, 21);
        duomenys >> janina[i].minutesVietoje;
        //cout << janina[i].vieta << " " << janina[i].minutesVietoje << endl;
    }
    duomenys.close();
}

void RikiavimasPagalPavadinima(int n, Uzrasas*& uzrasai)
{
    for(int i=0; i<n-1; i++)
    {
        int max=i;
        for(int j=i+1; j<n; j++)
        {
            if(strcmp(uzrasai[j].vieta, uzrasai[max].vieta)>0)
            {
                max=j;
            }
        }
        if(max!=i)
        {
            swap(uzrasai[i], uzrasai[max]);
        }
    }
}

void Skaiciavimas(int& n, Uzrasas*& uzrasai)
{
    for(int i=0; i<n-1; i++)
    {
        if(strcmp(uzrasai[i].vieta, uzrasai[i+1].vieta)==0)
        {
            uzrasai[i].minutesVietoje+=uzrasai[i+1].minutesVietoje;
            for(int j=i+1; j<n-1; j++)
            {
                uzrasai[j]=uzrasai[j+1];
            }
            i--;
            n--;
        }
    }
}

void Isvedimass(int n, Uzrasas*& uzrasai)
{
    for(int i=0; i<n; i++)
    {
        cout << uzrasai[i].vieta << " " << uzrasai[i].minutesVietoje << endl;
    }
}

/*void SkirtingosVietos(int n, int& kiek, Uzrasas*& janina, Atsakymai*& atsakymai)
{
    atsakymai = new Atsakymai[n];
    strcpy(atsakymai[kiek++].vietos, janina[0].vieta);
    for(int i=0; i<n; i++)
    {
        bool vienodi=false;
        for(int j=0; j<kiek; j++)
        {
            if(strcmp(janina[i].vieta, atsakymai[j].vietos)==0)
            {
                vienodi=true;
                cout << "b" << " " << janina[i].vieta << endl;
            }
            //cout << janina[j].vieta << " " << janina[i].vieta << " "  << strcmp(janina[i].vieta, janina[j].vieta) << endl;
        }
        cout << vienodi << endl;
        if(!vienodi)
        {
            strcpy(atsakymai[kiek++].vietos, janina[i].vieta);
            cout << "a" << endl;
        }
    }
}

void Skaiciavimai(int n, int kiek,  Uzrasas*& janina,  Atsakymai*& atsakymai)
{
    for(int i=0; i<kiek; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(strcmp(janina[j].vieta, atsakymai[i].vietos)==0)
            {
                atsakymai[i].vienosVietosMinutes+=janina[j].minutesVietoje;
            }
        }
    }
}*/


/*void Isvedimas(int n, int kiek, Uzrasas*& janina, Atsakymai*& atsakymai)
{
    ofstream rezultatai("rezultatai.txt");
    for(int i=0; i<kiek; i++)
    {
        cout << atsakymai[i].vietos << " " << atsakymai[i].vienosVietosMinutes << endl;
        rezultatai << atsakymai[i].vietos << " " << atsakymai[i].vienosVietosMinutes << endl;
    }
    rezultatai.close();
}*/
