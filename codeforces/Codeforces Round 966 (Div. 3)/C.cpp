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
        map<int, vector<int>> cub;
        int a[n];
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            cub[a[i]].push_back(i);
        }

        int m; cin >> m;
        while(m--){
            string s; cin >> s;
            if(s.size() != n){
                cout << "NO\n";
                continue;
            }

            map<char, vector<int>> cub2;
            for(int i = 0; i < n; ++i) cub2[s[i]].push_back(i);

            bool ok = true;
            for(auto& [val, indexes] : cub){
                char c = s[indexes[0]];
                for(int i : indexes) ok &= s[i] == c;
            }

            for(auto& [c, indexes] : cub2){
                int val = a[indexes[0]];
                for(int i : indexes) ok &= a[i] == val;
            }

            cout << (ok ? "YES\n" : "NO\n");
        }
    }
}
