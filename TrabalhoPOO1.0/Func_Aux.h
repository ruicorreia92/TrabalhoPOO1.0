#ifndef FUNC_AUX_H
#define FUNC_AUX_H

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <climits>
#include <stdlib.h>
#include<stdio.h>
#pragma once
#include "Mundo.h"
#include "Territor.h"

using namespace std;

int escolheOpcao(vector<string> opcoes);
int lerInt(string msg);
void acrecentaterr();
void listaterr();
void leficheiro(string namef);
int verificaTipo(string t);
int verificaQuant(string qt);
void param(int tipo, int *r, int *p1, int *p2, int *g1, int *g2);

#endif // !
