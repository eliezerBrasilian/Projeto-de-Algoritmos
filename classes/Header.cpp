#include "headers/Header.h"

void Header::buildHeader(string titulo){
    if(titulo == "SELECT_ON_SORT"){
        cout <<"{          > MODO " << titulo <<"                   }" << "\n";
    }
    else if(titulo == "INSERT_ON_SORT"){
        cout <<"{          > MODO " << titulo <<"                   }" << "\n";
    }
    else if(titulo == "BUBBLE_SORT"){
        cout <<"{          > MODO " << titulo <<"                      }" << "\n";
    }
    else if(titulo == "SHELL_SORT"){
        cout <<"{          > MODO " << titulo <<"                       }" << "\n";
    }
    else if(titulo == "HEAP_SORT"){
        cout <<"{          > MODO " << titulo <<"                        }" << "\n";
    }
    else if(titulo == "ALEATORIO"){
        cout <<"{          > MODO " << titulo <<"                        }" << "\n";
    }
    else if(titulo == "CRESCENTE"){
        cout <<"{          > MODO " << titulo <<"                        }" << "\n";
    }
    else if(titulo == "DECRESCENTE"){
        cout <<"{          > MODO " << titulo <<"                      }" << "\n";
    }
    
}