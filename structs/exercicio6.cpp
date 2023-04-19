#include <iostream>
using namespace std;

/*6) Elabore um programa que auxilie no controle de uma fazenda de gado que possuí um total de
2000 cabeças de gado. A base de dados é formada por um conjunto de estruturas (registros)
contendo os seguintes campos referente a cada cabeça de gado:
 código: código da cabeça de gado;
 leite: número de litros de leite produzido por semana;
 alim: quantidade de alimento ingerida por semana - em quilos;
 nasc: data de nascimento - mês e ano; e
 abate: ‘N’ (não) ou ‘S’ (sim).
O campo nasc. é do tipo struct data que por sua vez, possui dois campos:
 mês
 ano
Elaborar funções para:
a) Ler a base de dados (código, leite, alim, nasc.mês e nasc.ano), armazenado em um vetor de
estruturas.
b) Preencher o campo abate, considerando que a cabeça de gado irá para o abate caso:
 tenha mais de 5 anos, ou;
 produza menos de 40 litros de leite por semana, ou;
 produza até 70 litros de leite por semana e ingira mais de 50 quilos de alimento por dia.
Crie o menu de opções para:
a) Exibir a quantidade total de leite produzida por semana na fazenda;
b) Exibir a quantidade total de alimento consumido por semana na fazenda;
c) Exibir a quantidade total de leite que vai ser produzido por semana na fazenda, após o abate;
d) Exibir a quantidade total de alimento que vai ser consumido por semana na fazenda, após o
abate;
e) Exibir o número de cabeças de gado que irão para o abate; e
f) Sair do programa.*/

#define QUANTIDADE 2000

struct Data
{
    int mes;
    int ano;
};

struct Registros
{
    int codigo;
    int leite;
    int alim;
    struct Data nasc;
    bool abate;
};

void abate(Registros &gado)
{
    if (gado.nasc.ano > 5)
    {
        gado.abate = true;
    }
    else if (gado.leite < 40)
    {
        gado.abate = true;
    }
    else if (gado.leite < 70 && gado.alim > 50)
    {
        gado.abate = true;
    }
    else
    {
        gado.abate = false;
    }
}

void lerDados(Registros gado[QUANTIDADE])
{
    for (int i = 0; i < QUANTIDADE; i++)
    {
        cout << "Codigo de identificacao: " << gado[i].codigo << endl;
        cout << "Litros de leite por semana: " << gado[i].leite << endl;
        cout << "Alimentacao em kg por semana: " << gado[i].alim << endl;
        cout << "Data de nascimento: " << gado[i].nasc.mes << "/" << gado[i].nasc.ano << endl;
        cout << "Pronto para o abate(S/N): ";
        abate(gado[i]);
        if (gado[i].abate)
        {
            cout << "S" << endl;
        }
        else
        {
            cout << "N" << endl;
        }
        cout << "------------" << endl;
    }
}

void leiteTotal(Registros gado[QUANTIDADE]) // Quantidade total de leite produzida por semana
{
    int leiteTotal = 0;

    for (int i = 0; i < QUANTIDADE; i++)
    {
        leiteTotal = gado[i].leite + leiteTotal;
    }
    cout << leiteTotal << endl;
}

void alimTotal(Registros gado[QUANTIDADE]) // Quantidade total de alimento consumido por semana
{
    int alimentoTotal = 0;

    for (int i = 0; i < QUANTIDADE; i++)
    {
        alimentoTotal = gado[i].alim + alimentoTotal;
    }
    cout << alimentoTotal << endl;
}

void leiteTotalAbate(Registros gado[QUANTIDADE]) // Quantidade total de leite que vai ser produzido por semana, apos o abate
{
    int leiteTotal = 0;

    for (int i = 0; i < QUANTIDADE; i++)
    {
        abate(gado[i]);
        if (!gado[i].abate)
        {
            leiteTotal = gado[i].leite + leiteTotal;
        }
    }
    cout << leiteTotal << endl;
}

void alimTotalAbate(Registros gado[QUANTIDADE]) // Quantidade total de alimento que vai ser consumido por semana na fazenda, após o abate
{
    int alimentoTotal = 0;

    for (int i = 0; i < QUANTIDADE; i++)
    {
        abate(gado[i]);
        if (!gado[i].abate)
        {
            alimentoTotal = gado[i].alim + alimentoTotal;
        }
    }
    cout << alimentoTotal << endl;
}

void totalAbates(Registros gado[QUANTIDADE]) // Exibir o número de cabeças de gado que irão para o abate
{
    int totalAbates = 0;
    for (int i = 0; i < QUANTIDADE; i++)
    {
        abate(gado[i]);
        if (gado[i].abate)
        {
            totalAbates++;
        }
    }
}

void menu(Registros gado[QUANTIDADE])
{
    int escolha;
    bool sair = false;

    while (sair == false)
    {
        cout << "escolha: (1) Quantidade total de leite produzida por semana na fazenda" << endl;
        cout << "escolha: (2) Quantidade total de alimento consumido por semana na fazenda" << endl;
        cout << "escolha: (3) Quantidade total de leite que vai ser produzido por semana na fazenda, após o abate" << endl;
        cout << "escolha: (4) Quantidade total de alimento que vai ser consumido por semana na fazenda, após o abate" << endl;
        cout << "escolha: (5) Exibir o número de cabeças de gado que irão para o abate" << endl;
        cout << "escolha: (66) sair" << endl;
        cin >> escolha;
        cout << endl;

        switch (escolha)
        {
        case 1:
            leiteTotal(gado);
            break;
        case 2:
            alimTotal(gado);
            break;
        case 3:
            leiteTotalAbate(gado);
            break;
        case 4:
            alimTotalAbate(gado);
            break;
        case 5:
            totalAbates(gado);
            break;

        case 66:
            sair = true;
        }
    }
}

int main()
{
    Registros gado[QUANTIDADE];

    menu(gado);

    return 0;
}