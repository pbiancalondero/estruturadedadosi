#include <iostream>
using namespace std;
#include "cadastro.hpp"
#include "lista_dupla_exerc3.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Lista lista = Lista();


    insereInicioL(&lista, Cadastro (20, 3, 4.5));
    //insereInicioL(&lista, Cadastro (20, 3, 4.5));
    //insereInicioL(&lista, Cadastro (20, 7, 50));
    insereInicioL(&lista, Cadastro (20, 6, 55));
    insereInicioL(&lista, Cadastro (35, 4, 60));
    mostraL(&lista);

    removeL(&lista, Cadastro (1, 3, 4.5));
    cout<<endl<<endl;
    cout<<"Removendo um elemento:"<<endl;
    mostraL(&lista);


    cout<<endl<<endl;
    cout<<"Lista ordenada: "<<endl;
    ordenaChegada(&lista);
    mostraL(&lista);

    cout<<endl<<endl;
    cout<<"3 últimos: "<<endl;
    tresUltimos(&lista);

    cout<<endl<<endl;
    cout<<"Separa peso: "<<endl;
    separaPeso(&lista);


    destroiL(&lista);
    return EXIT_SUCCESS;
}

