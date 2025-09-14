#include<bits/stdc++.h>
using namespace std;
# define MOD 1'000'000'007

struct dsu{
    vector<int> RA, P;
    dsu(int n){
        RA.resize(n, 1);
        P.resize(n);
        iota(P.begin(), P.end(), 0);
    }
    int root(int x){
        return x == P[x] ? x : P[x] = root(P[x]);
    }
    bool join(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return false;
        if(RA[x] >= RA[y]) swap(x, y);
        RA[y] += RA[x];
        P[x] = y;
        return true;
    }
};



int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,m; cin >> n >> m;
    dsu clasesEquiv(n);
    int a,b;
    while(m--){
        cin >> a >> b;
        if( a == n ) a=0;
        if( b == n ) b=0;
        clasesEquiv.join(a,b);
    }


    int64_t ans = 1;
    set<int> repre;
    for(  int nodo= 0 ; nodo<n; nodo++ ){
        int representante = clasesEquiv.root(nodo);
       // cout << nodo << ' ' << representante << '\n';
        // si aun no esta agregado
        if(  repre.find(  representante  ) == repre.end() ){
            ans *= ( 1ll * clasesEquiv.RA[representante] );
            ans %= MOD;
            repre.insert( representante );
            //cout << clasesEquiv.RA[representante] << '\n';
        }
        //cout << '\n';

    }
    cout << ans << '\n';
}