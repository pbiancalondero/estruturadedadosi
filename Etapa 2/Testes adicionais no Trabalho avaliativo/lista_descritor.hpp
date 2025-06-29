#ifndef _HPP_LISTA_DESCRITOR
#define _HPP_LISTA_DESCRITOR

struct No
{
    Compromisso dado;
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

void mostraL(Lista *lista)
{
    No *n = lista->inicio;

    cout << "L:[" << lista->tamanho << "]{";
    while(n != NULL ) /// enquanto n não for NULL fica no laço
    {
        cout <<"["<< n->dado.dia <<"/"<< n->dado.mes<<"/"<< n->dado.ano<<" - "<< n->dado.descricao <<"]";
        n = n->prox;

        if(n != NULL)
            cout << ", ";
    }
    cout << "}\n";
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
bool insereInicioL(Lista *lista, Compromisso valor)
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
bool insereFimL(Lista *lista, Compromisso valor)
{

    No *novo = new No();
    if (novo == nullptr)
        return false;

    novo->dado = valor;
    novo->prox = NULL;

    if(vaziaL(lista))
    {
        lista->inicio = novo;//porque está vazia, então terá 1 elemento apenas
        lista->fim = novo;//porque está vazia, então terá 1 elemento apenas
    }
    else
    {
        lista->fim->prox = novo;
        lista->fim = novo;
    }

    lista->tamanho++;
    return true;
}


Compromisso leInicioL(Lista *lista)
{
    Compromisso dado;

    if(vaziaL(lista) == false)
        dado = lista->inicio->dado; //atribui o dado do início da lista para a variável dado

    return dado;
}

Compromisso removeInicioL(Lista *lista)
{
    No* aux;
    Compromisso dado;

    if(vaziaL(lista) == false)
    {
        dado = lista->inicio->dado; //atribui o dado do início da lista para a variável dado
        aux = lista->inicio; //pega a referenccia do primeiro nó, o qual será removido

        lista->inicio = lista->inicio->prox; //atualiza o início da lista para o próximo elemento

        delete aux;
    }
    else
        return dado;

    if(lista->inicio == NULL)
        lista->fim = nullptr;
    //se tiver só um elemento o fim tem que apontar pra null

    lista->tamanho--;
    return dado;
}

Compromisso leFinalL(Lista *lista)
{
    Compromisso dado;
    No* n = lista->inicio;
    while(n->prox!=NULL)
    {
        n = n->prox;
    }
    dado = n->dado;
    return dado;
}


Compromisso removeFinalL(Lista *lista)
{
    Compromisso dado;

    if (vaziaL(lista))
    {
        return dado;
    }

    No *atual = lista->inicio;
    No *anterior = nullptr;

    while (atual->prox != nullptr)
    {
        anterior = atual;
        atual = atual->prox;
    }

    dado = atual->dado; // Dado do último elemento

    if (anterior == nullptr)
    {
        // Lista tinha apenas um elemento
        lista->inicio = nullptr;
        lista->fim = nullptr;
    }
    else
    {
        // Remove o último elemento
        anterior->prox = nullptr;
        lista->fim = anterior;
    }

    delete atual;
    lista->tamanho--;

    return dado;
}

void inverteL(Lista *lista)
{
    Lista aux;

    if(vaziaL(lista))
        return;
    else
    {
        while(!vaziaL(lista))
            insereInicioL(&aux, removeFinalL(lista));

        while(!vaziaL(&aux))
            insereFimL(lista, removeFinalL(&aux));
    }
}

void ordenaDia(Lista *lista)
{
    if (lista == nullptr || lista->inicio == nullptr || lista->inicio->prox == nullptr)
        return;

    bool trocou;
    do
    {
        trocou = false;
        No *atual = lista->inicio;
        No *anterior = nullptr;

        while (atual != nullptr && atual->prox != nullptr)
        {
            No *proximo = atual->prox;

            if (atual->dado.dia > proximo->dado.dia)
            {
                Compromisso valor = atual->dado;
                atual->dado = proximo->dado;
                proximo->dado = valor;
                trocou = true;
            }
            anterior = atual;
            atual = atual->prox;
        }
    }
    while (trocou);
}

void ordenaMes(Lista *lista)
{
    if (lista == nullptr || lista->inicio == nullptr || lista->inicio->prox == nullptr)
        return;

    bool trocou;
    do
    {
        trocou = false;
        No *atual = lista->inicio;
        No *anterior = nullptr;

        while (atual != nullptr && atual->prox != nullptr)
        {
            No *proximo = atual->prox;

            if (atual->dado.mes > proximo->dado.mes)
            {
                Compromisso valor = atual->dado;
                atual->dado = proximo->dado;
                proximo->dado = valor;
                trocou = true;
            }
            anterior = atual;
            atual = atual->prox;
        }
    }
    while (trocou);
}

void ordenaAno(Lista *lista)
{
    if (lista == nullptr || lista->inicio == nullptr || lista->inicio->prox == nullptr)
        return;

    bool trocou;
    do
    {
        trocou = false;
        No *atual = lista->inicio;
        No *anterior = nullptr;

        while (atual != nullptr && atual->prox != nullptr)
        {
            No *proximo = atual->prox;

            if (atual->dado.ano > proximo->dado.ano)
            {
                Compromisso valor = atual->dado;
                atual->dado = proximo->dado;
                proximo->dado = valor;
                trocou = true;
            }
            anterior = atual;
            atual = atual->prox;
        }
    }
    while (trocou);
}

void ordenarL(Lista *lista)
{
    if (lista == nullptr || lista->inicio == nullptr || lista->inicio->prox == nullptr)
        return;

    ordenaDia(lista);
    ordenaMes(lista);
    ordenaAno(lista);

}

void insereAposPrimeiraOcorrencia(Lista *lista, int dia, int mes, int ano, Compromisso comp)
{
    if (lista == nullptr || lista->inicio == nullptr || lista->inicio->prox == nullptr)
        return;

    No *n = lista->inicio;

    while (n != nullptr)
    {
        if ((n->dado.dia == dia) && (n->dado.mes == mes) && (n->dado.ano == ano))
        {
            No *novo = new No();
            novo->dado = comp;
            novo->prox = n->prox;
            n->prox = novo;

            if (n == lista->fim)
                lista->fim = novo;

            lista->tamanho++;
            n = novo->prox;
            return;
        }
        else
            n = n->prox;
    }
}

void insereAposCadaOcorrencia(Lista *lista, int dia, int mes, int ano, Compromisso comp)
{
    if (lista == nullptr || lista->inicio == nullptr || lista->inicio->prox == nullptr)
        return;

    No *n = lista->inicio;

    while (n != nullptr)
    {
        if ((n->dado.dia == dia) && (n->dado.mes == mes) && (n->dado.ano == ano))
        {
            No *novo = new No();
            novo->dado = comp;
            novo->prox = n->prox;
            n->prox = novo;

            if (n == lista->fim)
                lista->fim = novo;

            lista->tamanho++;
            n = novo->prox;
        }
        else
            n = n->prox;
    }
}

#endif // _HPP_LISTA_DESCRITOR
