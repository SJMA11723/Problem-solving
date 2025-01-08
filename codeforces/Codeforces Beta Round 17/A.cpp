#include <bits/stdc++.h>

using namespace std;

vector<int> primos;

void criba(int n){
    bool criba[n + 1] = {};

    for(int i = 2; i <= n; ++i){
        if(criba[i]) continue;

        primos.push_back(i);

        criba[i] = true;

        for(int j = i * i; j <= n; j += i) criba[j] = true;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, res;

    cin >> n >> res;

    criba(n);

    int tam = primos.size();

    for(int i = 0; i < tam; ++i){
        for(int k = 1; k < i; ++k){
            if( (primos[k] + primos[k - 1] + 1) == primos[i]) res--;
        }
    }

    if(res < 1) cout << "YES";
    else cout << "NO";

}