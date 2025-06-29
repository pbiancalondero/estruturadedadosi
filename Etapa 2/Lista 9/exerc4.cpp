#include <iostream>
#include <string>
using namespace std;

#include "lista-exerc4.hpp"

No* buscaSenha(No** lista, string senha, int &frequencia)
{
    No *n = *lista;
    frequencia = 0;
    No *encontrado = NULL;

    while (n != NULL)
    {
        if (n->dado == senha)
        {
            frequencia++;
            if (frequencia == 1)
                encontrado = n;
        }
        n = n->prox;
    }

    return encontrado;
}

No* naoSeguras(No** lista)
{
    if (vaziaL(lista))
    {
        return NULL;
    }

    No* naoSeguras = NULL;
    No* atual = *lista;
    while (atual != NULL)
    {
        int frequencia;
        buscaSenha(lista, atual->dado, frequencia);

        if (atual->dado.length() < 4 || frequencia > 5)
        {
            if (buscaSenha(&naoSeguras, atual->dado, frequencia) == NULL)
            {
                insereFinalL(&naoSeguras, atual->dado);
            }
        }
        atual = atual->prox;
    }

    return naoSeguras;
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No* lista;
    inicializaL(&lista);

    insereFinalL(&lista, "chave12*");
    insereFinalL(&lista, "123");
    insereFinalL(&lista, "abc");
    insereFinalL(&lista, "abcde");
    insereFinalL(&lista, "abcde");
    insereFinalL(&lista, "odabas8*");
    insereFinalL(&lista, "abcde");
    insereFinalL(&lista, "a78");
    insereFinalL(&lista, "abcde");
    insereFinalL(&lista, "ac8");
    insereFinalL(&lista, "shiuahsiuhai%$");
    insereFinalL(&lista, "abcde");
    insereFinalL(&lista, "abcde");

    mostraL(&lista);

    No* listaNaoSeguras = naoSeguras(&lista);

    cout << "\nLista de senhas não seguras: " << endl;
    mostraL(&listaNaoSeguras);

    destroiL(&lista);
    destroiL(&listaNaoSeguras);

    return EXIT_SUCCESS;
}
