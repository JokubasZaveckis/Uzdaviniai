#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct Spalva
{
    int r;
    int g;
    int b;
};

struct Kvadratas
{
    int x, y, dx, dy;
    Spalva spalva;
};

struct Piesinys
{
    int pabaigos_X=0;
    int pabaigos_Y=0;
    Spalva langeliuSpalva[100][100];

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

    for(int i=0; i<100; i++)
    {
        for(int j=0; j<100; j++)
        {
            piesinys.langeliuSpalva[i][j].r=255;
            piesinys.langeliuSpalva[i][j].g=255;
            piesinys.langeliuSpalva[i][j].b=255;
        }
    }

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
        duomenys >> kvadratai[i].x >> kvadratai[i].y >> kvadratai[i].dx >> kvadratai[i].dy;
        duomenys >> kvadratai[i].spalva.r;
        duomenys >> kvadratai[i].spalva.g;
        duomenys >> kvadratai[i].spalva.b;
    }
    duomenys.close();
}

void VienoKvadratoUzspalvinimas(Kvadratas kvadratas, Piesinys& piesinys)
{
    for(int i=kvadratas.x; i<kvadratas.x+kvadratas.dx; i++)
    {
        for(int j=kvadratas.y; j<kvadratas.y+kvadratas.dy; j++)
        {
            piesinys.langeliuSpalva[i][j]=kvadratas.spalva;
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
        if(kvadratai[i].x+kvadratai[i].dx>piesinys.pabaigos_X) piesinys.pabaigos_X = kvadratai[i].x+kvadratai[i].dx;
        if(kvadratai[i].x+kvadratai[i].dy>piesinys.pabaigos_Y) piesinys.pabaigos_Y = kvadratai[i].y+kvadratai[i].dy;
    }
}

void Isvedimas(int n, Piesinys& piesinys, Kvadratas*& kvadratai)
{
    cout << piesinys.pabaigos_Y << " " << piesinys.pabaigos_X << endl;
    for(int i=0; i<piesinys.pabaigos_Y; i++)
    {
        for(int j=0; j<piesinys.pabaigos_X; j++)
        {
            cout << piesinys.langeliuSpalva[j][i].r << " " << piesinys.langeliuSpalva[j][i].g << " " << piesinys.langeliuSpalva[j][i].b << endl;
        }
    }
}


