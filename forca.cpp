#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "nao_acertou.hpp"
#include "nao_enforcou.hpp"
#include "imprimir.hpp"
#include "chuta.hpp"
#include "le_arquivo.hpp"
#include "sorteia_palavra.hpp"
#include "adiciona_palavra.hpp"
using namespace std;

//compilação
//g++ forca.cpp -o forca.out
//g++ *.cpp -o forca.out
//executando
//./forca.out

string palavra_secreta; 
map<char, bool> chutou;
vector<char> chutes_errados;

int main () {
    imprime_cabecalho();

    le_arquivo();
    sorteia_palavra();

    while(nao_acertou() && nao_enforcou()){
        imprime_erros();
        imprime_palavra();
        chuta();
    }

    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era: " << palavra_secreta << endl;
    if(nao_acertou()){
        cout << "Voce perdeu! Tente novamente!" << endl;
    }
    else{
        cout << "Parabens! Voce acertou a palavra secreta!" << endl;

        cout << "Voce deseja adicionar uma nova palavra ao banco? (S/N) ";
        char resposta;
        cin >> resposta;
        if(resposta == 'S'){
            adiciona_palavra();
        }
    }
    
    cin.get();
}