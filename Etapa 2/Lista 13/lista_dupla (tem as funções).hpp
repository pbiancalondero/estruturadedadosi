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


void mostraDif(Lista *lista1, Lista *lista2)
{
    Lista diferenca;

    // Percorre a primeira lista
    No *n = lista1->inicio;

    while (n)
    {
        // Verifica se o elemento de lista1 não está em lista2
        if (!buscaL(lista2, n->dado))
            insereFimL(&diferenca, n->dado); // Insere no final da lista diferenca
        n = n->prox;
    }

    // Ordenação da lista diferenca (Bubble Sort)
    bool trocou;
    do
    {
        trocou = false;
        No *atual = diferenca.inicio;

        while (atual != nullptr && atual->prox != nullptr)
        {
            if (atual->dado > atual->prox->dado)
            {
                // Troca os valores
                int valor = atual->dado;
                atual->dado = atual->prox->dado;
                atual->prox->dado = valor;
                trocou = true;
            }
            atual = atual->prox;
        }
    } while (trocou);

    // Exibe a lista diferenca
    No *aux = diferenca.inicio;

    cout << "Diferença (lista1 - lista2): {";
    while (aux != nullptr)
    {
        cout << aux->dado;
        aux = aux->prox;
        if (aux != nullptr)
            cout << ", ";
    }
    cout << "}" << endl;

    // Libera a memória alocada para a lista diferenca
    destroiL(&diferenca);
}

void mediana(Lista *lista)
{
    if (vaziaL(lista))
    {
        cout << "Lista vazia." << endl;
        return;
    }

    Lista aux;
    No *n = lista->inicio;

    // Copiar os elementos para uma lista auxiliar
    while (n != nullptr)
    {
        insereFimL(&aux, n->dado);
        n = n->prox;
    }

    // Ordenar a lista auxiliar em ordem crescente
    bool trocou;
    do
    {
        trocou = false;
        No *atual = aux.inicio;

        while (atual != nullptr && atual->prox != nullptr)
        {
            if (atual->dado > atual->prox->dado)
            {
                int valor = atual->dado;
                atual->dado = atual->prox->dado;
                atual->prox->dado = valor;
                trocou = true;
            }
            atual = atual->prox;
        }
    } while (trocou);

    double mediana;
    No *atual = aux.inicio;

    // Determinar a mediana
    if (aux.tamanho == 1)
    {
        mediana = atual->dado;
    }
    else if (aux.tamanho % 2 == 1)
    {
        int pos = aux.tamanho / 2;
        for (int i = 0; i < pos; i++)
            atual = atual->prox;
        mediana = atual->dado;
    }
    else
    {
        int pos1 = (aux.tamanho / 2) - 1;
        int pos2 = aux.tamanho / 2;

        for (int i = 0; i < pos1; i++)
            atual = atual->prox;

        int val1 = atual->dado;
        atual = atual->prox;
        int val2 = atual->dado;

        mediana = (val1 + val2) / 2.0;
    }

    // Exibir a mediana
    cout << fixed << setprecision(2);
    cout << "Mediana: " << mediana << endl;

    // Liberar a lista auxiliar
    destroiL(&aux);
}

void moda(Lista *lista)
{
    if (vaziaL(lista))
    {
        cout << "Lista vazia." << endl;
        return;
    }

    Lista valoresUnicos;
    Lista frequencias;
    No *n = lista->inicio;

    // Contar frequências
    while (n != nullptr)
    {
        No *existe = buscaL(&valoresUnicos, n->dado);
        if (existe == nullptr)
        {
            insereFimL(&valoresUnicos, n->dado);
            insereFimL(&frequencias, 1);
        }
        else
        {
            No *freqAtual = frequencias.inicio;
            No *valAtual = valoresUnicos.inicio;

            while (valAtual != nullptr && valAtual->dado != n->dado)
            {
                freqAtual = freqAtual->prox;
                valAtual = valAtual->prox;
            }

            if (freqAtual != nullptr)
                freqAtual->dado++;
        }

        n = n->prox;
    }

    // Determinar a maior frequência
    int maiorFreq = 0;
    No *freqAtual = frequencias.inicio;

    while (freqAtual != nullptr)
    {
        if (freqAtual->dado > maiorFreq)
            maiorFreq = freqAtual->dado;
        freqAtual = freqAtual->prox;
    }

    // Verificar se não há moda
    if (maiorFreq == 1)
    {
        cout << "VAZIA" << endl;
        destroiL(&valoresUnicos);
        destroiL(&frequencias);
        return;
    }

    // Exibir os valores com maior frequência
    bool primeiro = true;
    No *valAtual = valoresUnicos.inicio;
    freqAtual = frequencias.inicio;

    while (valAtual != nullptr)
    {
        if (freqAtual->dado == maiorFreq)
        {
            if (!primeiro)
                cout << ", ";
            cout << valAtual->dado;
            primeiro = false;
        }

        valAtual = valAtual->prox;
        freqAtual = freqAtual->prox;
    }
    cout << endl;

    // Liberar listas auxiliares
    destroiL(&valoresUnicos);
    destroiL(&frequencias);
}

bool insereFimL(Lista *lista, int valor)
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

void inserirCaractereApos(Lista *lista, int valor1, int valor2)
{
    No *n = lista->inicio;

    while (n != nullptr)
    {
        if (n->dado == valor1)
        {
            No *novo = new No();
            novo->dado = valor2;
            novo->prox = n->prox;
            novo->ant = n;

            if (n->prox != nullptr)
                n->prox->ant = novo;
            else
                lista->fim = novo;

            n->prox = novo;
            lista->tamanho++;

            n = novo->prox; // Avança para evitar loop infinito no caso de múltiplas inserções
        }
        else
        {
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

void inserirAntesPrimeiraOcorrencia(Lista *lista, int valor1, int valor2) {
    if (vaziaL(lista)) return;

    No *n = lista->inicio;
    No *anterior = nullptr;

    while (n != nullptr) {
        if (n->dado == valor1) {
            No *novo = new No();
            novo->dado = valor2;
            novo->prox = n;
            novo->ant = anterior;

            if (anterior == nullptr) {
                lista->inicio = novo;
            } else {
                anterior->prox = novo;
            }

            n->ant = novo;
            lista->tamanho++;
            return;
        }

        anterior = n;
        n = n->prox;
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


#endif // _HPP_LISTA_DUPLA



