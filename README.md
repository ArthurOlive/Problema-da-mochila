<h1 align="center"> Algoritmo da mochila em python</h1>
<p align= "justify">
  Joãozinho, apesar de estar no início do curso de computação, já andou pesquisando e se deparou com um problema interessante de otimização chamado de Problema da Mochila. O problema consiste em levar em uma mochila os objetos que somem o maior valor possível, mas sem extrapolar sua capacidade de peso. Cada objeto possui um peso e um valor associado.
Esse
</p>
<p align= "center">
<img src="https://github.com/ArthurOlive/Problema-da-mochila/blob/master/git_imgs/mochila.JPG"/>
</p>
<p align= "justify">
Esse problema pode ser resolvido por várias técnicas que incluem programação dinâmica, algoritmos gulosos, e algoritmos genéticos. Como Joãozinho tem interesse pela área de Inteligência Artificial, ele resolveu usar a técnica de algoritmos genéticos.
Joãozinho não será capaz de resolver completamente o problema, pois ele ainda está iniciando o aprendizado de programação de computadores, mas ele já pode construir a base do sistema necessário para a solução.
Vamos assumir que a mochila suporta 20Kg e que temos 16 objetos, cada um com peso e valor mostrados abaixo: Objeto A B C D E F G H I J
</p>
<img src="https://github.com/ArthurOlive/Problema-da-mochila/blob/master/git_imgs/peso_preco.JPG"/>
<p align= "justify">
A solução usando algoritmos genéticos vai representar cada objeto por um bit. Vamos construir sequencias de 16 bits para indicar quais objetos estão na mochila e quais não estão. A sequência abaixo poderia representar uma solução para o problema.
</p>
<img src="https://github.com/ArthurOlive/Problema-da-mochila/blob/master/git_imgs/ex1.JPG"/>
<p align= "justify">
O primeiro bit igual a 1 significa que o objeto A está na mochila, o segundo bit igual a zero
significa que o objeto B não está na mochila, e assim por diante. Cada sequência de 16 bits representa uma solução para o problema. Nem todas as soluções representadas assim são possíveis, muitas vão extrapolar o peso máximo da mochila, outras não representarão a melhor solução. Por essa razão precisamos criar uma função de avaliação de soluções. Dada uma solução, a função deve retornar o valor total da mochila, ou zero, caso o peso máximo seja extrapolado.
Estamos interessados em encontrar a sequência de bits que nos dê uma solução ótima para o problema. A técnica de algoritmos genéticos faz isso através de tentativas. Ela parte de um conjunto inicial de soluções que são fornecidas pelo usuário. No nosso caso, as soluções serão números:
</p>
<img src = "https://github.com/ArthurOlive/Problema-da-mochila/blob/master/git_imgs/saida1.JPG" /> 
<p align= "justify">
Cada número entre 0 e 65535 pode ser armazenado em uma variável inteira positiva com capacidade para 16 bits, fornecendo assim 6 soluções iniciais para o problema. A partir daí aplicaremos alguns operadores genéticos em cima das soluções iniciais para obter novas soluções.
A finalidade dos operadores genéticos é obter uma variação das soluções iniciais com o objetivo de chegar mais próximo de uma solução ótima para o problema. Normalmente os operadores são aplicados sobre soluções “promissoras”, mas aqui aplicaremos eles indiscriminadamente para simplificar o problema.
 </p>
<ol type="1">
  <li>Cruzamento</li>
  <p align= "center">
Ponto único: o cruzamento tipo ponto único gera uma nova solução a partir de duas soluções existentes, copiando parte dos            bits da primeira solução e o restante da segunda solução.
  </p>
  <img src="https://github.com/ArthurOlive/Problema-da-mochila/blob/master/git_imgs/ptUnic.JPG"/>
  <p align= "center">
Aritmético (AND): o cruzamento tipo aritmético gera uma nova solução a partir de duas existentes, usando o bit 1 nas posições em que ambas soluções iniciais sejam 1 e 0, caso contrário.
  </p>
  <img src="https://github.com/ArthurOlive/Problema-da-mochila/blob/master/git_imgs/ptArit.JPG"/>
  <li>Mutação</li>
  <p align= "center">
    Simples: a mutação simples modifica um bit de uma solução existente, obtendo assim uma nova solução.
  </p>
  <img src="https://github.com/ArthurOlive/Problema-da-mochila/blob/master/git_imgs/mutS.JPG"/> 
  <p align= "center">
    Dupla: a mutação dupla tem o mesmo comportamento da simples, mas a nova solução tem dois bits modificados, no lugar de apenas um.
  </p>
    <img src=" https://github.com/ArthurOlive/Problema-da-mochila/blob/master/git_imgs/mutD.JPG"/> 
</ol>
<p align= "center">
Aplicaremos cruzamento de ponto único entre as duas primeiras soluções fornecidas pelo usuário, cruzamento aritmético entre a terceira e quarta solução, mutação simples sobre a quinta solução e, finalmente, mutação dupla sobre a sexta e última solução. Isso significa que após aplicação dos operadores genéticos teremos mais 4 soluções novas para avaliar. A aplicação dos operadores em cima do exemplo inicial resultaria nos seguintes números:
</p>
<img src = "https://github.com/ArthurOlive/Problema-da-mochila/blob/master/git_imgs/saida2.JPG">
<p align= "center">
  Ajude Joãozinho a resolver esse problema. Construa um programa para ler os 6 valores iniciais, aplicar os operadores genéticos e avaliar as soluções obtidas. A saída do programa deve ser formatada e colorida como no exemplo abaixo:
</p>
<img src = "https://github.com/ArthurOlive/Problema-da-mochila/blob/master/git_imgs/exec.JPG">
<h2 align="center">INSTRUÇÕES PARA O PROGRAMA EM C++</h2>
O programa deverá conter uma função para cada uma das tarefas abaixo:
  <ol type = "1">
    <li align = "justify">
    Função de Avaliação: recebe um valor inteiro, exibe o valor e peso total da solução e retorna um booleano indicando se o peso está dentro do limite da mochila;
    </li>
    <li align = "justify">
    Cruzamento Ponto único: recebe dois valores inteiros representando as soluções e retorna um valor inteiro representando o cruzamento de ponto único entre as soluções;
    </li>
    <li align = "justify">
    Cruzamento Aritmético: recebe dois valores inteiros representando as soluções e retorna um valor inteiro representando o cruzamento aritmético entre as soluções;
    </li>
    <li align = "justify">
    Mutação Simples: recebe um valor inteiro representando uma solução e retorna um valor inteiro representando a mutação simples da solução;
    </li>
    <li align = "justify">
    Mutação Dupla: recebe um valor inteiro representando uma solução e retorna um valor inteiro representando a mutação dupla da solução.
    </li>
  </ol>
  <p align = "justify">
  Estas funções devem ser implementadas nos arquivos genetico.h e genetico.cpp. As funções que implementam os operadores genéticos precisarão manipular os bits dos números inteiros. Essa manipulação de bits deve ser feita através de funções separadas, a serem implementadas nos arquivos binario.h e binario.cpp:
  </p>
  <ol type = "1">
    <li align = "justify">
      Ligar Bit: recebe um valor inteiro e a posição do bit a ser ligado, retornando o valor inteiro resultante da modificação do bit;
    </li>
    <li align = "justify">
      Desligar Bit: recebe um valor inteiro e a posição do bit a ser desligado, retornando o valor inteiro resultante da modificação do bit;
    </li>
    <li align = "justify">
      Testar Bit: recebe um valor inteiro e a posição do bit a ser testado, retornando um booleano para indicar se o bit está ou não ligado;
    </li>
    <li>
      AND Binário: recebe dois valores inteiros e retorna um inteiro representando o resultado da operação AND bit a bit entre os números recebidos.
    </li>
    <li align = "justify">
      OR Binário: recebe dois valores inteiros e retorna um inteiro representando o resultado da operação OR bit a bit entre os números recebidos.
    </li>
    <li align = "justify">
      Bits Baixos: recebe um valor inteiro e retorna outro contendo apenas os 8 bits de mais baixa ordem do valor original, com os demais bits colocados para zero.
    </li>
    <li align = "justify">
      Bits Altos: recebe um valor inteiro e retorna outro contendo apenas os 8 bits de ordem mais alta do valor original, com os demais bits colocados para zero.
    </li>
  </ol>
  <p align = "justify">
  O programa final deverá conter cinco arquivos, sendo o arquivo problema.cpp aquele que conterá a função main e se encarregará de ler os dados pelo teclado e exibir os resultados do programa.
  </p>
  <h2 align="center">EXIGÊNCIAS</h2>
  <ol type = "1">
  <li>
    Não é permitido usar variáveis globais
  </li>
  </ol>
    
