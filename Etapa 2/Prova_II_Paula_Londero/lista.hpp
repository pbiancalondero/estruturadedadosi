#ifndef _HPP_LISTA_DINAMICA
#define _HPP_LISTA_DINAMICA

struct No
{
    int dado;
    struct No *prox;
};


void inicializaL(No **lista)
{
    *lista = NULL;
}

bool vaziaL(No **lista)
{
    if( (*lista) == NULL )
        return true;
    else
        return false;
}

/// excluir todos os elementos da lista
void destroiL(No **lista)
{
    No *n = *lista;
    while (n != NULL)
    {
        No *aux  = n;
        n = n->prox;
        delete aux;
    }
    *lista = NULL;
}

void mostraL(No **lista)
{
    No *n = *lista;

    cout << "L:{";
    while(n != NULL ) /// enquanto n não for NULL fica no laço
    {
        cout << n->dado;
        n = n->prox;

        if(n != NULL)
            cout << ", ";
    }
    cout << "}\n";
}

//insere no início da lista
bool insereInicioL(No **lista, int valor)
{

    No *novo = new No(); // aloca memória para o nó
    if (novo == NULL)
        return false;

    novo->dado = valor;
    novo->prox = *lista;
    *lista = novo;

    return true;
}

//retorna o valor do primeiro elemento da lista SEM removê-lo
int leInicioL(No **lista)
{
    int dado =0;

    if(vaziaL(lista) == false)
        dado = (*lista)->dado; //atribui o dado do início da lista para a variável dado

    return dado;
}

//retorna o valor do primeiro elemento da lista e REMOVE o elemento
int removeInicioL(No **lista)
{
    No* aux;
    int dado;

    if(vaziaL(lista) == false)
    {
        dado = (*lista)->dado; //atribui o dado do início da lista para a variável dado
        aux = *lista; //pega a referenccia do primeiro nó, o qual será removido

        *lista = (*lista)->prox; //atualiza o início da lista para o próximo elemento

        delete aux;
    }

    return dado;
}




///remover um nó da lista com um valor específico
bool removeL(No **lista, int valor)
{
    No *anterior = NULL;
    No *atual = *lista;
    ///fica no laço enquanto tiver elementos na lista
    /// e não encontrar o valor procurado
    while(atual!=NULL && atual->dado != valor)
    {
        anterior = atual;
        atual = atual->prox;
    }
    /// pode sair do laço sem encontrar o valor (atual==NULL)
    /// se encontrar -> atual tem o endereço do elemento para excluir
    if(atual == NULL) /// se atual é NULL -> não encontrou
        return false;

    if (anterior == NULL)
    {
        /// o elemento a ser excluído está no início da lista
        *lista = atual->prox;
    }
    else   /// elemento está no meio ou no fim
    {
        anterior->prox = atual->prox;
    }

    /// libera a memória do elemento
    delete(atual);
    return true;
}


No* buscaL(No **lista, int valor)
{
    No *n = *lista;
    while (n != NULL)
    {
        if (n->dado == valor)
            return n;

        n = n->prox;
    }

    return NULL;
}

void insereFinalL(No **lista, int valor)
{
    No *novo = new No();
    novo->dado = valor;
    novo->prox = NULL;

    if(vaziaL(lista))
    {
        *lista = novo;
    }
    else
    {
        No* n = *lista;
        while(n->prox!=NULL)
        {
            n = n->prox;
        }
        n->prox = novo;
    }
}

int removeFinalL(No **lista)
{
    int dado =0;
    No* n = *lista;
    No *anterior = NULL;

    if(n==NULL)//lista vazia
        return dado;

    while(n->prox!=NULL)//encontra o último nó, guardando o anterior
    {
        anterior = n;
        n = n->prox;
    }

    if(anterior ==NULL)//só tem um elemento, a lista ficará vazia
        *lista = NULL;
    else
        anterior->prox = NULL;//lista com mais de um elemento, atualiza o ponteiro anterior

    dado = n->dado;
    delete n;

    return dado;
}

void inverterPares(No **lista)
{
    No *n = *lista;
    No *aux = NULL;
    inicializaL(&aux);

    while (n != NULL)
    {
        int v = n->dado;
        if (v % 2 == 0)
            insereInicioL(&aux, v);
        n = n->prox;
    }

    n = *lista;

    while (n != NULL)
    {
        if (n->dado % 2 == 0)
        {
            int r = removeInicioL(&aux);
            n->dado = r;
        }
        n = n->prox;
    }
}


#endif // _HPP_LISTA_DINAMICA









