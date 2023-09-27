#include "Arquivo.h"
#include "Aleatorio.h"
#include "InsertionSort.h"
#include <time.h>
void InsertionSort::operacoes(string tipoDeAlgoritmo, string tipoDeOrdenacao, int size){
    
    Arquivo arquivo;
    clock_t inicio, fim;
    inicio = clock();
    double tempoTotalGasto;
    int *vetor = new int[size];


   if(tipoDeOrdenacao == "aleatorio"){
   Aleatorio aleatorio;

    vetor = aleatorio.gerarSequencia(size);
    arquivo.salvarEntrada(tipoDeAlgoritmo,tipoDeOrdenacao,size,vetor);
    aleatorio.embalhararNumeros(vetor,size);
   }

    else if(tipoDeOrdenacao == "crescente"){
        for(int i = 0; i < size; i++){
        vetor[i] = i;
        }
        arquivo.salvarEntrada(tipoDeAlgoritmo,tipoDeOrdenacao,size,vetor);
        InsertionSort ordenacao;
        ordenacao.crescente(size,vetor);
        
    }
    else if(tipoDeOrdenacao == "decrescente"){
        for(int i = 0; i < size; i++){
        vetor[i] = i;
        }
        arquivo.salvarEntrada(tipoDeAlgoritmo,tipoDeOrdenacao,size,vetor);
        InsertionSort ordenacao;
        ordenacao.decrescente(size,vetor);
    }

    fim = clock();
    tempoTotalGasto = ((double)(fim - inicio)/CLOCKS_PER_SEC);
    
    arquivo.salvarSaida(tipoDeAlgoritmo,tipoDeOrdenacao,size,vetor);
    arquivo.salvarTempo(tipoDeAlgoritmo,tipoDeOrdenacao,size,tempoTotalGasto);

    system("pause");
}


void InsertionSort::crescente(int size,int *vetor){
      int chave;
        int i;

    for (int j = 1; j < size; j++) {
        chave = vetor[j];
          i = j - 1;

         while (i >= 0 && vetor[i] > chave) {
            vetor[i + 1] = vetor[i];
            i = i - 1;
              }
        vetor[i + 1] = chave;
    }

}
void InsertionSort::decrescente(int size,int *vetor){
      int chave;
        int i;

    for (int j = 1; j < size; j++) {
        chave = vetor[j];
          i = j - 1;

         while (i >= 0 && vetor[i] < chave) {
            vetor[i + 1] = vetor[i];
            i = i - 1;
              }
        vetor[i + 1] = chave;
    }

}