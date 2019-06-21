/*
Nome: Rosangela Miyeko Shigenari
R.A.: 92334
Problema 1: Desafio da Cobra
*/

#include <stdio.h>
//calcula a posicao i e j no tabuleiro
void CalculaPosicao (long long int N, long long int L){
  long long int volta = 0, somaDaVolta, diferenca;
  long long int i,j, mode =0;//i = linha, j= coluna
  long long int soma; //soma = variavel auxiliar para calcular o numero da volta
  long long int aux;
  long long int Naux = N; //controle da variável N
  soma = L;
  if(L ==(N*N)){//verifca o caso extremo L = Nˆ2
    if(N%2 == 0){
      i = N/2 + 1;
      j = N/2;
    }//se for impar, sera o meio do tabuleiro
    else{
      i = (N+1)/2;
      j = (N+1)/2;
    }
  }
  else{
  while (soma>0) { //determina a volta que esta a cabeça da cobra

    soma = soma - (4*Naux-4);
    Naux = Naux - 2;
    volta ++;
  }
  somaDaVolta = 4*volta*(N-volta); //soma da volta "volta"
  //posicao do final da volta
  i = volta+1;
  j= volta;
  //verifica se precisa voltar posicoes para tras no tabuleiro para calcular a atual
  diferenca = somaDaVolta - L;

  if(diferenca == 0){
    //se nao a posicao é o final da volta, nao precisa voltar posicoes
    i = volta+1;
    j= volta;
  }
  else {
    aux = diferenca - (N-2*volta);//
    if(aux>=0){//desce
      i = i+ (N-2*volta); 
      diferenca = diferenca - (N-2*volta);
      mode = 1; 
    }
    else
      i = i + diferenca;
    }
    if(mode == 1){//direita
      if((diferenca - ((N+1)-(2*volta)))>=0){ 
      j = j+ ((N+1)-(2*volta)); 
      diferenca = diferenca - ((N+1)-(2*volta));
      mode = 2;// sobe o tabuleiro
    }
    else
      j = j + diferenca;
    }
    if(mode ==2){//sobe o tabuleiro
      if(diferenca - ((N+1)-(2*volta))>=0){
        i = i - ((N+1)-(2*volta));
        diferenca = diferenca - ((N+1)-(2*volta));
        mode = 3;
    }
      else
        i = i - diferenca;
      }
      if(mode==3){esquerda
        j = j - diferenca;
      }
}
  printf("%lld %lld\n",i, j);//imprime a posicao i e j no tabuleiro
}
int main(){
  long long int L, N;
  scanf("%lld", &N);//tamanho do tabuleiro N X N
  scanf("%lld", &L);//tamanho da cobra
  CalculaPosicao(N,L); //calcula a posicao da cabeça da cobra
}
