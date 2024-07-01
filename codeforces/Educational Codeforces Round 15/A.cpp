#include <bits/stdc++.h>

using namespace std;

int n, ant, x, maxi, tam;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> x;
        if(ant < x){
            tam++;
        } else {
            maxi = max(maxi, tam);
            tam = 1;
        }
        ant = x;
    }

    cout << max(maxi, tam);
}
