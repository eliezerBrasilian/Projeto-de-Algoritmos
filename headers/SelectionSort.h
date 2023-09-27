#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H
#include "headers/Ordenacao.h"
#include <string>
class SelectionSort : Ordenacao
{

public:
   void crescente(int,int*) override;
   void decrescente(int,int*) override;
   void operacoes(std::string,std::string,int) override;
};

#endif
