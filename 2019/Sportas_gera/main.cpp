#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>

using namespace std;

struct Slidininkas
{
    char vardas[21];
    int numeris;
    int valandos, minutes, sekundes;
    int laikasSekundemis;
    int taiklusSuviai[4] = {0};
    int kiekTaikliuSuviu=0;
    int galutinisLaikasSekundemis;
};

void Nuskaitymas(int&n, int&m, Slidininkas*& dalyvave, Slidininkas*& finisave);
void LaikoPavertimasISekundes(int kiek, Slidininkas*& sarasas);
void TaikliuSuviuSkaiciavimas(int m, Slidininkas*& finisave);
void MergaiciuAtskyrimasNuoBerniuku(int n, int& kiekVaikinu, int& kiekMerginu, Slidininkas*& dalyvave, Slidininkas*& merginos, Slidininkas*& vaikinai);
void FinisavusiuAtrinkimas(int m, int kiekZmoniu, int& finisavusiu, Slidininkas*& finisave, Slidininkas*& zmones, Slidininkas*& finisaveZmones);
void LaikoSkaiciavimas(int n, int m, int finisavusiu, Slidininkas*& zmones, Slidininkas*& finisave, Slidininkas*& finisaveZmones);
void Rikiavimas(int finisavusiu, Slidininkas*& finisaveZmones);
void MerginiuIsvedimas(int finisavusiuMerginu, Slidininkas*& finisavusiosMerginos, ofstream& rezultatai);
void VaikinuIsvedimas(int finisavusiuVaikinu, Slidininkas*& finisaveVaikinai, ofstream& rezultatai);

int main()
{
    int n, m, kiekVaikinu=0, kiekMerginu=0, finisavusiuMerginu=0, finisavusiuVaikinu=0;

    Slidininkas* dalyvave = nullptr;
    Slidininkas* finisave = nullptr;

    Nuskaitymas(n, m, dalyvave, finisave);

    Slidininkas* merginos = new Slidininkas[n];
    Slidininkas* finisavusiosMerginos = new Slidininkas[m];
    Slidininkas* vaikinai = new Slidininkas[n];
    Slidininkas* finisaveVaikinai = new Slidininkas[m];

    LaikoPavertimasISekundes(n, dalyvave);
    LaikoPavertimasISekundes(m, finisave);
    TaikliuSuviuSkaiciavimas(m, finisave);
    MergaiciuAtskyrimasNuoBerniuku(n, kiekVaikinu, kiekMerginu, dalyvave, merginos, vaikinai);
    FinisavusiuAtrinkimas(m, kiekVaikinu, finisavusiuVaikinu, finisave, vaikinai, finisaveVaikinai);
    FinisavusiuAtrinkimas(m, kiekMerginu, finisavusiuMerginu, finisave, merginos, finisavusiosMerginos);
    LaikoSkaiciavimas(n, m, finisavusiuVaikinu, dalyvave, finisave, finisaveVaikinai);
    LaikoSkaiciavimas(n, m, finisavusiuMerginu, dalyvave, finisave, finisavusiosMerginos);
    Rikiavimas(finisavusiuMerginu, finisavusiosMerginos);
    Rikiavimas(finisavusiuVaikinu, finisaveVaikinai);

    ofstream rezultatai("rezultatai.txt");

    MerginiuIsvedimas(finisavusiuMerginu, finisavusiosMerginos, rezultatai);
    VaikinuIsvedimas(finisavusiuVaikinu, finisaveVaikinai, rezultatai);

    rezultatai.close();

    delete[] dalyvave;
    delete[] finisave;
    delete[] merginos;
    delete[] vaikinai;
    delete[] finisavusiosMerginos;
    delete[] finisaveVaikinai;
    return 0;

    //std::ofstream::app

}

void Nuskaitymas(int&n, int&m, Slidininkas*& dalyvave, Slidininkas*& finisave)
{
    ifstream duomenys("duomenys.txt");

    duomenys >> n;
    dalyvave = new Slidininkas[n];

    for(int i=0; i<n; i++)
    {
        duomenys.ignore(256, '\n');
        duomenys.get(dalyvave[i].vardas, 21);
        duomenys >> dalyvave[i].numeris;
        duomenys >> dalyvave[i].valandos >> dalyvave[i].minutes >> dalyvave[i].sekundes;
    }

    duomenys >> m;
    finisave = new Slidininkas[m];
    for(int i=0; i<n; i++)
    {
        duomenys >> finisave[i].numeris;
        duomenys >> finisave[i].valandos >> finisave[i].minutes >> finisave[i].sekundes;
        if(finisave[i].numeris<200)
        {
            for(int j=0; j<2; j++)
            {
                duomenys >> finisave[i].taiklusSuviai[j];
            }
        }
        else
        {
            for(int j=0; j<4; j++)
            {
                duomenys >> finisave[i].taiklusSuviai[j];
            }
        }
    }
    duomenys.close();
}

void LaikoPavertimasISekundes(int kiek, Slidininkas*& sarasas)
{
    for(int i=0; i<kiek; i++)
    {
        sarasas[i].laikasSekundemis = sarasas[i].valandos*3600+sarasas[i].minutes*60+sarasas[i].sekundes;
    }
}

void TaikliuSuviuSkaiciavimas(int m, Slidininkas*& finisave)
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<4; j++)
        {
            finisave[i].kiekTaikliuSuviu+=finisave[i].taiklusSuviai[j];
        }
    }
}

void MergaiciuAtskyrimasNuoBerniuku(int n, int& kiekVaikinu, int& kiekMerginu, Slidininkas*& dalyvave, Slidininkas*& merginos, Slidininkas*& vaikinai)
{
    for(int i=0; i<n; i++)
    {
        if(dalyvave[i].numeris>=200)
        {
            /*vaikinai[kiekVaikinu].numeris = dalyvave[i].numeris;
            vaikinai[kiekVaikinu].laikasSekundemis=dalyvave[i].laikasSekundemis;
            for(int j=0; j<4; j++)
            {
                vaikinai[kiekVaikinu].taiklusSuviai[j]=dalyvave[i].taiklusSuviai[j];
            }
            strcpy(vaikinai[kiekVaikinu].vardas, dalyvave[i].vardas);
            kiekVaikinu++;*/

            vaikinai[kiekVaikinu++]=dalyvave[i];

        }
        else
        {
            merginos[kiekMerginu].numeris = dalyvave[i].numeris;
            merginos[kiekMerginu].laikasSekundemis=dalyvave[i].laikasSekundemis;
            for(int j=0; j<4; j++)
            {
                merginos[kiekMerginu].taiklusSuviai[j]=dalyvave[i].taiklusSuviai[j];
            }
            strcpy(merginos[kiekMerginu].vardas, dalyvave[i].vardas);
            kiekMerginu++;
        }
    }
}

void FinisavusiuAtrinkimas(int m, int kiekZmoniu, int& finisavusiu, Slidininkas*& finisave, Slidininkas*& zmones, Slidininkas*& finisaveZmones)
{
    for(int i=0; i<kiekZmoniu; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(zmones[i].numeris==finisave[j].numeris)
            {
                strcpy(finisaveZmones[finisavusiu].vardas, zmones[i].vardas);
                finisaveZmones[finisavusiu].numeris = zmones[i].numeris;
                finisaveZmones[finisavusiu].laikasSekundemis = zmones[i].laikasSekundemis;
                finisavusiu++;
            }
        }
    }
}

void LaikoSkaiciavimas(int n, int m, int finisavusiu, Slidininkas*& zmones, Slidininkas*& finisave, Slidininkas*& finisaveZmones)
{

    for(int i=0; i<finisavusiu; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(finisaveZmones[i].numeris==finisave[j].numeris)
            {
                if(finisaveZmones[i].numeris<200)
                {
                    finisaveZmones[i].galutinisLaikasSekundemis=finisave[j].laikasSekundemis-finisaveZmones[i].laikasSekundemis+(10-finisave[j].kiekTaikliuSuviu)*60;
                }
                else
                {
                    finisaveZmones[i].galutinisLaikasSekundemis=finisave[j].laikasSekundemis-finisaveZmones[i].laikasSekundemis+(20-finisave[j].kiekTaikliuSuviu)*60;
                }
            }
        }
    }
}

void Rikiavimas(int finisavusiu, Slidininkas*& finisaveZmones)
{
    for(int i=0; i<finisavusiu-1; i++)
    {
        int max=i;
        for(int j=i+1; j<finisavusiu; j++)
        {
            if(finisaveZmones[j].galutinisLaikasSekundemis<finisaveZmones[max].galutinisLaikasSekundemis || (finisaveZmones[j].galutinisLaikasSekundemis==finisaveZmones[max].galutinisLaikasSekundemis && (strcmp(finisaveZmones[j].vardas, finisaveZmones[max].vardas)<0)))
            {
                max=j;
            }
        }
        if(max!=i)
        {
            swap (finisaveZmones[i], finisaveZmones[max]);
        }
    }
}

void MerginiuIsvedimas(int finisavusiuMerginu, Slidininkas*& finisavusiosMerginos, ofstream& rezultatai)
{
    int h, m, s;
    rezultatai << "Merginos " << endl;
    for(int i=0; i<finisavusiuMerginu; i++)
    {
        rezultatai << finisavusiosMerginos[i].numeris << " " << finisavusiosMerginos[i].vardas << " ";
        h = finisavusiosMerginos[i].galutinisLaikasSekundemis/3600;
        m = (finisavusiosMerginos[i].galutinisLaikasSekundemis-h*3600)/60;
        s = finisavusiosMerginos[i].galutinisLaikasSekundemis%60;
        rezultatai << h << " " << m << " " << s << endl;
    }
}

void VaikinuIsvedimas(int finisavusiuVaikinu, Slidininkas*& finisaveVaikinai, ofstream& rezultatai)
{
    int h, m, s;
    rezultatai << "Vaikinai " << endl;
    for(int i=0; i<finisavusiuVaikinu; i++)
    {
        rezultatai << finisaveVaikinai[i].numeris << " " << finisaveVaikinai[i].vardas << " ";
        h = finisaveVaikinai[i].galutinisLaikasSekundemis/3600;
        m = (finisaveVaikinai[i].galutinisLaikasSekundemis-h*3600)/60;
        s = finisaveVaikinai[i].galutinisLaikasSekundemis%60;
        rezultatai << h << " " << m << " " << s << endl;
    }
}

