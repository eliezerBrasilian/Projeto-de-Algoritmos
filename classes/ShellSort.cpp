#include "headers/ShellSort.h"
#include "headers/Arquivo.h"
#include "headers/Aleatorio.h"
#include <time.h>
#include <string>

using namespace std;
void ShellSort::operacoes(string tipoDeAlgoritmo, string tipoDeOrdenacao, int size){
    
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

    arquivo.salvarEntrada("shellSort",tipoDeOrdenacao,size,vetor);
   
    crescente(size,vetor);
    fim = clock();
    tempoTotalGasto = ((double)(fim - inicio)/CLOCKS_PER_SEC);
    
    arquivo.salvarSaida("shellSort",tipoDeOrdenacao,size,vetor);
    arquivo.salvarTempo("shellSort",tipoDeOrdenacao,size,tempoTotalGasto);

    system("pause");
}


void ShellSort::crescente(int n,int *arr){
  int intervalo, i, j, temp;
    for (intervalo = n / 2; intervalo > 0; intervalo /= 2) {
        for (i = intervalo; i < n; i++) {
            temp = arr[i];
            for (j = i; j >= intervalo && arr[j - intervalo] > temp; j -= intervalo) {
                arr[j] = arr[j - intervalo];
            }
            arr[j] = temp;
        }
    }

}
void ShellSort::decrescente(int n,int *arr){
  int intervalo, i, j, temp;
    for (intervalo = n / 2; intervalo > 0; intervalo /= 2) {
        for (i = intervalo; i < n; i++) {
            temp = arr[i];
            for (j = i; j >= intervalo && arr[j - intervalo] < temp; j -= intervalo) {
                arr[j] = arr[j - intervalo];
            }
            arr[j] = temp;
        }
    }
}