#include "headers/Arquivo.h"
#include "headers/Aleatorio.h"
#include "headers/InsertionSort.h"
#include <time.h>
void InsertionSort::operacoes(string tipoDeAlgoritmo, string tipoDeOrdenacao, int size){
    
    Arquivo arquivo;
    clock_t inicio, fim;
    inicio = clock();
    double tempoTotalGasto;
    int *vetor = new int[size];
    Aleatorio aleatorio;

    for(int i = 0; i < size; i++){
    vetor[i] = i;
    }

    if(tipoDeOrdenacao == "aleatorio")aleatorio.embalhararNumeros(vetor,size);
    if(tipoDeOrdenacao == "decrescente")decrescente(size,vetor);
    if(tipoDeOrdenacao == "crescente")crescente(size,vetor);
       
    arquivo.salvarEntrada(tipoDeAlgoritmo,tipoDeOrdenacao,size,vetor);

    crescente(size,vetor);    
    fim = clock();
    tempoTotalGasto = ((double)(fim - inicio)/CLOCKS_PER_SEC);
    
    arquivo.salvarSaida(tipoDeAlgoritmo,tipoDeOrdenacao,size,vetor);
    arquivo.salvarTempo(tipoDeAlgoritmo,tipoDeOrdenacao,size,tempoTotalGasto);

    system("pause");
}

void InsertionSort::crescente(int size,int *vetor) {
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