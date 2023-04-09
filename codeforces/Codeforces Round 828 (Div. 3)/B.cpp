#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        long long ans = 0;
        long long n;
        long long odd = 0;
        int q;
        cin >> n >> q;
        for(int i = 0; i < n; ++i){
            long long x;
            cin >> x;
            ans += x;
            if(x % 2) odd++;
        }

        while(q--){
            int a;
            long long b;
            cin >> a >> b;
            if(a){
                ans += odd * b;
                if(b % 2) odd = 0;
            } else {
                ans += (n - odd) * b;
                if(b % 2) odd = n;
            }
            cout << ans << '\n';
        }
    }
}
