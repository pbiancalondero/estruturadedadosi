#include <iostream>
#include <string>
using namespace std;

#include "cadastro.hpp"
#include "lista_descritor.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");


    int valor, pos;
    Cadastro aux, aux2, aux3, aux4;
    Lista lista = Lista();//chama o cosntrutor para inicilizar a lista
    Lista lista1 = Lista();
    Lista lista2 = Lista();

    insereFimL(&lista, Cadastro (1, "paula", 18, 1000));
    insereFimL(&lista, Cadastro (2, "maria", 20, 2500));
    insereFimL(&lista, Cadastro (3, "joao", 70, 2500));
    insereFimL(&lista, Cadastro (4, "tiago", 89, 1200));
    insereFimL(&lista, Cadastro (5, "sandra", 30, 1500));
    insereFimL(&lista, Cadastro (6, "bianca", 45, 2300));
    insereFimL(&lista, Cadastro (7, "luiz", 12, 3000));

    mostraL(&lista);
    cout<< endl;
    cout<<"Lista ordenada: "<<endl;
    ordenaL(&lista);


    mostraL(&lista);

    cout<<endl;
        cout<< "\nMedia: "<<media(&lista)<<endl;

    aux = leInicioL(&lista);
    cout<<"LeInicio: "<<aux.nome<<endl;


    //aux2 = removeInicioL(&lista);
    //cout<<"RemoveInicio: "<<aux2.nome<<endl;

    aux3 = leFinalL(&lista);
    cout<<"LeFinal: "<<aux3.nome<<endl;

    cout<<endl;
    mostraL(&lista);
    cout<<endl;

    buscaL(&lista, "paula");

    removeL(&lista, "joao");

    mostraL(&lista);

    cout<< "\nMedia: "<<media(&lista);
    cout<<endl<<endl;

    funcionarioPobre(&lista);

    cout<<endl<<endl;
    cout<<"Removendo o último da lista: "<<endl;
    removeFinalL(&lista);
    mostraL(&lista);
    cout<<endl<<endl;
    cout<<"Lista invertida: "<<endl;
    inverteL(&lista);
    mostraL(&lista);

    cout<<endl<<endl;
    cout<<"Lista ordenada pela idade: "<<endl;
    mostraOrdenadaIdade(&lista);

    insereFimL(&lista1, Cadastro (1, "claudio", 18, 1000));
    insereFimL(&lista1, Cadastro (2, "otavio", 20, 2500));
    insereFimL(&lista1, Cadastro (3, "joao", 70, 2500));
    insereFimL(&lista2, Cadastro (4, "tiago", 41, 1200));
    insereFimL(&lista2, Cadastro (2, "otavio", 20, 2500));
    insereFimL(&lista2, Cadastro (5, "sandra", 30, 1500));
    insereFimL(&lista2, Cadastro (6, "bianca", 77, 2300));
    insereFimL(&lista2, Cadastro (7, "luiz", 12, 3000));

    cout<<endl<<endl;
    interseccao(&lista1, &lista2);

    cout<<endl<<endl;
    cout<<"União de duas listas: "<<endl;
    uniao(&lista1, &lista2);



    destroiL(&lista);
    return EXIT_SUCCESS;
}
