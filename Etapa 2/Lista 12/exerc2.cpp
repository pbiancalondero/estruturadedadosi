#include <iostream>
using namespace std;
#include "lista_dupla_exerc2.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    int valor, pos;
    No* aux = nullptr;
    Lista lista = Lista();

    insereInicioL(&lista, 12);
    insereInicioL(&lista, 40);
    insereInicioL(&lista, 1);
    insereInicioL(&lista, 40);
    insereInicioL(&lista, 31);
    insereInicioL(&lista, 40);
    insereInicioL(&lista, 2);
    insereInicioL(&lista, 40);
    insereInicioL(&lista, 25);
    insereInicioL(&lista, 27);
    insereInicioL(&lista, 40);
    mostraL(&lista);

    cout<<endl;
    removeTodosIguais(&lista, 40);
    mostraL(&lista);

    cout<<endl;
    leMaiores(&lista, 5);

    destroiL(&lista);
    return EXIT_SUCCESS;
}

