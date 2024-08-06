#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int x = n & (-n);
        if(x == n) cout << n / 2 << ' ' << n / 4 << ' ' << n / 4 << '\n';
        else cout << x << ' ' << (n - x) / 2 << ' ' << (n - x) / 2 << '\n';
    }
}