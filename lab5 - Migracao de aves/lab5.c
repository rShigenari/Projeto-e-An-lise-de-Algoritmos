/*
Nome: Rosangela Miyeko Shigenari
R.A.: 92334
Problema 5: Migração de Aves
*/

#include <stdio.h>

int CalcDistance(int a[], int n){
  int i, aux = 0;
  int dist[n];
  int cont_distance = 0;
  int result = 0;
  for(i = 0; i<n; i++){
    dist[i] = a[i] - aux;
    aux = a[i];
  }
  for(i = 0; i<n; i++){
    cont_distance = dist[i] + cont_distance;
    if(cont_distance <= 200)
      result++;
  }
  return result;
}

int main(){

   int n, i;
   scanf("%d", &n);
   int a[n];

   for(i = 0; i<n; i++){
     scanf("%d", &a[i]);
   }
   printf("%d\n", CalcDistance(a, n));

  return 0;
}
