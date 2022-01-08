#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Zaidimai
{
    int Zaidimas1=0;
    int Zaidimas2=0;
    int Zaidimas3=0;
};

struct Darbuotojas
{
    int vertinimas[3];
    int blogiausias;
};

void Nuskaitymas(int&n, int& direktoriausIvertinimas, Darbuotojas*& darbuotojai);
int DarbuotojoBlogiausiasZaidimas(int n, Darbuotojas darbuotojai);
void BlogiausioZaidimoSkaiciavimas(int n, int direktoriausIvertinimas, Darbuotojas*& darbuotojai, Zaidimai& zaidimukai);
void BlogiausioZaidimoPaieska(int direktoriausIvertinimas, Zaidimai zaidimukai, int& blogiausias);
void Isvedimas(Zaidimai zaidimukai, int blogiausias);

int main()
{
    int n, direktoriausIvertinimas, blogiausias;
    Zaidimai zaidimukai;
    Darbuotojas* darbuotojai = NULL;

    Nuskaitymas(n, direktoriausIvertinimas, darbuotojai);
    BlogiausioZaidimoSkaiciavimas(n, direktoriausIvertinimas, darbuotojai, zaidimukai);
    BlogiausioZaidimoPaieska(direktoriausIvertinimas, zaidimukai, blogiausias);
    Isvedimas(zaidimukai, blogiausias);

    delete[] darbuotojai;
    return 0;
}

void Nuskaitymas(int&n, int& direktoriausIvertinimas, Darbuotojas*& darbuotojai)
{
    ifstream duomenys("duomenys.txt");
    duomenys >> n;
    darbuotojai = new Darbuotojas[n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<3; j++)
        {
            duomenys >> darbuotojai[i].vertinimas[j];
        }
    }
    duomenys >> direktoriausIvertinimas;
    duomenys.close();
}

//int DarbuotojoBlogiausiasZaidimas(int n, Darbuotojas darbuotojai)
//{
//    int min=INT_MAX;
//    for(int i=0; i<n; i++)
//    {
//        for(int j=0; j<3; j++)
//        {
//            if(darbuotojai.vertinimas[j]>darbuotojai.vertinimas[min]) min=j;
//        }
//    }
//    return min;
//}

int DarbuotojoBlogiausiasZaidimas(int direktoriausIvertinimas, int vertinimas[])
{
    int blogiausias = vertinimas[0];

    if(blogiausias>vertinimas[1])
        blogiausias=vertinimas[1];

    if(blogiausias>vertinimas[2])
        blogiausias=vertinimas[2];

    if(blogiausias!=vertinimas[0] && blogiausias!=vertinimas[1] || blogiausias!=vertinimas[0] && blogiausias!=vertinimas[2] || blogiausias!=vertinimas[1] && blogiausias!=vertinimas[2])
    {
        if(blogiausias==vertinimas[0]) return 1;

        if(blogiausias==vertinimas[1]) return 2;

        if (blogiausias==vertinimas[2]) return 3;
    }
    else return direktoriausIvertinimas;
}

void BlogiausioZaidimoSkaiciavimas(int n, int direktoriausIvertinimas, Darbuotojas*& darbuotojai, Zaidimai& zaidimukai)
{
    for(int i=0; i<n; i++)
    {
        int blogiausias=DarbuotojoBlogiausiasZaidimas(direktoriausIvertinimas, darbuotojai[i].vertinimas);

        if(blogiausias==1) zaidimukai.Zaidimas1++;

        if(blogiausias==2) zaidimukai.Zaidimas2++;

        if(blogiausias==3) zaidimukai.Zaidimas3++;


//        if(blogiausias==direktoriausIvertinimas)
//        {
//            if(direktoriausIvertinimas==1) zaidimukai.Zaidimas1++;
//
//            if(direktoriausIvertinimas==2) zaidimukai.Zaidimas2++;
//
//            if(direktoriausIvertinimas==3) zaidimukai.Zaidimas3++;
//        }

    }
}

void BlogiausioZaidimoPaieska(int direktoriausIvertinimas, Zaidimai zaidimukai, int& blogiausias)
{
    if(zaidimukai.Zaidimas1>zaidimukai.Zaidimas2 && zaidimukai.Zaidimas1>zaidimukai.Zaidimas3)
        blogiausias = 1;

    if(zaidimukai.Zaidimas2>zaidimukai.Zaidimas1 && zaidimukai.Zaidimas2>zaidimukai.Zaidimas3)
        blogiausias = 2;

    if(zaidimukai.Zaidimas3>zaidimukai.Zaidimas1 && zaidimukai.Zaidimas3>zaidimukai.Zaidimas2)
        blogiausias = 3;

}

void Isvedimas(Zaidimai zaidimukai, int blogiausias)
{
    cout << zaidimukai.Zaidimas1 << " " << zaidimukai.Zaidimas2 << " " << zaidimukai.Zaidimas3 << endl;
    cout << blogiausias << endl;
}
