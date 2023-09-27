#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <string>

class Arquivo {
public:
    Arquivo(); // Construtor

    void salvarEntrada(std::string tipoDeAlgoritmo, std::string tipoDeOrdenacao, int size, int *vetor);
    void salvarSaida(std::string tipoDeAlgoritmo, std::string tipoDeOrdenacao, int size, int *vetor);
    void salvarTempo(std::string tipoDeAlgoritmo, std::string tipoDeOrdenacao, int size, double tempoTotalGasto);
};

#endif // ARQUIVO_H
