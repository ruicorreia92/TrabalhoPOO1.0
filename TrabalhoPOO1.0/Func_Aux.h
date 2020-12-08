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

void acrecentaterr();
void remover();
void listaterr(int al);
int conquiterr();
void criadoficheiro(string namef);
string leComandos(string namef, int* it);
int verificaTipo(string t);
int verificaQuant(string qt);
void param(int tipo, int* r, int* p1, int* p2, int* g1, int* g2);
int verificaCom(vector<string> cm, string t);

#endif // !
