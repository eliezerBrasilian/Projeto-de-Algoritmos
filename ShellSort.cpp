#include "ShellSort.h"
#include "Arquivo.h"
#include "Aleatorio.h"
#include <time.h>
#include <string>

using namespace std;
void ShellSort::operacoes(string tipoDeAlgoritmo, string tipoDeOrdenacao, int size){
    
    Arquivo arquivo;
    clock_t inicio, fim;
    inicio = clock();
    double tempoTotalGasto;
    int *vetor = new int[size];


   if(tipoDeOrdenacao == "aleatorio"){
   Aleatorio aleatorio;

    vetor = aleatorio.gerarSequencia(size);
    arquivo.salvarEntrada("shellSort",tipoDeOrdenacao,size,vetor);
    aleatorio.embalhararNumeros(vetor,size);
   }

    else if(tipoDeOrdenacao == "crescente"){
        for(int i = 0; i < size; i++){
        vetor[i] = i;
        }
        arquivo.salvarEntrada("shellSort",tipoDeOrdenacao,size,vetor);
        ShellSort ordenacao;
        ordenacao.crescente(size,vetor);
        
    }
    else if(tipoDeOrdenacao == "decrescente"){
        for(int i = 0; i < size; i++){
        vetor[i] = i;
        }
        arquivo.salvarEntrada("shellort",tipoDeOrdenacao,size,vetor);
        ShellSort ordenacao;
        ordenacao.decrescente(size,vetor);
    }

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
            for (j = i; j >= intervalo && arr[j - intervalo] > temp; j -= intervalo) {
                arr[j] = arr[j - intervalo];
            }
            arr[j] = temp;
        }
    }
}