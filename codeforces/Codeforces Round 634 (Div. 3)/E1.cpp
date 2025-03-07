/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXVAL 26

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n], cnt[MAXVAL + 1][n];
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
            cnt[arr[i]][i]++;
        }

        for(int i = 1; i < n; ++i)
        for(int j = 1; j <= MAXVAL; ++j)
        cnt[j][i] += cnt[j][i - 1];


        int ans = 1;
        for(int a = 1; a <= MAXVAL; ++a){
            for(int x = 1; 2 * x <= cnt[a][n - 1]; ++x){
                int l = 0, r = n;
                while(l < r){
                    int mid = l + (r - l) / 2;
                    if(cnt[a][mid] < x) l = mid + 1;
                    else r = mid;
                }

                int L = l;

                l = 0, r = n;
                while(l < r){
                    int mid = l + (r - l) / 2;
                    if(cnt[a][mid] <= cnt[a][n - 1] - x) l = mid + 1;
                    else r = mid;
                }

                int R = l;

                for(int b = 0; b <= MAXVAL; ++b) ans = max(ans, 2 * x + cnt[b][R - 1] - cnt[b][L]);
            }
        }
        cout << ans << '\n';
    }
}
