#ifndef _HPP_LISTA_DUPLA
#define _HPP_LISTA_DUPLA


struct No
{
    Cadastro dado;
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
    int contadorCodigo;
    Lista() /// construtor
    {
        //cout << "\n executando o construtor...\n";
        inicio = nullptr;
        fim = nullptr;
        tamanho =0;
        contadorCodigo = 1;
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
        cout <<"["<< n->dado.codigo<<", "<<n->dado.idade<<", "<<n->dado.peso<<"]"<<endl;
        n = n->prox;
        //if(n)
        //cout << ", ";
    }
    cout << "}\n";
}

void mostrarInversoL(Lista *lista)
{
    No *n = lista->fim;
    cout << "L[" << lista->tamanho << "]:{";
    while(n)
    {
        cout << n->dado.codigo <<", " << n->dado.idade << ", "<<n->dado.peso;
        n = n->ant;

        if(n)
            cout << ", ";
    }
    cout << "}" << endl;
}


///insere no início da lista
bool insereInicioL(Lista *lista, Cadastro valor)
{

    No *novo = new No();
    if (novo == NULL)
        return false;

    valor.codigo = lista->contadorCodigo++;

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
        if (n->dado.codigo == valor)
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

bool removeL(Lista *lista, Cadastro valor)
{
    No* no = buscaL(lista, valor.codigo);

    if(!no)
        return false;

    removerNoL(lista, no);

    return true;
}

bool insereFinalL(Lista *lista, Cadastro valor)
{

    No *novo = new No();
    if (novo == NULL)
        return false;

    valor.codigo = lista->contadorCodigo++;

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

bool insereFinaL(Lista *lista, Cadastro valor)
{

    No *novo = new No();
    if (novo == NULL)
        return false;

    //valor.codigo = lista->contadorCodigo++;

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

void ordenaChegada(Lista *lista)
{
    if (!lista || vaziaL(lista))
        return;

    bool trocou;
    do
    {
        trocou = false;
        No *atual = lista->inicio;
        while (atual && atual->prox)
        {
            if (atual->dado.codigo > atual->prox->dado.codigo)
            {
                Cadastro valor = atual->dado;
                atual->dado = atual->prox->dado;
                atual->prox->dado = valor;
                trocou = true;
            }
            atual = atual->prox;
        }
    }
    while (trocou);
}

void tresUltimos(Lista *lista)
{
    No *n = lista->fim;
    cout << "L[" << lista->tamanho << "]:{";
    cout <<"["<< n->dado.codigo<<", "<<n->dado.idade<<", "<<n->dado.peso<<"]"<<endl;
    if(n)
    {
        n = n->ant;
        cout <<"["<< n->dado.codigo<<", "<<n->dado.idade<<", "<<n->dado.peso<<"]"<<endl;
    }
    if(n)
    {
        n = n->ant;
        cout <<"["<< n->dado.codigo<<", "<<n->dado.idade<<", "<<n->dado.peso<<"]"<<endl;
    }
    cout << "}\n";
    delete(n);
}

void separaPeso(Lista *lista)
{
    if (!lista || vaziaL(lista))
        return;

    Lista lista2;
    Lista lista3;

    No *n = lista->inicio;

    while (n)
    {
        Cadastro valor = n->dado;

        if (valor.peso <= 50.0)
            insereFinaL(&lista2, valor);

        else
            insereFinaL(&lista3, valor);

        n = n->prox;
    }
    cout << "Lista com peso <= 50kg: " << endl;
    mostraL(&lista2);
    cout << "Lista com peso > 50kg: " << endl;
    mostraL(&lista3);

    delete(n);
    delete(&lista2);
    delete(&lista3);
}

#endif // _HPP_LISTA_DUPLA



