#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;

    cin >> t;

    while(t--){
        int n, res = 0;
        cin >> n;
        int arr[n], score[n] = {};

        for(int i = 0; i < n; ++i) cin >> arr[i];

        for(int i = n - 1; -1 < i; --i){
            score[i] = arr[i];
            if( (i + arr[i]) < n ) score[i] += score[i + arr[i]];
            res = max(res, score[i]);
        }

        cout << res << '\n';
    }
}