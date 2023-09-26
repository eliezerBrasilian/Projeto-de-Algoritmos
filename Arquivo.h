#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>

using namespace std::chrono;
using namespace std;
class Arquivo
{
public:
    ofstream geraArquivo(int,string);
    void escreveNoArquivo(ofstream&,const vector<int>&);
    void escreveTamanho(ofstream&,int);
    void escreveTempoGasto(ofstream&,double);
};



void Arquivo::escreveNoArquivo(ofstream& nome_arquivo,const vector<int>& sequencia){
    // nome_arquivo << sequencia << "\n\n";
     for (int i = 0; i < sequencia.size(); i++) {
        nome_arquivo << sequencia[i] << " ";
    }
     nome_arquivo << "\n\n";
}

ofstream Arquivo::geraArquivo(int size,string nome_arquivo){
    nome_arquivo += to_string(size);
    nome_arquivo += ".txt";
    
    ofstream arquivoSaida(nome_arquivo);

    // if (!arquivoSaida.is_open()) {
    //     cerr << "Erro ao abrir o arquivo de saída." << endl;
    //     return;
    // }
    return arquivoSaida;
}

void Arquivo::escreveTamanho(ofstream& nome_arquivo, int size){
    nome_arquivo << to_string(size) << "\n";
}
void Arquivo::escreveTempoGasto(ofstream& nome_arquivo, double tempo){
    std::cout << "Tempo gasto: " << tempo << " milisegundos." << endl;
    nome_arquivo << "Tempo gasto: " << to_string(tempo) << " milisegundos.";
}