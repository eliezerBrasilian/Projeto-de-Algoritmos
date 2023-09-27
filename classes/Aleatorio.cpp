#include "headers/Aleatorio.h"
#include <cstdio>
#include <time.h>
#include <cstdlib>
int* Aleatorio::gerarSequencia(int size) {
    int *vetor = new int[size];

    for (int i = 0; i < size; i++) {
        vetor[i] = rand() % 10;
    }

    return vetor;
}

void Aleatorio::embalhararNumeros(int vetor[], int size){
    srand(time(NULL));
 
     for(int i= size -1 ; i > 0 ; i--){
        int j = rand()% (i+1);
        int temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
     }

}
