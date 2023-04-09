#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }

        vector<pair<int, int>> ans;

        for(int i = 1; i < n; i += 2){
            if(arr[i] == arr[i - 1]){
                ans.push_back({i, i + 1});
            } else {
                ans.push_back({i, i});
                ans.push_back({i + 1, i + 1});
            }
        }

        if(ans.empty() || ans.back().second != n)
            cout << "-1\n";
        else {
            cout << ans.size() << '\n';
            for(pair<int, int> it : ans){
                cout << it.first << ' ' << it.second << '\n';
            }
        }
    }
}
