#include "headers/MergeSort.h"
#include "headers/Arquivo.h"
#include "headers/Aleatorio.h"
#include <time.h>
#include <string>
#include "stdio.h"
using namespace std;
void MergeSort::operacoes(string tipoDeAlgoritmo, string tipoDeOrdenacao, int size){
    
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
    if(tipoDeOrdenacao == "decrescente")decrescente(vetor, 0 ,size-1);
    if(tipoDeOrdenacao == "crescente")crescente(vetor, 0 ,size-1);

    arquivo.salvarEntrada("mergeSort",tipoDeOrdenacao,size,vetor);
   
    crescente(vetor, 0 ,size-1);
    fim = clock();
    tempoTotalGasto = ((double)(fim - inicio)/CLOCKS_PER_SEC);
    
    arquivo.salvarSaida("mergeSort",tipoDeOrdenacao,size,vetor);
    arquivo.salvarTempo("mergeSort",tipoDeOrdenacao,size,tempoTotalGasto);

    system("pause");
}
void MergeSort::crescenteParaRecursao(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void MergeSort::crescente(int *arr, int left, int right){
  if (left < right) {
        int m = left + (right - left) / 2;
        crescente(arr, left, m);
        crescente(arr, m + 1, right);
        crescenteParaRecursao(arr, left, m, right);
    }
}



void MergeSort::decrescenteParaRecursao(int arr[], int l, int m, int r) {
 int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void MergeSort::decrescente(int *arr, int left, int right){
    printf("esteve aqui\n\n");
  if (left < right) {
        int m = left + (right - left) / 2;
        crescente(arr, left, m);
        crescente(arr, m + 1, right);
        decrescenteParaRecursao(arr, left, m, right);
    }
}