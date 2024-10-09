#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        bool ans = false;
        while(n--){
            int x; cin >> x;
            if(x == k) ans = true;
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}
