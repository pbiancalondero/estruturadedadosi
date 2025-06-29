#include <iostream>
using namespace std;

#include "lista.hpp"


int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    int valor; //valor deve ser do mesmo tipo de DadoNoLista (lista.hpp)
    No* aux; //usado na busca
    No* lista; //evite usar "list", pois � uma palavra reservada

    inicializaL(&lista);

    cout << "\n\n###TESTE 1\n";
    insereInicioL(&lista, 10);
    insereInicioL(&lista, 20);
    insereInicioL(&lista, 30);
    insereInicioL(&lista, 40);
    mostraL(&lista);


    cout << "\n\n###TESTE 2\n";
    if(vaziaL(&lista) == true)
        cout << "A lista est� vazia\n";
    else
        cout << "A lista N�O est� vazia\n";


    cout << "\n\n###TESTE 3\n";
    cout << "remover o n� com o valor 40, o primeiro elemento (no in�cio da lista)\n";
    removeL(&lista, 40);
    mostraL(&lista);


    cout << "\n\n###TESTE 4\n";
    cout << "podemos verificar se a remo��o foi realizado com sucesso (se o elemento foi encontrado)\n";
    if(removeL(&lista, 20) == true)
        cout << "O valor 20 foi removido da lista!\n";
    else
        cout << "O valor 20 n�o foi encontrado!\n";
    mostraL(&lista);

    cout << "\n\n###TESTE 5\n";
    cout << "Ler o valor do primeiro n� da lista SEM remover o n�\n";
    if(vaziaL(&lista) == false)
    {
        valor = leInicioL(&lista);

        cout << "O valor do primeiro n� �: " << valor << endl;

    }
    mostraL(&lista);


    cout << "\n\n###TESTE 6\n";
    cout << "Ler o valor do primeiro n� da lista e REMOVER o n�\n";
    if(vaziaL(&lista) == false)
    {
        valor = removeInicioL(&lista);

        cout << "O valor do primeiro n� �: " << valor << endl;

    }
    mostraL(&lista);


    cout << "\n\n###TESTE 7\n";
    aux = buscaL(&lista, 30);
    if(aux != NULL)
        cout << "Um n� com o valor 30 foi encontrado: " << aux->dado << "\n";
    else
        cout << "O valor 30 n�o foi entrado na lista\n";


    cout << "\n\n###TESTE 8\n";
    aux = buscaL(&lista, 10);
    if(aux != NULL)
        cout << "Um n� com o valor 10 foi encontrado: " << aux->dado << "\n";
    else
        cout << "O valor 10 n�o foi entrado na lista\n";


    destroiL(&lista);
    return EXIT_SUCCESS;


}//final do main

