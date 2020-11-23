#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <climits>
#include "Territor.h"

int Idterr = 1;
char Idund = '_';
string s;


using namespace std;

territor::territor(const string name, int r, int p, int g, int pt) {
	ostringstream ostr;
	ostr << Idterr;
	s = ostr.str();

	nome = name +Idund + s;
	res = r;
	prod = p;
	ouro = g;
    pontos = pt;
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
		<< "\nProdutos: " << prod
		<< "\nGold: " << ouro << endl;
	return oss.str();
}
