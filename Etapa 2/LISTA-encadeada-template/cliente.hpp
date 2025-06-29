#ifndef _HPP_CLIENTE
#define _HPP_CLIENTE

struct Cliente
{
    string nome;
    int idade;
    Cliente()
    {
        nome = "";
        idade = 0;
    }

    Cliente(string n, int i)
    {
        nome = n;
        idade = i;
    }
};






#endif // _HPP_CLIENTE





