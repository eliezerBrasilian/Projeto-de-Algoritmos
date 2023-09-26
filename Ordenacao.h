#include <iostream>
#include "Arquivo.h"
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime>
//#include <Tempo.h>
using namespace std;

class Ordenacao
{

public:
    vector<vector<int>> getCrescente(vector<vector<int>>&);
    vector<vector<int>> getDecrescente(vector<vector<int>>&);
    std::vector<int> getAleatorio(int size);
    void preencherVetorAleatoriamente(std::vector<std::vector<int>>&, int);
    void escreverVetorNoArquivo(Arquivo&,vector<vector<int>>&, int, ofstream&);
    Ordenacao(){
        std::srand(std::time(nullptr));
    }
};


void Ordenacao::escreverVetorNoArquivo(Arquivo& arquivo,vector<vector<int>>& sequencias, int size, ofstream& nome_arquivo){
    const int TAMANHO_DO_VETOR = 10;
        for (int i = 0; i < size; i++) {
        cout << "Sequencia escrita" << i + 1 << ": ";
        for (int j = 0; j < TAMANHO_DO_VETOR; j++) {
            cout << sequencias[i][j] << " ";
        }
        cout << endl;
        arquivo.escreveNoArquivo(nome_arquivo, sequencias[i]);
    }
}
void Ordenacao::preencherVetorAleatoriamente(std::vector<std::vector<int>>& sequencias,int size) {
    const int TAMANHO_DO_VETOR = 10;
    for (int i = 0; i < size; i++) {
        std::vector<int> sequencia = getAleatorio(TAMANHO_DO_VETOR);
        sequencias.push_back(sequencia);
    }
}

std::vector<int> Ordenacao::getAleatorio(int size)
{
    std::vector<int> vetor_gerado(size);

    for (int i = 0; i < size; i++) {
        int digito = std::rand() % 10; 
        vetor_gerado[i] = digito;
    }

    return vetor_gerado;
}
// int Ordenacao::getAleatorio(int size){
//     int *vetor_gerado = new int[size];
//     for (int i = 0; i < size; i++) {
//         int digito = rand() % 10; 
//         vetor_gerado[i] = digito;
//     }
    
//     return *vetor_gerado;
// }



vector<vector<int>> Ordenacao::getCrescente(vector<vector<int>>& sequencias) {
    std::vector<std::vector<int>> sequencias_ordenadas;
    
    for (const std::vector<int>& sequencia : sequencias) {
        std::vector<int> sequencia_ordenada = sequencia; 
        int size = sequencia_ordenada.size();

        int chave;
        int i;

        for (int j = 1; j < size; j++) {
            chave = sequencia_ordenada[j];
            i = j - 1;

            while (i >= 0 && sequencia_ordenada[i] > chave) {
                sequencia_ordenada[i + 1] = sequencia_ordenada[i];
                i = i - 1;
            }
            sequencia_ordenada[i + 1] = chave;
        }

        sequencias_ordenadas.push_back(sequencia_ordenada); 
    }

    return sequencias_ordenadas;
}

vector<vector<int>> Ordenacao::getDecrescente(vector<vector<int>>& sequencias) {
    std::vector<std::vector<int>> sequencias_ordenadas;
    
    for (const std::vector<int>& sequencia : sequencias) {
        std::vector<int> sequencia_ordenada = sequencia; 
        int size = sequencia_ordenada.size();

        int chave;
        int i;

        for (int j = 1; j < size; j++) {
            chave = sequencia_ordenada[j];
            i = j - 1;

    
            while (i >= 0 && sequencia_ordenada[i] < chave) {
                sequencia_ordenada[i + 1] = sequencia_ordenada[i];
                i = i - 1;
            }
            sequencia_ordenada[i + 1] = chave;
        }

        sequencias_ordenadas.push_back(sequencia_ordenada); 
    }

    return sequencias_ordenadas;
}
