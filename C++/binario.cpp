/*
		<--		Explicação do principio usado	 -->
Pecebi que utilizando da comparação com o operador &. pode-se
obter um numero equivalente a a um binario especifico.
	ex:
		4  = 0100;
		8  = 1000;
		10 = 1010;

		10 & 8 = 8;
		1010 and 1000 = 1000;

Peceba que ele leva em consideração os binarios do numero 8 e 10
e compara cada coluna em questão comparando bit a bit. O retorno
é equivalente a uma operação AND entre os dois binarios.
*/

#define var 1

unsigned short andBit(unsigned short n1, unsigned short n2) {
	unsigned short res;		//variavel que receberá o resultado

	res = (n1 & n2);//operação "and" binaria.

	return res;		//retorna o resultado da operação
}

unsigned short orBit(unsigned short n1, unsigned short n2) {
	unsigned short res;		//variavel que receberá o resultado

	res = (n1 | n2);//Operação "or"

	return res;
}

/*<------------------------------------------------------------------------------------------------->
	As operações ligar e desligar bit ao meu ver sao desnecessarias, ja que a função XOR, realiza a
	troca dos bits de maneita que se estiver ligado desligue, e se estiver deligado desligue.
	   Tabela verdade
		A	B	XOR
		0	0	 0
		0	1	 1
		1	0	 1
		1	1	 0
*/

unsigned short ligBit(unsigned short n1, unsigned short posic) {
	unsigned short res;//variavel que receberá o resultado e uma variavel binaria.
	
	//rever o problema com o operador orBit
	res = orBit(n1, (var << posic));	//Operação "or" com a mascara.

	return res;
}

unsigned short desBit(unsigned short n1, unsigned short posic) {
	unsigned short res;//variavel que receberá o resultado, e uma variavel binaria.

	res = andBit(n1, ~(var << posic));//Operação "and" com a mascara negada.

	return res;
}
//<------------------------------------------------------------------------------------------------->

bool testBit(unsigned short n1, unsigned short posic) {
	//Se o numero inicial for maior que o numero com o bit desligado, significa que o bit em questao tem como valor bit = 1, se nao bit = 0.
	if (n1 > desBit(n1, posic)) {
		return true;//retorna 1
	}
	else {
		return false;//retorna 0
	}
}

unsigned short lowBit(unsigned short n1) {
	unsigned short res = 0;
	/*
	função equivalente a de baixo utilizando um for.
	//retirar esse for
	for (int i = 0; i < 8; i++) {
			res += andBit(n1, (var << i));//move o binario pelas colunas
	}
	*/
	
	//Utilizando um for retira-se essa repetição desencessaria desses elementos a baixo
	
	/*
	Recebe o somatorio binario dos elementos, partindo do principio que o somatorio das mascaras que contem 1, nao interem no
	valor final. por exemplo:
	mascara 1 = 0000000000000001
	mascara 2 = 0000000000000010
	mascara 3 = 0000000000000100
	mascara 4 = 0000000000001000
	mascara 5 = 0000000000010000
	...
	---------------------------- +  //somando tudo.
	res		  = 0000000000011111	//somente se a operação AND retornar positivo a mascara é somada.
	*/

	res += andBit(n1, (var << 0));
	res += andBit(n1, (var << 1));
	res += andBit(n1, (var << 2));
	res += andBit(n1, (var << 3));
	res += andBit(n1, (var << 4));
	res += andBit(n1, (var << 5));
	res += andBit(n1, (var << 6));
	res += andBit(n1, (var << 7));

	return res;
}

unsigned short hightBit(unsigned short n1) {
	unsigned short res = 0;
	//for para alterar o bit

	/*
	função equivalente a de baixo utilizando um for.
	//retirar esse for
	for (int i = 8; i < 16; i++) {
		res += andBit(n1, (var << i));//move o binario pelas colunas
	}
	*/

/*
	Recebe o somatorio binario dos elementos, partindo do principio que o somatorio das mascaras que contem 1, nao interem no
	valor final. por exemplo:
	mascara 1 = 0000000000000001
	mascara 2 = 0000000000000010
	mascara 3 = 0000000000000100
	mascara 4 = 0000000000001000
	mascara 5 = 0000000000010000
	...
	---------------------------- +  //somando tudo.
	res		  = 0000000000011111	//somente se a operação AND retornar positivo a mascara é somada.
*/
	res += andBit(n1, (var << 8));
	res += andBit(n1, (var << 9));
	res += andBit(n1, (var << 10));
	res += andBit(n1, (var << 11));
	res += andBit(n1, (var << 12));
	res += andBit(n1, (var << 13));
	res += andBit(n1, (var << 14));
	res += andBit(n1, (var << 15));

	return res;
}
