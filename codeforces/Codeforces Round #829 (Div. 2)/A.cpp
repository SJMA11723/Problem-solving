#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int q = 0;
        for(int i = 0; i < n; ++i){
            char c; cin >> c;
            if(c == 'Q') q++;
            else {
                q = max(0, q - 1);
            }
        }

        if(0 < q) cout << "No\n";
        else cout << "Yes\n";
    }
}