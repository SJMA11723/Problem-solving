/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    map<pair<int, int>, int> rev;
    pair<int, int> arr[n + 1];
    for(int i = 1; i <= n; ++i){
        int a, b; cin >> a >> b;
        if(b < a) swap(a, b);
        arr[i] = {a, b};
        rev[arr[i]] = i;
    }

    int P[n + 1] = {};
    for(int i = 1; i <= n; ++i){
        int a, b; tie(a, b) = arr[i];
        int prv = rev[{min(i, a), max(i, a)}];
        if(!prv || P[prv]) prv = rev[{min(i, b), max(i, b)}];
        P[prv] = i;
    }

    int cur = 1;
    while(P[cur] != 1){
        cout << cur << ' ';
        cur = P[cur];
    }
    cout << cur << '\n';
}
