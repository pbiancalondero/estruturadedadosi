#ifndef _HPP_LISTA_DESCRITOR
#define _HPP_LISTA_DESCRITOR
#include <iomanip>

struct No
{
    int dado;
    struct No *prox;
    No() // construtor
    {
        prox = nullptr;
    }
};

struct Lista
{
    No *inicio;
    No *fim;
    int tamanho;
    Lista() /// construtor
    {
        //cout << "\n executando o construtor...\n";
        inicio = nullptr;
        fim = nullptr;
        tamanho =0;
    }
};

void mostraL(Lista *lista, string nomeLista, char valor)
{
    No *n = lista->inicio;

    cout << nomeLista << "(" << valor<< "): ";
    while(n != NULL ) /// enquanto n não for NULL fica no laço
    {
        cout << n->dado;
        n = n->prox;

        if(n != NULL)
            cout << ", ";
    }
    cout << endl;
}

void destroiL(Lista *lista)
{
    No *n = lista->inicio;
    while(n != nullptr)
    {
        No *aux = n;
        n = n->prox;
        delete aux;
    }
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}


bool vaziaL(Lista *lista)
{
    if(lista->inicio == NULL )
        return true;
    else
        return false;
}

///insere no início da lista
bool insereInicioL(Lista *lista, int valor)
{

    No *novo = new No();
    if (novo == nullptr)
        return false;

    novo->dado = valor;
    novo->prox = lista->inicio;
    lista->inicio = novo;
    lista->tamanho++;
    if (!lista->fim)
        lista->fim = lista->inicio;

    return true;
}
bool insereFimL(Lista *lista, int valor)
{

    No *novo = new No();
    if (novo == nullptr)
        return false;

    novo->dado = valor;
    novo->prox = NULL;

    if(vaziaL(lista))
    {
        lista->inicio = novo;
        lista->fim = novo;
    }
    else
    {
        lista->fim->prox = novo;
        lista->fim = novo;
    }

    lista->tamanho++;
    return true;
}



bool removeL(Lista *lista, int valor)
{
    No *anterior = nullptr;
    No *atual = lista->inicio;
    ///fica no laço enquanto tiver elementos na lista
    /// e não encontrar o valor procurado
    while(atual && atual->dado != valor)
    {
        anterior = atual;
        atual = atual->prox;
    }
    /// pode sair do laço sem encontrar o valor (atual==NULL)
    /// se encontrar >>> atual tem o endereço do elemento para excluir
    /// NULL == false    >>> !false == true
    if(!atual) /// se atual é NULL >> não encontrou
        return false;
    if (!anterior) /// se anterior é igual a NULL
    {
        /// o elemento a ser excluído está no início da lista
        lista->inicio = atual->prox;
        if (!lista->inicio) ///lista ficou vazia ?
            lista->fim = lista->inicio;
    }
    else   /// elemento está no meio ou no fim
    {
        anterior->prox = atual->prox;
        if (!atual->prox)/// se for retirado último da lista
            lista->fim = anterior;
    }
    /// libera a memória do elemento
    lista->tamanho--;

    delete(atual);
    return true;

}

No* buscaL(Lista *lista, int valor)
{
    No *n = lista->inicio;
    while (n)
    {
        if (n->dado == valor)
            return n;

        n = n->prox;
    }

    return nullptr;
}

void mostraOrdemC(Lista *lista, string nomeLista, char valor)
{
    Lista aux;
    No *n = lista->inicio;

    while (n != nullptr)
    {
        insereFimL(&aux, n->dado);
        n = n->prox;
    }

    bool trocou;
    do
    {
        trocou = false;
        No *atual = aux.inicio;

        while (atual != nullptr && atual->prox != nullptr)
        {
            if (atual->dado > atual->prox->dado)
            {
                int valor = atual->dado;
                atual->dado = atual->prox->dado;
                atual->prox->dado = valor;
                trocou = true;
            }
            atual = atual->prox;
        }
    } while (trocou);

    mostraL(&aux, nomeLista, valor);

    destroiL(&aux);
}

void mostraOrdemD(Lista *lista, string nomeLista, char valor)
{
    Lista aux;
    No *n = lista->inicio;

    while (n != nullptr)
    {
        insereFimL(&aux, n->dado);
        n = n->prox;
    }

    bool trocou;
    do
    {
        trocou = false;
        No *atual = aux.inicio;

        while (atual != nullptr && atual->prox != nullptr)
        {
            if (atual->dado < atual->prox->dado)
            {
                int valor = atual->dado;
                atual->dado = atual->prox->dado;
                atual->prox->dado = valor;
                trocou = true;
            }
            atual = atual->prox;
        }
    } while (trocou);

    mostraL(&aux, nomeLista, valor);

    destroiL(&aux);
}

void mostraDif(Lista *lista1, Lista *lista2)
{
    Lista diferenca;

    No *n = lista1->inicio;

    while (n)
    {
        if (!buscaL(lista2, n->dado))
            insereFimL(&diferenca, n->dado);
        n = n->prox;
    }

    bool trocou;
    do
    {
        trocou = false;
        No *atual = diferenca.inicio;

        while (atual != nullptr && atual->prox != nullptr)
        {
            if (atual->dado > atual->prox->dado)
            {
                int valor = atual->dado;
                atual->dado = atual->prox->dado;
                atual->prox->dado = valor;
                trocou = true;
            }
            atual = atual->prox;
        }
    } while (trocou);

    No *aux = (&diferenca)->inicio;

    while(aux != NULL ) /// enquanto n não for NULL fica no laço
    {
        cout << aux->dado;
        aux = aux->prox;

        if(aux != NULL)
            cout << ", ";
    }
    cout << endl;

    destroiL(&diferenca);
}

void removeTodos(Lista *lista)
{
    while (!vaziaL(lista))
    {
        No *atual = lista->inicio;
        lista->inicio = lista->inicio->prox;
        delete atual;
        lista->tamanho--;
    }
    lista->fim = nullptr;
}

void mediana(Lista *lista)
{
    if (vaziaL(lista))
        return;

    Lista aux;
    No *n = lista->inicio;
    int cont = 0;

    // Copiar os elementos para uma lista auxiliar
    while (n != nullptr)
    {
        insereFimL(&aux, n->dado);
        cont++;
        n = n->prox;
    }

    // Ordenar a lista auxiliar em ordem crescente
    bool trocou;
    do
    {
        trocou = false;
        No *atual = aux.inicio;

        while (atual != nullptr && atual->prox != nullptr)
        {
            if (atual->dado > atual->prox->dado)
            {
                int valor = atual->dado;
                atual->dado = atual->prox->dado;
                atual->prox->dado = valor;
                trocou = true;
            }
            atual = atual->prox;
        }
    } while (trocou);

    double mediana;
    No *atual = aux.inicio;

    if (cont == 1)
    {
        mediana = atual->dado;
    }
    else if (cont % 2 == 1)
    {
        int pos = cont / 2;
        for (int i = 0; i < pos; i++)
            atual = atual->prox;
        mediana = atual->dado;
    }
    else
    {
        int pos1 = (cont / 2) - 1;
        int pos2 = cont / 2;

        for (int i = 0; i < pos1; i++)
            atual = atual->prox;

        int val1 = atual->dado;
        atual = atual->prox;
        int val2 = atual->dado;

        mediana = (val1 + val2) / 2.0;
    }

    // Exibir a mediana formatada
    cout << fixed << setprecision(2);
    cout << mediana << endl;

    // Liberar a lista auxiliar
    destroiL(&aux);
}

void moda(Lista *lista)
{
    if (vaziaL(lista))
        return;

    Lista auxFrequencias; // Lista auxiliar para contar frequências
    Lista valores;        // Lista auxiliar para armazenar valores únicos
    No *n = lista->inicio;

    // Contar a frequência de cada elemento
    while (n != nullptr)
    {
        No *existente = buscaL(&valores, n->dado);

        if (existente == nullptr)
        {
            insereFimL(&valores, n->dado);
            insereFimL(&auxFrequencias, 1);
        }
        else
        {
            No *freqAtual = auxFrequencias.inicio;
            No *valAtual = valores.inicio;

            while (valAtual != nullptr && valAtual->dado != n->dado)
            {
                freqAtual = freqAtual->prox;
                valAtual = valAtual->prox;
            }

            if (freqAtual != nullptr)
                freqAtual->dado++;
        }

        n = n->prox;
    }

    // Encontrar a maior frequência
    int maiorFrequencia = 0;
    No *freqAtual = auxFrequencias.inicio;
    while (freqAtual != nullptr)
    {
        if (freqAtual->dado > maiorFrequencia)
            maiorFrequencia = freqAtual->dado;

        freqAtual = freqAtual->prox;
    }

    // Verificar se é amodal
    if (maiorFrequencia == 1)
    {
        cout << "VAZIA" << endl;
        destroiL(&valores);
        destroiL(&auxFrequencias);
        return;
    }

    No *valAtual = valores.inicio;
    freqAtual = auxFrequencias.inicio;

    bool primeiro = true;
    while (valAtual != nullptr)
    {
        if (freqAtual->dado == maiorFrequencia)
        {
            if (!primeiro)
                cout << ", ";
            cout << valAtual->dado;
            primeiro = false;
        }

        valAtual = valAtual->prox;
        freqAtual = freqAtual->prox;
    }
    cout << endl;

    destroiL(&valores);
    destroiL(&auxFrequencias);
}

#endif // _HPP_LISTA_DESCRITOR
