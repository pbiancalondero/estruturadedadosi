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
    while(n != NULL ) /// enquanto n n�o for NULL fica no la�o
    {
        cout << n->dado;
        n = n->prox;

        if(n != NULL)
            cout << ", ";
    }
    cout << "}\n";
}

//insere no in�cio da lista
template<typename T>
bool insereInicioL(No<T> **lista, T valor)
{

    No<T> *novo = new No<T>(); // aloca mem�ria para o n�
    if (novo == NULL)
        return false;

    novo->dado = valor;
    novo->prox = *lista;
    *lista = novo;

    return true;
}

//retorna o valor do primeiro elemento da lista SEM remov�-lo
template<typename T>
T leInicioL(No<T> **lista)
{
    T dado =0;

    if(vaziaL(lista) == false)
        dado = (*lista)->dado; //atribui o dado do in�cio da lista para a vari�vel dado

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
        dado = (*lista)->dado; //atribui o dado do in�cio da lista para a vari�vel dado
        aux = *lista; //pega a referenccia do primeiro n�, o qual ser� removido

        *lista = (*lista)->prox; //atualiza o in�cio da lista para o pr�ximo elemento

        delete aux;
    }

    return dado;
}




///remover um n� da lista com um valor espec�fico
template<typename T>
bool removeL(No<T> **lista, T valor)
{
    No<T> *anterior = NULL;
    No<T> *atual = *lista;
    ///fica no la�o enquanto tiver elementos na lista
    /// e n�o encontrar o valor procurado
    while(atual!=NULL && atual->dado != valor)
    {
        anterior = atual;
        atual = atual->prox;
    }
    /// pode sair do la�o sem encontrar o valor (atual==NULL)
    /// se encontrar -> atual tem o endere�o do elemento para excluir
    if(atual == NULL) /// se atual � NULL -> n�o encontrou
        return false;

    if (anterior == NULL)/// o elemento a ser exclu�do est� no in�cio da lista
        *lista = atual->prox;
    else   /// elemento est� no meio ou no fim
        anterior->prox = atual->prox;

    /// libera a mem�ria do elemento
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









