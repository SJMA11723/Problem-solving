#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m, k; cin >> n >> m >> k;
        int nodiv = 0;
        for(int i = 1; i <= m; ++i){
            if(k % i){
                nodiv = i;
                break;
            }
        }

        if(nodiv){
            cout << "S ";
            for(int i = 0; i < n; ++i) cout << nodiv << " \n"[i + 1 == n];
        } else if(k > n){
            cout << "S ";
            for(int i = 0; i < n; ++i) cout << 1 << " \n"[i + 1 == n];
        } else if(m > 2){
            cout << "S ";
            int L = k / m;
            int cnt = 0;
            for(int i = 1; i <= n; ++i){
                cnt++;
                if(cnt == L){
                    cout << "1";
                    cnt = 0;
                } else cout << m;
                cout << " \n"[i == n];
            }
        } else cout << "N\n";
    }
}
