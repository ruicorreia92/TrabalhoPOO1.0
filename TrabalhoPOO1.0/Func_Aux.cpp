#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <climits>
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
	
	string namet, comando, creat="Criar";
	int quant, i;
	cout << "Digite o nome e o numero de Territorios a Criar. <Tipo> <Quantidade>\n";
	cin >> namet >> quant;
		for (i = 0; i < quant; i++) {
			a.acrescentar(namet, 8, 8, 8, 8);
		}
	
	return ;
}

void listaterr() {
	cout << a.getAsString() << endl;
}