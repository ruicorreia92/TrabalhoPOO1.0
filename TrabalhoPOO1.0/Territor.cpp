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

	nome = name + Idund + s;
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
int territor::getP1()const {

	return prod1;
}
int territor::getP2()const {

	return prod2;
}
int territor::getG1()const {

	return ouro1;
}
int territor::getG2()const{

	return ouro2;
}


string territor::getAsString()const {
	ostringstream oss;
	oss << "\n Nome: " << nome
		<< "\n Resistencia: " << res
		<< "\n Produtos1: " << prod1
		<< "\n Produtos2: " << prod2
		<< "\n Gold1: " << ouro1
		<< "\n Gold2: " << ouro2 << endl;
	return oss.str();
}
