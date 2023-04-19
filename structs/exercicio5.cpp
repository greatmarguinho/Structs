#include <iostream>

using namespace std;
/*Crie uma estrutura para descrever os carros de uma determinada revendedora, contendo os
seguintes campos:
 marca: string de tamanho 15
 ano: inteiro
 cor: string de tamanho 10
 preço: real
a) Crie a estrutura carro.
b) Declare o vetor vetcarros do tipo da estrutura definida acima, de tamanho 20.
Crie um menu para:
a) Definir um bloco procedimento para ler o vetor vetcarros.
b) Definir um procedimento que receba um preço e imprima os carros (marca, cor e ano) que
tenham preço igual ou menor ao preço recebido.
c) Definir um procedimento que leia a marca de um carro e imprima as informações de todos
os carros dessa marca (preço, ano e cor).
d) Definir um procedimento que leia uma marca, ano e cor e informe se existe ou não um
carro com essas características. Se existir, informar o preço.*/

#define TAMANHO 20 // tamanho do vetor vetcarros;

struct Carro
{
    char marca[15];
    int ano;
    char cor[10];
    double preco;
};

void imprimiCarrosTudo(Carro vetcarros)
{
    cout << "marca " << vetcarros.marca << endl;
    cout << "cor " << vetcarros.cor << endl;
    cout << "ano " << vetcarros.ano << endl;
    cout << "preco" << vetcarros.preco << endl;
    cout << "-----------" << endl;
}

void imprimiCarrosPreco(Carro vetcarros)
{
    cout << "marca " << vetcarros.marca << endl;
    cout << "cor " << vetcarros.cor << endl;
    cout << "ano " << vetcarros.ano << endl;
    cout << "-----------" << endl;
}

void imprimiCarrosMarca(Carro vetcarros)
{
    cout << "preco " << vetcarros.preco << endl;
    cout << "cor " << vetcarros.cor << endl;
    cout << "ano " << vetcarros.ano << endl;
    cout << "-----------" << endl;
}

void recebePreco(Carro vetcarros[TAMANHO])
{
    system("cls");
    double preco;
    cout << "Qual preco voce esta procurando?" << endl;
    cin >> preco;

    for (int i = 0; i < TAMANHO; i++)
    {
        if (preco <= vetcarros[i].preco)
        {
            imprimiCarrosPreco(vetcarros[i]);
        }
    }
}

void lerCarros(Carro vetcarros[TAMANHO])
{
    for (int i = 0; i < TAMANHO; i++)
    {
        imprimiCarrosTudo(vetcarros[i]);
    }
}

void lerMarca(Carro vetcarros[TAMANHO])
{
    system("cls");
    char marca[15];
    cout << "Qual marca voce esta procurando?" << endl;
    cin >> marca;
    for (int i = 0; i < TAMANHO; i++)
    {
        if (marca == vetcarros[i].marca)
        {
            imprimiCarrosMarca(vetcarros[i]);
        }
    }
}

void lerMarcaAnoCor(Carro vetcarros[TAMANHO])
{
    int ano;
    char marca[15];
    char cor[10];

    system("cls");
    cout << "Qual marca voce esta procurando?" << endl;
    cin >> marca;

    system("cls");
    cout << "Qual ano do carro voce esta procurando?" << endl;
    cin >> ano;

    system("cls");
    cout << "Qual cor de carro voce esta procurando?" << endl;
    cin >> cor;

    for (int i = 0; i < TAMANHO; i++)
    {
        if (marca == vetcarros[i].marca && ano == vetcarros[i].ano && cor == vetcarros[i].cor)
        {
            cout << vetcarros[i].preco;
        }
        else
        {
            cout << "nao encontramos nenhum carro com esses requisitos" << endl;
        }
    }
}

void menu(Carro vetcarros[TAMANHO])
{
    int escolha;
    bool sair = false;

    while (sair == false)
    {
        cout << "escolha: (1) lerCarros" << endl;
        cout << "escolha: (2) recebePreco" << endl;
        cout << "escolha: (3) lerMarca" << endl;
        cout << "escolha: (4) lerMarcaAnoCor" << endl;
        cout << "escolha: (66) sair" << endl;
        cin >> escolha;
        cout << endl;

        switch (escolha)
        {
        case 1:
            lerCarros(vetcarros);
            break;
        case 2:
            recebePreco(vetcarros);
            break;
        case 3:
            lerMarca(vetcarros);
            break;
        case 4:
            lerMarcaAnoCor(vetcarros);
            break;
        case 66:
            sair = true;
        }
    }
}

int main()
{
    Carro vetcarros[TAMANHO];
    menu(vetcarros);
    return 0;
}