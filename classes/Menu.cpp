#include "headers/Menu.h"
#include <iostream>
#include <cctype> // Para a função tolower
#include <stdio.h>
#include <locale.h>
#include "headers/InsertionSort.h"
#include "headers/SelectionSort.h"
#include "headers/BubbleSort.h"
#include "headers/ShellSort.h"
#include "headers/Header.h"
#include "headers/QuickSort.h"
#include "headers/MergeSort.h"
#include "headers/HeapSort.h"

#include <vector>
#include <iomanip>

using namespace std;

Menu::Menu() : insertOnSort("insertOnSort"),
               selectOnSort("selectOnSort"),
               bubbleSort("bubbleSort"),
               shellSort("shellSort"),
               titulo_insertOnSort("INSERT_ON_SORT"),
               titulo_selectOnSort("SELECT_ON_SORT"),
               titulo_bubbleSort("BUBBLE_SORT"),
               titulo_shellSort("SHELL_SORT"),
               titulo_quickSort("QUICK_SORT"),
               titulo_mergeSort("MERGE_SORT"),
               titulo_heapSort("HEAP_SORT")
               {}

void Menu::exibirMenu(){
    do
    {   
        system("cls");
        printf("{~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~}\n");
        printf("{               BEM VINDO AO MENU                     }\n");
        printf("{                                                     }\n");
        printf("{       1 -   INSERCAO (MODO INSERT_ON_SORT)          }\n");
        printf("{       2 -   INSERCAO (MODO SELECTION_ON_SORT)       }\n");
        printf("{       3 -   INSERCAO (MODO BUBBLE_SORT)             }\n");
        printf("{       4 -   INSERCAO (MODO SHELL_SORT)              }\n");
        printf("{       5 -   INSERCAO (MODO QUICK_SORT)              }\n");
        printf("{       6 -   INSERCAO (MODO MERGE_SORT)              }\n");
        printf("{       7 -   INSERCAO (MODO HEAP_SORT)               }\n");
        printf("{                   S - SAIR                          }\n");
        printf("{~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~}\n\n");
        printf("\t\tescolha uma opcao: ");
        cin >> escolha;

        if(escolha == 's' || escolha == 'S')return;
        switch (escolha)
        {
            case '1':
            menuSelectTipoDeOrdenacao("insertOnSort", titulo_insertOnSort);
                break;

            case '2':
             menuSelectTipoDeOrdenacao("selectOnSort", titulo_selectOnSort);
                break;

            case '3':
             menuSelectTipoDeOrdenacao("bubbleSort", titulo_bubbleSort);
                break;

            case '4':
             menuSelectTipoDeOrdenacao("shellSort", titulo_shellSort);
                 break;
             case '5':
              menuSelectTipoDeOrdenacao("quickSort", titulo_quickSort);
                 break;
            case '6':
             menuSelectTipoDeOrdenacao("mergeSort", titulo_mergeSort);
                break;
            case '7':
             menuSelectTipoDeOrdenacao("heapSort", titulo_heapSort);
                break;

            default:
                break;
        }
    } while (escolha != 's' || escolha != 'S');
    
}

void Menu::menuSelectTipoDeOrdenacao(string tipoDeAlgoritmo,string titulo){
    char opcao;

    do {
        system("cls");
        printf("{~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~}\n");
        Header::buildHeader(titulo);
        printf("{                                                  }\n");
        printf("{       A -   FAZER ORDENACAO ALEATORIA            }\n");
        printf("{       C -   FAZER ORDENACAO CRESCENTE            }\n");
        printf("{       D -   FAZER ORDENACAO DECRESCENTE          }\n");
        printf("{                                                  }\n");
        printf("{                   V - VOLTAR                     }\n");
        printf("{~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~}\n\n");
        printf("\t\tescolha uma opcao: ");
        cin >> opcao;

       if(tolower(opcao) == 'v')return;
    
       if(tolower(opcao) == 'c'){
            if(tipoDeAlgoritmo == "insertOnSort")
                menuSelectTamanho("crescente","insertOnSort","CRESCENTE");
            else if(tipoDeAlgoritmo == "selectOnSort")
                menuSelectTamanho("crescente","selectOnSort","CRESCENTE");
            else if(tipoDeAlgoritmo == "bubbleSort")
                menuSelectTamanho("crescente","bubbleSort","CRESCENTE");
            else if(tipoDeAlgoritmo == "shellSort")
                menuSelectTamanho("crescente","shellSort","CRESCENTE");
            else if(tipoDeAlgoritmo == "quickSort")
                menuSelectTamanho("crescente","quickSort","CRESCENTE");
            else if(tipoDeAlgoritmo == "mergeSort")
                menuSelectTamanho("crescente","mergeSort","CRESCENTE");
            else if(tipoDeAlgoritmo == "heapSort")
                menuSelectTamanho("crescente","heapSort","CRESCENTE");
       }
       if(tolower(opcao) == 'd'){
            if(tipoDeAlgoritmo == "insertOnSort")
                menuSelectTamanho("decrescente","insertOnSort","DECRESCENTE");
            else if(tipoDeAlgoritmo == "selectOnSort")
                menuSelectTamanho("decrescente","selectOnSort","DECRESCENTE");
            else if(tipoDeAlgoritmo == "bubbleSort")
                menuSelectTamanho("decrescente","bubbleSort","DECRESCENTE");
            else if(tipoDeAlgoritmo == "shellSort")
                menuSelectTamanho("decrescente","shellSort","DECRESCENTE");
            else if(tipoDeAlgoritmo == "quickSort")
               menuSelectTamanho("decrescente","quickSort","DECRESCENTE");
            else if(tipoDeAlgoritmo == "mergeSort")
                menuSelectTamanho("decrescente","mergeSort","DECRESCENTE");
            else if(tipoDeAlgoritmo == "heapSort")
                menuSelectTamanho("decrescente","heapSort","DECRESCENTE");
       }
       if(tolower(opcao) == 'a'){
            if(tipoDeAlgoritmo == "insertOnSort")
                menuSelectTamanho("aleatorio","insertOnSort","ALEATORIO");
            else if(tipoDeAlgoritmo == "selectOnSort")
                menuSelectTamanho("aleatorio","selectOnSort","ALEATORIO");
            else if(tipoDeAlgoritmo == "bubbleSort")
                menuSelectTamanho("aleatorio","bubbleSort","ALEATORIO");
            else if(tipoDeAlgoritmo == "shellSort")
                menuSelectTamanho("aleatorio","shellSort","ALEATORIO");
            else if(tipoDeAlgoritmo == "quickSort")
                menuSelectTamanho("aleatorio","quickSort","ALEATORIO");
            else if(tipoDeAlgoritmo == "mergeSort")
                menuSelectTamanho("aleatorio","mergeSort","ALEATORIO");
            else if(tipoDeAlgoritmo == "heapSort")
                menuSelectTamanho("aleatorio","mergeSort","ALEATORIO");
       }
    }while (true);
}

void Menu::menuSelectTamanho(
string tipoDeOrdenacao,
string tipoDeAlgoritmo, 
string titulo){
    char opcao;
    InsertionSort operacoes;
    SelectionSort operacoes_selection_sort;
    BubbleSort operacoes_bubble_sort;
    ShellSort operacoes_shell_sort;
    QuickSort operacoes_quick_sort;
    MergeSort operacoes_merge_sort;
    HeapSort operacoes_heap_sort;

    do 
    {
        system("cls");
        printf("{~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~}\n");
        Header::buildHeader(titulo);
        printf("{                                                  }\n");
        printf("{       A -  10                                    }\n");
        printf("{       B -  100                                   }\n");
        printf("{       C -  1000                                  }\n");
        printf("{       D -  10000                                 }\n");
        printf("{       E -  100000                                }\n");
        printf("{       F -  1000000                               }\n");
        printf("{                   V - VOLTAR                     }\n");
        printf("{~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~}\n\n");
        printf("\t\tescolha o tamanho do vetor: ");
        cin >> opcao;

        if(tolower(opcao) == 'v')return;
        if(tipoDeAlgoritmo == "insertOnSort"){
            if( tipoDeOrdenacao == "crescente"){
                if(tolower(opcao) == 'a'){
                    operacoes.operacoes("insertOnSort","crescente",10);
                }
                if(tolower(opcao) == 'b'){
                    operacoes.operacoes("insertOnSort","crescente",100);
                }
                if(tolower(opcao) == 'c'){
                operacoes.operacoes("insertOnSort","crescente",1000);
                }
                if(tolower(opcao) == 'd'){
                    operacoes.operacoes("insertOnSort","crescente",10000);
                }
                if(tolower(opcao) == 'e'){
                    operacoes.operacoes("insertOnSort","crescente",100000);
                }
                if(tolower(opcao) == 'f'){
                    operacoes.operacoes("insertOnSort","crescente",1000000);
                }
            }
            if( tipoDeOrdenacao == "decrescente"){
                if(tolower(opcao) == 'a'){
                operacoes.operacoes("insertOnSort","decrescente",10);
                }
                if(tolower(opcao) == 'b'){
                operacoes.operacoes("insertOnSort","decrescente",100);
                }
                if(tolower(opcao) == 'c'){
                operacoes.operacoes("insertOnSort","decrescente",1000);
                }
                if(tolower(opcao) == 'd'){
                operacoes.operacoes("insertOnSort","decrescente",10000);
                }
                if(tolower(opcao) == 'e'){
                    operacoes.operacoes("insertOnSort","decrescente",100000);
                }
                if(tolower(opcao) == 'f'){
                    operacoes.operacoes("insertOnSort","decrescente",1000000);
                }
             }
            else{
                if(tolower(opcao) == 'a'){
                operacoes.operacoes("insertOnSort","aleatorio",10);
                }
                if(tolower(opcao) == 'b'){
                operacoes.operacoes("insertOnSort","aleatorio",100);
                }
                if(tolower(opcao) == 'c'){
                operacoes.operacoes("insertOnSort","aleatorio",1000);
                }
                if(tolower(opcao) == 'd'){
                operacoes.operacoes("insertOnSort","aleatorio",10000);
                }
                if(tolower(opcao) == 'e'){
                    operacoes.operacoes("insertOnSort","aleatorio",100000);
                }
                if(tolower(opcao) == 'f'){
                    operacoes.operacoes("insertOnSort","aleatorio",1000000);
                }
            }
            
        }
      
        if(tipoDeAlgoritmo == "selectOnSort"){
            if( tipoDeOrdenacao == "crescente"){
                if(tolower(opcao) == 'a'){
                    operacoes_selection_sort.operacoes("selectOnSort","crescente",10);
                }
                if(tolower(opcao) == 'b'){
                    operacoes_selection_sort.operacoes("selectOnSort","crescente",100);
                }
                if(tolower(opcao) == 'c'){
                operacoes_selection_sort.operacoes("selectOnSort","crescente",1000);
                }
                if(tolower(opcao) == 'd'){
                    operacoes_selection_sort.operacoes("selectOnSort","crescente",10000);
                }
                if(tolower(opcao) == 'e'){
                    operacoes_selection_sort.operacoes("selectOnSort","crescente",100000);
                }
                if(tolower(opcao) == 'f'){
                    operacoes_selection_sort.operacoes("selectOnSort","crescente",1000000);
                }
            }
            if( tipoDeOrdenacao == "decrescente"){
                if(tolower(opcao) == 's')return;
                if(tolower(opcao) == 'a'){
                operacoes_selection_sort.operacoes("selectOnSort","decrescente",10);
                }
                if(tolower(opcao) == 'b'){
                operacoes_selection_sort.operacoes("selectOnSort","decrescente",100);
                }
                if(tolower(opcao) == 'c'){
                operacoes_selection_sort.operacoes("selectOnSort","decrescente",1000);
                }
                if(tolower(opcao) == 'd'){
                operacoes_selection_sort.operacoes("selectOnSort","decrescente",10000);
                }
                if(tolower(opcao) == 'e'){
                    operacoes_selection_sort.operacoes("selectOnSort","decrescente",100000);
                }
                if(tolower(opcao) == 'f'){
                    operacoes_selection_sort.operacoes("selectOnSort","decrescente",1000000);
                }
             }
            else{
                if(tolower(opcao) == 's')return;
                if(tolower(opcao) == 'a'){
                operacoes_selection_sort.operacoes("selectOnSort","aleatorio",10);
                }
                if(tolower(opcao) == 'b'){
                operacoes_selection_sort.operacoes("selectOnSort","aleatorio",100);
                }
                if(tolower(opcao) == 'c'){
                operacoes_selection_sort.operacoes("selectOnSort","aleatorio",1000);
                }
                if(tolower(opcao) == 'd'){
                operacoes_selection_sort.operacoes("selectOnSort","aleatorio",10000);
                }
                if(tolower(opcao) == 'e'){
                    operacoes_selection_sort.operacoes("selectOnSort","aleatorio",100000);
                }
                if(tolower(opcao) == 'f'){
                    operacoes_selection_sort.operacoes("selectOnSort","aleatorio",1000000);
                }
            }
        }
        if(tipoDeAlgoritmo == "bubbleSort"){
            if( tipoDeOrdenacao == "crescente"){
                if(tolower(opcao) == 'a'){
                    operacoes_bubble_sort.operacoes("bubbleSort","crescente",10);
                }
                if(tolower(opcao) == 'b'){
                    operacoes_bubble_sort.operacoes("bubbleSort","crescente",100);
                }
                if(tolower(opcao) == 'c'){
                    operacoes_bubble_sort.operacoes("bubbleSort","crescente",1000);
                }
                if(tolower(opcao) == 'd'){
                   operacoes_bubble_sort.operacoes("bubbleSort","crescente",10000);
                }
                if(tolower(opcao) == 'e'){
                    operacoes_bubble_sort.operacoes("bubbleSort","crescente",100000);
                }
                if(tolower(opcao) == 'f'){
                    operacoes_bubble_sort.operacoes("bubbleSort","crescente",1000000);
                }
            }
            if( tipoDeOrdenacao == "decrescente"){
                    if(tolower(opcao) == 's')return;
                    if(tolower(opcao) == 'a'){
                    operacoes_bubble_sort.operacoes("bubbleSort","decrescente",10);
                    }
                    if(tolower(opcao) == 'b'){
                    operacoes_bubble_sort.operacoes("bubbleSort","decrescente",100);
                    }
                    if(tolower(opcao) == 'c'){
                    operacoes_bubble_sort.operacoes("bubbleSort","decrescente",1000);
                    }
                    if(tolower(opcao) == 'd'){
                    operacoes_bubble_sort.operacoes("bubbleSort","decrescente",10000);
                    }
                    if(tolower(opcao) == 'e'){
                        operacoes_bubble_sort.operacoes("bubbleSort","decrescente",100000);
                    }
                    if(tolower(opcao) == 'f'){
                        operacoes_bubble_sort.operacoes("bubbleSort","decrescente",1000000);
                    }
                }
            else{
                if(tolower(opcao) == 'a'){
                    operacoes_bubble_sort.operacoes("bubbleSort","aleatorio",10);
                }
                if(tolower(opcao) == 'b'){
                    operacoes_bubble_sort.operacoes("bubbleSort","aleatorio",100);
                }
                if(tolower(opcao) == 'c'){
                    operacoes_bubble_sort.operacoes("bubbleSort","aleatorio",1000);
                }
                if(tolower(opcao) == 'd'){
                    operacoes_bubble_sort.operacoes("bubbleSort","aleatorio",10000);
                }
                if(tolower(opcao) == 'e'){
                    operacoes_bubble_sort.operacoes("bubbleSort","aleatorio",100000);
                }
                if(tolower(opcao) == 'f'){
                    operacoes_bubble_sort.operacoes("bubbleSort","aleatorio",1000000);
                }
            }
        }
        if(tipoDeAlgoritmo == "shellSort"){
            if( tipoDeOrdenacao == "crescente"){
                if(tolower(opcao) == 'a'){
                    operacoes_shell_sort.operacoes("shellSort","crescente",10);
                }
                if(tolower(opcao) == 'b'){
                    operacoes_shell_sort.operacoes("shellSort","crescente",100);
                }
                if(tolower(opcao) == 'c'){
                operacoes_shell_sort.operacoes("shellSort","crescente",1000);
                }
                if(tolower(opcao) == 'd'){
                    operacoes_shell_sort.operacoes("shellSort","crescente",10000);
                }
                if(tolower(opcao) == 'e'){
                    operacoes_shell_sort.operacoes("shellSort","crescente",100000);
                }
                if(tolower(opcao) == 'f'){
                    operacoes_shell_sort.operacoes("shellSort","crescente",1000000);
                }
            }
            if( tipoDeOrdenacao == "decrescente"){
                if(tolower(opcao) == 'a'){
                    operacoes_shell_sort.operacoes("shellSort","decrescente",10);
                }
                if(tolower(opcao) == 'b'){
                    operacoes_shell_sort.operacoes("shellSort","decrescente",100);
                }
                if(tolower(opcao) == 'c'){
                    operacoes_shell_sort.operacoes("shellSort","decrescente",1000);
                }
                if(tolower(opcao) == 'd'){
                    operacoes_shell_sort.operacoes("shellSort","decrescente",10000);
                }
                if(tolower(opcao) == 'e'){
                    operacoes_shell_sort.operacoes("shellSort","decrescente",100000);
                }
                if(tolower(opcao) == 'f'){
                    operacoes_shell_sort.operacoes("shellSort","decrescente",1000000);
                }
             }
            else{
                if(tolower(opcao) == 'a'){
                    operacoes_shell_sort.operacoes("shellSort","aleatorio",10);
                }
                if(tolower(opcao) == 'b'){
                    operacoes_shell_sort.operacoes("shellSort","aleatorio",100);
                }
                if(tolower(opcao) == 'c'){
                    operacoes_shell_sort.operacoes("shellSort","aleatorio",1000);
                }
                if(tolower(opcao) == 'd'){
                    operacoes_shell_sort.operacoes("shellSort","aleatorio",10000);
                }
                if(tolower(opcao) == 'e'){
                    operacoes_shell_sort.operacoes("shellSort","aleatorio",100000);
                }
                if(tolower(opcao) == 'f'){
                    operacoes_shell_sort.operacoes("shellSort","aleatorio",1000000);
                }
            }
            
        }
        if(tipoDeAlgoritmo == "quickSort"){
            if( tipoDeOrdenacao == "crescente"){
                if(tolower(opcao) == 'a'){
                    operacoes_quick_sort.operacoes("quickSort","crescente",10);
                }
                if(tolower(opcao) == 'b'){
                    operacoes_quick_sort.operacoes("quickSort","crescente",100);
                }
                if(tolower(opcao) == 'c'){
                operacoes_quick_sort.operacoes("quickSort","crescente",1000);
                }
                if(tolower(opcao) == 'd'){
                    operacoes_quick_sort.operacoes("quickSort","crescente",10000);
                }
                if(tolower(opcao) == 'e'){
                    operacoes_quick_sort.operacoes("quickSort","crescente",100000);
                }
                if(tolower(opcao) == 'f'){
                    operacoes_quick_sort.operacoes("quickSort","crescente",1000000);
                }
            }
            if( tipoDeOrdenacao == "decrescente"){
                if(tolower(opcao) == 'a'){
                    operacoes_quick_sort.operacoes("quickSort","decrescente",10);
                }
                if(tolower(opcao) == 'b'){
                    operacoes_quick_sort.operacoes("quickSort","decrescente",100);
                }
                if(tolower(opcao) == 'c'){
                    operacoes_quick_sort.operacoes("quickSort","decrescente",1000);
                }
                if(tolower(opcao) == 'd'){
                    operacoes_quick_sort.operacoes("quickSort","decrescente",10000);
                }
                if(tolower(opcao) == 'e'){
                    operacoes_quick_sort.operacoes("quickSort","decrescente",100000);
                }
                if(tolower(opcao) == 'f'){
                    operacoes_quick_sort.operacoes("quickSort","decrescente",1000000);
                }
             }
            else{
                if(tolower(opcao) == 'a'){
                    operacoes_quick_sort.operacoes("quickSort","aleatorio",10);
                }
                if(tolower(opcao) == 'b'){
                    operacoes_quick_sort.operacoes("quickSort","aleatorio",100);
                }
                if(tolower(opcao) == 'c'){
                    operacoes_quick_sort.operacoes("quickSort","aleatorio",1000);
                }
                if(tolower(opcao) == 'd'){
                    operacoes_quick_sort.operacoes("quickSort","aleatorio",10000);
                }
                if(tolower(opcao) == 'e'){
                    operacoes_quick_sort.operacoes("quickSort","aleatorio",100000);
                }
                if(tolower(opcao) == 'f'){
                    operacoes_quick_sort.operacoes("quickSort","aleatorio",1000000);
                }
            }
            
        }   
        if(tipoDeAlgoritmo == "mergeSort"){
            if( tipoDeOrdenacao == "crescente"){
                if(tolower(opcao) == 'a'){
                    operacoes_merge_sort.operacoes("mergeSort","crescente",10);
                }
                if(tolower(opcao) == 'b'){
                    operacoes_merge_sort.operacoes("mergeSort","crescente",100);
                }
                if(tolower(opcao) == 'c'){
                operacoes_merge_sort.operacoes("mergeSort","crescente",1000);
                }
                if(tolower(opcao) == 'd'){
                    operacoes_merge_sort.operacoes("mergeSort","crescente",10000);
                }
                if(tolower(opcao) == 'e'){
                    operacoes_merge_sort.operacoes("mergeSort","crescente",100000);
                }
                if(tolower(opcao) == 'f'){
                    operacoes_merge_sort.operacoes("mergeSort","crescente",1000000);
                }
            }
            if( tipoDeOrdenacao == "decrescente"){
                if(tolower(opcao) == 'a'){
                    operacoes_merge_sort.operacoes("mergeSort","decrescente",10);
                }
                if(tolower(opcao) == 'b'){
                    operacoes_merge_sort.operacoes("mergeSort","decrescente",100);
                }
                if(tolower(opcao) == 'c'){
                    operacoes_merge_sort.operacoes("mergeSort","decrescente",1000);
                }
                if(tolower(opcao) == 'd'){
                    operacoes_merge_sort.operacoes("mergeSort","decrescente",10000);
                }
                if(tolower(opcao) == 'e'){
                    operacoes_merge_sort.operacoes("mergeSort","decrescente",100000);
                }
                if(tolower(opcao) == 'f'){
                    operacoes_merge_sort.operacoes("mergeSort","decrescente",1000000);
                }
             }
            else{
                if(tolower(opcao) == 'a'){
                    operacoes_merge_sort.operacoes("mergeSort","aleatorio",10);
                }
                if(tolower(opcao) == 'b'){
                    operacoes_merge_sort.operacoes("mergeSort","aleatorio",100);
                }
                if(tolower(opcao) == 'c'){
                    operacoes_merge_sort.operacoes("mergeSort","aleatorio",1000);
                }
                if(tolower(opcao) == 'd'){
                    operacoes_merge_sort.operacoes("mergeSort","aleatorio",10000);
                }
                if(tolower(opcao) == 'e'){
                    operacoes_merge_sort.operacoes("mergeSort","aleatorio",100000);
                }
                if(tolower(opcao) == 'f'){
                    operacoes_merge_sort.operacoes("mergeSort","aleatorio",1000000);
                }
            }
            
        }
        if(tipoDeAlgoritmo == "heapSort"){
            if( tipoDeOrdenacao == "crescente"){
                if(tolower(opcao) == 'a'){
                    operacoes_heap_sort.operacoes("heapSort","crescente",10);
                }
                if(tolower(opcao) == 'b'){
                    operacoes_heap_sort.operacoes("heapSort","crescente",100);
                }
                if(tolower(opcao) == 'c'){
                operacoes_heap_sort.operacoes("heapSort","crescente",1000);
                }
                if(tolower(opcao) == 'd'){
                    operacoes_heap_sort.operacoes("heapSort","crescente",10000);
                }
                if(tolower(opcao) == 'e'){
                    operacoes_heap_sort.operacoes("heapSort","crescente",100000);
                }
                if(tolower(opcao) == 'f'){
                    operacoes_heap_sort.operacoes("heapSort","crescente",1000000);
                }
            }
            if( tipoDeOrdenacao == "decrescente"){
                if(tolower(opcao) == 'a'){
                    operacoes_heap_sort.operacoes("heapSort","decrescente",10);
                }
                if(tolower(opcao) == 'b'){
                    operacoes_heap_sort.operacoes("heapSort","decrescente",100);
                }
                if(tolower(opcao) == 'c'){
                    operacoes_heap_sort.operacoes("heapSort","decrescente",1000);
                }
                if(tolower(opcao) == 'd'){
                    operacoes_heap_sort.operacoes("heapSort","decrescente",10000);
                }
                if(tolower(opcao) == 'e'){
                    operacoes_heap_sort.operacoes("heapSort","decrescente",100000);
                }
                if(tolower(opcao) == 'f'){
                    operacoes_heap_sort.operacoes("heapSort","decrescente",1000000);
                }
             }
            else{
                if(tolower(opcao) == 'a'){
                    operacoes_heap_sort.operacoes("heapSort","aleatorio",10);
                }
                if(tolower(opcao) == 'b'){
                    operacoes_heap_sort.operacoes("heapSort","aleatorio",100);
                }
                if(tolower(opcao) == 'c'){
                    operacoes_heap_sort.operacoes("heapSort","aleatorio",1000);
                }
                if(tolower(opcao) == 'd'){
                    operacoes_heap_sort.operacoes("heapSort","aleatorio",10000);
                }
                if(tolower(opcao) == 'e'){
                    operacoes_heap_sort.operacoes("heapSort","aleatorio",100000);
                }
                if(tolower(opcao) == 'f'){
                    operacoes_heap_sort.operacoes("heapSort","aleatorio",1000000);
                }
            }
            
        }
       
    }while (true);
}

int Menu::particao(){
    int escolha_;

        system("cls");
        printf("{~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~}\n");
        printf("{               ESCOLHA A PARTICAO                    }\n");
        printf("{                                                     }\n");
        printf("{       1 -   PIVO SENDO PRIMEIRO INDICE              }\n");
        printf("{       2 -   PIVO SENDO A MEDIA DOS INDICES          }\n");
        printf("{       3 -   PIVO SENDO A MEDIANA DE 3 ELEMENTOS     }\n");
        printf("{       4 -   PIVO ALEATORIO                          }\n");
        printf("{                                                     }\n");
        printf("{~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~}\n\n");
        printf("\t\tescolha uma opcao: ");
        cin >> escolha_;

  return escolha_;  
}




