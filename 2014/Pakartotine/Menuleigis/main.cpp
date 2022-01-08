#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct Komanda
{
    int k;
    int X;
    int Y;
    int funkcijos[30];
    int ivykdyta=0;
    int priezastis;

};

void Nuskaitymas(int&n, int&x0, int& y0, Komanda*& komandos);
void PriezastiesIeskojimas(int n, int x0, int y0, Komanda*& komandos);
void Isvedimas(int n, Komanda*& komandos);

int main()
{
    int n, x0, y0;
    Komanda* komandos = nullptr;

    Nuskaitymas(n, x0, y0, komandos);
    PriezastiesIeskojimas(n, x0, y0, komandos);
    Isvedimas(n, komandos);

    delete[] komandos;
    return 0;
}

void Nuskaitymas(int&n, int&x0, int& y0, Komanda*& komandos)
{
    ifstream duomenys("duomenys.txt");
    duomenys >> x0 >> y0;
    duomenys >> n;
    komandos = new Komanda[n];
    for(int i=0; i<n; i++)
    {
        duomenys >> komandos[i].k;
        //cout << komandos[i].k << " ";
        for(int j=0; j<komandos[i].k; j++)
        {
            duomenys >> komandos[i].funkcijos[j];
            //cout << komandos[i].funkcijos[j] << " ";
        }
        //cout << endl;
    }
    duomenys.close();
}

void PriezastiesIeskojimas(int n, int x0, int y0, Komanda*& komandos)
{
    for(int i=0; i<n; i++)
    {
        komandos[i].X=x0;
        komandos[i].Y=y0;
        for(int j=0; j<komandos[i].k; j++)
        {
            if(komandos[i].funkcijos[j]==1)
            {
                komandos[i].X++;
                komandos[i].Y++;
            }
            if(komandos[i].funkcijos[j]==2)
            {
                komandos[i].X++;
                komandos[i].Y--;
            }
            if(komandos[i].funkcijos[j]==3)
            {
                komandos[i].X--;
                komandos[i].Y--;
            }
            if(komandos[i].funkcijos[j]==4)
            {
                komandos[i].X--;
                komandos[i].Y++;
            }
            komandos[i].ivykdyta++;

            if(komandos[i].X==x0 && komandos[i].Y==y0)
            {
                komandos[i].priezastis=2;
                break;
            }

            else komandos[i].priezastis=1;
        }
    }
}

void Isvedimas(int n, Komanda*& komandos)
{
    for(int i=0; i<n; i++)
    {
        if(komandos[i].priezastis==1)
        {
            cout << setw(20) << left <<  "sekos pabaiga ";
            for(int j=0; j<komandos[i].ivykdyta; j++)
            {
                cout << komandos[i].funkcijos[j] << " ";
            }
            cout << komandos[i].ivykdyta << " ";
            cout << komandos[i].X << " " << komandos[i].Y << " " ;
            cout << endl;
        }
        else
        {
            cout << setw(20) << left << "pasiektas tikslas ";
            for(int j=0; j<komandos[i].ivykdyta; j++)
            {
                cout << komandos[i].funkcijos[j] << " ";
            }
            cout << komandos[i].ivykdyta << endl;
        }
    }
}








