// TrabalhoPOO1.0.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <climits>
#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
#include "Mundo.h"
#include "Territ_inic.h"
#include "territor.h"
#include "Func_Aux.h"
#include "utilis.h"

using namespace std;



int main() {

	initRandom();

	string aux, aux1, aux2, aux3;
	int opcao = 0;
	int nalet = 0;
	int it = 0, cont, flag = 0;
	vector<string> comandos = { "Carrega","Cria","Conquista","Passa", "Maisouro",
	   "Maisprod", "Maismilitar", "Adquire", "Lista", "Avanca",
	   "Grava", "Ativa", "Apaga", "Toma", "Modifica", "Fevento", "Sair" };

	cout << "\n Bem Vindo ao\n"
		<< "\n    IMPERIO\n\n";
	system("PAUSE");
	/*cout << "Prima uma tecla pra continuar";
	aux3 =	getchar();*/

	do {
		cout << "\n Digite um Comando: \n";
		cin >> aux1;
		opcao = verificaCom(comandos, aux1);//Verifica se o comando existe ou foi escrito corretamente

		if (opcao == 0) {//se escolher o comando Carrega
			do {
				if (flag == 1) {
					remover();// Se ja foi lido o Comando <Carrega> se for novamente chamado faz reset aos valores e Vectores 
				 }
				/*cout << "Prima uma tecla pra continuar";
				aux3 =	getchar();*/
				system("PAUSE");//Prima uma tecla pra continuar
				//getc(stdin);
				
				aux2 = leComandos("comandos.txt", &it);//Le os comandos de um ficheiro
			

				cont = verificaCom(comandos, aux2);
				switch (cont) {
			
				case 1: // <Cria>  Cria Territorios lidos de um ficheiro de texto
				{

					criadoficheiro("ficheiro.txt");

				}
				break;
				case 2: // <Conquista>  Inicia a tentativa de conquista
				{
					nalet = conquiterr();//Se correr bem atualiza os vectores ; Remove o territorio conquistado e insere em outor vector
				}
				break;
				case 8: // <Lista>  Mostra no ecra a Informa��o do territorio inicial e dos territorios do mundo
				{
					listaterr(nalet);
				}
				break;
				case 16: // <sair>
				{
					cout << "\n Fim da leitura de comandos\n";
					flag = 1;
				}
				break;
				}

			} while (cont != 16);
			
			it = 0;
			opcao = -1;
		}

		switch (opcao) {
	
		case 1: // Cria
		{
			acrecentaterr();//Acrecenta territorios manualmente

		}
		break;
		case 2: // <Conquista>  Inicia a tentativa de conquista
		{
			nalet = conquiterr();
		}
		break;
		case 8: // <Lista>  Mostra no ecra a Informa��o do territorio inicial e dos territorios do mundo
		{
			listaterr(nalet);
		}
		break;
		case 16: // sair
		{

		}
		break;
		}

	} while (opcao != 16);

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
