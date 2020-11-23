#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <climits>
#include "Mundo.h"
#include "Territor.h"


using namespace std;


Mundo::Mundo(string nome1) : nome(nome1) {
    
}

void Mundo::acrescentar(const string name, int res, int prod, int gold, int pontos) {
  
    territ.push_back(territor(name, res, prod, gold, pontos));
}


string Mundo::getAsString()const {
    ostringstream oss;

    oss << "\n nome " << nome
        << " tem " << territ.size() << " territ \n";

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
    cout << " Destruido: " << getNome();
}