#ifndef _HPP_LISTA_DESCRITOR_TEMPLATE
#define _HPP_LISTA_DESCRITOR_TEMPLATE


template<typename T>
struct No
{
    T dado;
    struct No *prox;
    No() // construtor
    {
        prox = nullptr;
    }
};

template<typename T>
struct Lista
{
    No<T> *inicio;
    No<T> *fim;
    int tamanho;
    Lista() /// construtor
    {
        //cout << "\n executando o construtor...\n";
        inicio = nullptr;
        fim = nullptr;
        tamanho =0;
    }
};


template<typename T>
void mostraL(Lista<T> *lista)
{
    No<T> *n = lista->inicio;

    cout << "L["<< lista->tamanho << "]:{";
    while(n != NULL ) /// enquanto n n�o for NULL fica no la�o
    {
        cout << n->dado;
        n = n->prox;

        if(n != NULL)
            cout << ", ";
    }
    cout << "}\n";
}

template<typename T>
void destroiL(Lista<T> *lista)
{
    No<T> *n = lista->inicio;
    while(n != nullptr)
    {
        No<T> *aux = n;
        n = n->prox;
        delete aux;
    }
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

template<typename T>
bool vaziaL(Lista<T> *lista)
{
    if(lista->inicio == NULL )
        return true;
    else
        return false;
}

///insere no in�cio da lista
template<typename T>
bool insereInicioL(Lista<T> *lista, T valor)
{

    No<T> *novo = new No<T>();
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

template<typename T>
bool insereFimL(Lista<T> *lista, T valor)
{

    No<T> *novo = new No<T>();
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


template<typename T>
bool removeL(Lista<T> *lista, T valor)
{
    No<T> *anterior = nullptr;
    No<T> *atual = lista->inicio;
    ///fica no la�o enquanto tiver elementos na lista
    /// e n�o encontrar o valor procurado
    while(atual && atual->dado != valor)
    {
        anterior = atual;
        atual = atual->prox;
    }
    /// pode sair do la�o sem encontrar o valor (atual==NULL)
    /// se encontrar >>> atual tem o endere�o do elemento para excluir
    /// NULL == false    >>> !false == true
    if(!atual) /// se atual � NULL >> n�o encontrou
        return false;
    if (!anterior) /// se anterior � igual a NULL
    {
        /// o elemento a ser exclu�do est� no in�cio da lista
        lista->inicio = atual->prox;
        if (!lista->inicio) ///lista ficou vazia ?
            lista->fim = lista->inicio;
    }
    else   /// elemento est� no meio ou no fim
    {
        anterior->prox = atual->prox;
        if (!atual->prox)/// se for retirado �ltimo da lista
            lista->fim = anterior;
    }
    /// libera a mem�ria do elemento
    lista->tamanho--;

    delete(atual);
    return true;

}

template<typename T>
No<T>* buscaL(Lista<T> *lista, T valor)
{
    No<T> *n = lista->inicio;
    while (n)
    {
        if (n->dado == valor)
            return n;

        n = n->prox;
    }

    return nullptr;
}


#endif // _HPP_LISTA_DESCRITOR



