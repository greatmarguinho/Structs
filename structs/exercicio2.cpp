#include <iostream>
using namespace std;

/* 2) Elabore um programa em C que leia do usuário uma data (criar o tipo data, com Dia, mês e Ano).
Para a verificação da data deve ser feito uma função que receba a data e retorne verdade se ela
é válida e falso caso contrário. Anos bissextos são dados pelas regras (segundo o calendário
Gregoriano):
i) De 4 em 4 anos é Ano bissexto.
ii) De 100 em 100 anos não é Ano bissexto.
iii) De 400 em 400 anos é Ano bissexto.
iv) Prevalecem as últimas regras sobre as primeiras.
A título de curiosidade, o Ano de 1900 foi o último Ano a ser aplicada a regra ii (não é bissexto).
A próxima vez será em 2100.
*/

struct Data
{
    int Dia, Mes, Ano;

    
};

bool verificaBissexto(Data d)
{
    if (d.Ano % 400 == 0)
    {
        return true;
    }
    else if (d.Ano % 100 == 0)
    {
        return false;
    }
    else if (d.Ano % 4 == 0)
    {
        return true;
    }
    else{
        return false;
    }
}


bool validaData(Data d){
    switch (d.Mes){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if(d.Dia >0 && d.Dia <32){
                return true;
            }

        break;
        case 4: case 6: case 9: case 11:
            if(d.Dia >0 && d.Dia <31){
                return true;
            }
        

        break;
        case 2:
            if(d.Dia >0 && d.Dia < 30 && verificaBissexto(d)){
                return true;
            } else if (d.Dia >0 && d.Dia < 29 && !verificaBissexto(d)) {
                return false;
            }

        break;
    }//switch

    return false;
    
}
int main()
{

    Data data;
    bool dataVerdadeira = true;

    cout << "digite o Dia: ";
    cin >> data.Dia;
    cout << "\ndigite o Mes: ";
    cin >> data.Mes;
    cout << "\ndigite o Ano: ";
    cin >> data.Ano;

    dataVerdadeira = validaData(data);

    if (dataVerdadeira == true)
    {
        cout << "essa data eh valida";
    }else{
        cout << "data inválida";
    }
}