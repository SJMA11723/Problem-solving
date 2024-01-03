#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, p; cin >> n >> p;
    bool ap[n + 1] = {};
    for(int i = 0; i < p; ++i){
        int idx; cin >> idx;
        ap[idx] = true;
    }

    cin >> p;
    for(int i = 0; i < p; ++i){
        int idx; cin >> idx;
        ap[idx] = true;
    }
    bool ok = true;
    for(int i = 1; i <= n; ++i) ok = ok && ap[i];
    cout << (ok ? "I become the guy.\n" : "Oh, my keyboard!\n");
}
 
