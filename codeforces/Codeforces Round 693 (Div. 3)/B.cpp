#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;

    cin >> t;

    while(t--){
        int n, uno = 0, dos = 0, x;

        cin >> n;

        for(int i = 0; i < n; ++i){
            cin >> x;
            if(x % 2) uno++;
            else dos++;
        }

        if(dos % 2){
            if(1 < uno){
                cout << ( (uno % 2) ? "NO\n" : "YES\n");
            } else cout << "no\n";
        } else {
            cout << ( (uno % 2) ? "NO\n" : "YES\n");
        }
    }
}