#include <bits/stdc++.h>
#define MAXN 1000001

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
ll fact[MAXN], invFact[MAXN];

ll binExp(ll a, ll b){
    if(!b) return 1;

    ll tmp = binExp(a, b / 2);

    if(b % 2) return tmp * tmp % MOD * a % MOD;
    return tmp * tmp % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fact[0] = 1;
    for(ll i = 1; i <= MAXN; ++i){
        fact[i] = i * fact[i - 1] % MOD;
    }

    int n, k;
    cin >> n >> k;
    int arr[n + 2];
    arr[0] = 0;

    map<int, unordered_set<int> > cub;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        cub[ arr[i] ].insert(i);
    }

    ll p = 1, q = binExp(fact[n], MOD - 2);
    for(auto it : cub){
        p *= fact[it.second.size()];
        p %= MOD;
    }

    cout << p * q % MOD << '\n';

    while(k--){
        int i, x;
        cin >> i >> x;
        /// elimino
        p = p * binExp( cub[ arr[i] ].size() , MOD - 2) % MOD;
        cub[ arr[i] ].erase(i);
        if(cub[ arr[i] ].size() == 0) cub.erase(arr[i]);

        /// agrego
        cub[x].insert(i);
        p = p * (ll)cub[x].size() % MOD;
        arr[i] = x;

        cout << p * q % MOD << '\n';
    }

    return 0;
}
