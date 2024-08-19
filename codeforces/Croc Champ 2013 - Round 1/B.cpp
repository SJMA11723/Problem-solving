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
    int n, m; cin >> n >> m;
    int deg[n] = {};
    for(int i = 0 ; i < m; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        deg[a]++;
        deg[b]++;
    }

    int deg1 = 0, deg2 = 0, deg_center;
    for(int i = 0; i < n; ++i)
    if(deg[i] == 1) deg1++;
    else if(deg[i] == 2) deg2++;
    else if(deg[i] == n - 1) deg_center++;

    if(deg2 == n) cout << "ring ";
    else if(deg1 + deg2 == n && deg1 == 2) cout << "bus ";
    else if(deg_center == 1 && deg1 == n - 1) cout << "star ";
    else cout << "unknown ";
    cout << "topology\n";
}
