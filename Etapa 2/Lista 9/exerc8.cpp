#include <iostream>
using namespace std;

#include "exerc1.hpp"

bool inserePosicao(No** lista, int pos, int valor)
{
    No *novo = new No();
    novo->dado = valor;
    novo->prox = NULL;

    if (pos < 0 || vaziaL(lista))
    {
        return false;
    }

    if (pos == 0)
    {
        novo->prox = *lista;
        *lista = novo;
        return true;
    }

    No* atual = *lista;
    int cont = 0;

    // Percorre a lista até encontrar a posição
    while (atual != NULL && cont < pos - 1)
    {
        atual = atual->prox;
        cont++;
    }

    // Se a posição for maior que o tamanho da lista ou igual ao tamanho da lista
    if (atual == NULL || atual->prox == NULL)
    {
        return false;
    }

    novo->prox = atual->prox;
    atual->prox = novo;
    return true;
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No* lista;
    int pos = 0, valor = 0;

    inicializaL(&lista);

    insereFinalL(&lista, 2);
    insereFinalL(&lista, 5);
    insereFinalL(&lista, 3);
    insereFinalL(&lista, 9);
    insereFinalL(&lista, 9);
    insereFinalL(&lista, 8);
    insereFinalL(&lista, 7);
    insereFinalL(&lista, 6);
    insereFinalL(&lista, 2);
    insereFinalL(&lista, 1);

    mostraL(&lista);
    cout << endl;

    inserePosicao(&lista, 0, 100);
    mostraL(&lista);
    cout << endl;

    inserePosicao(&lista, 3, 200);
    mostraL(&lista);
    cout << endl;

    inserePosicao(&lista, 11, 300);
    mostraL(&lista);
    cout << endl;

    inserePosicao(&lista, 13, 1000);
    mostraL(&lista);
    cout << endl;

    inserePosicao(&lista, -1, 1000);
    mostraL(&lista);
    cout << endl;

    destroiL(&lista);
    return EXIT_SUCCESS;
}
