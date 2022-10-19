#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        int o = a % 2 + b % 2 + c % 2;
        if(0 < o && o < 3) cout << "YES\n";
        else cout << "NO\n";
    }
}
