#include <iostream>
using namespace std;

#include "lista-template.hpp"
#include "cliente.hpp"


void mostraL(No<Cliente> **l, string nome="")
{

    No<Cliente> *n = *l;

    cout << "L<" << nome << ">:{";
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
No<Cliente>* buscaL(No<Cliente> **l, string nome)
{

    No<Cliente> *n = *l;
    while (n != NULL)
    {
        if (n->dado.nome == nome)
            return n;

        n = n->prox;
    }

    return NULL;

}

//busca de pela idade
No<Cliente>* buscaL(No<Cliente> **l, int idade)
{

    No<Cliente> *n = *l;
    while (n != NULL)
    {
        if (n->dado.idade == idade)
            return n;

        n = n->prox;
    }

    return NULL;

}

bool removeL(No<Cliente> **lista, string nome)
{
    No<Cliente> *anterior = NULL;
    No<Cliente> *atual = *lista;
    ///fica no laço enquanto tiver elementos na lista
    /// e não encontrar o valor procurado
    while(atual!=NULL && atual->dado.nome != nome)
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



int main(void)
{
    setlocale(LC_ALL, "Portuguese");


    cout << "\n#######INT#######\n";
    No<int>* l1;
    inicializaL(&l1);
    insereInicioL(&l1, 10);
    insereInicioL(&l1, 20);
    insereInicioL(&l1, 30);
    insereInicioL(&l1, 40);
    mostraL(&l1, "int");
    destroiL(&l1);


    cout << "\n#######FLOAT#######\n";
    No<float>* l2;
    inicializaL(&l2);

    if(vaziaL(&l2))
        cout << "Lista<float> vazia!\n";
    else
        cout << "Lista<float> não está vazia.\n";

    insereInicioL(&l2, 10.5f);
    insereInicioL(&l2, 50.6f);
    insereInicioL(&l2, 20.2f);
    insereInicioL(&l2, 10.3f);
    mostraL(&l2, "float");
    cout << "leInicioL<float>: " << leInicioL(&l2) << endl;

     cout << "Busca<float> valor 10.5: ";
    if( buscaL(&l2, 10.5f)!=NULL)
        cout << "a lista contém o valor 10.5" << endl;
    else
        cout << "a lista não contém o valor 10.5" << endl;

    cout << "Removendo o valor 50.6 da lista...\n";
    if(removeL(&l2, 50.6f))
        cout << "O valor 50.6 foi removido da lista\n";
    else
        cout << "O valor 50.6 não existe na lista\n";

    mostraL(&l2, "float");

    float x = removeInicioL(&l2);
    cout << "Valor x: " << x << endl;
    mostraL(&l2, "float");
    destroiL(&l2);


    cout << "\n#######DOUBLE#######\n";
    No<double>* l3;
    inicializaL(&l3);
    insereInicioL(&l3, 10.5);
    insereInicioL(&l3, 50.6);
    insereInicioL(&l3, 20.2);
    insereInicioL(&l3, 10.3);
    mostraL(&l3, "double");
    double y = removeInicioL(&l3);
    cout << "Valor y: " << y << endl;
    destroiL(&l3);


    cout << "\n#######CLIENTE#######\n";
    No<Cliente>* l4;
    inicializaL(&l4);
    insereInicioL(&l4, Cliente("Fulano", 10));
    insereInicioL(&l4, Cliente("Ciclano", 20));
    mostraL(&l4, "Cliente");


    cout << "Busca<Cliente> com nome Ciclano: ";
    if( buscaL(&l4, "Ciclano")!= NULL)
        cout << "a lista contém o cliente Ciclano" << endl;
    else
        cout << "a lista não contém o cliente Ciclano" << endl;

    cout << "Busca<Cliente> com idade 10: ";
    if( buscaL(&l4, 10)!=NULL)
        cout << "a lista contém um cliente com idade=10" << endl;
    else
        cout << "a lista não contém um cliente com idade=10" << endl;

    cout << "Removendo o cliente com nome Ciclano da lista...\n";
    if(removeL(&l4, "Ciclano"))
        cout << "O cliente Ciclano foi removido da lista\n";
    else
        cout << "O cliente Ciclano não existe na lista\n";

    mostraL(&l4, "Cliente");

    Cliente c = removeInicioL(&l4);
    cout << "Cliente c: " << c.nome << ", " << c.idade << endl;
    destroiL(&l4);

    return EXIT_SUCCESS;


}//final do main

