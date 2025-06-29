#include<iostream>
#include<string>
#include <sstream>
#include <fstream>

using namespace std;

#include "lista_descritor_char.hpp"

int main()
{
    setlocale(LC_ALL, "portuguese");
    stringstream strBuffer;
    string op, linha;
    Lista L1 = Lista();
    Lista L2 = Lista();
    Lista L3 = Lista();


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

        if(op == "inserir")
        {
            string nomeLista;
            int quantidade;
            string caracteres;
            strBuffer >> nomeLista >> quantidade;
            for (int i = 0; i < quantidade; i++) {
                char caractere;
                strBuffer >> caractere;
                caracteres += caractere;
            }

            if (nomeLista == "L1") inserir(&L1, quantidade, caracteres);
            else if (nomeLista == "L2") inserir(&L2, quantidade, caracteres);
            else if (nomeLista == "L3") inserir(&L3, quantidade, caracteres);

        } else if (op == "mostrar") {
            string nomeLista;
            char ordem;
            strBuffer >> nomeLista >> ordem;

            cout << nomeLista << ": ";
            if (nomeLista == "L1") mostrar(&L1, ordem);
            else if (nomeLista == "L2") mostrar(&L2, ordem);
            else if (nomeLista == "L3") mostrar(&L3, ordem);

        } else if (op == "substituir") {
            string nomeLista;
            int quantidade;
            string caracteres;
            strBuffer >> nomeLista >> quantidade;
            for (int i = 0; i < quantidade; i++) {
                char caractere;
                strBuffer >> caractere;
                caracteres += caractere;
            }

            if (nomeLista == "L1") substituir(&L1, quantidade, caracteres);
            else if (nomeLista == "L2") substituir(&L2, quantidade, caracteres);
            else if (nomeLista == "L3") substituir(&L3, quantidade, caracteres);

        } else if (op == "inserirCaractereApos") {
            string nomeLista;
            char caractere1, caractere2;
            strBuffer >> nomeLista >> caractere1 >> caractere2;

            if (nomeLista == "L1") inserirCaractereApos(&L1, caractere1, caractere2);
            else if (nomeLista == "L2") inserirCaractereApos(&L2, caractere1, caractere2);
            else if (nomeLista == "L3") inserirCaractereApos(&L3, caractere1, caractere2);

        } else if (op == "contarOcorrencia") {
            string nomeLista1, nomeLista2;
            strBuffer >> nomeLista1 >> nomeLista2;

            if (nomeLista1 == "L1" && nomeLista2 == "L2") {
                cout << "Ocorrências: " << contarOcorrencia(&L1, &L2) << endl;
            }

        } else if (op == "inserirAntesPrimeiraOcorrencia") {
            string nomeLista1, nomeLista2, nomeLista3;
            strBuffer >> nomeLista1 >> nomeLista2 >> nomeLista3;

            if (nomeLista1 == "L1" && nomeLista2 == "L2" && nomeLista3 == "L3") {
                inserirAntesPrimeiraOcorrencia(&L1, &L2, &L3);
            }
        }
    }

    return 0;
}
