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
	int res ;
	int prod ;
	int ouro ;
	int pontos;
public:

	territor(const string name, int r, int p, int g, int pt);
	~territor();
	int getRes()const;
	string getNome()const;
	string getAsString()const;
};


#endif
