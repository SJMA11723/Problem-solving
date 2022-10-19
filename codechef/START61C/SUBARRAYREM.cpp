#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n], unos = 0, ans = 0;
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
            unos += arr[i];
        }



        /**
            - optimal operations are xor of a 0 adyacent to 1. Use a stack for this
              and remove efficiently every pair of adyacent 0, 1 (or 1, 0)
            - When there is no 0's, then score increments by ones/3.
              Here optimal operation is 1 xor 1 xor 1 = 1.
            - When there is no 1's then score increments by 0 (0 xor 0 xor ... xor 0 = 0)
        */

        int ceros = 0;
        for(int i = 0; i < n; ++i){
            if(arr[i] == 0)
                ceros++;
            else if(ceros){
                ceros--;
                unos--;
                ans++;
            }
        }

        if(unos <= ceros){
            ans += unos;
        } else {
            ans += ceros + (unos - ceros) / 3;
        }

        cout << ans << '\n';
    }
}
