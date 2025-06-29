#ifndef _HPP_LISTA_DESCRITOR
#define _HPP_LISTA_DESCRITOR

using namespace std;


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
        cout << "[" << n->dado.dia << "/" << n->dado.mes << "/" << n->dado.ano << " - " << n->dado.descricao << "]";
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


//não pode usar auxiliar
void ordenarL(Lista *lista)
{
    bool ordenado= true;

    do{
        ordenado= true;
        No *n = lista->inicio;
        while(n && n->prox)
        {
            if( n->prox->dado.ano < n->dado.ano ||
               (n->prox->dado.ano == n->dado.ano && n->prox->dado.mes < n->dado.mes) ||
               (n->prox->dado.ano == n->dado.ano && n->prox->dado.mes == n->dado.mes && n->prox->dado.dia < n->dado.dia))
            {
                ordenado = false;
                Compromisso aux = n->dado;
                n->dado = n->prox->dado;
                n->prox->dado = aux;
            }
            n = n->prox;
        }
    }while(!ordenado);
}

//não pode usar auxiliar; atualizar os descritores da lista!
void insereAposPrimeiraOcorrencia(Lista *lista, int dia, int mes, int ano, Compromisso comp)
{
    No *n = lista->inicio;

    //achar o no
    while(n && (n->dado.ano != ano || n->dado.mes != mes || n->dado.dia != dia) )
        n = n->prox;


    if(!n) /// se atual é NULL >> não encontrou
        return;

    No *novo = new No();
    if (novo == nullptr)
        return;

    novo->dado = comp;
    novo->prox = n->prox;
    n->prox = novo;
    if(!novo->prox)
        lista->fim=novo;

    lista->tamanho++;

}

//não pode usar auxiliar; atualizar os descritores da lista!
void insereAposCadaOcorrencia(Lista *lista, int dia, int mes, int ano, Compromisso comp)
{
    No *n = lista->inicio;

    //achar o no
    while(n)
    {
        if(n->dado.ano == ano && n->dado.mes == mes && n->dado.dia == dia)
        {
            No *novo = new No();
            if (novo == nullptr)
                return;

            novo->dado = comp;
            novo->prox = n->prox;
            n->prox = novo;
            if(!novo->prox)
                lista->fim=novo;

            lista->tamanho++;
            n = novo;
        }
        n = n->prox;
    }

}



#endif // _HPP_LISTA_DESCRITOR



