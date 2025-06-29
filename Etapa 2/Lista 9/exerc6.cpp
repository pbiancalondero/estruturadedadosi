#include <iostream>
using namespace std;

#include "exerc1.hpp"

void ordenaL(No** lista)
{
    if (vaziaL(lista) || (*lista)->prox == NULL)
    {
        cout << "Lista vazia ou com apenas 1 elemento" << endl;
        return;
    }

    bool trocou;
    do {
        trocou = false;
        No* atual = *lista;

        while (atual->prox != NULL)
        {
            if (atual->dado > atual->prox->dado)
            {
                atual->dado = atual->dado + atual->prox->dado;
                atual->prox->dado = atual->dado - atual->prox->dado;
                atual->dado = atual->dado - atual->prox->dado;
                trocou = true;
            }
            atual = atual->prox;
        }
    } while (trocou);
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No* lista;

    inicializaL(&lista);

    insereFinalL(&lista, 3);
    insereFinalL(&lista, 5);
    insereFinalL(&lista, 8);
    insereFinalL(&lista, 9);
    insereFinalL(&lista, 12);
    insereFinalL(&lista, 11);
    insereFinalL(&lista, 7);
    insereFinalL(&lista, 10);

    mostraL(&lista);

    ordenaL(&lista);

    cout << "Lista após a chamada da Função: " << endl;
    mostraL(&lista);

    destroiL(&lista);
    return EXIT_SUCCESS;
}
