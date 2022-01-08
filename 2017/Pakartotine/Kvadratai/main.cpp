#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

struct Spalva
{
    int r;
    int g;
    int b;
};

struct Kvadratas
{
    int x_0;
    int y_0;
    int ilgis;
    Spalva spalva;
};

struct Piesinys
{
    int pabaigos_X=0;
    int pabaigos_Y=0;
    Spalva langeliuSpalva[100][100];

    Piesinys()
    {
        for(int i=0; i<100; i++)
        {
            for(int j=0; j<100; j++)
            {
                langeliuSpalva[i][j].r=255;
                langeliuSpalva[i][j].g=255;
                langeliuSpalva[i][j].b=255;
            }
        }
    }
};

void Nuskaitymas(int&n, Kvadratas*& kvadratai);
void VienoKvadratoUzspalvinimas(Kvadratas kvadratas, Piesinys& piesinys);
void PiesinioNupiesimas(int n, Kvadratas*& kvadratai, Piesinys& piesinys);
void PabaigosKordinaciuRadimas(Piesinys& piesinys, int n, Kvadratas*& kvadratai);
void Isvedimas(int n, Piesinys& piesinys, Kvadratas*& kvadratai);


int main()
{
    int n;
    Kvadratas* kvadratai=nullptr;
    Piesinys piesinys;

    Nuskaitymas(n, kvadratai);
    PiesinioNupiesimas(n, kvadratai, piesinys);
    PabaigosKordinaciuRadimas(piesinys, n, kvadratai);
    Isvedimas(n, piesinys, kvadratai);

    delete[] kvadratai;
    return 0;
}

void Nuskaitymas(int&n, Kvadratas*& kvadratai)
{
    ifstream duomenys("duomenys.txt");
    duomenys >> n;
    kvadratai = new Kvadratas[n];
    for(int i=0; i<n; i++)
    {
        duomenys >> kvadratai[i].x_0 >> kvadratai[i].y_0 >> kvadratai[i].ilgis;
        duomenys >> kvadratai[i].spalva.r;
        duomenys >> kvadratai[i].spalva.g;
        duomenys >> kvadratai[i].spalva.b;
    }
    duomenys.close();
}

void VienoKvadratoUzspalvinimas(Kvadratas kvadratas, Piesinys& piesinys)
{
    for(int i=kvadratas.x_0; i<kvadratas.x_0+kvadratas.ilgis; i++)
    {
        for(int j=kvadratas.y_0; j<kvadratas.y_0+kvadratas.ilgis; j++)
        {
            if(piesinys.langeliuSpalva[i][j].r==255 && piesinys.langeliuSpalva[i][j].g==255 && piesinys.langeliuSpalva[i][j].b==255)
            {
                piesinys.langeliuSpalva[i][j]=kvadratas.spalva;
            }
        }
    }
}

void PiesinioNupiesimas(int n, Kvadratas*& kvadratai, Piesinys& piesinys)
{
    for(int i=0; i<n; i++)
    {
        VienoKvadratoUzspalvinimas(kvadratai[i], piesinys);
    }
}

void PabaigosKordinaciuRadimas(Piesinys& piesinys, int n, Kvadratas*& kvadratai)
{
    for(int i=0; i<n; i++)
    {
        if(kvadratai[i].x_0+kvadratai[i].ilgis>piesinys.pabaigos_X) piesinys.pabaigos_X = kvadratai[i].x_0+kvadratai[i].ilgis;
        if(kvadratai[i].x_0+kvadratai[i].ilgis>piesinys.pabaigos_Y) piesinys.pabaigos_Y = kvadratai[i].y_0+kvadratai[i].ilgis;
    }
}

void Isvedimas(int n, Piesinys& piesinys, Kvadratas*& kvadratai)
{
    cout << piesinys.pabaigos_X << " " << piesinys.pabaigos_Y << endl;
    for(int i=0; i<piesinys.pabaigos_X; i++)
    {
        for(int j=0; j<piesinys.pabaigos_Y; j++)
        {
            cout << piesinys.langeliuSpalva[j][i].r << " " << piesinys.langeliuSpalva[j][i].g << " " << piesinys.langeliuSpalva[j][i].b << endl;
        }
    }
}








