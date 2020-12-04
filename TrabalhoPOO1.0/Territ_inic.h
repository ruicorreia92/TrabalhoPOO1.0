#ifndef TERRIT_INIC_H
#define TERRIT_INIC_H



#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <climits>
#include <stdlib.h>
#include<stdio.h>
#include "Mundo.h"
#include "Territ_inic.h"
#include "Territor.h"
#pragma once

using namespace std;

class Territ_inic
{   
	vector<territor> terrconqui;
	string nome;
	int res;
	int prod1;
	int ouro1;

public:

	Territ_inic(const string name, int r, int p1,  int g1);
	~Territ_inic();
	int getRes()const;
	string getNome()const;
	string getAsString()const;
};

#endif // !TERRIT_INIC_H