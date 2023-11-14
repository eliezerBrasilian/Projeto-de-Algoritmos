#ifndef MENU_H
#define MENU_H
#include <string>
class Menu
{
 private:
    char escolha;
    std::string insertOnSort = "insertOnSort";
    std::string selectOnSort = "selectOnSort";
    std::string bubbleSort = "bubbleSort";
    std::string shellSort = "shellSort";
    std::string titulo_insertOnSort = "INSERT_ON_SORT";
    std::string titulo_selectOnSort = "SELECT_ON_SORT";
    std::string titulo_bubbleSort = "BUBBLE_SORT";
    std::string titulo_shellSort = "SHELL_SORT";
    std::string titulo_quickSort = "QUICK_SORT";
    std::string titulo_mergeSort = "MERGE_SORT";

 public: 
    void exibirMenu();
    void menuSelectTipoDeOrdenacao(std::string,std::string);
    void menuSelectTamanho(std::string,std::string,std::string);
   Menu();
};

#endif