#ifndef _HPP_LISTA_DINAMICA
#define _HPP_LISTA_DINAMICA

struct No
{
    string dado;
    struct No *prox;
};

void inicializaL(No **lista)
{
    *lista = NULL;
}

bool vaziaL(No **lista)
{
    return (*lista == NULL);
}

void destroiL(No **lista)
{
    No *n = *lista;
    while (n != NULL)
    {
        No *aux = n;
        n = n->prox;
        delete aux;
    }
    *lista = NULL;
}

void mostraL(No **lista)
{
    No *n = *lista;
    cout << "L: {";
    while (n != NULL)
    {
        cout << n->dado;
        n = n->prox;
        if (n != NULL)
            cout << ", ";
    }
    cout << "}\n";
}

void insereFinalL(No **lista, string valor)
{
    No *novo = new No();
    novo->dado = valor;
    novo->prox = NULL;

    if (vaziaL(lista))
    {
        *lista = novo;
    }
    else
    {
        No *n = *lista;
        while (n->prox != NULL)
        {
            n = n->prox;
        }
        n->prox = novo;
    }
}

#endif
