#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <climits>
#include <stdlib.h>
#include<stdio.h>
#include "Mundo.h"
#include "Territor.h"


using namespace std;


Mundo::Mundo(string nome1) : nome(nome1) {

}

void Mundo::acrescentar(const string name, int res, int prod1, int prod2, int gold1, int gold2) {

	territ.push_back(territor(name, res, prod1, prod2, gold1, gold2));
}

void Mundo::limpar() {

	territ.clear();
	
}

string Mundo::getAsString()const {
	ostringstream oss;

	oss << "\n Nome: " << nome
		<< " Tem " << territ.size() << " territorios \n";

	for (vector<territor>::const_iterator it = territ.begin();
		it != territ.end(); ++it) {
		oss << it->getAsString() << endl;
	}

	return oss.str();
}


int Mundo::verificavector(string str, int *resis) {

	for (vector<territor>::const_iterator it = territ.begin(); it != territ.end(); ++it) {
		if (it->getNome() == str) {
			*resis = it->getRes();
			return 1;
		}
	}
	return 0;
}

int Mundo::remove1(string namet,int *r, int *p1, int *p2, int *gd1, int *gd2) {

	for (vector<territor>::const_iterator it = territ.begin(); it != territ.end(); ++it) {
		if (it->getNome() == namet) {
			*r = it->getRes();
			*p1 = it->getP1();
			*p2 = it->getP2();
			*gd1 = it->getG1();
			*gd2 = it->getG2();
			territ.erase(it);
			return 1;
		}
	}return 0;

}

string Mundo::getNome()const {
	return nome;
}

Mundo::~Mundo() {
	cout << " Destruido: " << getNome() << endl;
}