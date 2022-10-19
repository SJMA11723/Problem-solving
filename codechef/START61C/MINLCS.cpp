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
        string A, B;
        cin >> A >> B;

        /**
            Optimal rearrange is to sort A and reverse sort B,
            then only subsequences of the same character are available
        */

        int cub[300] = {};
        int cub2[300] = {};
        for(int i = 0; i < n; ++i){
            cub[ A[i] ]++;
            cub2[ B[i] ]++;
        }

        int ans = 0;
        for(int i = 0; i < 300; ++i){
            if(!cub[i] || !cub2[i]) continue;

            ans = max(ans, min(cub[i], cub2[i]));
        }

        cout << ans << '\n';
    }
}
