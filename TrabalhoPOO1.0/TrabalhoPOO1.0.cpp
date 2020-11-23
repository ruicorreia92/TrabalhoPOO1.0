// TrabalhoPOO1.0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Add RuiCorreia

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <climits>
#include "Mundo.h"
#include "territor.h"
#include "Func_Aux.h"

using namespace std;
//vamos ver se e desta

int main() {
	{
		vector<string> opcoes = { "Sair",
			"Acrescentar Territorio",
			"Mostrar Territorios" };

		Mundo a("Mundo_1");

		int opcao = 0;
		do {
			opcao = escolheOpcao(opcoes);
			switch (opcao) {
			case 0: // Sair
				cout << "\nSair\n";
				break;
			case 1: // Acrescentar rectangulo
			{
				a.acrescentar("Planicie", 8, 8, 8, 8);
				//desenho.acrescentar(1,2,3,4);
			}
			break;
			case 2: // Listar informacao do desenho
			{
				cout << a.getAsString() << endl;
			}
			break;
			case 3: // Ler comandos
			{
				void ler_comandos();
			}
			break;
			}

		} while (opcao != 0);
	}
	cin.get();
}





//int main()
//{    
//    Mundo a("Mundo_1");
//
//
//
//
//    a.acrescentar("Ilha", 9, 8, 7, 6);
//    a.acrescentar("Planicie", 8, 8, 8, 8);
//    a.acrescentar("Duna", 7, 7, 7, 7);
//    a.acrescentar("Castelo", 6, 6, 6, 6);
//
//    cout << a.getAsString();
//}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
