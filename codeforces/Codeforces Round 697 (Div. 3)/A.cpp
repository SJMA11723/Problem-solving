#include <bits/stdc++.h>

using namespace std;

long long t, n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--){
        cin >> n;

        if(n % 2){
            cout << "yes\n";
            continue;
        }

        bool ok = false;

        while(1 < n){
            if(n % 2){
                ok = true;
                break;
            }

            n /= 2;
        }

        cout << ( (ok) ? "yes\n" : "no\n" );
    }
}
