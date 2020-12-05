#ifndef TERRITOR_H
#define TERRITOR_H

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <climits>
#pragma once

using namespace std;

class territor
{
	string nome;
	int res;
	int prod1;
	int prod2;
	int ouro1;
	int ouro2;
public:

	territor(const string name, int r, int p1, int p2, int g1, int g2);
	~territor();
	int getRes()const;
	int getP1()const;
	int getP2()const;
	int getG1()const;
	int getG2()const;
	string getNome()const;
	string getAsString()const;
};


#endif
