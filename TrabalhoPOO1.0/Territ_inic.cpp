#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <climits>
#include <stdlib.h>
#include<stdio.h>
#include "Territ_inic.h"


using namespace std;

int Idterr = 1;
char Idund = '_';
string s;

Territ_inic::Territ_inic(const string name, int r, int p1, int g1, int pt) {
	ostringstream ostr;
	ostr << nome;
	s = ostr.str();

	nome = name + Idund + s;
	res = r;
	prod1 = p1;
	ouro1 = g1;
	pontos = pt;
}

Territ_inic::~Territ_inic() {
	
	/*cout << "destruido:" << getNome();*/

}
string Territ_inic::getNome()const {

	return nome;
}
int Territ_inic::getRes()const {

	return res;
}

/*string Territ_inic::getAsString()const {
	ostringstream oss;
	oss << "\nNome: " << nome
		<< "\nResistencia: " << res
		<< "\nProdutos1: " << prod1
		<< "\nGold1: " << ouro1 
	return oss.str();
} */ 

string Territ_inic::getAsString()const {
	ostringstream oss;

	oss << "\nNome: " << nome
		<< "\nResistencia: " << res
		<< "\nProdutos1: " << prod1
		<< "\nGold1: " << ouro1
		<< "\nPontos: " << pontos
		<< " tem " << terrconqui.size() << " territorios \n";

	for (vector<territor>::const_iterator it = terrconqui.begin();
		it != terrconqui.end(); ++it) {
		oss << it->getAsString() << endl;
	}

	return oss.str();
}
