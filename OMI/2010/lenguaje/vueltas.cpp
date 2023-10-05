#include <bits/stdc++.h>

using namespace std;

bool H, V;
int n, m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int mat[n][m];
    for(int i = 0; i < n; ++i){
        for(int k = 0; k < m; ++k) cin >> mat[i][k];
    }
    int p;
    cin >> p;
    for(int i = 0; i < p; ++i){
        char c;
        cin >> c;
        if(c == 'H'){
            H = !H;
        } else {
            V = !V;
        }
    }

    if(H){ /// si debemos cambiar horizontal, lo cambiamos
        for(int i = 0; i < n; ++i){
            for(int k = 0; k < m/2; ++k) swap(mat[i][k], mat[i][m - 1 - k]);
        }
    }

    if(V){ /// si debemos cambiar vertical, lo cambiamos
        for(int i = 0; i < n/2; ++i){
            for(int k = 0; k < m; ++k) swap(mat[i][k], mat[n - 1 - i][k]);
        }
    }

    for(int i = 0; i < n; ++i){
        for(int k = 0; k < m; ++k) cout << mat[i][k] << ' ';
        cout << '\n';
    }

}
