#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void Nuskaitymas(int rastasAuksas[]);
void Skaiciavimai(int rastasAuksas[], int gautasAuksas[]);
void Isvedimas(int gautasAuksas[], int rastasAuksas[]);

int main()
{
    int rastasAuksas[5];
    int gautasAuksas[10]={0};

    Nuskaitymas(rastasAuksas);
    Skaiciavimai(rastasAuksas, gautasAuksas);
    Isvedimas(gautasAuksas, rastasAuksas);

}

void Nuskaitymas(int rastasAuksas[])
{
    ifstream duomenys("duomenys.txt");
    for(int i=0; i<5; i++)
    {
        duomenys >> rastasAuksas[i];
    }
    duomenys.close();
}

/*void Skaiciavimai(int rastasAuksas[], int gautasAuksas[])
{
    int a, piratai=10;
    for(int i=0; i<5; i++)
    {
        a=rastasAuksas[i];
        for(int j=0; j<10; j++)
        {
            gautasAuksas[0]=a;
            gautasAuksas[j+1]++;
            gautasAuksas[0]--;
        }
    }
}*/
void Skaiciavimai(int rastasAuksas[], int gautasAuksas[])
{
    int piratai=10;
    for(int i=0; i<5; i++)
    {
            for(int j=i+1; j<piratai && rastasAuksas[i]!=0; j++)
            {
                gautasAuksas[j]++;
                rastasAuksas[i]--;
            }
    }
}

void Isvedimas(int gautasAuksas[], int rastasAuksas[])
{
    for(int i=0; i<10; i++)
    {

        cout << gautasAuksas[i]+(i<5? rastasAuksas[i] : 0) << endl;
    }
}
