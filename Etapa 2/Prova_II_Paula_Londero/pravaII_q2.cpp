#include <iostream>
using namespace std;
#include "lista_dupla.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    Lista l1 = Lista();
    Lista l2 = Lista();
    Lista l3 = Lista();

    cout << "\n\n###TESTE 1\n";
    insereInicioL(&l1, 5);
    insereInicioL(&l1, 7);
	insereInicioL(&l1, 3);
	insereInicioL(&l1, 1);
	insereInicioL(&l1, 9);
	insereInicioL(&l2, 5);
	insereInicioL(&l2, 4);
	insereInicioL(&l2, 11);
    mostraL(&l1, "l1 normal   :");
    mostrarInversoL(&l1, "l1 invertida:");
    mostraL(&l2, "l2 normal   :");
    mostrarInversoL(&l2, "l2 invertida:");
    mostraL(&l3, "l3 normal   :");
    mostrarInversoL(&l3, "l3 invertida:");
    cout << "Tamanho da lista 3: " << l3.tamanho << endl;



    cout << "\n\n###TESTE 2\n";
    concatenarListas(&l1, &l2, &l3);
    mostraL(&l1, "l1 normal   :");
    mostrarInversoL(&l1, "l1 invertida:");
    mostraL(&l2, "l2 normal   :");
    mostrarInversoL(&l2, "l2 invertida:");
    mostraL(&l3, "l3 normal   :");
    mostrarInversoL(&l3, "l3 invertida:");
    cout << "Tamanho da lista 3: " << l3.tamanho << endl;


    cout << "\n\n###TESTE 3\n";
    destroiL(&l1);
    destroiL(&l2);
    destroiL(&l3);
    insereInicioL(&l1, 5);
    insereInicioL(&l1, 7);
	insereInicioL(&l2, 5);
	insereInicioL(&l2, 4);
	insereInicioL(&l2, 11);
    insereInicioL(&l2, 2);
	insereInicioL(&l2, 13);
	insereInicioL(&l2, 15);
	insereInicioL(&l2, 6);

    mostraL(&l1, "l1 normal   :");
    mostrarInversoL(&l1, "l1 invertida:");
    mostraL(&l2, "l2 normal   :");
    mostrarInversoL(&l2, "l2 invertida:");
    mostraL(&l3, "l3 normal   :");
    mostrarInversoL(&l3, "l3 invertida:");
    cout << "Tamanho da lista 3: " << l3.tamanho << endl;


    cout << "\n\n###TESTE 4\n";
    concatenarListas(&l1, &l2, &l3);
    mostraL(&l1, "l1 normal   :");
    mostrarInversoL(&l1, "l1 invertida:");
    mostraL(&l2, "l2 normal   :");
    mostrarInversoL(&l2, "l2 invertida:");
    mostraL(&l3, "l3 normal   :");
    mostrarInversoL(&l3, "l3 invertida:");
    cout << "Tamanho da lista 3: " << l3.tamanho << endl;


    destroiL(&l1);
    destroiL(&l2);
    destroiL(&l3);
    return EXIT_SUCCESS;
}

