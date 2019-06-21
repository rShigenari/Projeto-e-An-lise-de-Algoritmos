/*
Nome: Rosangela Miyeko Shigenari
R.A.: 92334
Problema 3: Café lucrativo
*/

#include<stdio.h>
#include<stdlib.h>

//funcao que retorna o maximo entre 2 inteiros
int ReturnMax(int a, int b){
  if(a>b)
    return a;
  else
    return b;
}
int ProblemSolution(int W, int n, int *v, int *t)
{
    int maxVet[W+1]; //armazenas os maximos
    int i, j;
    for(i = 0; i<W+1; i++){//inicializa o vetor
      maxVet[i] = 0;
    }
//variacao do problema da mochila
//busca do maior lucro
    for (i=0; i<W+1; i++)
{      for (j=0; j<n; j++)
{         if (t[j] <= i)
            {maxVet[i] = ReturnMax(maxVet[i], maxVet[i - t[j]] + v[j]);// atualiza o maximo
            printf("%d\n", maxVet[i] );
            }
          }
          printf("acabei\n");
        }

    return maxVet[W];
}
//funcao principal
int main()
{
    int P, N, i;
    int result;

    scanf("%d", &P);
    scanf("%d", &N);

    int *t = (int *) malloc(N * sizeof(int));
    int *v = (int *) malloc(N * sizeof(int));

    for(i = 0; i<N; i++){
      scanf("%d", &t[i] );
      scanf("%d", &v[i] );
    }
    result = ProblemSolution(P, N, v, t);
    printf("%d\n", result);


    return 0;
}
