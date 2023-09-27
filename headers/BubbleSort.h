#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include <string>
#include "headers/Ordenacao.h"
class BubbleSort : public Ordenacao
{

public:
   void crescente(int,int*) override;
   void decrescente(int,int*) override;
   void operacoes(std::string,std::string,int);
};

#endif
