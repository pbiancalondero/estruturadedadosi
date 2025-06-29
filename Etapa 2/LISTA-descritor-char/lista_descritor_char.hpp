#ifndef _HPP_LISTA_DESCRITOR
#define _HPP_LISTA_DESCRITOR

struct No
{
    char dado;
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
        cout << n->dado;
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
bool insereInicioL(Lista *lista, char valor)
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
bool insereFimL(Lista *lista, char valor)
{

    No *novo = new No();
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



bool removeL(Lista *lista, char valor)
{
    No *anterior = nullptr;
    No *atual = lista->inicio;
    ///fica no laço enquanto tiver elementos na lista
    /// e não encontrar o valor procurado
    while(atual && atual->dado != valor)
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

No* buscaL(Lista *lista, char valor)
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


bool inserir(Lista *lista, int quantidade, string caracteres) {
    if (quantidade > caracteres.size()) return false;

    for (int i = 0; i < quantidade; i++) {
        if (!insereFimL(lista, caracteres[i])) {
            return false;
        }
    }
    return true;
}

void mostrar(Lista *lista, char ordem) {
    if (vaziaL(lista)) {
        cout << "VAZIA" << endl;
        return;
    }

    if (ordem == 'I') { // Ordem inversa
        Lista aux;
        No *n = lista->inicio;
        while (n != nullptr) {
            insereInicioL(&aux, n->dado);
            n = n->prox;
        }
        mostraL(&aux);
        destroiL(&aux);
    } else if (ordem == 'N') { // Ordem normal
        mostraL(lista);
    } else {
        cout << "Ordem inválida!" << endl;
    }
}

bool substituir(Lista *lista, int quantidade, string caracteres) {
    destroiL(lista);
    return inserir(lista, quantidade, caracteres);
}

void inserirCaractereApos(Lista *lista, char caractere1, char caractere2) {
    No *n = lista->inicio;

    while (n != nullptr) {
        if (n->dado == caractere2) {
            No *novo = new No();
            novo->dado = caractere1;
            novo->prox = n->prox;
            n->prox = novo;
            if (n == lista->fim) {
                lista->fim = novo;
            }
            lista->tamanho++;
            n = novo->prox;
        } else {
            n = n->prox;
        }
    }
}

int contarOcorrencia(Lista *L1, Lista *L2) {
    if (vaziaL(L2)) return 0;

    No *n1 = L1->inicio;
    int ocorrencias = 0;

    while (n1 != nullptr) {
        No *n2 = L2->inicio;
        No *atual = n1;

        while (n2 != nullptr && atual != nullptr && n2->dado == atual->dado) {
            n2 = n2->prox;
            atual = atual->prox;
        }

        if (n2 == nullptr) {
            ocorrencias++;
        }

        n1 = n1->prox;
    }

    return ocorrencias;
}

void inserirAntesPrimeiraOcorrencia(Lista *L1, Lista *L2, Lista *L3) {
    if (vaziaL(L2) || vaziaL(L3)) return;

    No *n1 = L1->inicio;
    No *anterior = nullptr;

    while (n1 != nullptr) {
        No *n2 = L2->inicio;
        No *atual = n1;

        while (n2 != nullptr && atual != nullptr && n2->dado == atual->dado) {
            n2 = n2->prox;
            atual = atual->prox;
        }

        if (n2 == nullptr) {
            No *n3 = L3->inicio;
            while (n3 != nullptr) {
                No *novo = new No();
                novo->dado = n3->dado;
                novo->prox = n1;

                if (anterior == nullptr) {
                    L1->inicio = novo;
                } else {
                    anterior->prox = novo;
                }

                anterior = novo;
                n3 = n3->prox;
            }
            L1->tamanho += L3->tamanho;
            return;
        }

        anterior = n1;
        n1 = n1->prox;
    }
}

bool Acrescentar(Lista *L1, Lista *L2, int posicao) {
    if (posicao <= 0 || posicao > L2->tamanho) return false;

    No *atual = L2->inicio;
    int contador = 1;

    // Navegar até a posição desejada
    while (contador < posicao && atual != nullptr) {
        atual = atual->prox;
        contador++;
    }

    // Adicionar elementos de L2 a partir da posição encontrada
    while (atual != nullptr) {
        insereFimL(L1, atual->dado);
        atual = atual->prox;
    }

    return true;
}

bool RemoveNFim(Lista *L1, int N) {
    if (N <= 0 || N > L1->tamanho) return false;

    // Localizar o novo "fim" da lista após a remoção
    No *atual = L1->inicio;
    int novaTamanho = L1->tamanho - N;
    for (int i = 1; i < novaTamanho; i++) {
        atual = atual->prox;
    }

    // Remover elementos a partir do "fim" da lista
    No *remover = atual->prox;
    while (remover != nullptr) {
        No *aux = remover;
        remover = remover->prox;
        delete aux;
    }

    atual->prox = nullptr;
    L1->fim = atual;
    L1->tamanho -= N;

    return true;
}

bool RemoveIntervalo(Lista *L1, int Pi, int Pf) {
    if (Pi <= 0 || Pf <= 0 || Pi > Pf || Pi > L1->tamanho || Pf > L1->tamanho) return false;

    No *atual = L1->inicio;
    No *anterior = nullptr;

    // Navegar até Pi
    for (int i = 1; i < Pi && atual != nullptr; i++) {
        anterior = atual;
        atual = atual->prox;
    }

    // Remover elementos entre Pi e Pf
    for (int i = Pi; i <= Pf && atual != nullptr; i++) {
        No *aux = atual;
        atual = atual->prox;
        delete aux;
        L1->tamanho--;
    }

    // Atualizar ponteiros dos descritores
    if (anterior != nullptr) {
        anterior->prox = atual;
    } else {
        L1->inicio = atual;
    }

    if (atual == nullptr) {
        L1->fim = anterior;
    }

    return true;
}

#endif // _HPP_LISTA_DESCRITOR



