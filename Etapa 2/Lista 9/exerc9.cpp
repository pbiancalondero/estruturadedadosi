#include <iostream>
using namespace std;

#include "exerc1.hpp"

void recursiva(No** lista)
{
    if(!vaziaL(lista))
    {
        int i = removeInicioL(lista);

        recursiva(lista);

        insereFinalL(lista, i);
    }
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No* lista; //evite usar "list", pois é uma palavra reservada

    inicializaL(&lista);

    insereFinalL(&lista, 3);
    insereFinalL(&lista, 5);
    insereFinalL(&lista, 8);
    insereFinalL(&lista, 9);
    insereFinalL(&lista, 12);
    insereFinalL(&lista, 11);
    insereFinalL(&lista, 7);
    insereFinalL(&lista, 10);

    mostraL(&lista);

    recursiva(&lista);

    cout<<"Lista após a chamada da Função: "<<endl;
    mostraL(&lista);

    destroiL(&lista);
    return EXIT_SUCCESS;


}//final do main
