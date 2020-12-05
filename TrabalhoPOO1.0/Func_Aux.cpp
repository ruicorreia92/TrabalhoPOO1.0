#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <climits>
#include <cctype>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Mundo.h"
#include "Territ_inic.h"
#include "territor.h"
#include "Func_Aux.h"
#include "utilis.h"

using namespace std;

string nomeI = "MeuImperio";

int ar = intUniformRnd( 0, 3);

Mundo a("Mundo_1");


Territ_inic ini(nomeI, 9, ar, 1, 1, 0);


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



void acrecentaterr() {// Pede ao utilizador o tipo de territorio e a quantidade e insere no vector de territorios

	string namet;
	string qut;
	int  i, flag = 0, flag1 = 0;
	int quant;
	int r, p1, p2, g1, g2;


	do {
		cout << "Digite o nome e o numero de Territorios a Criar. <Tipo> <Quantidade>\n";
		cin >> namet >> qut;
		flag = verificaTipo(namet);//verifica se o tipo existe
		flag1 = verificaQuant(qut);//verifica se a quantidade é um int;
	} while (flag == -1 || flag1 != 1);
	quant = stoi(qut);
	param(flag, &r, &p1, &p2, &g1, &g2);

	for (i = 0; i < quant; i++) {
		a.acrescentar(namet, r, p1, p2, g1, g2);
	}

	return;
}


void listaterr() {
	cout << ini.getAsString() << endl;
	cout << a.getAsString() << endl;
	
}



string leComandos(string namef, int* it) {
	string cmd;
	ifstream fich1(namef);

	if (!fich1) {
		cout << "\n Ocorreu um erro ao abrir o Ficheiro: " << namef << endl;
		return cmd;
	}

	fich1.seekg(*it);
	getline(fich1, cmd);
	*it += (cmd.size() + 2);
	cout << "\nFoi lido o comando: " << cmd << endl;
	fich1.close();

	return cmd;
}

void criadoficheiro(string namef) {
	int x, b, c, d, e, cont = -1;
	string tipo;
	ifstream fich1(namef);
	if (!fich1) {
		cout << "\n Ocorreu um erro ao abrir o Ficheiro: " << namef
			<< "\n Verifique se o nome esta correto Ex: XXXXXX.txt" << endl;
		return;
	}
	while (fich1) {
		fich1 >> tipo >> x >> b >> c >> d >> e;
		if (fich1)
			a.acrescentar(tipo, x, b, c, d, e);
		cont++;
	}
	cout << "\Foram Criados: " << cont << " territorios\n\n";
	fich1.close();
}

int verificaTipo(string t) {
	int cont = 0;
	vector<string> ter = { "Planicie","Montanha", "Fortaleza", "Mina", "Duna", "Castelo", "Refugio", "Pescaria" };
	for (vector<string>::const_iterator it = ter.begin();
		it != ter.end(); ++it) {
		if (*it == t) {
			return cont;
		}cont++;
	}
	cout << "\nTipo nao existe ou foi mal Escrito.\n";
	cout << "\nExemplo: Montanha // Planicie\n";
	return -1;
}

int verificaCom(vector<string> cm, string t) {
	int cont = 0;
	for (vector<string>::const_iterator it = cm.begin();
		it != cm.end(); ++it) {
		if (*it == t) {
			return cont;
		}cont++;
	}
	cout << "\nComando nao existe ou foi mal Escrito.\n";
	cout << "Exemplo: Carrega // Cria\n";
	return -1;
}

int verificaQuant(string qt) {
	int i, res = 1;
	for (i = 0; i < qt.size(); i++) {
		if (qt[i] < '0' || qt[i]> '9')
			res = 0;
	}
	if (res == 0)
		cout << "\nNumero Invalido\n";
	return res;
}

void conquiterr() {



}

void param(int tipo, int* r, int* p1, int* p2, int* g1, int* g2) {
	if (tipo == 0)//Planicie
	{
		*r = 5; *p1 = 1; *p2 = 2; *g1 = 1; *g2 = 1;
	}
	if (tipo == 1)//Montanha
	{
		*r = 6; *p1 = 1; *p2 = 1; *g1 = 0; *g2 = 0;
	}
	if (tipo == 2)//Fortaleza
	{
		*r = 8; *p1 = 0; *p2 = 0; *g1 = 0; *g2 = 0;
	}
	if (tipo == 3)//Mina
	{
		*r = 5; *p1 = 0; *p2 = 0; *g1 = 1; *g2 = 2;
	}
	if (tipo == 4)//Duna
	{
		*r = 4; *p1 = 1; *p2 = 1; *g1 = 0; *g2 = 0;
	}
	if (tipo == 5)//Castelo
	{
		*r = 7; *p1 = 3; *p2 = 3; *g1 = 1; *g2 = 1;
	}
	if (tipo == 6)//Refugio dos Piratas
	{
		*r = 9; *p1 = 0; *p2 = 0; *g1 = 1; *g2 = 1;
	}
	if (tipo == 7)//Pescaria
	{
		*r = 9; *p1 = 2; *p2 = 4; *g1 = 0; *g2 = 0;
	}

}
