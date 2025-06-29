#include <iostream>
#include <string>
using namespace std;

struct Compromisso
{
    int dia;
	int mes;
    int ano;
	string descricao;

    Compromisso()
    {
        dia = 0;
        mes = 0;
		ano = 0;
		descricao="";
    }

    Compromisso(int d, int m, int a, string desc)
    {
        dia = d;
        mes = m;
		ano = a;
		descricao = desc;
    }
};

#include "lista_descritor.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Lista lista = Lista();

    cout << "\n#TESTE 1\n";
	insereFimL(&lista, Compromisso(5, 8, 2025, "C1"));
	insereFimL(&lista, Compromisso(5, 8, 2024, "C2"));
	insereFimL(&lista, Compromisso(5, 9, 2024, "C3"));
	insereFimL(&lista, Compromisso(5, 10, 2024, "C4"));
	insereFimL(&lista, Compromisso(5, 11, 2024, "C5"));
	insereFimL(&lista, Compromisso(5, 12, 2024, "C6"));
	insereFimL(&lista, Compromisso(4, 12, 2024, "C7"));
	insereFimL(&lista, Compromisso(5, 9, 2025, "C8"));
	insereFimL(&lista, Compromisso(6, 9, 2025, "C9"));
	insereFimL(&lista, Compromisso(1, 8, 2025, "C10"));
	insereFimL(&lista, Compromisso(5, 11, 2024, "C11"));
	insereFimL(&lista, Compromisso(6, 11, 2024, "C12"));
	mostraL(&lista);

    cout << "\n#TESTE 2\n";
	insereAposPrimeiraOcorrencia(&lista, 1, 8, 2025, Compromisso(5, 12, 2025, "CX1"));
	mostraL(&lista);
	cout << "Compromisso do fim da lista: " << lista.fim->dado.descricao << endl;


    cout << "\n#TESTE 3\n";
	insereAposPrimeiraOcorrencia(&lista, 5, 11, 2024, Compromisso(6, 12, 2025, "CX2"));
	mostraL(&lista);
	cout << "Compromisso do fim da lista: " << lista.fim->dado.descricao << endl;


	cout << "\n#TESTE 4\n";
	insereAposPrimeiraOcorrencia(&lista, 6, 11, 2024, Compromisso(7, 12, 2025, "CX3"));
	mostraL(&lista);
	cout << "Compromisso do fim da lista: " << lista.fim->dado.descricao << endl;


	cout << "\n#TESTE 5\n";
	insereAposCadaOcorrencia(&lista, 5, 11, 2024, Compromisso(8, 12, 2025, "CX4"));
	mostraL(&lista);
	cout << "Compromisso do fim da lista: " << lista.fim->dado.descricao << endl;

	cout << "\n#TESTE 6\n";
	insereAposCadaOcorrencia(&lista, 7, 12, 2025, Compromisso(9, 12, 2025, "CX5"));
	mostraL(&lista);
	cout << "Compromisso do fim da lista: " << lista.fim->dado.descricao << endl;


    cout << "\n#TESTE 7\n";
    ordenarL(&lista);
    mostraL(&lista);

    destroiL(&lista);
    return EXIT_SUCCESS;
}
