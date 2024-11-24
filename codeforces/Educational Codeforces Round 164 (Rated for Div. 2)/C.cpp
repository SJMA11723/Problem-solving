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
        string a, b;
        cin >> a >> b;
        int n = a.size();
        bool ok = false;
        for(int i = 0; i < n; ++i){
            if(a[i] == b[i]) continue;
            if(a[i] < b[i]){
                if(!ok) swap(a[i], b[i]);
            } else if(b[i] < a[i]){
                if(ok) swap(a[i], b[i]);
            }
            ok = true;
        }
        cout << a << '\n' << b << '\n';
    }
}
