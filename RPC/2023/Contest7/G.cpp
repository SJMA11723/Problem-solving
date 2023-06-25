/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define isOn(n, i) ( (n) & (1 << i) )

using namespace std;

typedef long long ll;

ll prod[1 << 17];

ll multiplos(ll n, ll p[], int k){
    ll ret = 0;
    int lim = 1 << k;
    for(int i = 1; i < lim; ++i){
        if(__builtin_popcount(i) % 2) ret += n / prod[i];
        else ret -= n / prod[i];
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, p[15];
    int k;
    cin >> n >> k;
    for(int i = 0; i < k; ++i) cin >> p[i];

    int lim = 1 << k;
    for(int i = 1; i < lim; ++i){
        ll mult = 1;
        for(int j = 0; j < k; ++j)
            if(isOn(i, j)) mult *= p[j];
        prod[i] = mult;
    }

    ll ini = 1, fin = LLONG_MAX - 1;
    while(ini < fin){
        ll mitad = (ini + fin) / 2;
        if(mitad - multiplos(mitad, p, k) < n) ini = mitad + 1;
        else fin = mitad;
    }
    cout << ini << '\n';
}
