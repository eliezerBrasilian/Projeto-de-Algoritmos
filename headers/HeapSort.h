#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "headers/Ordenacao.h"
using namespace std;

class HeapSort : public Ordenacao
{

public:
   void crescente(int,int*) override;
   void decrescente(int,int*) override;
   void ajustarHeap_crescente(int*, int, int);
   void ajustarHeap_decrescente(int*, int, int);
   void operacoes(string,string,int) override;//crescente, aleatorio, decrescente
};

#endif
