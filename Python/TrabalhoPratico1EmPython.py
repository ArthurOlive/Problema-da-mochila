#operações binarias

def operatorAnd(op1, op2):
    opR = op1 & op2
    return opR

def  operatorLowBit(op1):
    opR = 0
    opR += operatorAnd(op1, 1)
    opR += operatorAnd(op1, 2)
    opR += operatorAnd(op1, 4)
    opR += operatorAnd(op1, 8)
    opR += operatorAnd(op1, 16)
    opR += operatorAnd(op1, 32)
    opR += operatorAnd(op1, 64)
    opR += operatorAnd(op1, 128)
    return opR

def operatorHightBit(op1):
    opR = 0
    opR += operatorAnd(op1, 256)
    opR += operatorAnd(op1, 512)
    opR += operatorAnd(op1, 1024)
    opR += operatorAnd(op1, 2048)
    opR += operatorAnd(op1, 4096)
    opR += operatorAnd(op1, 8192)
    opR += operatorAnd(op1, 16384)
    opR += operatorAnd(op1, 32768)
    return opR

def operatorPtUnico(op1, op2):
    opR = operatorLowBit(op2) + operatorHightBit(op1)
    return opR

def operatorMutSimples(op1):
    opR = op1 ^ 512
    return opR

def operatorMutDupla(op1):
    opR = op1 ^ 8
    opR = opR ^ 4096
    return opR

def classificacao(op1):
    peso = 0
    preco = 0
    if (operatorAnd(op1, 1) != 0):
        peso += 1
        preco += 12
    if (operatorAnd(op1, 2) != 0):
        peso += 4
        preco += 4
    if (operatorAnd(op1, 4) != 0):
        peso += 2
        preco += 3
    if (operatorAnd(op1, 8) != 0):
        peso += 5
        preco += 10
    if (operatorAnd(op1, 16) != 0):
        peso += 4
        preco += 15
    if (operatorAnd(op1, 32) != 0):
        peso += 2
        preco += 20
    if (operatorAnd(op1, 64) != 0):
        peso += 1
        preco += 10
    if (operatorAnd(op1, 128) != 0):
        peso += 4
        preco += 2
    if (operatorAnd(op1, 256) != 0):
        peso += 3
        preco += 1
    if (operatorAnd(op1, 512) != 0):
        peso += 2
        preco += 1
    if (operatorAnd(op1, 1024) != 0):
        peso += 1
        preco += 3
    if (operatorAnd(op1, 2048) != 0):
        peso += 9
        preco += 15
    if (operatorAnd(op1, 4096) != 0):
        peso += 4
        preco += 10
    if (operatorAnd(op1, 8192) != 0):
        peso += 5
        preco += 8
    if (operatorAnd(op1, 16384) != 0):
        peso += 3
        preco += 4
    if (operatorAnd(op1, 32768) != 0):
        peso += 12
        preco += 4

    if(peso > 20):
        print (op1 , " - $" ,preco, " - ", peso, "Kg -  X" )
    else:
        print(op1, " - $", preco, " - ", peso, "Kg -  OK")

#Aqui começa o programa
print("Escolha uma forma de ler os numeros")
print("1 - importando um .txt com 6 numeros")
print("2 - escrevendo os numeros na execursao")
escolha = input("Opção : ")

if(escolha == '1'):
    nomeArq = input("Digite o nome do txt: ")
    Arq = open(nomeArq, "r")
    temp = Arq.read()
    lines = []
    lines = temp.split('\n')
    print(lines)
    op1 = int(lines[0])
    op2 = int(lines[1])
    op3 = int(lines[2])
    op4 = int(lines[3])
    op5 = int(lines[4])
    op6 = int(lines[5])
    Arq.close()

elif(escolha == '2'):
    print ("Entre com 6 soluções iniciais (números entre 0 e 65535):")
    op1 = int(input())
    op2 = int(input())
    op3 = int(input())
    op4 = int(input())
    op5 = int(input())
    op6 = int(input())
else:
    print("Escolha invalida!!")
    exit()


#operações:
print("Resultado da Avaliação")
print("-----------------------")
classificacao(op1)
classificacao(op2)
classificacao(op3)
classificacao(op4)
classificacao(op5)
classificacao(op6)
print("-----------------------")
classificacao(operatorPtUnico(op1, op2))
classificacao(operatorAnd(op3, op4))
classificacao(operatorMutSimples(op5))
classificacao(operatorMutDupla(op6))

