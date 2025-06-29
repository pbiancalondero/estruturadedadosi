#include <iostream>
using namespace std;

#include "exerc1.hpp"

void insereOrdenado(No** lista, int valor)
{
    No *novo = new No();
    novo->dado = valor;
    novo->prox = NULL;

    if (vaziaL(lista) || (*lista)->dado >= valor)
    {
        novo->prox = *lista;
        *lista = novo;
        return;
    }

    No *atual = *lista;

    while (atual->prox != NULL && atual->prox->dado < valor)
    {
        atual = atual->prox;
    }

    novo->prox = atual->prox;
    atual->prox = novo;
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No* lista;

    inicializaL(&lista);

    insereOrdenado(&lista, 3);
    insereOrdenado(&lista, 5);
    insereOrdenado(&lista, 8);
    insereOrdenado(&lista, 9);
    insereOrdenado(&lista, 12);
    insereOrdenado(&lista, 11);
    insereOrdenado(&lista, 7);
    insereOrdenado(&lista, 10);

    mostraL(&lista);

    destroiL(&lista);
    return EXIT_SUCCESS;
}
