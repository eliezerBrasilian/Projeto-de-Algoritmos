#include "headers/Arquivo.h"
#include "iostream"

using namespace  std;

Arquivo::Arquivo() {
 char path[100];
    sprintf(path,"mkdir InsertOnSort\\arquivos_de_entrada\\crescente");
    system(path);
    sprintf(path,"mkdir InsertOnSort\\arquivos_de_entrada\\decrescente");
    system(path);
    sprintf(path,"mkdir InsertOnSort\\arquivos_de_entrada\\aleatorio");
    system(path);

    sprintf(path,"mkdir InsertOnSort\\arquivos_de_saida\\crescente");
    system(path);
    sprintf(path,"mkdir InsertOnSort\\arquivos_de_saida\\decrescente");
    system(path);
    sprintf(path,"mkdir InsertOnSort\\arquivos_de_saida\\aleatorio");
    system(path);

    sprintf(path,"mkdir InsertOnSort\\arquivos_de_tempo\\crescente");
    system(path);
    sprintf(path,"mkdir InsertOnSort\\arquivos_de_tempo\\decrescente");
    system(path);
    sprintf(path,"mkdir InsertOnSort\\arquivos_de_tempo\\aleatorio");
    system(path);


    sprintf(path,"mkdir SelectOnSort\\arquivos_de_entrada\\crescente");
    system(path);
    sprintf(path,"mkdir SelectOnSort\\arquivos_de_entrada\\decrescente");
    system(path);
    sprintf(path,"mkdir SelectOnSort\\arquivos_de_entrada\\aleatorio");
    system(path);

    sprintf(path,"mkdir SelectOnSort\\arquivos_de_saida\\crescente");
    system(path);
    sprintf(path,"mkdir SelectOnSort\\arquivos_de_saida\\decrescente");
    system(path);
    sprintf(path,"mkdir SelectOnSort\\arquivos_de_saida\\aleatorio");
    system(path);

    sprintf(path,"mkdir SelectOnSort\\arquivos_de_tempo\\crescente");
    system(path);
    sprintf(path,"mkdir SelectOnSort\\arquivos_de_tempo\\decrescente");
    system(path);
    sprintf(path,"mkdir SelectOnSort\\arquivos_de_tempo\\aleatorio");
    system(path);



    sprintf(path,"mkdir BubbleSort\\arquivos_de_entrada\\crescente");
    system(path);
    sprintf(path,"mkdir BubbleSort\\arquivos_de_entrada\\decrescente");
    system(path);
    sprintf(path,"mkdir BubbleSort\\arquivos_de_entrada\\aleatorio");
    system(path);

    sprintf(path,"mkdir BubbleSort\\arquivos_de_saida\\crescente");
    system(path);
    sprintf(path,"mkdir BubbleSort\\arquivos_de_saida\\decrescente");
    system(path);
    sprintf(path,"mkdir BubbleSort\\arquivos_de_saida\\aleatorio");
    system(path);

    sprintf(path,"mkdir BubbleSort\\arquivos_de_tempo\\crescente");
    system(path);
    sprintf(path,"mkdir BubbleSort\\arquivos_de_tempo\\decrescente");
    system(path);
    sprintf(path,"mkdir BubbleSort\\arquivos_de_tempo\\aleatorio");
    system(path);


    sprintf(path,"mkdir ShellSort\\arquivos_de_entrada\\crescente");
    system(path);
    sprintf(path,"mkdir ShellSort\\arquivos_de_entrada\\decrescente");
    system(path);
    sprintf(path,"mkdir ShellSort\\arquivos_de_entrada\\aleatorio");
    system(path);

    sprintf(path,"mkdir ShellSort\\arquivos_de_saida\\crescente");
    system(path);
    sprintf(path,"mkdir ShellSort\\arquivos_de_saida\\decrescente");
    system(path);
    sprintf(path,"mkdir ShellSort\\arquivos_de_saida\\aleatorio");
    system(path);

    sprintf(path,"mkdir ShellSort\\arquivos_de_tempo\\crescente");
    system(path);
    sprintf(path,"mkdir ShellSort\\arquivos_de_tempo\\decrescente");
    system(path);
    sprintf(path,"mkdir ShellSort\\arquivos_de_tempo\\aleatorio");
    system(path);
}

void Arquivo::salvarEntrada(string tipoDeAlgoritmo, string tipoDeOrdenacao, int size, int *vetor) {
    char path[100];
     cout << "tipo de algoritmo: " << tipoDeAlgoritmo<< endl; 
    if (tipoDeAlgoritmo == "insertOnSort") {

        if (tipoDeOrdenacao == "aleatorio") {
            sprintf(path, "InsertOnSort\\arquivos_de_entrada\\aleatorio\\aleatorio%d.txt", size);
        } else if (tipoDeOrdenacao == "crescente") {
            sprintf(path, "InsertOnSort\\arquivos_de_entrada\\crescente\\crescente%d.txt", size);
        } else if (tipoDeOrdenacao == "decrescente") {
            sprintf(path, "InsertOnSort\\arquivos_de_entrada\\decrescente\\decrescente%d.txt", size);
        }
   
       cout << "Caminho do arquivo de entrada: " << path << endl; 
    }

    if (tipoDeAlgoritmo == "selectOnSort") {

        if (tipoDeOrdenacao == "aleatorio") {
            sprintf(path, "SelectOnSort\\arquivos_de_entrada\\aleatorio\\aleatorio%d.txt", size);
        } else if (tipoDeOrdenacao == "crescente") {
            sprintf(path, "SelectOnSort\\arquivos_de_entrada\\crescente\\crescente%d.txt", size);
        } else if (tipoDeOrdenacao == "decrescente") {
            sprintf(path, "SelectOnSort\\arquivos_de_entrada\\decrescente\\decrescente%d.txt", size);
        }

    }

     if (tipoDeAlgoritmo == "bubbleSort") {

        if (tipoDeOrdenacao == "aleatorio") {
            sprintf(path, "BubbleSort\\arquivos_de_entrada\\aleatorio\\aleatorio%d.txt", size);
        } else if (tipoDeOrdenacao == "crescente") {
            sprintf(path, "BubbleSort\\arquivos_de_entrada\\crescente\\crescente%d.txt", size);
        } else if (tipoDeOrdenacao == "decrescente") {
            sprintf(path, "BubbleSort\\arquivos_de_entrada\\decrescente\\decrescente%d.txt", size);
        }

    }

     if (tipoDeAlgoritmo == "shellSort") {

        if (tipoDeOrdenacao == "aleatorio") {
            sprintf(path, "ShellSort\\arquivos_de_entrada\\aleatorio\\aleatorio%d.txt", size);
        } else if (tipoDeOrdenacao == "crescente") {
            sprintf(path, "ShellSort\\arquivos_de_entrada\\crescente\\crescente%d.txt", size);
        } else if (tipoDeOrdenacao == "decrescente") {
            sprintf(path, "ShellSort\\arquivos_de_entrada\\decrescente\\decrescente%d.txt", size);
        }

    }

    FILE *arquivo = fopen(path, "w");

    fprintf(arquivo, "%d \n", size);
    for (int i = 0; i < size; i++) {
         fprintf(arquivo, "%d ", vetor[i]);
         fprintf(arquivo, "\n");
        }

    fclose(arquivo);
}

void Arquivo::salvarSaida(string tipoDeAlgoritmo, string tipoDeOrdenacao, int size, int *vetor) {
    char path[100];

    if (tipoDeAlgoritmo == "insertOnSort") {
        if (tipoDeOrdenacao == "aleatorio") {
            sprintf(path, "InsertOnSort\\arquivos_de_saida\\aleatorio\\aleatorio%d.txt", size);
        } else if (tipoDeOrdenacao == "crescente") {
            sprintf(path, "InsertOnSort\\arquivos_de_saida\\crescente\\crescente%d.txt", size);
        } else {
            sprintf(path, "InsertOnSort\\arquivos_de_saida\\decrescente\\decrescente%d.txt", size);
        }
    }
    if (tipoDeAlgoritmo == "selectOnSort") {

        if (tipoDeOrdenacao == "aleatorio") {
            sprintf(path, "SelectOnSort\\arquivos_de_saida\\aleatorio\\aleatorio%d.txt", size);
        } else if (tipoDeOrdenacao == "crescente") {
            sprintf(path, "SelectOnSort\\arquivos_de_saida\\crescente\\crescente%d.txt", size);
        } else if (tipoDeOrdenacao == "decrescente") {
            sprintf(path, "SelectOnSort\\arquivos_de_saida\\decrescente\\decrescente%d.txt", size);
        }
    }

      if (tipoDeAlgoritmo == "bubbleSort") {

        if (tipoDeOrdenacao == "aleatorio") {
            sprintf(path, "BubbleSort\\arquivos_de_saida\\aleatorio\\aleatorio%d.txt", size);
        } else if (tipoDeOrdenacao == "crescente") {
            sprintf(path, "BubbleSort\\arquivos_de_saida\\crescente\\crescente%d.txt", size);
        } else if (tipoDeOrdenacao == "decrescente") {
            sprintf(path, "BubbleSort\\arquivos_de_saida\\decrescente\\decrescente%d.txt", size);
        }
    }

      if (tipoDeAlgoritmo == "shellSort") {

        if (tipoDeOrdenacao == "aleatorio") {
            sprintf(path, "ShellSort\\arquivos_de_saida\\aleatorio\\aleatorio%d.txt", size);
        } else if (tipoDeOrdenacao == "crescente") {
            sprintf(path, "ShellSort\\arquivos_de_saida\\crescente\\crescente%d.txt", size);
        } else if (tipoDeOrdenacao == "decrescente") {
            sprintf(path, "ShellSort\\arquivos_de_saida\\decrescente\\decrescente%d.txt", size);
        }
    }

    FILE *arquivo = fopen(path, "w");

    fprintf(arquivo, "%d \n", size);
    for (int i = 0; i < size; i++) {
         fprintf(arquivo, "%d ", vetor[i]);
         fprintf(arquivo, "\n");

    }

    fclose(arquivo);
}

void Arquivo::salvarTempo(string tipoDeAlgoritmo, string tipoDeOrdenacao, int size, double tempoTotalGasto) {
       char path[100];
   
    if (tipoDeAlgoritmo == "insertOnSort") {

        if (tipoDeOrdenacao == "aleatorio") {
            sprintf(path, "InsertOnSort\\arquivos_de_tempo\\aleatorio\\aleatorio%d.txt", size);
        } else if (tipoDeOrdenacao == "crescente") {
            sprintf(path, "InsertOnSort\\arquivos_de_tempo\\crescente\\crescente%d.txt", size);
        } else if (tipoDeOrdenacao == "decrescente") {
            sprintf(path, "InsertOnSort\\arquivos_de_tempo\\decrescente\\decrescente%d.txt", size);
        }
    }
    if (tipoDeAlgoritmo == "selectOnSort") {

        if (tipoDeOrdenacao == "aleatorio") {
            sprintf(path, "SelectOnSort\\arquivos_de_tempo\\aleatorio\\aleatorio%d.txt", size);
        } else if (tipoDeOrdenacao == "crescente") {
            sprintf(path, "SelectOnSort\\arquivos_de_tempo\\crescente\\crescente%d.txt", size);
        } else if (tipoDeOrdenacao == "decrescente") {
            sprintf(path, "SelectOnSort\\arquivos_de_tempo\\decrescente\\decrescente%d.txt", size);
        }
    }

      if (tipoDeAlgoritmo == "bubbleSort") {

        if (tipoDeOrdenacao == "aleatorio") {
            sprintf(path, "BubbleSort\\arquivos_de_tempo\\aleatorio\\aleatorio%d.txt", size);
        } else if (tipoDeOrdenacao == "crescente") {
            sprintf(path, "BubbleSort\\arquivos_de_tempo\\crescente\\crescente%d.txt", size);
        } else if (tipoDeOrdenacao == "decrescente") {
            sprintf(path, "BubbleSort\\arquivos_de_tempo\\decrescente\\decrescente%d.txt", size);
        }
    }

       if (tipoDeAlgoritmo == "shellSort") {

        if (tipoDeOrdenacao == "aleatorio") {
            sprintf(path, "ShellSort\\arquivos_de_tempo\\aleatorio\\aleatorio%d.txt", size);
        } else if (tipoDeOrdenacao == "crescente") {
            sprintf(path, "ShellSort\\arquivos_de_tempo\\crescente\\crescente%d.txt", size);
        } else if (tipoDeOrdenacao == "decrescente") {
            sprintf(path, "ShellSort\\arquivos_de_tempo\\decrescente\\decrescente%d.txt", size);
        }
    }

    FILE *arquivo = fopen(path, "w");
    fprintf(arquivo,"Tempo total gasto: %lf",tempoTotalGasto);


    fclose(arquivo);
}