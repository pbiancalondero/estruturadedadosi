#include <iostream>
using namespace std;
#include "lista_dupla_template.hpp"
#include "cliente.hpp"


void mostraL(Lista<Cliente> *lista)
{

    No<Cliente> *n = lista->inicio;

    cout << "L[" << lista->tamanho << "]:{";
    while(n != NULL ) /// enquanto n não for NULL fica no laço
    {
        cout << "[" << n->dado.nome << ", " << n->dado.idade << "]";
        n = n->prox;

        if(n != NULL)
            cout << ", ";
    }
    cout << "}\n";

}

void mostrarInversoL(Lista<Cliente> *lista)
{
    No<Cliente> *n = lista->fim;
    cout << "L[" << lista->tamanho << "]:{";
    while(n)
    {
        cout << "[" << n->dado.nome << ", " << n->dado.idade << "]";
        n = n->ant;

        if(n)
            cout << ", ";
    }
    cout << "}" << endl;
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
    No<Cliente>* no = buscaL(lista, nome);

    if(!no)
        return false;

    removerNoL(lista, no);

    return true;
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");


     cout << "\n#######INT#######\n";
    Lista<int> lista1 = Lista<int>();
    insereInicioL(&lista1, 10);
    insereInicioL(&lista1, 20);
    insereInicioL(&lista1, 30);
    insereInicioL(&lista1, 40);
    mostraL(&lista1);
    mostrarInversoL(&lista1);
    destroiL(&lista1);



    cout << "\n#######FLOAT#######\n";
    Lista<float> lista2 = Lista<float>();

    if(vaziaL(&lista2))
        cout << "Lista<float> vazia!\n";
    else
        cout << "Lista<float> não está vazia.\n";

    insereInicioL(&lista2, 10.1f);
    insereInicioL(&lista2, 20.2f);
    insereInicioL(&lista2, 30.3f);
    insereInicioL(&lista2, 40.4f);
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

    insereInicioL(&lista3, 10.1);
    insereInicioL(&lista3, 20.2);
    insereInicioL(&lista3, 30.3);
    insereInicioL(&lista3, 40.4);
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
    insereInicioL(&lista4, Cliente("Fulano", 10));
    insereInicioL(&lista4, Cliente("Ciclano", 20));
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

