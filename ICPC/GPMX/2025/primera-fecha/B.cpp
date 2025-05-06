#include<bits/stdc++.h>
using namespace std;
# define MAXN 1005


int espirales[8][MAXN][MAXN];

int x[4] = { 0, 1, 0, -1};
int y[4] = { 1, 0, -1, 0};

// 1 es en sentido de reloj 0 no lo es
int siguiente( int direct, bool reloj ){
    if( reloj  ==  false ) return (direct + 1 )% 4;

   if( direct == 0 ) return  3;
   if( direct == 3 ) return  2;
   if( direct == 2 ) return  1;
   if( direct == 1 ) return  0;
}

void generar( int i, int j, int direct, bool reloj, int id, int n ){


    espirales[id][i][j] =1;
    int val = 2;

    while( val <= n*n ){
        // si el sigueitne movimeinto en la direccion ya no es 0
        int ii = i + x[direct];
        int jj = j + y[direct];
        if(  ii >= n || ii <0 || jj >= n || jj <0 || espirales[id][ii][jj] != 0 )
            direct = siguiente( direct, reloj);

        i += x[direct];
        j += y[direct];
        espirales[id][i][j]  =  val;
        val++;
    }


}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;

    /// generar espirales
    generar(0,0,  0,false,   0, n );
    generar(0,0,  1,true,   1, n );
    generar(0,n-1, 1,false,   2, n );
    generar(0,n-1, 2,true,   3, n );
    generar(n-1,n-1,  2,false,   4, n );
    generar(n-1,n-1,  3,true,   5, n );
    generar(n-1,0,  3,false,   6, n );
    generar(n-1,0,  0,true,   7, n );

//    for( int d=0; d<8; d++ ){
//    for( int i=0; i<n; i++ ){
//    for( int j=0; j<n; j++ ){
//        cout << espirales[d][i][j] << ' ';
//    }
//    cout << '\n';
//    }
//    cout << '\n' << '\n';
//    }

    int arr[8][n * n];
    int mat[n][n];
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j){
        cin >> mat[i][j];
        for(int k = 0; k < 8; ++k)
            arr[k][ espirales[k][i][j] - 1 ] = mat[i][j];
    }

    int64_t ans = 0, cur_sum = 0;
    int N = n * n;
    for(int k = 0; k < 8; ++k, cur_sum = 0)
    for(int i = 0; i < N; ++i){
        cur_sum = max( (int64_t)arr[k][i], cur_sum + arr[k][i] );
        ans = max(ans, cur_sum);
    }
    cout << ans << '\n';
}
