#include "grybavimas.h"

void Grybavimas::Suma()
{
    bendraSuma = baravykai+raudonikiai+lepsiai;
}

void Grybavimas::Prideti(Grybavimas grybavimas)
{
    baravykai += grybavimas.baravykai;
    raudonikiai += grybavimas.raudonikiai;
    lepsiai += grybavimas.lepsiai;
}
