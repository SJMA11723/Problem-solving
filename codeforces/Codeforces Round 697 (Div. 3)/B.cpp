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

        long long tmp = n;

        if(n % 2020 == 0 || n % 2021 == 0) cout << "yes\n";
        else {
            bool ok = false;
            while(0 < n){
                if(n % 2021 == 0){ok = true; break;}

                n -= 2020;
            }

            while(0 < n){
                if(n % 2020 == 0){ok = true; break;}

                n -= 2021;
            }

            if(ok) cout << "yes\n";
            else cout << "no\n";
        }
    }
}