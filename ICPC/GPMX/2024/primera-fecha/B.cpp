#include  <bits/stdc++.h>
#define MAXK 700

using namespace std;

const int MOD = 1e9 + 7;

const int N = 20;

const int C[N] = {0, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0};

struct matrix{
    int arr[N][N];

    matrix(bool rec = false){
        memset(arr, 0, sizeof(arr));

        if(rec){
            for(int i = 0; i < N - 1; ++i){
                arr[i][i + 1] = 1;
                arr[N - 1][i] = C[N - 1 - i];
            }
            arr[N - 1][N - 1] = C[0];
        }
    }

    matrix(const matrix &b){
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                arr[i][j] = b.arr[i][j];
            }
        }
    }

    matrix operator*(matrix b){
        matrix res;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                for(int k = 0; k < N; ++k){
                    res.arr[i][j] += 1ll * arr[i][k] * b.arr[k][j] % MOD;
                    if(res.arr[i][j] > MOD) res.arr[i][j] -= MOD;
                }
            }
        }
        return res;
    }
};

matrix I;

matrix bin_exp(matrix A, int n){
    if(!n) return I;

    matrix tmp = bin_exp(A, n / 2);

    if(n % 2) return tmp * tmp * A;
    return tmp * tmp;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < N; ++i) I.arr[i][i] = 1;

    //int iterar = 0;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        //iterar++;
        //int n = iterar;


        //n = 24 - t - 1;
        //cout << "Caso: " << n << ": ";
        n-=1;

        n += N;
        matrix X = bin_exp(matrix(true), n -(N-1)  );
        int ans = 0;
        //for(int i = 0; i < N; ++i){
        for(int i = N-1; i >=0; i--){
            ans += X.arr[i][N - 1];
            if(ans > MOD) ans -= MOD;
            ////cout << X.arr[i][N - 1] << ' ';
        } //cout << '\n';


        //X = X * matrix(true);
        //ans += X.arr[0][N - 2];
        cout << ans << '\n';
    }
}
