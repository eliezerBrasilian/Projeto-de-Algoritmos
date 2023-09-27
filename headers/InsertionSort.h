#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "headers/Ordenacao.h"
using namespace std;

class InsertionSort : public Ordenacao
{

public:
   void crescente(int,int*) override;
   void decrescente(int,int*) override;
   void operacoes(string,string,int) override;//crescente, aleatorio, decrescente
};

#endif
