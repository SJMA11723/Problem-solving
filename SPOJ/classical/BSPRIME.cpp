/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int t;
pair<int, int> queries[50000];

void criba(int n, vector<int> &primos){
    primos.clear();
    if(n < 2) return;

    vector<bool> no_primo(n + 1);
    no_primo[0] = no_primo[1] = true;


    for(long long i = 3; i * i <= n; i += 2){
        if(no_primo[i]) continue;
        for(long long j = i * i; j <= n; j += 2 * i)
            no_primo[j] = true;
    }

    primos.push_back(2);
    for(int i = 3; i <= n; i += 2){
        if(!no_primo[i])
            primos.push_back(i);
    }
}

void criba(int n){
    const int S = sqrt(n);

    vector<int> primosRaiz;
    criba(sqrt(n) + 1, primosRaiz);

    vector<char> no_primo(S);
    for(int ini = 0; ini <= n; ini += S){
        fill(no_primo.begin(), no_primo.end(), false);
        for(long long p : primosRaiz){
            long long m = p * max(p, (ini + p - 1) / p) - ini;
            for(; m <= S; m += p)
                no_primo[m] = true;
        }

        for(int i = 0; i < S && i + ini <= n; ++i){
            if(!no_primo[i] && 1 < i + ini){
                int cnt = 0, bits = 0, idxQ = 0;
                int p = i + ini;
                bool ok = false;
                for(int k = 30; 0 <= k && idxQ < t; --k){
                    if(p & (1 << k)){
                        cnt++;
                        ok = true;
                    }
                    if(ok) bits++;
                    if(idxQ < t && bits == queries[idxQ].first){
                        queries[idxQ].first = cnt;
                        swap(queries[idxQ].first, queries[idxQ].second);
                        idxQ++;
                    }
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;

    for(int i = 0; i < t; ++i){
        int n; cin >> n;
        queries[i] = {n, i};
    }
    sort(queries, queries + t);
    criba(101865019);
    sort(queries, queries + t);
    for(int i = 0; i < t; ++i)
        cout << queries[i].second << '\n';
}
