#include "headers/BubbleSort.h"
#include "headers/Arquivo.h"
#include "headers/Aleatorio.h"
#include <time.h>
#include <string>

using namespace std;
void BubbleSort::operacoes(string tipoDeAlgoritmo, string tipoDeOrdenacao, int size){
    
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

    arquivo.salvarEntrada("bubbleSort",tipoDeOrdenacao,size,vetor);
      
    crescente(size,vetor);    
    fim = clock();
    tempoTotalGasto = ((double)(fim - inicio)/CLOCKS_PER_SEC);
    
    arquivo.salvarSaida("bubbleSort",tipoDeOrdenacao,size,vetor);
    arquivo.salvarTempo("bubbleSort",tipoDeOrdenacao,size,tempoTotalGasto);

    system("pause");
}

void BubbleSort::crescente(int n,int *arr){
  int temp, trocou;
    do {
        trocou = 0;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                trocou = 1;
            }
        }
    } while (trocou);

}
void BubbleSort::decrescente(int n,int *arr){
int temp, trocou;
    do {
        trocou = 0;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] < arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                trocou = 1;
            }
        }
    } while (trocou);
}