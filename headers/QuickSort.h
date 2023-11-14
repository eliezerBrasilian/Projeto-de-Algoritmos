#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "headers/Ordenacao.h"
using namespace std;

class QuickSort
{

public:
   void operacoes(string,string,int);
   void trocar(int*,int*);
   int particao_versao1(int*,int,int);
   int particao_versao1_decrescente(int*,int,int);
   int particao_versao2(int*,int,int);
   int particao_versao2_decrescente(int*,int,int);
   int mediana_de_tres(int*,int,int);
   int particao_versao3(int*,int,int);
   int particao_versao3_decrescente(int*,int,int);
   int particao_aleatoria(int*,int,int);
   void crescente(int*,int,int,int);
   void decrescente(int*,int,int,int);
   //crescente, aleatorio, decrescente
};

#endif
