#include <iostream>
using namespace std;

#include "exerc1.hpp"

int verificaOrdem(No** lista)
{
    if (vaziaL(lista) || (*lista)->prox == NULL)
    {
        return 2;
    }

    No* atual = *lista;
    No* proximo = atual->prox;
    bool crescente = true;
    bool decrescente = true;

    while (proximo != NULL)
    {
        if (atual->dado > proximo->dado)
        {
            crescente = false;
        }
        if (atual->dado < proximo->dado)
        {
            decrescente = false;
        }
        atual = proximo;
        proximo = proximo->prox;
    }

    if (crescente)
    {
        return 0;
    }
    if (decrescente)
    {
        return 1;
    }
    return 2;
}
int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No* lista;

    inicializaL(&lista);

    insereFinalL(&lista, 1);
    insereFinalL(&lista, 5);
    insereFinalL(&lista, 21);
    insereFinalL(&lista, 10);
    insereFinalL(&lista, 30);

    mostraL(&lista);


    if (verificaOrdem(&lista) == 0)
        cout << "0- Ordem crescente" << endl;
    else if (verificaOrdem(&lista) == 1)
        cout << "1- Ordem decrescente" << endl;
    else if (verificaOrdem(&lista) == 2)
        cout << "2- Não está ordenada" << endl;

    destroiL(&lista);
    return EXIT_SUCCESS;
}
