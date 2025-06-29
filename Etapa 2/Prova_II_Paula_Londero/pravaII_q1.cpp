#include <iostream>
#include <string>
using namespace std;

#include "lista.hpp"


int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No* lista;
    inicializaL(&lista);

    cout << "\n\n###TESTE 1\n";
    insereInicioL(&lista, 5);
    insereInicioL(&lista, 7);
	insereInicioL(&lista, 3);
	insereInicioL(&lista, 1);
	insereInicioL(&lista, 9);
	insereInicioL(&lista, 5);
	insereInicioL(&lista, 4);
	insereInicioL(&lista, 11);
	insereInicioL(&lista, 2);
	insereInicioL(&lista, 13);
	insereInicioL(&lista, 15);
	insereInicioL(&lista, 6);
	mostraL(&lista);
	inverterPares(&lista);
	mostraL(&lista);


	cout << "\n\n###TESTE 2\n";
    destroiL(&lista);
    insereInicioL(&lista, 10);
    insereInicioL(&lista, 7);
	insereInicioL(&lista, 3);
	insereInicioL(&lista, 8);
	insereInicioL(&lista, 9);
	insereInicioL(&lista, 12);
	insereInicioL(&lista, 4);
	insereInicioL(&lista, 11);
	insereInicioL(&lista, 13);
	insereInicioL(&lista, 2);
	insereInicioL(&lista, 15);
	insereInicioL(&lista, 6);
	mostraL(&lista);
	inverterPares(&lista);
	mostraL(&lista);




    destroiL(&lista);
    return EXIT_SUCCESS;


}//final do main

