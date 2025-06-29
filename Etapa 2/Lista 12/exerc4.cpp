#include <iostream>
#include <string>
using namespace std;
#include "lista_dupla_template.hpp"

void inversaoValor(Lista<string> *lista)
{
    No<string> *n = lista->inicio;
    while(n)
    {
        if(n->dado == "direita")
            n->dado = "esquerda";

        else if(n->dado == "esquerda")
            n->dado = "direita";

        else if(n->dado == "cima")
            n->dado = "baixo";

        else if(n->dado == "baixo")
            n->dado = "cima";

        n = n->prox;
    }
}


int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Lista<string> lista = Lista<string>();
    insereInicioL(&lista, string("direita"));
    insereInicioL(&lista, string("direita"));
    insereInicioL(&lista, string("cima"));
    insereInicioL(&lista, string("esquerda"));
    insereInicioL(&lista, string("cima"));
    insereInicioL(&lista, string("cima"));
    insereInicioL(&lista, string("cima"));
    insereInicioL(&lista, string("cima"));
    insereInicioL(&lista, string("direita"));
    insereInicioL(&lista, string("direita"));
    insereInicioL(&lista, string("cima"));
    insereInicioL(&lista, string("direita"));
    insereInicioL(&lista, string("direita"));
    insereInicioL(&lista, string("direita"));
    insereInicioL(&lista, string("baixo"));
    insereInicioL(&lista, string("direita"));
    insereInicioL(&lista, string("cima"));
    insereInicioL(&lista, string("direita"));
    insereInicioL(&lista, string("baixo"));
    insereInicioL(&lista, string("direita"));

    mostraL(&lista);
    cout<<endl;
    inversaoValor(&lista);
    mostrarInversoL(&lista);
    destroiL(&lista);

    return EXIT_SUCCESS;
}

