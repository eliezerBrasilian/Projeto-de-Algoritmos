#ifndef SHELLSORT_H
#define SHELLSORT_H
#include <string>
#include "headers/Ordenacao.h"
class ShellSort : Ordenacao
{

public:
   void crescente(int,int*) override;
   void decrescente(int,int*) override;
   void operacoes(std::string,std::string,int) override;
};

#endif
