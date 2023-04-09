/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
* LinkedIn: https://www.linkedin.com/in/jorgetzab/
*/

#include <bits/stdc++.h>

using namespace std;

long long coins(long long arr[], int n, long long k, long long d){
    long long ans = 0;
    for(int i = 0; i < n && i <= k; ++i){
        ans += (d + k - i) / (k + 1) * arr[i];
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        long long c, d;
        int n;
        cin >> n >> c >> d;
        long long arr[n], sum = 0;
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }

        sort(arr, arr + n);
        reverse(arr, arr + n);

        for(int i = 0; i < min(n, (int)d); ++i){
            sum += arr[i];
        }

        if(c <= sum){
            cout << "Infinity\n";
            continue;
        }

        if(coins(arr, n, 0, d) < c){
            cout << "Impossible\n";
            continue;
        }

        int ini = 1, fin = d;
        while(ini < fin){
            int mid = (ini + fin) / 2;
            if(c <= coins(arr, n, mid, d)) ini = mid + 1;
            else fin = mid;
        }

        cout << ini - 1 << '\n';
    }
}
