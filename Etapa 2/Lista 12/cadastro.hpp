#ifndef _HPP_CLIENTE
#define _HPP_CLIENTE

struct Cadastro
{
    int codigo;
    int idade;
    float peso;

    Cadastro()
    {
        codigo = 0;
        idade = 0;
        peso = 0.0f;
    }

    Cadastro(int c, int i, float p)
    {
        codigo = c;
        idade = i;
        peso = p;
    }
};

#endif // _HPP_CLIENTE
