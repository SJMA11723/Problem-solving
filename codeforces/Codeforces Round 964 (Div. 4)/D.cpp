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
        string a, b; cin >> a >> b;
        int idx = 0;
        for(int i = 0; i < a.size(); ++i){
            if(idx == b.size()){
                if(a[i] == '?') a[i] = 'a';
                continue;
            }

            if(a[i] == b[idx]) idx++;
            else if(a[i] == '?'){
                a[i] = b[idx];
                idx++;
            }
        }

        cout << (idx == b.size() ? "YES\n" + a + "\n" : "NO\n");
    }
}
