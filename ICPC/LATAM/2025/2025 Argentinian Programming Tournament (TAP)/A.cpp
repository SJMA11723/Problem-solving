#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    int n = s.size();
    bool pnxt[n] = {};
    bool t = s.back() == 'P';
    for(int i = n - 2; 0 <= i; --i){
        pnxt[i] = t;
        t = t || (s[i] == 'P');
    }

    t = 0;
    for(int i = 0; i < n; ++i){
        if(t && pnxt[i] && s[i] == 'A'){
            cout << "S\n";
            return 0;
        }

        t = t || (s[i] == 'T');
    }
    cout << "N\n";
}