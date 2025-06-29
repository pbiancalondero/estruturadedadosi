#include <iostream>
using namespace std;

#include "lista-template.hpp"

void invertido(No<char>** lista)
{
    No<char>* aux;

    while(!vaziaL(lista))
        insereInicioL(&aux,removeFinalL(lista));

    while(!vaziaL(&aux))
        insereFinalL(lista, removeFinalL(&aux));

}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No<char>* L1; //evite usar "list", pois é uma palavra reservada

    inicializaL(&L1);

    insereInicioL(&L1, 'U');
    insereInicioL(&L1, 'O');
    insereInicioL(&L1, 'I');
    insereInicioL(&L1, 'E');
    insereInicioL(&L1, 'A');

    mostraL(&L1, "L1");

    invertido(&L1);

    cout<<"Lista após a chamada da Função: "<<endl;
    mostraL(&L1, "L1");

    destroiL(&L1);
    return EXIT_SUCCESS;


}//final do main
