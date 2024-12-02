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
        int deg[n] = {}, P[n], root;
        for(int i = 0; i < n; ++i){
            int p; cin >> p; p--;
            P[i] = p;
            deg[p]++;
            deg[i]++;
            if(i == p) root = i;
        }

        if(n == 1){
            cout << "1\n1\n1\n";
            continue;
        }

        int ans = 0;
        for(int i = 0; i < n; ++i) ans += deg[i] == 1 && root != i;
        cout << ans << '\n';
        bool vis[n] = {};
        for(int i = 0; i < n; ++i){
            if(!(deg[i] == 1 && root != i)) continue;
            stack<int> st;
            int cur = i;
            while(!vis[cur]){
                st.push(cur + 1);
                vis[cur] = true;
                cur = P[cur];
            }

            cout << st.size() << '\n';
            while(st.size()){
                cout << st.top() << " \n"[st.size() == 1];
                st.pop();
            }
        }
    }
}
