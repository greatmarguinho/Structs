#include <iostream>
#include <chrono>
using namespace std;

/*3) Faça um programa que, usando struct, armazene o nome e a data de nascimento de até 10 
pessoas (o usuário entrará com estas informações). A geração da data de nascimento deve ser 
feita aleatoriamente através da função abaixo: 
void CriaData (TData &D) {
 D.Mes = 1 + (rand() % 12);
 D.Ano = 1940 + (rand() % 74);
 D.Dia = 1 + (rand() % 30);
}
O programa deve:
 Verificar se a data de nascimento gerada é válida (utilize o algoritmo desenvolvido na 
exercício número 2);
 listar todos os nomes e respectivas idades; e
 listar os nomes das pessoas mais velhas do que uma certa idade (deve ser validada 
também esta data) fornecida pelo usuário

Devem ser criadas funções diferentes para cada uma dessas atividades.
*/
struct TData{
    int Mes;
    int Ano;
    int Dia;
    int Idade;
    bool Idoso;
    string nome;
};

bool verificaBissexto(TData d)
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


bool validaData(TData d){
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

void CriaData (TData &D) {
 D.Mes = 1 + (rand() % 12);
 D.Ano = 1940 + (rand() % 74);
 D.Dia = 1 + (rand() % 30);
}

void idadeDaPessoa(TData &D){
    int idade;
    // Obter o tempo atual
    auto now = std::chrono::system_clock::now();

    // Converter o tempo em uma estrutura tm
    std::time_t now_t = std::chrono::system_clock::to_time_t(now);
    std::tm* now_tm = std::localtime(&now_t);

    /*now_tm->tm_mday; dia atual
    1 + now_tm->tm_mon; mes atual
    1900 + now_tm->tm_year << std::endl; ano atual*/

    D.Idade = (1900 + now_tm->tm_year) - D.Ano;
}


void ListarPessoas(TData D){

    idadeDaPessoa(D);
    cout << "nome: " << D.nome << endl;
    cout << D.Dia << "/";
    cout << D.Mes << "/";
    cout << D.Ano << endl;
    cout << "idade: " << D.Idade << endl;

}


void ListarIdosos(TData &D){
    int idadeIdosa = 60;
    if(D.Idade >= idadeIdosa){
        D.Idoso = true;
        cout << "idoso" << "\n\n\n";
    } else{
        D.Idoso = false;
        cout << "\n\n\n";
    }
}


void CadastreNome(TData &D){
    cout << "insira seu nome: " << endl;
    cin >> D.nome;
}

void MensagemDeValidacao(TData &D){
    if(validaData(D)){
            cout << "data valida" << endl;
        }else{
            cout << "data invalida" << endl;
        }
}

int main(){
    TData pessoas[10];
    for(int i = 0; i < 10; i++){
        CadastreNome(pessoas[i]);
        CriaData(pessoas[i]);
    }

    for(int i = 0; i < 10; i++){
        ListarPessoas(pessoas[i]);
        MensagemDeValidacao(pessoas[i]);
        ListarIdosos(pessoas[i]);
    }
}