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

//Constantes dos pre�os:
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
	int peso = 0;	//variavel armazenar� o peso quando se souber os objetos
	int valor = 0;	//variavel armazenar� o pre�o quando se souber os objetos

	//Chama testBit para testar cada bit do numero passado.

	//Fun��o poderia ser altamente simplificada utilizando um for.
	//Os if's a seguir s�o para adicionar os pessoas e o valor definido pela tabelha contida no trabalho
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
	para resolver o problema do espa�o depois do $, utiliza-se a forma. 
	cout << right; cout.width(3); cout << "$"+to_string(valor) << " \xC4 ";
	Tambem deve-se adicionar o #include <string>
	*/
	cout << "$";
	cout << right; cout.width(3); cout << valor << " \xC4 ";
	cout << right; cout.width(2); cout << peso << "Kg" << " \xC4 ";

	//Teste para retornar se o peso � ou n�o inferior ao limite de peso maximo da mochila.
	if (peso <= P_MOCHILA_MAX) {
		return true;
	}
	else {
		return false;
	}
}

unsigned short cruzPtUnic(unsigned short n1, unsigned short n2) {
/*
					<--		Explica��o do principio usado	 -->

Patindo do principio que um numero qualquer � formado por bits, pode-se ent�o obter os bits da posi��o
1 ate 8 da primeira solu��o, e depois os bits da posi��o de 9 � 16 da segunda solu��o, determinado esses 
numeros por um AND, � realizado uma soma dos inteiros resultantes de cada bit. Ou seja deve-se realizar 
uma mascara que receba um bit, que se desloca para a esqueda, sendo esse controle controlado pelo o padr�o
de 1 ate 8 e de 9 ate 16. 
Para cada retorno positivo ir� ser realizado a soma dos numeros resultantes dos binario e o mesmo representar� 
os binarios de 1 ate 8 de uma solu��o e 9 ate 16 da outra solu��o. Apos isso deve-se realizar a soma de ambos 
os valores.

Exemplo: 2 cujo binario � 10 e 1 cujo binario � 01, quando somados resultam em 3, cujo binario � 11.

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

Utilizando a fun��o XOR como mecionado os testes de ligado e desligado nesta duas fun��es em especifico se torna inutil,
pois a utiliza��o de teste so serve para o caso de quando as fun��es de binarias apenas ligam e desligam o bit, ou seja,
a fun��o ligar bit apenas liga, e somente liga, mesmo se o bit ja estiver ligado, e a fun��o deligar bit so deliga, mesmo que o o bit
ja esteja desligado.

Ou seja, utilizando-se o XOR, economiza-se 3 if's desnecess�rio, pela caracteristica de nao ser necessario saber se o bit est� ligado ou
desligado, o XOR vai sempre ir� inverter os bits.

*/
unsigned short mutSimples(unsigned short n1) {
	unsigned short res;//variavel resultante

	//se estiver bit = 1 entao coloque o bit = 0; se o bit = 0 coloque o bit = 1.

	//se o bit estiver ligado, desligue com a fun��o desligar bit.
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

	//se o bit estiver ligado, desligue com a fun��o desligar bit.
	//senao o bit esta desligado, entao desligue o bit
	//repete-se para as 2 posi��es de bits, 3 e 12, come�ando a contar a partir do 0.

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