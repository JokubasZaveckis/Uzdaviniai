#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    ifstream byla("byla.txt");
    int n, kiekis[20];
    float kaina[20], biudzetas;
    byla>>n;
    for (int i=0; i<n; i++)
    {
        byla >> kiekis[i];
        byla >> kaina[i];
    }
    byla>>biudzetas;
    byla.close();

    //brangiausia
    int max=0;
    for (int i=1; i<n; i++)
    {
        if (kaina[i]>kaina[max]) max = i;
    }

    //pigiausia
    int min=0;
    for (int i=1; i<n; i++)
    {
        if (kaina[i] < kaina[min]) min = i;
    }

    //brangiausia kiekiu
     float maxb = 0;
     for (int i=1; i<n; i++)
     {
         if (kiekis[i]*kaina[i]>kiekis[maxb]*1.0*kaina[maxb]) maxb = i;
     }
    cout << maxb << endl;
    return 0;
}
