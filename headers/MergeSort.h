#ifndef MERGESORT_H
#define MERGESORT_H

#include "headers/Ordenacao.h"
using namespace std;

class MergeSort
{

public:
   void crescenteParaRecursao(int*,int,int,int);
   void crescente(int*,int,int);
   void decrescenteParaRecursao(int*,int,int,int);
   void decrescente(int*,int,int);
   void operacoes(string,string,int);//crescente, aleatorio, decrescente
};

#endif
