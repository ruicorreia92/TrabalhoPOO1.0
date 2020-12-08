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

Mundo a("Mundo");//Cria o Mundo 

Territ_inic ini(nomeI, 9, 0, 1, 1, 0);//Cria o territorio inicial

// Pede ao utilizador o tipo de territorio e a quantidade e insere no vector de territorios
void acrecentaterr() {

	string namet;
	string qut;
	int  i, flag = 0, flag1 = 0;
	int quant;
	int r, p1, p2, g1, g2;


	do {
		cout << " Digite o nome e o numero de Territorios a Criar. <Tipo> <Quantidade>\n";
		cin >> namet >> qut;
		flag = verificaTipo(namet);//verifica se o tipo existe
		flag1 = verificaQuant(qut);//verifica se a quantidade é um int;
	} while (flag == -1 || flag1 != 1);
	quant = stoi(qut);
	param(flag, &r, &p1, &p2, &g1, &g2);

	for (i = 0; i < quant; i++) {
		a.acrescentar(namet, r, p1, p2, g1, g2);
	}
	cout << "\nForam Criados: " << quant << "territorios\n";
	return;
}

//Quando o comando <Carrega> e chamado mais que uma vez faz reset aos vectores de territorios
void remover() {
	
	a.limpar();
	ini.clean();
	resetIderr();
	ini.resetArmy();
}

//Mostra toda informação do jogo
void listaterr(int al) {
	char opc;
	int opp = 0;
	string consulta;
	do {
		cout << "\nDeseja listar um Territorio(U) ou todos(T): U//T: ";
		cin >> opc;
	} while (opc != 'U' && opc != 'T');
	if (opc == 'T') {
		cout << ini.getAsString();
		cout << " Ultimo numero aleatorio: " << al << endl << endl;
		cout << a.getAsString() << endl;
	}else
		if (opc == 'U') {
			do {
				cout << "Imperio ou Mundo? ";
				cin >> consulta;
				if (consulta == "Imperio") {
					cout << ini.getAsString() << endl;
					opp = 1;
				}
				if (consulta == "Mundo") {
					cout << a.getAsString() << endl;
					opp = 1;
				}
			} while (opp == 0);
		}
}


//Le os comandos de um ficheiro de texto em sequencia e devolve o comando pra execucao
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
	cout << "\n Foi lido o comando: " << cmd << endl;
	fich1.close();

	return cmd;
}

//Cria uma serie de territorios a partir de um ficheiro de texto
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
	cout << "\n Foram Criados: " << cont << " territorios\n\n";
	fich1.close();
}


//Verifica se o comando Digitado existe ou foi mal escrito
int verificaCom(vector<string> cm, string t) {
	int cont = 0;
	for (vector<string>::const_iterator it = cm.begin();
		it != cm.end(); ++it) {
		if (*it == t) {
			return cont;
		}cont++;
	}
	cout << "\n Comando nao existe ou foi mal Escrito.\n";
	cout << " Exemplo: Carrega // Cria\n";
	return -1;
}

//Verifica se o Tipo de territorio a ser criado existe ou foi mal digitado
int verificaTipo(string t) {
	int cont = 0;
	vector<string> ter = { "Planicie","Montanha", "Fortaleza", "Mina", "Duna", "Castelo", "Refugio", "Pescaria" };
	for (vector<string>::const_iterator it = ter.begin();
		it != ter.end(); ++it) {
		if (*it == t) {
			return cont;
		}cont++;
	}
	cout << "\n Tipo nao existe ou foi mal Escrito.\n";
	cout << "\n Exemplo: Montanha // Planicie\n";
	return -1;
}

//Verifica se a quantidade a ser criada e um numero inteiro
int verificaQuant(string qt) {
	int i, res = 1;
	for (i = 0; i < qt.size(); i++) {
		if (qt[i] < '0' || qt[i]> '9')
			res = 0;
	}
	if (res == 0)
		cout << "\n Numero Invalido\n";
	return res;
}

//Copia os dados de um territorio depois apaga do vector; Adiciona um novo territorio ao imperio com os dados copiados
int transferTerr(string nometerr) {
	string name;
	int confirm;
	int res, pr1, pr2, g1, g2;
	confirm = a.remove1(nometerr, &res, &pr1, &pr2, &g1, &g2);
	if (confirm == 1) {
		ini.conquist(nometerr, res, pr1, pr2, g1, g2);
		return 1;
	}
	return 0;
}

//Funcao principal de conquista pede ao utilizador o territorio a conquistar
//verifica se existe, Gera o numero aleatorio para a funcao 
//Informa o utilizador do resultado da operação , atualiza os valores e retorna o numero aleatorio gerado
int conquiterr() {
	initRandom();
	string nTer;
	int resT = 0;
	int flag, nAle = 0, arma, checkT;
	do {
		cout << "\n Qual o territorio que deseja conquistar: \n";
		cin >> nTer;
		flag = a.verificavector(nTer, &resT);
		if (flag == 0) {
			cout << "\n O Territorio escolhido nao existe\n";
		}
	} while (flag == 0);
	nAle = intUniformRnd(0, 6);
	arma = nAle;
	arma += ini.getArmy();
	if (arma > resT) {
		checkT = transferTerr(nTer);
		if (checkT == 1) {
			cout << "\n Territorio: " << nTer << " foi conquistado\n";
			ini.setPontos();
		}
			
	}
	else {
		cout << "\n Territorio: " << nTer << " resistiu ao ataque\n";
		ini.setArmy();
	}
	return nAle;
}

//Funcao que devolve os parametros iniciais par a criacao de territorios conforme o tipo
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
