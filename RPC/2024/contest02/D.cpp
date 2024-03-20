#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    string s[n];
    for(int i=0;i<n;i++) cin >> s[i];

    string ans;
    for(int i = 0; i < m; ++i){
        int cub[26] = {};
        for(int j = 0; j < n; ++j) cub[s[j][i] - 'a']++;
        pair<int, char> arr[n];
        for(int j = 0; j < n; ++j){
            arr[j] = {-cub[ s[j][i] - 'a' ], s[j][i]};
        }
        sort(arr, arr + n);
        ans += arr[0].second;
    }

    cout << ans << '\n';
}

