#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct Skyrius
{
    int skirtiTaskai[3];
};

struct Logotipas
{
    int taskuSuma=0;
    int balsuSuma=0;
};

struct Direktorius
{
    int skirtiTaskai[3];
};

void Nuskaitymas(int&k, Skyrius*& skyriai, Direktorius& direktorius);
void VienoSkyriausTaskuSkaiciavimas(Skyrius skyriai, Logotipas*& logotipai);
void VisuSkyriuSudetiTaskai(int k, Skyrius*& skyriai, Direktorius& direktorius, Logotipas*& logotipai);
void DirektoriausTaskai(Logotipas*& logotipai, Direktorius direktorius);
void BaluSkaiciavimas(int k, Skyrius*& skyriai, Logotipas*& logotipai);
int GeriausioRadimas(int k, Logotipas*& logotipai);
void Isvedimas(int k, Logotipas*& logotipai);

int main()
{
    int k;
    Logotipas* logotipai = new Logotipas[3];
    Skyrius* skyriai = nullptr;
    Direktorius direktorius;

    Nuskaitymas(k, skyriai, direktorius);
    VisuSkyriuSudetiTaskai(k, skyriai, direktorius, logotipai);
    DirektoriausTaskai(logotipai, direktorius);
    BaluSkaiciavimas(k, skyriai, logotipai);
    Isvedimas(k, logotipai);


    delete[] logotipai;
}

void Nuskaitymas(int&k, Skyrius*& skyriai, Direktorius& direktorius)
{
    ifstream duomenys("duomenys.txt");
    duomenys >> k;
    skyriai = new Skyrius[k];

    for(int i=0; i<k; i++)
    {
        for(int j=0; j<3; j++)
        {
            duomenys >> skyriai[i].skirtiTaskai[j];
        }
    }

    for(int i=0; i<3; i++)
    {
        duomenys >> direktorius.skirtiTaskai[i];
    }

    duomenys.close();
}

void VienoSkyriausTaskuSkaiciavimas(Skyrius skyrius, Logotipas*& logotipas)
{
    int geriausias=skyrius.skirtiTaskai[0];
    if(geriausias<skyrius.skirtiTaskai[1])
    {
        geriausias = skyrius.skirtiTaskai[1];
    }
    else if (geriausias<skyrius.skirtiTaskai[2])
    {
        geriausias = skyrius.skirtiTaskai[2];
    }
    //cout << skyrius.skirtiTaskai[0] << " " << skyrius.skirtiTaskai[1] << " " << skyrius.skirtiTaskai[2] << endl;
    //cout << logotipas[0].taskuSuma << " " << logotipas[1].taskuSuma << " " << logotipas[2].taskuSuma << endl;
    if((geriausias!=skyrius.skirtiTaskai[0] && geriausias!=skyrius.skirtiTaskai[1]) || (geriausias!=skyrius.skirtiTaskai[0] && geriausias!=skyrius.skirtiTaskai[2]) || (geriausias!=skyrius.skirtiTaskai[1] && geriausias!=skyrius.skirtiTaskai[2]))
    {
        if(geriausias==skyrius.skirtiTaskai[0]) logotipas[0].taskuSuma+=4;

        else if(geriausias==skyrius.skirtiTaskai[1]) logotipas[1].taskuSuma+=4;

        else logotipas[2].taskuSuma+=4;
    }

    else if(skyrius.skirtiTaskai[0]==skyrius.skirtiTaskai[1] && skyrius.skirtiTaskai[0]!=skyrius.skirtiTaskai[2])
    {
        logotipas[0].taskuSuma+=2;
        logotipas[1].taskuSuma+=2;
    }

    else if(skyrius.skirtiTaskai[0]==skyrius.skirtiTaskai[2] && skyrius.skirtiTaskai[0]!=skyrius.skirtiTaskai[1])
    {
        logotipas[0].taskuSuma+=2;
        logotipas[2].taskuSuma+=2;
    }

    else if(skyrius.skirtiTaskai[1]==skyrius.skirtiTaskai[2] && skyrius.skirtiTaskai[0]!=skyrius.skirtiTaskai[1])
    {
        logotipas[1].taskuSuma+=2;
        logotipas[2].taskuSuma+=2;
    }
    //cout << logotipas[0].taskuSuma << " " << logotipas[1].taskuSuma << " " << logotipas[2].taskuSuma << endl;
}

void VisuSkyriuSudetiTaskai(int k, Skyrius*& skyriai, Direktorius& direktorius, Logotipas*& logotipai)
{
    for(int i=0; i<k; i++)
    {
        VienoSkyriausTaskuSkaiciavimas(skyriai[i], logotipai);
    }
}

void DirektoriausTaskai(Logotipas*& logotipai, Direktorius direktorius)
{
    if(logotipai[0].taskuSuma==logotipai[1].taskuSuma && logotipai[0].taskuSuma>logotipai[2].taskuSuma)
    {
        logotipai[0].taskuSuma+=direktorius.skirtiTaskai[0];
        logotipai[1].taskuSuma+=direktorius.skirtiTaskai[1];
    }
    else if(logotipai[0].taskuSuma==logotipai[2].taskuSuma && logotipai[0].taskuSuma>logotipai[1].taskuSuma)
    {
        logotipai[0].taskuSuma+=direktorius.skirtiTaskai[0];
        logotipai[2].taskuSuma+=direktorius.skirtiTaskai[2];
    }
    else if(logotipai[1].taskuSuma==logotipai[2].taskuSuma && logotipai[0].taskuSuma<logotipai[2].taskuSuma)
    {
        logotipai[1].taskuSuma+=direktorius.skirtiTaskai[1];
        logotipai[2].taskuSuma+=direktorius.skirtiTaskai[2];
    }
    else
    {
        logotipai[0].taskuSuma+=direktorius.skirtiTaskai[0];
        logotipai[1].taskuSuma+=direktorius.skirtiTaskai[1];
        logotipai[2].taskuSuma+=direktorius.skirtiTaskai[2];
    }
}

void BaluSkaiciavimas(int k, Skyrius*& skyriai, Logotipas*& logotipai)
{
    for(int i=0; i<k; i++)
    {
        for(int j=0; j<3; j++)
        {
            logotipai[j].balsuSuma+=skyriai[i].skirtiTaskai[j];
        }
    }
}

int GeriausioRadimas(int k, Logotipas*& logotipai)
{
    int max=0;
    for(int i=1; i<3; i++)
    {
        if(logotipai[i].taskuSuma>logotipai[max].taskuSuma) max=i;
    }
    return max;
}

void Isvedimas(int k, Logotipas*& logotipai)
{
    int max = GeriausioRadimas(k, logotipai);
    for(int i=0; i<3; i++)
    {
        cout << logotipai[i].balsuSuma << " ";
    }
    cout << endl;
    for(int i=0; i<3; i++)
    {
        cout << logotipai[i].taskuSuma << " ";
    }
    cout << endl;
    cout << max+1 << endl;
}

