#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <string>
class Ordenacao{
    public:
    virtual void crescente(int,int*) = 0;
    virtual void decrescente(int,int*) = 0;
    virtual void operacoes(std::string,std::string,int) = 0;
};


#endif