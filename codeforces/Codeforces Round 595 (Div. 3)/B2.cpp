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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int p[n];
        for(int &x : p){
            cin >> x;
            x--;
        }

        int ans[n];
        bool vis[n] = {};
        for(int i = 0; i < n; ++i){
            int cur = p[i];
            stack<int> st;
            while(!vis[cur]){
                vis[cur] = true;
                st.push(cur);
                cur = p[cur];
            }

            int len = st.size();
            while(st.size()){
                ans[st.top()] = len;
                st.pop();
            }
        }

        for(int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
    }
}
