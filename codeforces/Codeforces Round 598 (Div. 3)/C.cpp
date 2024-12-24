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
    int n, m, d; cin >> n >> m >> d;
    int c[m];
    for(int &x : c) cin >> x;

    int river[n] = {};
    int idx = n - 1;
    stack<int> st;
    for(int i = m - 1; 0 <= i; --i){
        for(int j = 0; j < c[i]; ++j) river[idx--] = i + 1;
        st.push(idx + 1);
    }

    bool ok = true;
    idx = -1;
    while(idx <= n && ok){
        if(idx + d >= n) break;
        if(river[idx + d]) break;
        if(st.empty()){
            ok = false;
            break;
        }

        int nxt = st.top();
        int id = m - (int)st.size();
        st.pop();

        for(int i = 0; i < c[id]; ++i) river[nxt + i] = 0;
        for(int i = 0; i < c[id]; ++i) river[idx + d + i] = id + 1;

        idx += d + c[id] - 1;
    }

    if(ok){
        cout << "YES\n";
        for(int i = 0; i < n; ++i) cout << river[i] << " \n"[i + 1 == n];
    } else cout << "NO\n";
}
