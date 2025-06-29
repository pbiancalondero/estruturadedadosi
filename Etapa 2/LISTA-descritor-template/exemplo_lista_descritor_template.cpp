#include <iostream>
using namespace std;

#include "lista_descritor_template.hpp"
#include "cliente.hpp"



void mostraL(Lista<Cliente> *lista)
{

    No<Cliente> *n = lista->inicio;

    cout << "L["<< lista->tamanho <<"]:{";
    while(n != NULL ) /// enquanto n não for NULL fica no laço
    {
        cout << "[" << n->dado.nome << ", " << n->dado.idade << "]";
        n = n->prox;

        if(n != NULL)
            cout << ", ";
    }
    cout << "}\n";

}


//busca de pelo nome do cliente
No<Cliente>* buscaL(Lista<Cliente> *lista, string nome)
{

    No<Cliente> *n = lista->inicio;
    while (n != NULL)
    {
        if (n->dado.nome == nome)
            return n;

        n = n->prox;
    }

    return NULL;

}

//busca de pela idade
No<Cliente>* buscaL(Lista<Cliente> *lista, int idade)
{

    No<Cliente> *n = lista->inicio;
    while (n != NULL)
    {
        if (n->dado.idade == idade)
            return n;

        n = n->prox;
    }

    return NULL;

}

bool removeL(Lista<Cliente> *lista, string nome)
{
    No<Cliente> *anterior = nullptr;
    No<Cliente> *atual = lista->inicio;
    ///fica no laço enquanto tiver elementos na lista
    /// e não encontrar o valor procurado
    while(atual && atual->dado.nome != nome )
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



int main(void)
{
    setlocale(LC_ALL, "Portuguese");


    cout << "\n#######INT#######\n";
    Lista<int> lista1 = Lista<int>();
    insereFimL(&lista1, 10);
    insereFimL(&lista1, 20);
    insereFimL(&lista1, 30);
    insereFimL(&lista1, 40);
    mostraL(&lista1);
    destroiL(&lista1);


    cout << "\n#######FLOAT#######\n";
    Lista<float> lista2 = Lista<float>();

    if(vaziaL(&lista2))
        cout << "Lista<float> vazia!\n";
    else
        cout << "Lista<float> não está vazia.\n";

    insereFimL(&lista2, 10.1f);
    insereFimL(&lista2, 20.2f);
    insereFimL(&lista2, 30.3f);
    insereFimL(&lista2, 40.4f);
    mostraL(&lista2);
    cout << "Busca<float> valor 20.2: ";
    if( buscaL(&lista2, 20.2f)!=NULL)
        cout << "a lista contém o valor 20.2" << endl;
    else
        cout << "a lista não contém o valor 20.2" << endl;

    cout << "Removendo o valor 30.3 da lista...\n";
    if(removeL(&lista2, 30.3f))
        cout << "O valor 30.3 foi removido da lista\n";
    else
        cout << "O valor 30.3 não existe na lista\n";
    mostraL(&lista2);
    destroiL(&lista2);


    cout << "\n#######DOUBLE#######\n";
    Lista<double> lista3 = Lista<double>();

    insereFimL(&lista3, 10.1);
    insereFimL(&lista3, 20.2);
    insereFimL(&lista3, 30.3);
    insereFimL(&lista3, 40.4);
    mostraL(&lista3);

    cout << "Removendo o valor 40.4 da lista...\n";
    if(removeL(&lista3, 40.4))
        cout << "O valor 40.4 foi removido da lista\n";
    else
        cout << "O valor 40.4 não existe na lista\n";
    mostraL(&lista3);
    destroiL(&lista3);



    cout << "\n#######CLIENTE#######\n";
    Lista<Cliente> lista4 = Lista<Cliente>();
    insereFimL(&lista4, Cliente("Fulano", 10));
    insereFimL(&lista4, Cliente("Ciclano", 20));
    mostraL(&lista4);


    cout << "Busca<Cliente> com nome Ciclano: ";
    if( buscaL(&lista4, "Ciclano")!= NULL)
        cout << "a lista contém o cliente Ciclano" << endl;
    else
        cout << "a lista não contém o cliente Ciclano" << endl;

    cout << "Busca<Cliente> com idade 10: ";
    if( buscaL(&lista4, 10)!=NULL)
        cout << "a lista contém um cliente com idade=10" << endl;
    else
        cout << "a lista não contém um cliente com idade=10" << endl;

    cout << "Removendo o cliente com nome Ciclano da lista...\n";
    if(removeL(&lista4, "Ciclano"))
        cout << "O cliente Ciclano foi removido da lista\n";
    else
        cout << "O cliente Ciclano não existe na lista\n";

    mostraL(&lista4);
    destroiL(&lista4);


    return EXIT_SUCCESS;
}
