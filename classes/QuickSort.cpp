#include "headers/QuickSort.h"
#include "headers/Arquivo.h"
#include "headers/Aleatorio.h"
#include "headers/Menu.h"
#include <time.h>
#include <string>
#include "stdio.h"
using namespace std;

void QuickSort::operacoes(string tipoDeAlgoritmo, string tipoDeOrdenacao, int size){
    
    Arquivo arquivo;
    clock_t inicio, fim;
    inicio = clock();
    double tempoTotalGasto;
    int retornoparticao;
    int *vetor = new int[size];
    Aleatorio aleatorio;
    Menu particao;

    for(int i = 0; i < size; i++){
        vetor[i] = i;
        }

    if(tipoDeOrdenacao == "aleatorio"){
    retornoparticao = particao.particao();
    aleatorio.embalhararNumeros(vetor,size);}

    if(tipoDeOrdenacao == "decrescente"){
    retornoparticao = particao.particao();
    decrescente(vetor, 0 ,size - 1,retornoparticao);
    }

    if(tipoDeOrdenacao == "crescente"){
    retornoparticao = particao.particao();
    crescente(vetor, 0 , size-1,retornoparticao);
    }

    arquivo.salvarEntrada("quickSort",tipoDeOrdenacao,size,vetor);
   
    crescente(vetor, 0 ,size-1,retornoparticao);
    fim = clock();
    tempoTotalGasto = ((double)(fim - inicio)/CLOCKS_PER_SEC);
    
    arquivo.salvarSaida("quickSort",tipoDeOrdenacao,size,vetor);
    arquivo.salvarTempo("quickSort",tipoDeOrdenacao,size,tempoTotalGasto);

    system("pause");
}



// Função para trocar dois elementos de um array
void QuickSort::trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para encontrar o pivô usando o primeiro elemento
int QuickSort::particao_versao1(int arr[], int baixo, int alto) {
    int pivo = arr[baixo];
    int i = baixo;
    for (int j = baixo + 1; j <= alto; j++) {
        if (arr[j] < pivo) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[baixo], &arr[i]);
    return i;
}


int QuickSort::particao_versao1_decrescente(int arr[], int baixo, int alto) {
    int pivo = arr[baixo];
    int i = baixo;
    for (int j = baixo + 1; j <= alto; j++) {
        if (arr[j] > pivo) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[baixo], &arr[i]);
    return i;
}

// Função para encontrar o pivô usando a média
int QuickSort::particao_versao2(int arr[], int baixo, int alto) {
    int meio = (baixo + alto) / 2;
    trocar(&arr[meio], &arr[baixo]);
    return particao_versao1(arr, baixo, alto);
}

int QuickSort::particao_versao2_decrescente(int arr[], int baixo, int alto) {
    int meio = (baixo + alto) / 2;
    trocar(&arr[meio], &arr[baixo]);
    return particao_versao1_decrescente(arr, baixo, alto);
}

// Função para encontrar o pivô usando a mediana de três elementos
int QuickSort::mediana_de_tres(int arr[], int baixo, int alto) {
    int meio = (baixo + alto) / 2;
    if (arr[baixo] > arr[meio]) {
        trocar(&arr[baixo], &arr[meio]);
    }
    if (arr[meio] > arr[alto]) {
        trocar(&arr[meio], &arr[alto]);
    }
    if (arr[baixo] > arr[meio]) {
        trocar(&arr[baixo], &arr[meio]);
    }
    return meio;
}

int QuickSort::particao_versao3(int arr[], int baixo, int alto) {
    int indice_pivo = mediana_de_tres(arr, baixo, alto);
    trocar(&arr[indice_pivo], &arr[baixo]);
    return particao_versao1(arr, baixo, alto);
}

int QuickSort::particao_versao3_decrescente(int arr[], int baixo, int alto) {
    int indice_pivo = mediana_de_tres(arr, baixo, alto);
    trocar(&arr[indice_pivo], &arr[baixo]);
    return particao_versao1_decrescente(arr, baixo, alto);
}

// Função para encontrar o pivô escolhendo aleatoriamente
int QuickSort::particao_aleatoria(int arr[], int baixo, int alto) {
    int aleatorio = baixo + rand() % (alto - baixo + 1);
    trocar(&arr[aleatorio], &arr[baixo]);
    return particao_versao1(arr, baixo, alto);
}

// Função Quicksort principal

void QuickSort::crescente(int arr[], int baixo, int alto, int tipo_particao) {
    if (baixo < alto) {
        int indice_pivo;
        switch (tipo_particao) {
            case 1:
                indice_pivo = particao_versao1(arr, baixo, alto);
                break;
            case 2:
                indice_pivo = particao_versao2(arr, baixo, alto);
                break;
            case 3:
                indice_pivo = particao_versao3(arr, baixo, alto);
                break;
            case 4:
                indice_pivo = particao_aleatoria(arr, baixo, alto);
                break;
            default:
                printf("Versão não reconhecida\n");
                return;
        }

        crescente(arr, baixo, indice_pivo - 1, tipo_particao);
        crescente(arr, indice_pivo + 1, alto, tipo_particao);
    }
}


void QuickSort::decrescente(int arr[], int baixo, int alto, int tipo_particao) {
    if (baixo < alto) {
        int indice_pivo;
        switch (tipo_particao) {
            case 1:
                indice_pivo = particao_versao1_decrescente(arr, baixo, alto);
                break;
            case 2:
                indice_pivo = particao_versao2_decrescente(arr, baixo, alto);
                break;
            case 3:
                indice_pivo = particao_versao3_decrescente(arr, baixo, alto);
                break;
            case 4:
                indice_pivo = particao_aleatoria(arr, baixo, alto);
                break;
            default:
                printf("Versão não reconhecida\n");
                return;
        }

        decrescente(arr, baixo, indice_pivo - 1, tipo_particao);
        decrescente(arr, indice_pivo + 1, alto, tipo_particao);
    }
}