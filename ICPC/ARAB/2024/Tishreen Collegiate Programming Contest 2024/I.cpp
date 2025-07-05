#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int N = (n + 1) / 2;
        cout << 1ll * N * (N + 1) - N * (n % 2) << '\n';
    }
}