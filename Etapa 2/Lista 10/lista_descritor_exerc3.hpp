#ifndef _HPP_LISTA_DESCRITOR
#define _HPP_LISTA_DESCRITOR

struct No
{
    Veiculo dado;
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
        cout <<"["<< n->dado.placa <<", "<< n->dado.ano<<", "<< n->dado.marca<<", "<< n->dado.modelo <<"]";
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
bool insereInicioL(Lista *lista, Veiculo valor)
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
bool insereFimL(Lista *lista, Veiculo valor)
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


bool removeL(Lista *lista, string placa)
{
    No *anterior = nullptr;
    No *atual = lista->inicio;
    ///fica no laço enquanto tiver elementos na lista
    /// e não encontrar o valor procurado
    while(atual && atual->dado.placa != placa)
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

No* buscaL(Lista *lista, string placa)
{
    No *n = lista->inicio;
    while (n)
    {
        if (n->dado.placa == placa)
            return n;

        n = n->prox;
    }

    return nullptr;
}


Veiculo leInicioL(Lista *lista)
{
    Veiculo dado;

    if(vaziaL(lista) == false)
        dado = lista->inicio->dado; //atribui o dado do início da lista para a variável dado

    return dado;
}

Veiculo removeInicioL(Lista *lista)
{
    No* aux;
    Veiculo dado;

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

Veiculo leFinalL(Lista *lista)
{
    Veiculo dado;
    No* n = lista->inicio;
    while(n->prox!=NULL)
    {
        n = n->prox;
    }
    dado = n->dado;
    return dado;
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

            if (atual->dado.placa > proximo->dado.placa)
            {
                Veiculo aux = atual->dado;
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


Veiculo removeFinalL(Lista *lista)
{
    Veiculo dado;

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

void mostraOrdenadaModelo(Lista *lista)
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
            if (atual->dado.modelo > atual->prox->dado.modelo)
            {
                Veiculo valor = atual->dado;
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

void mostraOrdenadaAno(Lista *lista)
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
            if (atual->dado.ano > atual->prox->dado.ano)
            {
                Veiculo valor = atual->dado;
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
    Veiculo valor;
    Veiculo dados;

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
            if (n1->dado.placa == n2->dado.placa)
            {
                // Verificar se o elemento já não está na lista de interseção
                No *busca = buscaL(&aux, n1->dado.placa);
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


bool removeMarcaAno(Lista *lista, string fab)
{
    No *anterior = nullptr;
    No *atual = lista->inicio;
    ///fica no laço enquanto tiver elementos na lista
    /// e não encontrar o valor procurado
    bool encontrou = false;

    while (atual != nullptr) {
        if (atual->dado.marca == fab && atual->dado.ano > 2000) {
            // Veículo atende aos critérios e será removido
            No *remover = atual;
            if (anterior == nullptr) {
                // Remover do início
                lista->inicio = atual->prox;
                if (lista->inicio == nullptr) {
                    lista->fim = nullptr; // Lista ficou vazia
                }
            } else {
                // Remover do meio ou fim
                anterior->prox = atual->prox;
                if (atual->prox == nullptr) {
                    lista->fim = anterior; // Atualizou o fim
                }
            }

            atual = atual->prox; // Avança para o próximo
            delete remover;      // Libera memória
            lista->tamanho--;
            encontrou = true;
        } else {
            // Avança para o próximo
            anterior = atual;
            atual = atual->prox;
        }
    }

    if (!encontrou) {
        cout << "Nenhum veículo encontrado para o fabricante \"" << fab << "\" com ano superior a 2000.\n";
        return false;
    }

    cout << "Veículos do fabricante \"" << fab << "\" com ano superior a 2000 foram removidos.\n";
    return true;
}

void filtraVeiculo(Lista *lista, string filtro)
{
    No *atual = lista->inicio;
    bool encontrou = false;

    cout << "Veículos do fabricante \"" << filtro << "\":\n";

    while (atual != nullptr)
    {
        if (atual->dado.marca == filtro)
        {
            cout << "- Placa: " << atual->dado.placa << "\n";
            encontrou = true;
        }
        atual = atual->prox;
    }

    if (!encontrou)
    {
        cout << "Nenhum veículo encontrado para o fabricante \"" << filtro << "\".\n";
    }
    delete(atual);
}
#endif // _HPP_LISTA_DESCRITOR
