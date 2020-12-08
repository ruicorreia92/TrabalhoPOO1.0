#ifndef TERRIT_INIC_H
#define TERRIT_INIC_H



#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <climits>
#include <stdlib.h>
#include<stdio.h>
#include "Territor.h"
#pragma once

using namespace std;

class Territ_inic
{   
	vector<territor> terrconqui;
	string nomeIni;
	int res;
	int army;
	int prod1;
	int ouro1;
	int pontos;

public:

	void clean();

	Territ_inic(string nome2, int r, int amy, int p1, int g1, int ptt);

	// acrescenta o territorio conquistado ao Imperio
	void conquist(const string name, int res, int prod1, int prod2, int gold1, int gold2);
	//retorna o nome
	string getNome()const;
	void setArmy();
	void resetArmy();
	// retorna a potencia militar do terrirtorio inicial
	int getArmy()const;
	
	// retorna uma string com a descricao do objecto
	string getAsString()const;
	void setPontos();
	~Territ_inic();

};

#endif // !TERRIT_INIC_H