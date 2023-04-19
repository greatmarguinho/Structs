#include <iostream>
using namespace std;

/*4) Faça um programa de controle de despesas e dados de um condomínio de apartamentos. Os
dados de cada apartamento são armazenados em um vetor de estruturas. Para cada apartamento
tem-se os seguintes dados:
 Nome do responsável.
 Número do apartamento.
 Área em m2
.
 Número de moradores.
 Valor a ser pago no mês.
Crie a estrutura descrita acima e declare um vetor de estruturas, lembrando que o condomínio
possui 40 apartamento. A seguir, crie um menu no main e:
 Crie uma função que preencha o vetor acima, exceto o campo valor.
 Informe a área total do condomínio.
 Informe qual apartamento possui o maior número de moradores, e imprima seus dados.
Caso haja mais que um, imprima as informações de todos.
 Tenha uma opção para sair do programa.
*/

#define APARTAMENTO 2

struct Apartamento
{
    string nomeResponsavel;
    int numeroApartamento;
    int area;
    int numeroMoradores;
    int valor;
};

void preencheDados(Apartamento &ap)
{
    cout << "Insira nome do responsavel do imovel: ";
    cin >> ap.nomeResponsavel;
    cout << endl;

    cout << "Insira numero do apartamento: ";
    cin >> ap.numeroApartamento;
    cout << endl;

    cout << "Insira area do apartamento: ";
    cin >> ap.area;
    cout << endl;

    cout << "Insira numero de moradores do apartamento: ";
    cin >> ap.numeroMoradores;
    cout << endl;
}

void printaMorador(Apartamento ap)
{
    cout << "Nome do responsavel do imovel: ";
    cout << ap.nomeResponsavel << endl;

    cout << "Numero do apartamento: ";
    cout << ap.numeroApartamento << endl;

    cout << "Area do apartamento: ";
    cout << ap.area << endl;

    cout << "Numero de moradores do apartamento: ";
    cout << ap.numeroMoradores << "\n\n\n";
}

void forPreencheAp(Apartamento ap[APARTAMENTO])
{
    for (int i = 0; i < APARTAMENTO; i++)
    {
        preencheDados(ap[i]);
    }
}

void AreaTotal(Apartamento ap[APARTAMENTO])
{
    int areaTotal = 0;
    for (int i = 0; i < APARTAMENTO; i++)
    {
        areaTotal = areaTotal + ap[i].area;
    }
    cout << "A area total dos condominios e " << areaTotal << endl;
}

void maisMoradores(Apartamento ap[APARTAMENTO])
{
    int maiorNumeroMoradores[APARTAMENTO] = {0};
    int aux = 0;
    int j = 0;
    for (int i = 0; i < APARTAMENTO; i++)
    {
        if (ap[i].numeroMoradores > aux)
        {
            aux = ap[i].numeroMoradores;
            j = 0;
        }
        if (ap[i].numeroMoradores >= aux)
        {
            maiorNumeroMoradores[j] = i;
            j++;
        }
    }

    cout << "os moradores com mais pessoas morando junto e ou sao:\n";
    for (int i = 0; i < j; i++)
    {
        printaMorador(ap[maiorNumeroMoradores[i]]);
    }
}

void menu(Apartamento ap[APARTAMENTO])
{
    bool sair = false;
    int escolha;
    system("cls");

    while (sair == false)
    {
        cout << "(1) Preencher dados\n(2) Area Total\n(3) Apartamentos com mais moradores\n(66) ORDER 66\n";
        cout << "escolha uma opcao: ";
        cin >> escolha;
        switch (escolha)
        {
        case 1:
            forPreencheAp(ap);
            break;

        case 2:
            AreaTotal(ap);
            break;

        case 3:
            maisMoradores(ap);
            break;

        case 66:
            sair = true;
            break;
        }
    }
}

int main()
{
    Apartamento ap[APARTAMENTO];

    menu(ap);
    return 0;
}