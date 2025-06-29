#include <iostream>
using namespace std;
#include "lista_dupla.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Lista lista = Lista();

    mostraL(&lista);
    insereInicioL(&lista, 10);
    insereInicioL(&lista, 20);
    insereInicioL(&lista, 30);
    insereInicioL(&lista, 31);
    insereInicioL(&lista, 32);
    insereInicioL(&lista, 33);
    insereInicioL(&lista, 34);
    insereInicioL(&lista, 40);
    mostraL(&lista);


    cout<<"\n Inserindo no final da lista: "<<endl;
    insereFinalL(&lista, 78);
    mostraL(&lista);

    cout<<"\nRemovendo o primeiro da lista: "<<endl;
    removerPrimeiroL(&lista);
    mostraL(&lista);

    cout<<"\nRemovendo o último da lista: "<<endl;
    removerUltimoL(&lista);
    mostraL(&lista);

    cout<<endl;
    removerPrimeiroL(&lista);
    mostraL(&lista);


    cout<<endl;
    removerPrimeiroL(&lista);
    mostraL(&lista);


    cout<<endl;
    removerPrimeiroL(&lista);
    mostraL(&lista);

    cout<<endl;
    removerPrimeiroL(&lista);
    mostraL(&lista);

    cout<<endl;
    removerPrimeiroL(&lista);
    mostraL(&lista);

    cout<<endl;
    removerUltimoL(&lista);
    mostraL(&lista);

    cout<<endl;
    removerUltimoL(&lista);
    mostraL(&lista);

    insereFinalL(&lista, 78);
    mostraL(&lista);


    destroiL(&lista);
    return EXIT_SUCCESS;
}

