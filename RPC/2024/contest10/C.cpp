#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    set<int> mset[n];
    while(m--){
        int p, l; cin >> p >> l;
        if(l == 3) continue;
        p--;
        mset[p].insert(l);
    }

    for(int i = 0; i < n; ++i)
        if(mset[i].size() == 2) cout << i + 1 << '\n';
}
