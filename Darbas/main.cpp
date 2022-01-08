#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <unistd.h>

using namespace std;

bool Neigiami();

struct QueueFloat
{
    void Enqueue(float number);
    void EmptyQueue();
    void PrintQueue();


private:
    float* _queue = nullptr;
    int _count = 0;

    void _createAndCopyArray(int _count);
    void _removeFirstCreateAndCopyArray();
};

int main()
{
    srand(time(NULL));
    float x, y, z, skaicius;
    float suma=0;
    QueueFloat eile;
    y=rand()%10;
    for(int i=0; i<y; i++)
    {
        x=rand() % 100;
        z=rand() % 101;
        if(Neigiami())
        {
            skaicius = x/z*-1;
            eile.Enqueue(skaicius);
        }
        else
        {
            skaicius = x/z;
            eile.Enqueue(skaicius);
        }
        suma=suma+skaicius;
    }
    eile.PrintQueue();

    cout << suma << endl;

}

bool Neigiami()
{
    int x;
    x=rand()%3;
    if(x==1)
        return true;

}

void QueueFloat::_createAndCopyArray(int _count)
{
    float* copy = _queue;
    _queue = new float[_count];
    for (int i = 0; i < _count - 1; i++)
    {
        _queue[i] = copy[i];
    }
    delete[] copy;
}

void QueueFloat::_removeFirstCreateAndCopyArray()
{
    for (int i = 0; i < _count - 1; i++)
    {
        _queue[i] = _queue[i + 1];
    }
    _count--;

    _createAndCopyArray(_count+1);
}

void QueueFloat::Enqueue(float number)
{
    _count++;
    _createAndCopyArray(_count);
    _queue[_count - 1] = number;
}

void QueueFloat::PrintQueue()
{
    if(_queue==nullptr)
    {
        cout << "Empty queue" << endl;
        return;
    }
    for (int i = 0; i < _count; i++)
    {
        cout << fixed << setprecision(2) <<  _queue[i] << " ";
    }
    cout << endl;
}
//sukurti eile, duomenu tipas - realieji skaiciai, skaicius sugeneruoti atsitiktine tvarka "dalyba" , main ciklas visu eileje esanciu elementu suma

//bendro tipo eile
