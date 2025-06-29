#ifndef _HPP_LISTA_DESCRITOR
#define _HPP_LISTA_DESCRITOR

struct No
{
    Cadastro dado;
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

    cout << "L:[tam:" << lista->tamanho << "]{";
    while(n != NULL ) /// enquanto n não for NULL fica no laço
    {
        cout <<"["<< n->dado.codigo <<", "<< n->dado.nome<<", "<< n->dado.idade<<", "<< n->dado.salario <<"]";
        n = n->prox;

        if(n != NULL)
            cout << endl;
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
bool insereInicioL(Lista *lista, Cadastro valor)
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
bool insereFimL(Lista *lista, Cadastro valor)
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


bool removeL(Lista *lista, string nome)
{
    No *anterior = nullptr;
    No *atual = lista->inicio;
    ///fica no laço enquanto tiver elementos na lista
    /// e não encontrar o valor procurado
    while(atual && atual->dado.nome != nome)
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

No* buscaL(Lista *lista, string nome)
{
    No *n = lista->inicio;
    while (n)
    {
        if (n->dado.nome == nome)
            return n;

        n = n->prox;
    }

    return nullptr;
}


Cadastro leInicioL(Lista *lista)
{
    Cadastro dado;

    if(vaziaL(lista) == false)
        dado = lista->inicio->dado; //atribui o dado do início da lista para a variável dado

    return dado;
}

Cadastro removeInicioL(Lista *lista)
{
    No* aux;
    Cadastro dado;

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

Cadastro leFinalL(Lista *lista)
{
    Cadastro dado;
    No* n = lista->inicio;
    while(n->prox!=NULL)
    {
        n = n->prox;
    }
    dado = n->dado;
    return dado;
}

float media(Lista *lista)
{
    No *n = lista->inicio;
    int cont = 0;
    float soma = 0;

    while(n != NULL ) /// enquanto n não for NULL fica no laço
    {
        soma += n->dado.salario;
        n = n->prox;
        cont ++;
    }
    float media = soma/cont;

    return media;
}

void funcionarioPobre(Lista *lista)
{
    No *n = lista->inicio;
    float m = media(lista);

    while(n != NULL ) /// enquanto n não for NULL fica no laço
    {
        if(n->dado.salario < m)
        {
            cout<<n->dado.nome <<", ";
        }
        n = n->prox;
    }
}

void ordenaL(Lista *lista)
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

            if (atual->dado.nome > proximo->dado.nome)
            {
                Cadastro aux = atual->dado;
                atual->dado = proximo->dado;
                proximo->dado = aux;

                trocou = true;
            }
            anterior = atual;
            atual = atual->prox;
        }
    }
    while (trocou);
}


Cadastro removeFinalL(Lista *lista)
{
    Cadastro dado;

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

void mostraOrdenada(Lista *lista)
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

            if (atual->dado.idade > proximo->dado.idade)
            {
                Cadastro aux = atual->dado;
                atual->dado = proximo->dado;
                proximo->dado = aux;

                trocou = true;
            }
            anterior = atual;
            atual = atual->prox;
        }
    }
    while (trocou);
}

void mostraOrdenadaIdade(Lista *lista)
{
    if (vaziaL(lista))
        return;

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
            if (atual->dado.idade > atual->prox->dado.idade)
            {
                Cadastro valor = atual->dado;
                atual->dado = atual->prox->dado;
                atual->prox->dado = valor;
                trocou = true;
            }
            atual = atual->prox;
        }
    } while (trocou);

    mostraL(&aux);

    destroiL(&aux);
}


void uniao(Lista *lista1, Lista *lista2)
{
    Lista aux;
    Cadastro valor;
    Cadastro dados;

    while(!vaziaL(lista1))
    {
        valor = removeFinalL(lista1);
        insereFimL(&aux, valor);
    }

    while(!vaziaL(lista2))
    {
        dados = removeFinalL(lista2);
        insereFimL(&aux, dados);
    }

    mostraL(&aux);
    destroiL(&aux);

}

void interseccao(Lista *lista1, Lista *lista2)
{
    if (vaziaL(lista1) || vaziaL(lista2))
    {
        cout << "Uma ou ambas as listas estão vazias!\n";
        return;
    }

    Lista aux;
    No *n1 = lista1->inicio;

    while (n1 != nullptr)
    {
        No *n2 = lista2->inicio;
        while (n2 != nullptr)
        {
            // Comparar os dados (assumindo que os códigos identificam de forma única os elementos)
            if (n1->dado.codigo == n2->dado.codigo)
            {
                // Verificar se o elemento já não está na lista de interseção
                No *busca = buscaL(&aux, n1->dado.nome);
                if (!busca)
                {
                    insereFimL(&aux, n1->dado);
                }
            }
            n2 = n2->prox;
        }
        n1 = n1->prox;
    }

    cout << "Elementos comuns entre as listas:\n";
    mostraL(&aux);

    destroiL(&aux);
}

#endif // _HPP_LISTA_DESCRITOR



