#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <climits>
#include <stdlib.h>
#include<stdio.h>
#include "Territor.h"

int Idterr = 1;
char Idund = '_';
string s;


using namespace std;

territor::territor(const string name, int r, int p1, int p2, int g1, int g2) {
	ostringstream ostr;
	ostr << Idterr;
	s = ostr.str();

	nome = name +Idund + s;
	res = r;
	prod1 = p1;
	prod2 = p2;
	ouro1 = g1;
    ouro2 = g2;
	Idterr++;
}

territor::~territor() {
	/*cout << "destruido:" << getNome();*/

}
string territor::getNome()const {

	return nome;
}
int territor::getRes()const {

	return res;
}

string territor::getAsString()const {
	ostringstream oss;
	oss << "\nNome: " << nome
		<< "\nResistencia: " << res
		<< "\nProdutos1: " << prod1
		<< "\nProdutos2: " << prod2
		<< "\nGold1: " << ouro1 
		<< "\nGold2: " << ouro2 << endl;
	return oss.str();
}
