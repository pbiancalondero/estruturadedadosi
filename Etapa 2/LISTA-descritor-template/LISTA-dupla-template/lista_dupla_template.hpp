#ifndef _HPP_LISTA_DUPLA_TEMPLATE
#define _HPP_LISTA_DUPLA_TEMPLATE

template<typename T>
struct No
{
    T dado;
    No *prox;
    No *ant;
    No() // construtor
    {
        prox = nullptr;
        ant = nullptr;
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
void destroiL(Lista<T> *l)
{
    No<T> *n = l->inicio;
    while(n)
    {
        No<T> *aux = n;
        n = n->prox;
        delete aux;
    }
    l->fim = NULL;
    l->inicio = NULL;
    l->tamanho = 0;
}

template<typename T>
bool vaziaL(Lista<T> *lista)
{
    if(! (lista->inicio) )
        return true;
    else
        return false;
}


template<typename T>
void mostraL(Lista<T> *lista)
{
    No<T> *n = lista->inicio;
    cout << "L[" << lista->tamanho << "]:{";
    while(n)
    {
        cout << n->dado;
        n = n->prox;

        if(n)
            cout << ", ";
    }
    cout << "}" << endl;
}

template<typename T>
void mostrarInversoL(Lista<T> *lista)
{
    No<T> *n = lista->fim;
    cout << "L[" << lista->tamanho << "]:{";
    while(n)
    {
        cout << n->dado;
        n = n->ant;

        if(n)
            cout << ", ";
    }
    cout << "}" << endl;
}


///insere no início da lista
template<typename T>
bool insereInicioL(Lista<T> *lista, T valor)
{

    No<T> *novo = new No<T>();
    if (!novo)
        return false;

    novo->dado = valor;
    novo->ant = nullptr; //Se o novo nó será adicionado no início da lista, o ponteiro *ant do primeiro nó sempre é nulo
    novo->prox = lista->inicio;

    if (!lista->fim) //lista vazia?
        lista->fim = novo;
    else
        lista->inicio->ant = novo;

    lista->inicio = novo;
    lista->tamanho++;

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

template<typename T>
bool removerNoL(Lista<T> *lista, No<T> *no)
{
    if(!no || !lista || vaziaL(lista))
        return false;

    if (!no->ant) /// se anterior é igual a NULL, o elemento a ser excluído está no início da lista
    {
        lista->inicio = no->prox;
        if (!lista->inicio) ///lista ficou vazia ?
            lista->fim = nullptr;
        else
            lista->inicio->ant = nullptr;

    }else{ /// elemento está no meio ou no fim

        no->ant->prox = no->prox;
        if (!no->prox)/// se for retirado último da lista
            lista->fim = no->ant;
        else
            no->prox->ant = no->ant;

    }

    /// libera a memória do elemento
    lista->tamanho--;
    delete(no);
    return true;
}

template<typename T>
bool removeL(Lista<T> *lista, T valor)
{
    No<T>* no = buscaL(lista, valor);

    if(!no)
        return false;

    removerNoL(lista, no);

    return true;
}


#endif // _HPP_LISTA_DUPLA_TEMPLATE



