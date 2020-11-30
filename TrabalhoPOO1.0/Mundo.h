#ifndef MUNDO_H
#define MUNDO_H

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <climits>
#pragma once
#include "Mundo.h"
#include "Territor.h"

using namespace std;

class Mundo
{
	vector<territor> territ;
	string nome;
public:
	Mundo(string nome);

	// acrescenta um territorio
	void acrescentar(const string name, int res, int prod1, int prod2, int gold1, int gold2);
	//retorna o nome
	string getNome()const;
	// retorna uma string com a descricao do objecto
	string getAsString()const;
	~Mundo();
};

#endif