#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        string str;
        char c;
        cin >> str >> c;
        int n = str.size();
        bool ok = false;
        for(int i = 0; i < n && !ok; ++i){
            if(str[i] == c){
                ok = ok || (i % 2 == 0 && (n - 1 - i) % 2 == 0);
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
