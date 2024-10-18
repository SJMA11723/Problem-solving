#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min(int a, int b){return a < b ? a : b;}

int n, m; /// dimensiones del mapa
int r, c; /// inicio
int x, y; /// destino
int ans = INT_MAX;
int *mapa;
char used[11];

/// Cambio de coordenada en el orden arriba, derecha, abajo, izquierda
int dir_r[4] = {-1, 0, 1, 0};
int dir_c[4] = {0, 1, 0, -1};

int bfs(){
    int idxCola = 0, finCola = 0; /// indice del elemento actual de la cola y el final de la cola
    int colaR[10000]; /// guarda la fila
    int colaC[10000]; /// guarda la columna
    char visitado[10000] = {};

    /// verifica si el podemos usar el elemento inicial
    if(used[ mapa[r * m + c] ] == 0) return 0;

    finCola++;
    colaR[0] = r;
    colaC[0] = c;

    while(idxCola < finCola){
        int actR = colaR[idxCola];
        int actC = colaC[idxCola];
        idxCola++;

        if(actR == x && actC == y) return 1;

        for(int k = 0; k < 4; ++k){
            int nr = actR + dir_r[k]; /// nuevas coordenadas
            int nc = actC + dir_c[k];
            int pos = nr * m + nc;
            /// Si esta fuera de los limites la omite
            if(nr < 0 || nc < 0 || n <= nr || m <= nc || visitado[pos] || used[mapa[pos]] == 0) continue;
            colaR[finCola] = nr;
            colaC[finCola] = nc;
            visitado[pos] = 1;
            finCola++;
        }
    }

    /// No se encontro algun camino a (x, y)
    return 0;
}

/// busqueda completa con todos los subconjuntos
void subconjuntos(int actual){
    if(actual == 11){
        /// cuenta cuantos elementos tiene el posible camino
        int con = 0;
        for(int i = 1; i < 11; ++i) con += used[i];

        /// Si existe un camino, entonces actualiza la respuesta
        /// con el minimo
        if(bfs()) ans = min(ans, con);
        return;
    }

    used[actual] = 1; /// toma el elemento actual
    subconjuntos(actual + 1);
    used[actual] = 0; /// no toma el elemento actual
    subconjuntos(actual + 1);
}

int main(void){
    scanf("%d %d %d %d %d %d", &n, &m, &r, &c, &x, &y);
    mapa = (int*)malloc(n * m * sizeof(int));
    for(int i = 0; i < n*m; ++i) scanf("%d", &mapa[i]);

    /// Indexa en cero las coordenadas
    r--;c--;
    x--;y--;

    /// Encuentra la respuesta
    subconjuntos(1);

    printf("%d\n", ans);
    return 0;
}