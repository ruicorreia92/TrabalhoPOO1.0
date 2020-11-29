// TrabalhoPOO1.0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Add RuiCorreia

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <climits>
#include "Mundo.h"
#include "territor.h"
#include "Func_Aux.h"

using namespace std;
//vamos ver se e desta vez

int main() {

	
	string dois;
	int x, b, c, d;

	
	{
		vector<string> opcoes = { "Sair",
			"Acrescentar Territorio",
			"Mostrar Territorios","Ler Ficheiro" };

		////Abre o ficheiro e verifica se correu bem
		//ifstream fich1("ficheiro.txt");
		//if (!fich1) {
		//	cout << "ocorreu um erro" << endl;
		//	return -1;
		//}
		////

		//////le do ficheiro e acrecenta um territorio ao vector "Mundo a"
		//while (fich1) {
		//	fich1 >> dois >> x >> b >> c >> d;
		//	a.acrescentar(dois, x, b, c, d);
		//}
		//fich1.close();
		//
	 //   //grava os territorios do <vector> no ficheiro de texto
		//ofstream out("ficheiro1.txt");
	 //   out << a.getAsString();
		//out.close();

		int opcao = 0;
		do {
			opcao = escolheOpcao(opcoes);
			switch (opcao) {
			case 0: // Sair
				cout << "\nSair\n";
				break;
			case 1: // Acrescentar territorios
			{  
				acrecentaterr();
				
			}
			break;
			case 2: // Listar informacao do desenho
			{
				listaterr();
			}
			break;
			case 3: // criar do ficheiro
			{   string aux;
				cout << "Digite o nome do ficheiro: ";
				cin >> aux;
				leficheiro(aux);
				
			}
			break;
			}

		} while (opcao != 0);
	}
	cin.get();
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
