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


string Mundo::getAsString()const {
	ostringstream oss;

	oss << "\n Nome " << nome
		<< " tem " << territ.size() << " territorios \n";

	for (vector<territor>::const_iterator it = territ.begin();
		it != territ.end(); ++it) {
		oss << it->getAsString() << endl;
	}

	return oss.str();
}

string Mundo::getNome()const {
	return nome;
}

Mundo::~Mundo() {
	cout << " Destruido: " << getNome() << endl;
}