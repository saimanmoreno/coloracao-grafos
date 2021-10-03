# Algorimot para Resolucão do Problema de Coloração de Grafo em C

Escrever um programa que tente encontrar uma coloração ideal 
para um determinado grafo. As cores são aplicadas aos nós do 
grafo e as únicas cores disponíveis são preto e branco. A coloração 
do grafo é chamada de ideal se um máximo de nós for preto. A 
coloração é restrita pela regra de que dois nós conectados não 
podem ser pretos

#Entrada
O grafo é fornecido como um conjunto de nós indicado pelos números 1... n, n ≤ 100 e 
um conjunto de arestas não direcionadas, indicado por pares de números de nós (n1; n2), 
n1 ≠ n2.
O ficheiro de entrada contém m grafos. O número m é dado na primeira linha. A primeira 
linha de cada grafo contém n e k, o número de nós e o número de arestas, respectivamente. 
As seguintes k linhas contêm as arestas fornecidas por um par de números de nós, que 
são separados por um espaço

#Saída
A saída deve consistir em 2m linhas, duas linhas para cada grafo encontrado no ficheiro
de entrada. A primeira linha deve conter o número máximo de nós que podem ser pintados 
de preto no gráfico. A segunda linha deve conter uma possível coloração ideal. É 
fornecido pela lista de nós pretos, separados por um espaço em branco

# Exemplo de Entrada
1
6 8
1 2
1 3
2 4
2 5
3 4
3 6
4 6
5 6

# Saída
3
1 4 5
