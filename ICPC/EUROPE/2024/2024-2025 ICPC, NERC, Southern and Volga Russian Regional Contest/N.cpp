#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int a, b;
        char c;
        cin >> a >> c >> b;
        if(a < b) cout << a << '<' << b << '\n';
        else if(a == b) cout << a << '=' << b << '\n';
        else cout << a << '>' << b << '\n';
    }
}