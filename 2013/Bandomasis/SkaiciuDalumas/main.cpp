#include <iostream>
#include <fstream>
using namespace std;

int main()
/*{
    int rezultatas=0;
    for(int i=1000; i<=9999; i++)
    {
        if(i%3==0)
            rezultatas++;
    }
    ofstream rezultatai("rezultatai.txt");
    rezultatai << rezultatas << endl;
    return 0;
}*/

{
    int rezultatas=0;
    for(int i=1002; i<=9999; i+=3)
    {
        rezultatas++;
    }
    cout << rezultatas << endl;
    return 0;
}
