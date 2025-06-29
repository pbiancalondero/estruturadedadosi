#ifndef _HPP_CLIENTE
#define _HPP_CLIENTE

struct Cadastro
{
    int codigo;
    string nome;
    int idade;
    float salario;
    Cadastro()
    {
        codigo = 0;
        nome = " ";
        idade = 0;
        salario = 0.0f;
    }

    Cadastro(int c, string n, int i, float s)
    {
        codigo = c;
        nome = n;
        idade = i;
        salario = s;
    }
};

#endif // _HPP_CLIENTE
