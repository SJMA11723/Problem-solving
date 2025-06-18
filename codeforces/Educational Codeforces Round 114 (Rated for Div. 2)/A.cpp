#include <bits/stdc++.h>

using namespace std;

int t;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        int af[n + 1] = {};

        for(int k = 0; k < n; ++k){
            for(int i = 0; i < af[n]; ++i) cout << '(';
            for(int i = 0; i < n - af[n]; ++i) cout << "()";
            for(int i = 0; i < af[n]; ++i) cout << ')';
            af[n]++;
            cout << '\n';
        }
    }
}