#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <climits>
#include <stdlib.h>
#include<stdio.h>
#include "Territ_inic.h"
#include "Territor.h"
#include "utilis.h"

using namespace std;



Territ_inic::Territ_inic(string nome2, int r, int amy, int p1, int g1, int ptt) {
	initRandom();
	amy = intUniformRnd(0, 3);

	nomeIni = nome2;
	res = r;
	army = amy;
	prod1 = p1;
	ouro1 = g1;
	pontos = ptt;


}

void Territ_inic::conquist(const string name, int res, int prod1, int prod2, int gold1, int gold2) {

	terrconqui.push_back(territor(name, res, prod1, prod2, gold1, gold2));
}


string Territ_inic::getAsString()const {
	ostringstream oss;

	oss << "\n Nome: " << nomeIni
		<< "\n Resistencia: " << res
		<< "\n Forca Militar: " << army
		<< "\n Produtos: " << prod1
		<< "\n Ouro: " << ouro1
		<< "\n Pontos conquistados: " << pontos
		<< "\n Tem " << terrconqui.size() << " territorios conquistados\n";

	for (vector<territor>::const_iterator it = terrconqui.begin();
		it != terrconqui.end(); ++it) {
		oss << it->getAsString() << endl;
	}

	return oss.str();
}

string Territ_inic::getNome()const {
	return nomeIni;
}

Territ_inic::~Territ_inic() {
	cout << " Destruido: " << getNome() << endl;
}