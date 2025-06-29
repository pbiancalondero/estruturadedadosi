#ifndef _HPP_LISTA_DUPLA
#define _HPP_LISTA_DUPLA


struct No
{
    int dado;
    No *prox;
    No *ant;
    No() // construtor
    {
        prox = nullptr;
        ant = nullptr;
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

void destroiL(Lista *l)
{
    No *n = l->inicio;
    while(n)
    {
        No *aux = n;
        n = n->prox;
        delete aux;
    }
    l->fim = NULL;
    l->inicio = NULL;
    l->tamanho = 0;
}

bool vaziaL(Lista *lista)
{
    if(! (lista->inicio) )
        return true;
    else
        return false;
}

void mostraL(Lista *lista)
{
    No *n = lista->inicio;
    cout << "L[" << lista->tamanho << "]:{";
    while(n)
    {
        cout << n->dado;
        n = n->prox;
        if(n)
            cout << ", ";
    }
    cout << "}\n";
}

void mostrarInversoL(Lista *lista)
{
    No *n = lista->fim;
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
bool insereInicioL(Lista *lista, int valor)
{

    No *novo = new No();
    if (novo == NULL)
        return false;

    novo->dado = valor;
    novo->ant = nullptr; //Se o novo nó será adicionado no início da lista, o ponteiro *ant do primeiro nó sempre é nulo
    novo->prox = lista->inicio;

    if (lista->fim == NULL)// //lista vazia?
        lista->fim = novo;
    else
        lista->inicio->ant = novo;

    lista->inicio = novo;
    lista->tamanho++;

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

bool removerNoL(Lista *lista, No *no)
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

    }
    else   /// elemento está no meio ou no fim
    {

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

bool removeL(Lista *lista, int valor)
{
    No* no = buscaL(lista, valor);

    if(!no)
        return false;

    removerNoL(lista, no);

    return true;
}

bool insereFinalL(Lista *lista, int valor)
{

    No *novo = new No();
    if (novo == NULL)
        return false;

    novo->dado = valor;
    novo->prox = nullptr; //Se o novo nó será adicionado no início da lista, o ponteiro *ant do primeiro nó sempre é nulo
    novo->ant = lista->fim;

    if (lista->fim == NULL)// //lista vazia?
        lista->inicio = novo;
    else
        lista->fim->prox = novo;

    lista->fim = novo;
    lista->tamanho++;

    return true;
}


bool removerPrimeiroL(Lista *lista)
{
    No *n = lista->inicio;

    if(!lista || vaziaL(lista))
        return false;

    if (!n)
        return false;

    if(lista->tamanho==1)
    {
        lista->fim = nullptr;
        lista->inicio = nullptr;
    }
    else
    {

        lista->inicio = n->prox;
        if (!lista->inicio) ///lista ficou vazia ?
            lista->fim = nullptr;
        else
            lista->inicio->ant = nullptr;
    }

    /// libera a memória do elemento
    lista->tamanho--;
    delete(n);
    return true;
}

bool removerUltimoL(Lista *lista)
{
    No *n = lista->fim;

    if(!lista || vaziaL(lista))
        return false;

    if (!n)
        return false;

    if(lista->tamanho==1)
    {
        lista->fim = nullptr;
        lista->inicio = nullptr;
    }
    else
    {
        lista->fim = n->ant;
        if (!lista->inicio) ///lista ficou vazia ?
            lista->fim = nullptr;
        else
            lista->fim->prox = nullptr;
    }

    /// libera a memória do elemento
    lista->tamanho--;
    delete(n);
    return true;
}

void removeTodos(Lista *L, int valor)
{
    No *n = L->inicio;
    if(! n || !L || vaziaL(L))
        return;

    while(n)
    {
        No *np = n->prox;
        if (n->dado == valor)
            removerNoL(L, n);
        n = np;

    }
L->tamanho --;
    delete(n);
}

void removeTodosIguais(Lista *L, int valor) //função usando ponteiros
{
    No *no = L->inicio;

    if( !no || !L || vaziaL(L))
        return;

    while(no)
    {
        No *prox = no->prox;
        if(no->dado == valor)
        {
            if (!no->ant) /// se anterior é igual a NULL, o elemento a ser excluído está no início da lista
            {
                L->inicio = no->prox;
                if (!L->inicio) ///lista ficou vazia ?
                    L->fim = nullptr;
                else
                    L->inicio->ant = nullptr;
            }
            else   /// elemento está no meio ou no fim
            {

                no->ant->prox = no->prox;
                if (!no->prox)/// se for retirado último da lista
                    L->fim = no->ant;
                else
                    no->prox->ant = no->ant;
            }
             L->tamanho--;
        }

        no = prox;

    }
    /// libera a memória do elemento

    delete(no);
}

Lista leMaiores(Lista *L, int K)
{
    Lista aux;

    if (vaziaL(L))
        return aux;

    No *n = L->inicio;

    while (n)
    {
        No *novo = new No();
        novo->dado = n->dado;

        if (vaziaL(&aux))
            aux.inicio = aux.fim = novo;

        else
        {
            No *atual = aux.inicio;
            No *anterior = nullptr;

            while (atual && atual->dado > novo->dado)
            {
                anterior = atual;
                atual = atual->prox;
            }

            if (!anterior)
            {
                novo->prox = aux.inicio;
                aux.inicio->ant = novo;
                aux.inicio = novo;
            }
            else if (!atual)
            {
                novo->ant = aux.fim;
                aux.fim->prox = novo;
                aux.fim = novo;
            }
            else
            {
                novo->ant = anterior;
                novo->prox = atual;
                anterior->prox = novo;
                atual->ant = novo;
            }
        }

        aux.tamanho++;

        if (aux.tamanho > K)
            removerUltimoL(&aux);

        n = n->prox;
    }

    mostraL(&aux);
    destroiL(&aux);
}

#endif // _HPP_LISTA_DUPLA
