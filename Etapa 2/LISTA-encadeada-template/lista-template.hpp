#ifndef _HPP_LISTA_DINAMICA_TEMPLATE
#define _HPP_LISTA_DINAMICA_TEMPLATE


template<typename T>
struct No
{
    T dado;
    struct No *prox;
};

template<typename T>
void inicializaL(No<T> **lista)
{
    *lista = NULL;
}

template<typename T>
bool vaziaL(No<T> **lista)
{
    if( (*lista) == NULL )
        return true;
    else
        return false;
}

/// excluir todos os elementos da lista
template<typename T>
void destroiL(No<T> **lista)
{
    No<T> *n = *lista;
    while (n != NULL)
    {
        No<T> *aux  = n;
        n = n->prox;
        delete aux;
    }
    *lista = NULL;
}

template<typename T>
void mostraL(No<T> **lista, string nome="")
{
    No<T> *n = *lista;

    cout << "L<" << nome << ">:{";
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
template<typename T>
bool insereInicioL(No<T> **lista, T valor)
{

    No<T> *novo = new No<T>(); // aloca memória para o nó
    if (novo == NULL)
        return false;

    novo->dado = valor;
    novo->prox = *lista;
    *lista = novo;

    return true;
}

//retorna o valor do primeiro elemento da lista SEM removê-lo
template<typename T>
T leInicioL(No<T> **lista)
{
    T dado =0;

    if(vaziaL(lista) == false)
        dado = (*lista)->dado; //atribui o dado do início da lista para a variável dado

    return dado;
}

//retorna o valor do primeiro elemento da lista e REMOVE o elemento
template<typename T>
T removeInicioL(No<T> **lista)
{
    No<T>* aux;
    T dado;

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
template<typename T>
bool removeL(No<T> **lista, T valor)
{
    No<T> *anterior = NULL;
    No<T> *atual = *lista;
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

    if (anterior == NULL)/// o elemento a ser excluído está no início da lista
        *lista = atual->prox;
    else   /// elemento está no meio ou no fim
        anterior->prox = atual->prox;

    /// libera a memória do elemento
    delete(atual);
    return true;
}

template<typename T>
No<T>* buscaL(No<T> **lista, T valor)
{
    No<T> *n = *lista;
    while (n != NULL)
    {
        if (n->dado == valor)
            return n;

        n = n->prox;
    }

    return NULL;
}

#endif // _HPP_LISTA_DINAMICA









