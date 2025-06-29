#include<iostream>
#include<string>
#include <sstream>
#include <fstream>

using namespace std;

struct Veiculo
{
    string placa;
    int ano;
    string marca;
    string modelo;
    Veiculo()
    {
        placa = " ";
        ano = 0;
        marca = " ";
        modelo = " ";
    }
    Veiculo(string p, int a, string m, string mod)
    {
        placa = p;
        ano = a;
        marca = m;
        modelo = mod;
    }
};

#include "lista_descritor_exerc3.hpp"

int main()
{
    setlocale(LC_ALL, "portuguese");
    stringstream strBuffer;
    string op, linha, ordenar, removeVei, fab, filtro;
    char menu;
    Lista lista = Lista();


    ifstream arq ("cadastro.txt");

    if (!arq.is_open())
    {
        cout << "Erro: n�o foi poss�vel abrir o arquivo texto.\n";
        return 0;
    }

    while(!arq.eof())
    {
        linha = ""; //IMPORTANTE, sempre inicializar a string
        getline(arq, linha);
        if(linha.size()==0)
            break;

        strBuffer = stringstream(linha);
        int contPlavra=1;
        string palavra;
        Veiculo v;
        while(getline(strBuffer, palavra , '#')) //le cada palavra da linha separada pelo delimitador #
        {
            if(contPlavra==1) //primeira palavra da linha
                v.placa = palavra;
            else if(contPlavra==2) //segunda palavra da linha
                v.ano = stoi(palavra);
            else if(contPlavra==3) //terceira palavra da linha
                v.marca = palavra;
            else if(contPlavra==4) //quarta palavra da linha
                v.modelo = palavra;
            contPlavra++;
        }
        cout << "Ve�culo lido: " << v.placa << ", " << v.ano << ", " << v.marca << ", " << v.modelo << endl;
        insereInicioL(&lista, Veiculo(v.placa, v.ano, v.marca, v.modelo));
    }

    //mostraL(&lista);


   cout << "###MENU###\n";
    cout << "a- Mostrar lista\n";
    cout << "b- Ordenar lista\n";
    cout << "c- Remover um ve�culo\n";
    cout << "d- Remover ve�culo com base no fabricante e no ano\n";
    cout << "e- Filtrar ve�culo\n";
    cout << "f- Sair\n";
    do
    {
        cout << "Digite a op��o: ";
        cin >> menu;
        cin.ignore();

        if(menu!='a' && menu!='b' && menu!='c' && menu!='d' && menu!='e' && menu!='f')
        {
            cout << "Erro: op��o inv�lida!\n";
            continue;
        }

        if(menu=='a')
        {
            if(vaziaL(&lista))
                cout<<"Lista vazia"<<endl;
            else
            {
                cout<<endl;
                mostraL(&lista);
                cout<<endl;
            }
        }

        else if(menu=='b')
        {
            cout<<"Informe se a lista deve ser ordenada pelo ano ou pelo modelo: "<<endl;
            getline(cin,ordenar);
            fflush(stdin);
            cout<<endl;
            if(!vaziaL(&lista))
            {
                if(ordenar == "ano")
                    mostraOrdenadaAno(&lista);

                else if(ordenar == "modelo")
                    mostraOrdenadaModelo(&lista);
                cout<<endl;
            }
            else
                cout<<"Lista vazia"<<endl;
        }

        else if(menu =='c')
        {
            cout<<"Informe a placa do ve�culo: "<<endl;
            getline(cin,removeVei);
            fflush(stdin);

            if(vaziaL(&lista))
                cout<<"Lista vazia"<<endl;

            else
                removeL(&lista, removeVei);
        }

        else if(menu =='d')
        {
            cout<<"Informe a marca do ve�culo: "<<endl;
            getline(cin,fab);
            fflush(stdin);

            if(vaziaL(&lista))
                cout<<"Lista vazia"<<endl;

            else
                removeMarcaAno(&lista, fab);
        }

        else if(menu =='e')
        {
            cout<<"Informe a marca do ve�culo: "<<endl;
            getline(cin,filtro);
            fflush(stdin);

            if(vaziaL(&lista))
                cout<<"Lista vazia"<<endl;

            else
                filtraVeiculo(&lista, filtro);
        }

    }

    while(menu!='f');
    return 0;
}
