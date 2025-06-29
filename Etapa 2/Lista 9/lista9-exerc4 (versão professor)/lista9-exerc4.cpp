#include <iostream>
using namespace std;

#include "lista.hpp"

int freqL(No** lista, string str)
{
    int cont = 0;
    No *n = *lista;


    while(n != NULL ) /// enquanto n não for NULL fica no laço
    {

        if(n->dado == str)
            cont++;
        n = n->prox;

    }

    return cont;
}
void naoSegura(No** lsenhas, No** lsenhaNSeguras)
{
    No *n = *lsenhas;


    while(n != NULL ) /// enquanto n não for NULL fica no laço
    {

        if((n->dado.size()<4 || freqL(lsenhas, n->dado)>5) && buscaL(lsenhaNSeguras, n->dado) == NULL)
            insereInicioL(lsenhaNSeguras, n->dado);

        n = n->prox;

    }
}
int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No *lsenhas, *lsenhaNSeguras;
    inicializaL(&lsenhas);
    inicializaL(&lsenhaNSeguras);

    insereInicioL(&lsenhas, "ABC");
    insereInicioL(&lsenhas, "Senha1");
    insereInicioL(&lsenhas, "Senha2");
    insereInicioL(&lsenhas, "Senha3");
    insereInicioL(&lsenhas, "ACB");
    insereInicioL(&lsenhas, "Senha2");
    insereInicioL(&lsenhas, "Senha2");
    insereInicioL(&lsenhas, "Senha2");
    insereInicioL(&lsenhas, "Senha2");
    insereInicioL(&lsenhas, "Senha2");


    naoSegura(&lsenhas, &lsenhaNSeguras);

    mostraL(&lsenhas, "lsenhas");
    mostraL(&lsenhaNSeguras, "lsenhaNSeguras");

    destroiL(&lsenhas);
    destroiL(&lsenhaNSeguras);
    return EXIT_SUCCESS;


}//final do main

