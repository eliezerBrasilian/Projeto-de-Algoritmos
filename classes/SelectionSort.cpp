#include "headers/SelectionSort.h"
#include "headers/Arquivo.h"
#include "headers/Aleatorio.h"
#include <time.h>
#include <string>

using namespace std;
void SelectionSort::operacoes(string tipoDeAlgoritmo, string tipoDeOrdenacao, int size){
    
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
    
    arquivo.salvarEntrada("selectOnSort",tipoDeOrdenacao,size,vetor);
    
    crescente(size,vetor);   
    fim = clock();
    tempoTotalGasto = ((double)(fim - inicio)/CLOCKS_PER_SEC);
    
    arquivo.salvarSaida("selectOnSort",tipoDeOrdenacao,size,vetor);
    arquivo.salvarTempo("selectOnSort",tipoDeOrdenacao,size,tempoTotalGasto);

    system("pause");
}

void SelectionSort::crescente(int size,int *vetor){
     int i, j, minIndex;

    for (i = 0; i < size - 1; i++) {
        minIndex = i;

        for (j = i + 1; j < size; j++) {
            if (vetor[j] < vetor[minIndex]) {
                minIndex = j;
            }
        }

        int temp = vetor[i];
        vetor[i] = vetor[minIndex];
        vetor[minIndex] = temp;
    }

}

void SelectionSort::decrescente(int size,int *vetor){
    
      int i, j, minIndex;

    for (i = 0; i < size - 1; i++) {
        minIndex = i;

        for (j = i + 1; j < size; j++) {
            if (vetor[j] > vetor[minIndex]) {
                minIndex = j;
            }
        }

        int temp = vetor[i];
        vetor[i] = vetor[minIndex];
        vetor[minIndex] = temp;
    }
}