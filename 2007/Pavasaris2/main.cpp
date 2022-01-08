#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void Nuskaitymas(int ryte[],int diena[], int vakare[]);
int MaxTemp(int ryte[],int diena[], int vakare[]);
void Isvedimas1(int ryte[],int diena[], int vakare[]);
void Isvedimas2(int ryte[],int diena[], int vakare[]);

int main()
{
    int ryte[32]={0}, diena[32]={0}, vakare[32]={0};
    Nuskaitymas(ryte, diena, vakare);
    Isvedimas1(ryte,diena, vakare);
    Isvedimas2(ryte,diena, vakare);
    return 0;
}
void Nuskaitymas(int ryte[],int diena[], int vakare[])
{
    ifstream duomenys("U1duom.txt");
    int n, a;
    duomenys >> n;
    for(int i=0; i<n; i++)
    {
        duomenys >> a;
        duomenys >> ryte[a] >> diena[a] >> vakare[a];
    }
    cout << n;
    duomenys.close();
}
int MaxTemp(int ryte[],int diena[], int vakare[])
{
    int max = INT_MIN;
    for(int i=1; i<32; i++)
    {
        if(ryte[i]>diena[i] && ryte[i]>vakare[i] && ryte[i]>max)
            max = ryte[i];
        else if(diena[i]>vakare[i] && diena[i]>max)
            max = diena[i];
        else if(vakare[i]>max)
            max = vakare[i];
    }
    cout << endl;
    cout << max;
    return max;
}
void Isvedimas1(int ryte[],int diena[], int vakare[])
{
    int max = MaxTemp(ryte,diena, vakare);
    ofstream duomenys("U2rez.txt");
    for(int i=0; i<32; i++)
    {
        if(ryte[i]==max || diena[i]==max || vakare[i]==max) duomenys << i << " ";
    }
    duomenys << endl;
    duomenys.close();
}
void Isvedimas2(int ryte[],int diena[], int vakare[])
{
    ofstream duomenys("U2rez.txt", std::fstream::app);
    for(int i=0; i<32; i++)
    {
        if(diena[i]>=20 && ryte[i]>=20 && vakare[i]>=20)
            duomenys << i << " ";
    }
    duomenys.close();
}
//strukturom
