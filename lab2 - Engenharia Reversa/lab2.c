/*
Nome: Rosangela Miyeko Shigenari
R.A.: 92334
Problema 2: Engenharia reversa
*/

#include <stdio.h>
int aux =0;

 int backtracking_subconjunto(int conjunto[], int N, int k, int massa, int vet_solucao[], int somaNo) {
    int i, result;
    if(N>0)
  {
  	  if (somaNo == massa) {
        aux = 1;
        k = N;
      }
      else if (k!=N) {
       vet_solucao[k] = 1;// seleciona um elemento
       somaNo += conjunto[k];
       if(aux!=1)//se a soma ja foi encontrada nao precisa percorrer o outro lado
        backtracking_subconjunto(conjunto, N, k + 1, massa, vet_solucao, somaNo);
       somaNo -= conjunto[k];
       vet_solucao[k] = 0;// nao seleciona
       if(aux!=1)//se a soma ja foi encontrada nao precisa percorrer o outro lado
        backtracking_subconjunto(conjunto, N, k + 1, massa, vet_solucao, somaNo);
     }

	}
    result = aux;
    return result;
}

int main()
{
	int n_elementos, n_compostos;
  int massa_c;
  int result, somaNo, i;

  scanf("%d\n",&n_elementos);

  int massa_e[n_elementos];
  int vet_aux [n_elementos];
  if(n_elementos>0)
  {
    for(i =0; i<n_elementos; i++)
    scanf("%d",&massa_e[i]);
  }

  scanf("%d", &n_compostos );
  if(n_compostos>0)
  {
    for(i = 0; i<n_compostos; i++){
      scanf("%d", &massa_c);
      aux = 0;
      result = backtracking_subconjunto(massa_e, n_elementos, 0, massa_c, vet_aux, somaNo);
      if(result==1)
        printf("yes\n" );
      else
        printf("no\n");
    }
}
	return 0;
}
