/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    return a.first == b.first;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    pair<int, int> a[n];
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        a[i] = {x, i + 1};
    }
    sort(a, a + n);
    n = unique(a, a + n, comp) - a;
    if(k <= n){
        cout << "YES\n";
        for(int i = 0; i < k; ++i) cout << a[i].second << " \n"[i + 1 == k];
    } else cout << "NO\n";
}
