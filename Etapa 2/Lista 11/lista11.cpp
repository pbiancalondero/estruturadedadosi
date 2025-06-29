#include<iostream>
#include<string>
#include <sstream>
#include <fstream>

using namespace std;

#include "lista_descritor.hpp"

int main()
{
    setlocale(LC_ALL, "portuguese");
    stringstream strBuffer;
    string op, linha;
    Lista L1 = Lista();
    Lista L2 = Lista();


    ifstream arq ("entrada.txt");

    if (!arq.is_open())
    {
        cout << "Erro: não foi possível abrir o arquivo texto.\n";
        return 0;
    }

    while(!arq.eof())
    {
        linha = ""; //IMPORTANTE, sempre inicializar a string
        getline(arq, linha);
        strBuffer = stringstream(linha);
        strBuffer >> op;

        if(op == "adiciona")
        {
            string nomeLista;
            int valor;
            strBuffer >> nomeLista; //segundo dado da linha
            strBuffer >> valor; //terceiro dado da linha
            if(nomeLista == "L1")
            {
                insereFimL(&L1, valor);
                cout << "O número " << valor << " foi adicionado na lista L1\n";
            }
            else if(nomeLista == "L2")
            {
                insereFimL(&L2, valor);
                cout << "O número " << valor << " foi adicionado na lista L2\n";
            }
        }
        else if(op == "mostra")
        {
            string nomeLista;
            char valor;
            strBuffer >> nomeLista; //segundo dado da linha
            strBuffer >> valor;

            if(nomeLista == "L1")
            {
                if(vaziaL(&L1))
                    cout<<"L1 ("<< valor <<"): VAZIA\n";

                else
                {
                    if(valor == 'I')
                        mostraL(&L1, nomeLista, valor);
                    else if(valor == 'C')
                        mostraOrdemC(&L1, nomeLista, valor);
                    else if(valor == 'D')
                        mostraOrdemD(&L1, nomeLista, valor);
                }
            }
            else if(nomeLista == "L2")
            {
                if(vaziaL(&L2))
                    cout<<"L2 ("<< valor <<"): VAZIA\n";

                else
                {
                    if(valor == 'I')
                        mostraL(&L2, nomeLista, valor);
                    else if(valor == 'C')
                        mostraOrdemC(&L2, nomeLista, valor);
                    else if(valor == 'D')
                        mostraOrdemD(&L2, nomeLista, valor);
                }
            }
        }
        else if(op == "mostraDif")
        {
            string nomeLista;
            string nomeLista2;
            strBuffer >> nomeLista; //segundo dado da linha
            strBuffer >> nomeLista2; //terceiro dado da linha

            if(vaziaL(&L2) && vaziaL(&L1))
                cout<<"L1 - L2: VAZIA\n";

            else
            {
                if(nomeLista == "L1")
                {
                    if(vaziaL(&L1))
                        cout<<"L1 - L2: VAZIA\n";
                    else
                    {
                        cout<<nomeLista<< " - "<< nomeLista2<<": ";
                        mostraDif(&L1, &L2);
                    }
                }

                else if(nomeLista == "L2")
                {
                    if(vaziaL(&L2))
                        cout<<"L2 - L1: VAZIA\n";
                    else
                    {
                        cout<<nomeLista<< " - "<< nomeLista2<<": ";
                        mostraDif(&L2, &L1);
                    }
                }
            }
        }

        else if(op == "removeTodos")
        {
            string nomeLista;
            strBuffer >> nomeLista; //segundo dado da linha

            if(nomeLista == "L1")
            {
                removeTodos(&L1);
                cout<<"Todos os elementos de "<<nomeLista<<" foram removidos"<<endl;
            }
            else if(nomeLista == "L2")
            {
                removeTodos(&L2);
                cout<<"Todos os elementos de "<<nomeLista<<" foram removidos"<<endl;
            }
        }

        else if(op == "mediana")
        {
            string nomeLista;
            strBuffer >> nomeLista; //segundo dado da linha

            if(vaziaL(&L1))
                cout<<"Erro ao calcular a mediana de "<<nomeLista<<": lista vazia!"<<endl;
            else if(vaziaL(&L2))
                cout<<"Erro ao calcular a mediana de "<<nomeLista<<": lista vazia!"<<endl;
            else
            {
                if(nomeLista == "L1")
                {
                    cout<< "Mediana L1: ";
                    mediana(&L1);
                }

                else if(nomeLista == "L2")
                {
                    cout<< "Mediana L2: ";
                    mediana(&L2);
                }
            }
        }

        else if(op == "moda")
        {
            string nomeLista;
            strBuffer >> nomeLista; //segundo dado da linha

            if(vaziaL(&L1))
                cout<<"Moda(s) "<<nomeLista<<": VAZIA"<<endl;
            else if(vaziaL(&L2))
                cout<<"Moda(s) "<<nomeLista<<": VAZIA"<<endl;
            else
            {
                if(nomeLista == "L1")
                {
                    cout<< "Moda(s) L1: ";
                    moda(&L1);
                }

                else if(nomeLista == "L2")
                {
                    cout<< "Moda(s) L2: ";
                    moda(&L2);
                }
            }

        }

    }

    return 0;
}
