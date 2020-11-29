#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <climits>
#include <cctype>
#include <string.h>
#include "Mundo.h"
#include "territor.h"
#include "Func_Aux.h"

using namespace std;

Mundo a("Mundo_1");

int escolheOpcao(vector<string> opcoes) {
	for (unsigned int i = 0; i < opcoes.size(); ++i)
		cout << endl << i << " - " << opcoes[i];

	int opcao = -1;
	do {
		opcao = lerInt("\nopcao > ");
	} while (opcao < 0 || opcao >= opcoes.size());
	return opcao;
}
int lerInt(string msg) {
	int valor;
	bool leu = false;
	do {
		cout << msg;
		string s;
		cin >> s;
		istringstream iss(s);
		if (iss >> valor) // se correu bem a leitura
			leu = true;
	} while (!leu);
	return valor;
}

void acrecentaterr(){
	
	string namet, comando;
	int  i,flag=0, flag1=0;
	char quant;
	do {
		cout << "Digite o nome e o numero de Territorios a Criar. <Tipo> <Quantidade>\n";
		cin >> namet >> quant;
		flag = verificaTipo(namet);
		flag1 = verificaQuant(quant);
	} while (flag != 1 || flag1 != 1);
		for (i = 0; i < quant; i++) {
			a.acrescentar(namet, 8, 8, 8, 8);
		}
	
	return ;
}

void listaterr() {
	cout << a.getAsString() << endl;
}


void leficheiro(string namef) {
	int x, b, c, d;
	string dois;
	ifstream fich1(namef);
		if (!fich1) {
			cout << "ocorreu um erro" << endl;
			return ;
		}
		while (fich1) {
				fich1 >> dois >> x >> b >> c >> d;
				a.acrescentar(dois, x, b, c, d);
			}
			fich1.close();
}

int verificaTipo(string t) {
	vector<string> ter = { "Planicie","Montanha", "Fortaleza", "Mina", "Duna", "Castelo", "Refugio", "Pescaria" };
	for (vector<string>::const_iterator it = ter.begin();
		it != ter.end(); ++it) {
		if (*it == t){
			return 1;
		}
	}
	cout << "\nTipo não existe ou foi mal Escrito.\n";
	cout << "Exemplo: Montanha // Planicie";
	return 0;
}

int verificaQuant(char qt) {



}


