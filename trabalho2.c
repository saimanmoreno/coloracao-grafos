/*
 * Simao Moreno
 * 110406
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// CONSTANTES
#define VAZIO 0
#define PRETO 1


// VARIAVEIS GLOBAIS
int num_nos;					// numero de nos
int nos[100];					// lista de nos
int matriz_adj[100][100];		// matriz de adjacencias

int melhores_nos[100];
int max_nos_pretos = 0;


// PROTOTIPOS DE FUNCOES
void calcular(int num_no, int num_pretos);


int main()
{

	int num_grafos, num_arestas, n1, n2, i, j, k, a;

	scanf("%d", &num_grafos); // o ficheiro de entrada contem m grafos dado na primeira linha

	for (i = 0; i < num_grafos; i++) // para cada grafo
	{

		scanf(" %d %d", &num_nos, &num_arestas); // a primeira linha de cada grafo contem o numero de nos e de arestas

		max_nos_pretos = 0; // inicialmente o numero maximo de nos pretos e zero

		for (j = 0; j < num_nos; j++) // pecorrer todos os nos
		{
			nos[j] = VAZIO;		// preencher a lista com zero

			for (k = 0; k < num_nos; k++)
			{
				matriz_adj[j][k] = VAZIO; // preencher toda a matriz de adjacencia com zero
			}
		}

		for (j = 0; j < num_arestas; j++)
		{

			scanf(" %d %d", &n1, &n2); // conjunto de arestas nao direccionadas indicado por pares de numero de nos

			if ((n1 > 0 && n1 <= 100) && (n2 > 0 && n2 <= 100)) // conjunto de nos indicado pelos numeros 1...n, n <= 100 
			{
				if (n1 != n2)		// e conj. de arestas indicado por pares de num de nos (n1;n2) com n1!=n2
				{
					/*
					 * REPRESENTACAO DE GRAFOS EM MATRIZ DE ADJACENCIAS:
					 * - matriz de |V| |V| onde a entrada (n1, n2)
					 *   indica se existe ligacao entre o no n1 e n2
					 *   (ligacao = 1, sem ligacao = 0)
					*/
					matriz_adj[n1 - 1][n2 - 1] = 1;		
					matriz_adj[n2 - 1][n1 - 1] = 1;
					// n1 - 1 e n2 - 1, pois primeira posicao da matriz e zero
				}
				else
				{
					printf("PARES DE NUMEROS DE NOS DEVEM SER DIFERENTES! \n");
					j--;
				}
			} else {
				printf("CONJUNTO DE NOS DEVE ESTAR INDICADO ENTRE 1...N, N <= 100\n");
				j--;
			}
		}

		calcular(0, 0);		// comecar a calcular a primeira linha e a primeira coluna

		printf("%d\n", max_nos_pretos);		// a primeira linha deve conter o numero maximo de nos que pode ser pintados de preto

		a = 0;		// para preencher com espacos

		for (j = 0; j < num_nos; j++)
		{

			if (melhores_nos[j] == PRETO)		
			{
				printf("%s%d", (a ? " " : ""), j + 1); 		// imprimir a posicao mais um, pois posicao n guarda no n+1
				a = 1;		// na proxima vez que encontrarmos um no preto vamos separa-lo da anterior por um espaco em branco
			}
		}

		printf("\n");
	}
}


void calcular(int num_no, int num_pretos)
{
	
	int i,  feito = 0;

	nos[num_no] = PRETO;		// calcular(0,0) -> nos[0] = preto
	num_pretos++;

	if (num_pretos > max_nos_pretos)		// se o numero de nos pretos for maior que o numero maximo de nos entao estes sao igualados
	{
		max_nos_pretos = num_pretos;
		feito = 1;		// variavel de verificacao (0 - false, 1 - true)
	}

	for (i = 0; i < num_nos; i++)
		if (matriz_adj[num_no][i] && nos[i] == VAZIO)
			nos[i] = 10 + num_no; 		// branco

	for (i = 0; i < num_nos; i++)
	{

		if (nos[i] == VAZIO)
		{
			calcular(i, num_pretos);		// recursividade
			feito = 0;
			break;
		}
	}

	if (feito)
	{
		memcpy(melhores_nos, nos, sizeof(nos));		// copiar o array nos para o array melhores nos, onde sizeof(nos) e o numero de nos a ser copiados
	}

	for (i = 0; i < num_nos; i++)
		if (nos[i] == 10 + num_no)
			nos[i] = VAZIO;

	nos[num_no] = 10 + num_no; 		// branco
	num_pretos--;

	for (i = 0; i < num_nos; i++)
	{

		if (nos[i] == VAZIO)
		{
			calcular(i, num_pretos);
			break;
		}
	}

	nos[num_no] = VAZIO;
}


/*
 * Simao Moreno
 * 110406
 */
