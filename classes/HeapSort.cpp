#include "headers/HeapSort.h"
#include "headers/Arquivo.h"
#include "headers/Aleatorio.h"
#include <time.h>
#include <string>

using namespace std;
void HeapSort::operacoes(string tipoDeAlgoritmo, string tipoDeOrdenacao, int size){
    
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
    
    arquivo.salvarEntrada("heapSort",tipoDeOrdenacao,size,vetor);
    
    crescente(size,vetor);   
    fim = clock();
    tempoTotalGasto = ((double)(fim - inicio)/CLOCKS_PER_SEC);
    
    arquivo.salvarSaida("heapSort",tipoDeOrdenacao,size,vetor);
    arquivo.salvarTempo("heapSort",tipoDeOrdenacao,size,tempoTotalGasto);

    system("pause");
}

void HeapSort::ajustarHeap_crescente(int *vetor, int n, int i) {
    int maior = i;
    int filhoEsquerda = 2 * i + 1;
    int filhoDireita = 2 * i + 2;

    if (filhoEsquerda < n && vetor[filhoEsquerda] > vetor[maior])
        maior = filhoEsquerda;

    if (filhoDireita < n && vetor[filhoDireita] > vetor[maior])
        maior = filhoDireita;

    if (maior != i) {
        std::swap(vetor[i], vetor[maior]);
        ajustarHeap_crescente(vetor, n, maior);
    }
}

void HeapSort::crescente(int tamanho, int *vetor) {
    
    for (int i = tamanho / 2 - 1; i >= 0; i--)
        ajustarHeap_crescente(vetor, tamanho, i);

    for (int i = tamanho - 1; i > 0; i--) {
        std::swap(vetor[0], vetor[i]);  
        ajustarHeap_crescente(vetor, i, 0); 
    }
}



void HeapSort::ajustarHeap_decrescente(int *vetor, int n, int i) {
    int maior = i;
    int filhoEsquerda = 2 * i + 1;
    int filhoDireita = 2 * i + 2;

    if (filhoEsquerda < n && vetor[filhoEsquerda] > vetor[maior])
        maior = filhoEsquerda;

    if (filhoDireita < n && vetor[filhoDireita] > vetor[maior])
        maior = filhoDireita;

    if (maior != i) {
        std::swap(vetor[i], vetor[maior]);
        ajustarHeap_decrescente(vetor, n, maior);
    }
}


void HeapSort::decrescente(int tamanho,int *vetor){
      for (int i = tamanho / 2 - 1; i >= 0; i--)
        ajustarHeap_decrescente(vetor, tamanho, i);

    for (int i = tamanho - 1; i > 0; i--) {
        std::swap(vetor[0], vetor[i]);  
        ajustarHeap_decrescente(vetor, i, 0); 
    }
}