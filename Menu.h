#include <iostream>
#include <stdio.h>
#include <locale.h>
#include "Ordenacao.h"
#include "Tempo.h"
#include <vector>
#include <iomanip>
using namespace std;
class Menu
{
 private:
    char escolha;
    int tamanho_maximo = 100;
 public: 
    void exibirMenu();
    void menuInsertOnSort();
    void ordemCrescente();
    void semOrdem();
    void ordemDecresente();
    void ordemAleatoria();
    void gerarSequenciaAleatoria(int, Arquivo&,Ordenacao&,ofstream&);
    void gerarSequenciaCrescente(int, Arquivo&,Ordenacao&,ofstream&);
    void gerarSequenciaDecrescente(int, Arquivo&,Ordenacao&,ofstream&);
 public:
    Menu(){
        setlocale(LC_ALL,"pt_BR.UTF-8");
    }
};

void Menu::exibirMenu(){
    do
    {   
        system("cls");
        printf("{~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~}\n");
        printf("{               BEM VINDO AO MENU                  }\n");
        printf("{                                                  }\n");
        printf("{       1 -   INSERCAO (MODO INSERT_ON_SORT)       }\n");
        printf("{                                                  }\n");
        printf("{                                                  }\n");
        printf("{                   S - SAIR                       }\n");
        printf("{~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~}\n\n");
        printf("\t\tescolha uma opcao: ");
        cin >> escolha;

        if(escolha == 's' || escolha == 'S')return;
        switch (escolha)
        {
            case '1':
            menuInsertOnSort();
                break;

            default:
                break;
        }
    } while (escolha != 's' || escolha != 'S');
    
}

void Menu::menuInsertOnSort(){
    char opcao;
    do {
        system("cls");
        printf("{~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~}\n");
        printf("{             > MODO DE INSERT_ON_SORT             }\n");
        printf("{                                                  }\n");
        printf("{       A -   EXIBIR VETOR EM ORDEM ALEATORIA      }\n");
        printf("{       C -   EXIBIR VETOR EM ORDEM CRESCENTE      }\n");
        printf("{       D -   EXIBIR VETOR EM ORDEM DECRESCENTE    }\n");
        printf("{                                                  }\n");
        printf("{                   S - SAIR                       }\n");
        printf("{~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~}\n\n");
        printf("\t\tescolha uma opcao: ");
        cin >> opcao;

       if(opcao == 's' || opcao == 'S' )return;
       if(opcao == 'e' || opcao == 'E'){
        semOrdem();
       }
       if(opcao == 'c' || opcao == 'C'){
        ordemCrescente();
       }
       if(opcao == 'd' || opcao == 'D'){
        ordemDecresente();
       }
       if(opcao == 'a' || opcao == 'A'){
        ordemAleatoria();
       }

    }while (opcao != 's' || opcao != 'S');
}

void Menu::semOrdem(){
//     Ordenacao ordenacao;
//    int *lista = ordenacao.getLista();
//    for (int i = 0; i < 5; i++)
//    {
//     cout << lista[i] << " ";
//    }
    system("pause");
}
void Menu::ordemCrescente(){
    Ordenacao ordenacao;
    Arquivo arquivo;
    ofstream nome_arquivo;
    int i = 10;
    while(i <= tamanho_maximo){
        nome_arquivo = arquivo.geraArquivo(i,"entradaCrescente");
        arquivo.escreveTamanho(nome_arquivo,i);
        gerarSequenciaCrescente(i, arquivo,ordenacao,nome_arquivo);
        i *= 10;
    }
    system("pause");
}

void Menu::gerarSequenciaCrescente(int size, Arquivo& arquivo, Ordenacao& ordenacao, ofstream& nome_arquivo) {
    Tempo timer_gerar_entrada;
    vector<vector<int>> sequencias;
    
    auto inicio_gerar_entrada = timer_gerar_entrada.iniciaContagem();
    ordenacao.preencherVetorAleatoriamente(sequencias,size);
    ordenacao.escreverVetorNoArquivo(arquivo,sequencias,size,nome_arquivo);


    Arquivo arquivo_saida;
    ofstream ref_arquivo_saida;
    ref_arquivo_saida = arquivo_saida.geraArquivo(size,"saidaCrescente");
    arquivo.escreveTamanho(ref_arquivo_saida,size);
    vector<vector<int>> ordenados = ordenacao.getCrescente(sequencias);
    ordenacao.escreverVetorNoArquivo(arquivo_saida,ordenados,size,ref_arquivo_saida);
       
    auto duration_gerar_entrada = timer_gerar_entrada.interrompeContagem(inicio_gerar_entrada);
    
    Arquivo arquivo_tempo_gasto;
    ofstream ref_tempo_gasto;
    ref_tempo_gasto = arquivo_tempo_gasto.geraArquivo(size,"tempoGastoCrescente");

    auto tempo_gasto =  duration_gerar_entrada;
    double tempo_gasto_segundo = tempo_gasto.count(); 
    
    arquivo_tempo_gasto.escreveTempoGasto(ref_tempo_gasto,tempo_gasto_segundo);
    nome_arquivo.close();
    ref_arquivo_saida.close();
    ref_tempo_gasto.close();
}


void Menu::ordemDecresente(){
    Ordenacao ordenacao;
    Arquivo arquivo;
    ofstream nome_arquivo;
    int i = 10;
    while(i <= tamanho_maximo){
        nome_arquivo = arquivo.geraArquivo(i,"entradaDecrescente");
        arquivo.escreveTamanho(nome_arquivo,i);
        gerarSequenciaDecrescente(i, arquivo,ordenacao,nome_arquivo);
        i *= 10;
    }
    system("pause");
}

void Menu::gerarSequenciaDecrescente(int size, Arquivo& arquivo, Ordenacao& ordenacao, ofstream& nome_arquivo) {
    Tempo timer_gerar_entrada;
    vector<vector<int>> sequencias;
    
    auto inicio_gerar_entrada = timer_gerar_entrada.iniciaContagem();
    ordenacao.preencherVetorAleatoriamente(sequencias,size);
    ordenacao.escreverVetorNoArquivo(arquivo,sequencias,size,nome_arquivo);


    Arquivo arquivo_saida;
    ofstream ref_arquivo_saida;
    ref_arquivo_saida = arquivo_saida.geraArquivo(size,"saidaDerescente");
    arquivo.escreveTamanho(ref_arquivo_saida,size);
    vector<vector<int>> ordenados = ordenacao.getDecrescente(sequencias);
    ordenacao.escreverVetorNoArquivo(arquivo_saida,ordenados,size,ref_arquivo_saida);
       
    auto duration_gerar_entrada = timer_gerar_entrada.interrompeContagem(inicio_gerar_entrada);
    
    Arquivo arquivo_tempo_gasto;
    ofstream ref_tempo_gasto;
    ref_tempo_gasto = arquivo_tempo_gasto.geraArquivo(size,"tempoGastoDecrescente");

    auto tempo_gasto =  duration_gerar_entrada;
    double tempo_gasto_segundo = tempo_gasto.count(); 
    
    arquivo_tempo_gasto.escreveTempoGasto(ref_tempo_gasto,tempo_gasto_segundo);
    nome_arquivo.close();
    ref_arquivo_saida.close();
    ref_tempo_gasto.close();
}

void Menu::ordemAleatoria(){
    Ordenacao ordenacao;
    Arquivo arquivo;
    ofstream nome_arquivo;
    int i = 10;//voltar pra 10

    while(i <= tamanho_maximo){
        cout << "ordemAleatoria" << "\n";
        nome_arquivo = arquivo.geraArquivo(i,"entradaAleatoria");
        arquivo.escreveTamanho(nome_arquivo,i);
        gerarSequenciaAleatoria(i, arquivo,ordenacao,nome_arquivo);
        i *= 10;
    }
    system("pause");
}

void Menu::gerarSequenciaAleatoria(int size, Arquivo& arquivo, Ordenacao& ordenacao, ofstream& nome_arquivo) {
    Tempo timer_gerar_entrada;
    vector<vector<int>> sequencias;
    
    auto inicio_gerar_entrada = timer_gerar_entrada.iniciaContagem();
    ordenacao.preencherVetorAleatoriamente(sequencias,size);
    ordenacao.escreverVetorNoArquivo(arquivo,sequencias,size,nome_arquivo);

    Arquivo arquivo_saida;
    ofstream ref_arquivo_saida;
    ref_arquivo_saida = arquivo_saida.geraArquivo(size,"saidaAleatoria");
    arquivo.escreveTamanho(ref_arquivo_saida,size);
    ordenacao.escreverVetorNoArquivo(arquivo_saida,sequencias,size,ref_arquivo_saida);
       
    auto duration_gerar_entrada = timer_gerar_entrada.interrompeContagem(inicio_gerar_entrada);
    
    Arquivo arquivo_tempo_gasto;
    ofstream ref_tempo_gasto;
    ref_tempo_gasto = arquivo_tempo_gasto.geraArquivo(size,"tempoGastoAleatoria");

    auto tempo_gasto =  duration_gerar_entrada;
    double tempo_gasto_segundo = tempo_gasto.count(); 
    
   arquivo_tempo_gasto.escreveTempoGasto(ref_tempo_gasto,tempo_gasto_segundo);
   nome_arquivo.close();
   ref_arquivo_saida.close();
   ref_tempo_gasto.close();
}
