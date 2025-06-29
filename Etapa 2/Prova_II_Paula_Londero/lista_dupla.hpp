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

void mostraL(Lista *lista, string nome)
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

void mostrarInversoL(Lista *lista, string descricao)
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

bool removeL(Lista *lista, int valor)
{
    No* no = buscaL(lista, valor);

    if(!no)
        return false;

    removerNoL(lista, no);

    return true;
}
void concatenarListas(Lista *l1, Lista *l2, Lista *l3) {
    if (vaziaL(l1) || vaziaL(l2)) {
        cout << "Não é possível concatenar listas vazias!" << endl;
        return;
    }

    // Define os ponteiros de L3
    l3->inicio = l1->inicio;
    l3->fim = l2->fim;
    l3->tamanho = l1->tamanho + l2->tamanho;

    // Conecta o último nó de L1 ao primeiro nó de L2
    l1->fim->prox = l2->inicio;
    l2->inicio->ant = l1->fim;

    // Esvazia L1 e L2
    l1->inicio = nullptr;
    l1->fim = nullptr;
    l1->tamanho = 0;

    l2->inicio = nullptr;
    l2->fim = nullptr;
    l2->tamanho = 0;
}





#endif // _HPP_LISTA_DUPLA



