#include <iostream>
using namespace std;

#include "exerc1.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No* lista; //evite usar "list", pois é uma palavra reservada
    No* lista1;
    No* lista2;
    No* listaSaida;

    inicializaL(&lista);
    inicializaL(&lista1);
    inicializaL(&lista2);
    inicializaL(&listaSaida);

    insereInicioL(&lista, 10);
    insereInicioL(&lista, 20);
    insereInicioL(&lista, 30);
    insereInicioL(&lista, 40);
    insereFinalL(&lista, 100);
    insereFinalL(&lista, 200);
    mostraL(&lista);
    cout<<"Leitura do último elemento: "<<leFinalL(&lista)<<endl;
    cout<<"Total: " <<totalL(&lista)<<endl;
    removeFinalL(&lista);
    mostraL(&lista);
    cout<<"Leitura do último elemento: "<<leFinalL(&lista)<<endl;
    cout<<"Total: " <<totalL(&lista)<<endl;

    insereInicioL(&lista1, 1);
    insereInicioL(&lista1, 2);
    insereInicioL(&lista1, 3);
    insereInicioL(&lista1, 4);
    insereInicioL(&lista1, 5);
    insereInicioL(&lista2, 1);
    insereInicioL(&lista2, 2);
    insereInicioL(&lista2, 3);

    mostraL(&lista1);
    cout<<"Leitura de posição: ";
    cout<< lePosicao(&lista1, 1)<<endl;

    if(igualL(&lista1, &lista2))
        cout<<"\nListas iguais"<<endl;
        else
            cout<<"\nListas diferentes"<<endl;



    uniao(&lista1,&lista2,&listaSaida);
    cout<<"União: "<<endl;
    mostraL(&listaSaida);

    destroiL(&lista);
    return EXIT_SUCCESS;


}//final do main

