/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define ff first
#define ss second

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;

        bool simetric = false, transposed = false;

        vector<int> arr[n];
        for(int i = 0; i < n; ++i){
            arr[i].resize(4);
            for(int j = 0; j < 4; ++j) cin >> arr[i][j];
            vector<int> A_t = {arr[i][0], arr[i][2], arr[i][1], arr[i][3]};
            if(arr[i][1] == arr[i][2]) simetric = true;

            for(int j = 0; j <= i; ++j)
            if(A_t == arr[i]) transposed = true;
        }

        cout << (simetric && transposed && m % 2 == 0 ? "YES\n" : "NO\n");
    }
}
