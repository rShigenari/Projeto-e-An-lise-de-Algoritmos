/*
Nome: Rosangela Miyeko Shigenari
R.A.: 92334
Problema 4: Festas em comunidades
*/
#include <stdio.h>
#include <stdlib.h>

//estrutura da lista de adjacencia
struct NoListaAdj
{
    int dest;
    struct NoListaAdj* prox;
};

//representacao da lista de adjacencia
struct ListaAdj
{
    struct NoListaAdj *head;
};

//estrutura do grafo
struct Grafo
{
    int V; // numero de vertices
    struct ListaAdj* vet; //vetor da lista de adjacencias
};

//cria nova lista de adjacencia
struct NoListaAdj* newNoListaAdj(int dest)
{
    struct NoListaAdj* criaNo =
     (struct NoListaAdj*) malloc(sizeof(struct NoListaAdj));
    criaNo->dest = dest;
    criaNo->prox = NULL;
    return criaNo;
}

//cria um grafo com V vertices
struct Grafo* criaGrafo(int V)
{
    struct Grafo* g =
        (struct Grafo*) malloc(sizeof(struct Grafo));
    g->V = V;

    //cria uma linha da lista de adjacencia
    g->vet =
      (struct ListaAdj*) malloc(V * sizeof(struct ListaAdj));

    int i;
    for (i = 0; i < V; ++i)
        g->vet[i].head = NULL;//inicializa o vetor

    return g;
}

//adiciona uma aresta nao direcionada
void criaAresta(struct Grafo* g, int ini, int dest)
{

    struct NoListaAdj* criaNo = newNoListaAdj(dest);
    //adiciona a ida
    criaNo->prox = g->vet[ini].head;
    g->vet[ini].head = criaNo;

    //adiciona sentido contrario
    criaNo = newNoListaAdj(ini);
    criaNo->prox = g->vet[dest].head;
    g->vet[dest].head = criaNo;
}

//funcao solucao do problema
int ResolveProblem(struct Grafo* g, int K, int N)
{
    int i;
    int cont;
    int satisfaz = 0;
    int aux[N];
    struct NoListaAdj* item;

    for (i = 0; i < g->V; i++)
    {    cont = 0;
         item = g->vet[i].head;
        while (item)
        {   cont++; //conta a quantidade de itens de uma linha da lista de adjacencia
            item = item->prox;
        }
        if(cont<K)
          aux[i] = 0;
        else
          aux[i] = 1;
    }
    for (i = 0; i < g->V; i++)
    {   cont = 0;
        item = g->vet[i].head;
        while (item)
        {
          if(aux[item->dest]==1)
            cont++;
          item = item->prox;
        }
        if(cont>=K)
          satisfaz++;
    }
    return satisfaz;
}

int main()
{
    int N, P, K;
    int i;
    int a,b;
    int result;

    scanf("%d", &N);
    scanf("%d", &P);
    scanf("%d", &K);
    struct Grafo* g = criaGrafo(N);
    for(i = 1; i<=P; i++){
      //insere as arestas
      scanf("%d", &a);
      scanf("%d", &b);
      if(a==0 || b==0)
        return 0;
      else
        criaAresta(g, a-1, b-1);
    }

    //imprime a solucao
    result = ResolveProblem(g, K, N);
    printf("%d", result );

    return 0;
}
