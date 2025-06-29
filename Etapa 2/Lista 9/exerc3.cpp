#include <iostream>
using namespace std;

#include "exerc1.hpp"

void retiraInsere(No** lista, int x)
{
    for(int i =0; i<x; i++)
    {
        int d = removeInicioL(lista);
        insereFinalL(lista, d);
    }
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No* lista; //evite usar "list", pois é uma palavra reservada
    int x = 0;

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

    retiraInsere(&lista, 4);

    cout<<"Lista após a chamada da Função: "<<endl;
    mostraL(&lista);

    destroiL(&lista);
    return EXIT_SUCCESS;


}//final do main
