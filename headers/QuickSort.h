#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "headers/Ordenacao.h"
using namespace std;

class QuickSort : public Ordenacao
{

public:
   void crescente(int,int*) override;
   void decrescente(int,int*) override;
   void operacoes(string,string,int) override;//crescente, aleatorio, decrescente
};

#endif
