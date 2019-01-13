#include <iostream>
using namespace std;

#include "binario.h"

//Constante da mochila
#define P_MOCHILA_MAX 20

//Constantes dos Pesos:
#define pA 12
#define pB 3
#define pC 5
#define pD 4
#define pE 9
#define pF 1
#define pG 2
#define pH 3
#define pI 4
#define pJ 1
#define pK 2
#define pL 4
#define pM 5
#define pN 2
#define pO 4
#define pP 1

//Constantes dos preços:
#define vA 4
#define vB 4
#define vC 8
#define vD 10
#define vE 15
#define vF 3 
#define vG 1
#define vH 1
#define vI 2
#define vJ 10
#define vK 20
#define vL 15
#define vM 10
#define vN 3
#define vO 4
#define vP 12

bool funcAvaliar(unsigned short n1) {
		
	//variaveis para retorno de dado.
	int peso = 0;	//variavel armazenará o peso quando se souber os objetos
	int valor = 0;	//variavel armazenará o preço quando se souber os objetos

	//Chama testBit para testar cada bit do numero passado.

	//Função poderia ser altamente simplificada utilizando um for.
	//Os if's a seguir são para adicionar os pessoas e o valor definido pela tabelha contida no trabalho
	if(testBit(n1, 0) != 0){
		peso += pP;
		valor += vP;
	}

	if (testBit(n1, 1) != 0) {
		peso += pO;
		valor += vO;
	}

	if (testBit(n1, 2) != 0) {
		peso += pN;
		valor += vN;
	}

	if (testBit(n1, 3) != 0) {
		peso += pM;
		valor += vM;
	}

	if (testBit(n1, 4) != 0) {
		peso += pL;
		valor += vL;
	}

	if (testBit(n1, 5) != 0) {
		peso += pK;
		valor += vK;
	}

	if (testBit(n1, 6) != 0) {
		peso += pJ;
		valor += vJ;
	}

	if (testBit(n1, 7) != 0) {
		peso += pI;
		valor += vI;
	}

	if (testBit(n1, 8) != 0) {
		peso += pH;
		valor += vH;
	}

	if (testBit(n1, 9) != 0) {
		peso += pG;
		valor += vG;
	}

	if (testBit(n1, 10) != 0) {
		peso += pF;
		valor += vF;
	}

	if (testBit(n1, 11) != 0) {
		peso += pE;
		valor += vE;
	}

	if (testBit(n1, 12) != 0) {
		peso += pD;
		valor += vD;
	}

	if (testBit(n1, 13) != 0) {
		peso += pC;
		valor += vC;
	}

	if (testBit(n1, 14) != 0) {
		peso += pB;
		valor += vB;
	}

	if (testBit(n1, 15) != 0) {
		peso += pA;
		valor += vA;
	}

	//exibe a mensage na tela.

	cout << right; cout.width(6); cout << n1 << " \xC4 ";
	/*
	para resolver o problema do espaço depois do $, utiliza-se a forma. 
	cout << right; cout.width(3); cout << "$"+to_string(valor) << " \xC4 ";
	Tambem deve-se adicionar o #include <string>
	*/
	cout << "$";
	cout << right; cout.width(3); cout << valor << " \xC4 ";
	cout << right; cout.width(2); cout << peso << "Kg" << " \xC4 ";

	//Teste para retornar se o peso é ou não inferior ao limite de peso maximo da mochila.
	if (peso <= P_MOCHILA_MAX) {
		return true;
	}
	else {
		return false;
	}
}

unsigned short cruzPtUnic(unsigned short n1, unsigned short n2) {
/*
					<--		Explicação do principio usado	 -->

Patindo do principio que um numero qualquer é formado por bits, pode-se então obter os bits da posição
1 ate 8 da primeira solução, e depois os bits da posição de 9 à 16 da segunda solução, determinado esses 
numeros por um AND, é realizado uma soma dos inteiros resultantes de cada bit. Ou seja deve-se realizar 
uma mascara que receba um bit, que se desloca para a esqueda, sendo esse controle controlado pelo o padrão
de 1 ate 8 e de 9 ate 16. 
Para cada retorno positivo irá ser realizado a soma dos numeros resultantes dos binario e o mesmo representará 
os binarios de 1 ate 8 de uma solução e 9 ate 16 da outra solução. Apos isso deve-se realizar a soma de ambos 
os valores.

Exemplo: 2 cujo binario é 10 e 1 cujo binario é 01, quando somados resultam em 3, cujo binario é 11.

um AND entre um binario e uma mascara retorna o valor se e somente se o numero do binario existir.
	
*/

	unsigned short res;

	res = lowBit(n2) + hightBit(n1); //o somatorio dos bits de 0 a 7, do primeiro valor de entrada, somado com os bits de 8 a 15 da segunda entrada

	return res;	//retorna a variavel valor.
}

unsigned short cruzArit(unsigned short n1, unsigned short n2) {
	//logica ja mecionada acima.
	unsigned short res;

	res = andBit(n1, n2);//realiza o "and" binario e retorna o valor pela variavel valor.

	return res;
}

/*
<--------------------------------------------------------------------------------------------------------------------------->
								Explicando um principio extra.

Utilizando a função XOR como mecionado os testes de ligado e desligado nesta duas funções em especifico se torna inutil,
pois a utilização de teste so serve para o caso de quando as funções de binarias apenas ligam e desligam o bit, ou seja,
a função ligar bit apenas liga, e somente liga, mesmo se o bit ja estiver ligado, e a função deligar bit so deliga, mesmo que o o bit
ja esteja desligado.

Ou seja, utilizando-se o XOR, economiza-se 3 if's desnecessário, pela caracteristica de nao ser necessario saber se o bit está ligado ou
desligado, o XOR vai sempre irá inverter os bits.

*/
unsigned short mutSimples(unsigned short n1) {
	unsigned short res;//variavel resultante

	//se estiver bit = 1 entao coloque o bit = 0; se o bit = 0 coloque o bit = 1.

	//se o bit estiver ligado, desligue com a função desligar bit.
	//senao o bit esta desligado, entao desligue o bit
	if (testBit(n1, 9) == 1) {
		res = desBit(n1,9);
	}
	else
	{
		res = ligBit(n1, 9);
	}

	return res;//retornar o numero formado pelos binarios resultantes.
}

unsigned short mutDupla(unsigned short n1) {
	unsigned short res;//variavel resultante

	//se o bit estiver ligado, desligue com a função desligar bit.
	//senao o bit esta desligado, entao desligue o bit
	//repete-se para as 2 posições de bits, 3 e 12, começando a contar a partir do 0.

	if (testBit(n1,3) == 1) {
		res = desBit(n1, 3);
	}
	else
	{
		res = ligBit(n1, 3);
	}
	if (testBit(res,12) == 1) {
		res = desBit(res, 12);	//dessa  vez passa a matriz resultante, para recalcular
	}
	else
	{
		res = ligBit(res, 12);	//dessa  vez passa a matriz resultante, para recalcular
	}
	
	return res;
}
//<--------------------------------------------------------------------------------------------------------------------------->