/*
	Programa do trabalho pratico da disciplina de programa��o.
	Autor: Arthur Vitor Matias de Oliveira
	Professor: Judson
	Data: 14 - 11 - 18
*/

//biblioteca padr�o de input e output
#include <iostream>
#include <Windows.h>
using namespace std;

//chama os dois arquivos de cabe�ario criados.
#include "genetico.h"
#include "binario.h"

//Defini��o de cores
#define COR_DEFAULT 7
#define COR_CORRECT 2
#define COR_ERRO 12

/*
						<--		Roteiro		-->
	1 passo:
	-> cruzamento de ponto �nico entre as duas primeiras solu��es fornecidas pelo
	usu�rio.
	-> cruzamento aritm�tico entre a terceira e quarta solu��o.
	-> muta��o simples sobre a quinta solu��o.
	-> muta��o dupla sobre a sexta e �ltima solu��o.

	OBS: O resultado sevir� para o passo 2.

	2 passo:
	->Criar cada fun��o das opera��es binarias
*/

/*
					<--		Obeserva��es	-->
	Os operadores << e >> movem os bits dentro do conjunto de bits.
		ex:
			cout << sol1 << endl; // valor de saida = 1 ou ...00001
			sol1 = (sol1 << 1);// altera o local do bit
			cout << sol1; // o valor da saida deve ser ...00010 ou 2;

	O operador 'and' ou '&' funciona como na logica boleana comun s� que para bits.
	ela atera os bits de forma que permanece 1 apenas se o bit das duas
	variaveis forem 1, no resto se aplica o 0.
		ex:
			001 & 011 = 001.

	As variaveis s�o para definir um conjunto de bits aleatorios, que nesse casso vai ate
	16 bits. isso ser� processado pelo programa para retornar 1 e 0 para saber se o profuto
	estar� ou nao na mochila.

	O cruzamento de ponto unico preve copiar os primeiros 8 bits de uma
	solu��o e os outros 8 bits da outra, seguindo de uma soma.
*/

/*
						<--		OBS		-->
	O codigo foi alterado, retirando todos loop For de todas as fun��es.
*/

int main() {

	//variaveis que alocaram as solu��es
	unsigned short sol1, sol2, sol3, sol4, sol5, sol6;

	//HANDLE para alterar a cor do "ok" e do "x". 
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	cout << "Entre com 6 solucoes iniciais (numeros entre 0 e 65535):\n";
	//recebe todos os valores
	cin >> sol1;
	cin >> sol2;
	cin >> sol3;
	cin >> sol4;
	cin >> sol5;
	cin >> sol6;

	cout << "\n";
	
	//Escreve na tela o resultado, avaliando o retorno da fun��o avaliar e exibindo o 'x' ou 'ok' depedendo do retorno de funcAvaliar().

	cout << "  Resultado da Avaliacao \n";
	cout << " ------------------------\n";
	if (funcAvaliar(sol1) == true) {
		SetConsoleTextAttribute(hConsole, COR_CORRECT);	//coloca a cor verde no elemento "Ok".
		cout << "OK" << endl;
		SetConsoleTextAttribute(hConsole, COR_DEFAULT);	//retorna a cor padrao
	}
	else {
		SetConsoleTextAttribute(hConsole, COR_ERRO);	//coloca a cor vermelha no elemento "X".
		cout << "X" << endl;
		SetConsoleTextAttribute(hConsole, COR_DEFAULT);	//retorna a cor padrao
	}
	if (funcAvaliar(sol2) == true) {
		SetConsoleTextAttribute(hConsole, COR_CORRECT);	//coloca a cor verde no elemento "Ok".
		cout << "OK" << endl;
		SetConsoleTextAttribute(hConsole, COR_DEFAULT);	//retorna a cor padrao
	}
	else {
		SetConsoleTextAttribute(hConsole, COR_ERRO);	//coloca a cor vermelha no elemento "X".
		cout << "X" << endl;
		SetConsoleTextAttribute(hConsole, COR_DEFAULT);	//retorna a cor padrao
	}
	if (funcAvaliar(sol3) == true) {
		SetConsoleTextAttribute(hConsole, COR_CORRECT);	//coloca a cor verde no elemento "Ok".
		cout << "OK" << endl;
		SetConsoleTextAttribute(hConsole, COR_DEFAULT);	//retorna a cor padrao
	}
	else {
		SetConsoleTextAttribute(hConsole, COR_ERRO);	//coloca a cor vermelha no elemento "X".
		cout << "X" << endl;
		SetConsoleTextAttribute(hConsole, COR_DEFAULT);	//retorna a cor padrao
	}
	if (funcAvaliar(sol4) == true) {
		SetConsoleTextAttribute(hConsole, COR_CORRECT);	//coloca a cor verde no elemento "Ok".
		cout << "OK" << endl;
		SetConsoleTextAttribute(hConsole, COR_DEFAULT);	//retorna a cor padrao
	}
	else {
		SetConsoleTextAttribute(hConsole, COR_ERRO);	//coloca a cor vermelha no elemento "X".
		cout << "X" << endl;
		SetConsoleTextAttribute(hConsole, COR_DEFAULT);	//retorna a cor padrao
	}
	if (funcAvaliar(sol5) == true) {
		SetConsoleTextAttribute(hConsole, COR_CORRECT);	//coloca a cor verde no elemento "Ok".
		cout << "OK" << endl;
		SetConsoleTextAttribute(hConsole, COR_DEFAULT);	//retorna a cor padrao
	}
	else {
		SetConsoleTextAttribute(hConsole, COR_ERRO);	//coloca a cor vermelha no elemento "X".
		cout << "X" << endl;
		SetConsoleTextAttribute(hConsole, COR_DEFAULT);	//retorna a cor padrao
	}
	if (funcAvaliar(sol6) == true) {
		SetConsoleTextAttribute(hConsole, COR_CORRECT);	//coloca a cor verde no elemento "Ok".
		cout << "OK" << endl;
		SetConsoleTextAttribute(hConsole, COR_DEFAULT);	//retorna a cor padrao
	}
	else {
		SetConsoleTextAttribute(hConsole, COR_ERRO);	//coloca a cor vermelha no elemento "X".
		cout << "X" << endl;
		SetConsoleTextAttribute(hConsole, COR_DEFAULT);	//retorna a cor padrao
	}

	cout << " ------------------------\n";

	//chama uma fun��o dentro de uma fun��o
	//Exibe os valores do passo 1
	if (funcAvaliar(cruzPtUnic(sol1, sol2)) == true) {
		SetConsoleTextAttribute(hConsole, COR_CORRECT);	//coloca a cor verde no elemento "Ok".
		cout << "OK" << endl;
		SetConsoleTextAttribute(hConsole, COR_DEFAULT);	//retorna a cor padrao
	}
	else {
		SetConsoleTextAttribute(hConsole, COR_ERRO);	//coloca a cor vermelha no elemento "X".
		cout << "X" << endl;
		SetConsoleTextAttribute(hConsole, COR_DEFAULT);	//retorna a cor padrao
	}
	if (funcAvaliar(cruzArit(sol3, sol4)) == true) {
		SetConsoleTextAttribute(hConsole, COR_CORRECT);	//coloca a cor verde no elemento "Ok".
		cout << "OK" << endl;
		SetConsoleTextAttribute(hConsole, COR_DEFAULT);	//retorna a cor padrao
	}
	else {
		SetConsoleTextAttribute(hConsole, COR_ERRO);	//coloca a cor vermelha no elemento "X".
		cout << "X" << endl;
		SetConsoleTextAttribute(hConsole, COR_DEFAULT);	//retorna a cor padrao
	}
	if (funcAvaliar(mutSimples(sol5)) == true) {
		SetConsoleTextAttribute(hConsole, COR_CORRECT);	//coloca a cor verde no elemento "Ok".
		cout << "OK" << endl;
		SetConsoleTextAttribute(hConsole, COR_DEFAULT);	//retorna a cor padrao
	}
	else {
		SetConsoleTextAttribute(hConsole, COR_ERRO);	//coloca a cor vermelha no elemento "X".
		cout << "X" << endl;
		SetConsoleTextAttribute(hConsole, COR_DEFAULT);	//retorna a cor padrao
	}
	if (funcAvaliar(mutDupla(sol6)) == true) {
		SetConsoleTextAttribute(hConsole, COR_CORRECT);	//coloca a cor verde no elemento "Ok".
		cout << "OK" << endl;
		SetConsoleTextAttribute(hConsole, COR_DEFAULT);	//retorna a cor padrao
	}
	else {
		SetConsoleTextAttribute(hConsole, COR_ERRO);	//coloca a cor vermelha no elemento "X".
		cout << "X" << endl;
		SetConsoleTextAttribute(hConsole, COR_DEFAULT);	//retorna a cor padrao
	}

	system("pause");
	return 0;
}