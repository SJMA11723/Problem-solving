#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int min(int a, int b){return a < b ? a : b;}

typedef struct edges{
    int size;
    int *to;
}edges;

void addEdge(edges *grafo, int from, int to);

int dfs(edges *grafo, int from, char *visitado, int destino, char *encontrado);

int main(void){
    int n, x;
    scanf("%d %d", &n, &x);
    edges *grafo = (edges*)calloc(n + 1, sizeof(edges));

    for(int i = 1; i < n; ++i){
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(grafo, a, b);
        addEdge(grafo, b, a);
    }

    char *visitado = (char*)calloc(n + 1, sizeof(char));

    char c;
    printf("%d\n", dfs(grafo, 1, visitado, x, &c) - 1);

    for(int i = 0; i <= n; ++i)
        free(grafo[i].to);
    free(grafo);
    free(visitado);
    return 0;
}

int dfs(edges *grafo, int from, char *visitado, int destino, char *encontrado){
    visitado[from] = 1;

    int ans = 0;
    char destEcontrado = 0;
    for(int i = 0; i < grafo[from].size; ++i){
        int to = grafo[from].to[i];
        if(visitado[to]) continue;
        int con = dfs(grafo, to, visitado, destino, &destEcontrado);
        if(con == 1){
            ans = 1;
            break;
        }
        ans += con;
    }

    *encontrado = *encontrado || destEcontrado;

    //printf("%d %d\n", from, ans);

    if(from == destino){
        *encontrado = 1;
        return 1;
    }
    if(destEcontrado) return ans + 1;
    return ans + 2;
}

void addEdge(edges *grafo, int from, int to){
    /// Copia los elementos
    int n = grafo[from].size;
    int arr[n + 1];
    memcpy(arr, grafo[from].to, n * sizeof(int));

    /// Crea un nuevo arreglo
    arr[n++] = to;
    free(grafo[from].to);
    grafo[from].to = (int*)malloc(n * sizeof(int));
    memcpy(grafo[from].to, arr, sizeof(arr));
    grafo[from].size = n;
}