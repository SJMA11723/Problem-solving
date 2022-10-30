#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n], sum = 0;
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
            sum += arr[i];
        }

        if(sum % 2){
            cout << "-1\n";
            continue;
        }

        vector<pair<int, int>> ans;
        ans.reserve(n);

        int ini = 0;
        sum = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] == 0) continue;

            if(sum == 0){
                sum += ((i - ini + 1) % 2) ? arr[i] : -arr[i];
                continue;
            }

            sum += ((i - ini + 1) % 2) ? arr[i] : -arr[i];

            if(sum == 0){
                ans.push_back({ini + 1, i + 1});
                ini = i + 1;
                continue;
            }

            if((i - ini + 1) % 2){
                ans.push_back({ini + 1, ini + 1});
                ini++;

                if(arr[ini - 1]){
                    ans.push_back({ini + 1, i + 1});
                } else {
                    ans.push_back({ini + 1, i});
                    ans.push_back({i + 1, i + 1});
                }
            } else {
                ans.push_back({ini + 1, i});
                ans.push_back({i + 1, i + 1});
            }

            ini = i + 1;
            sum = 0;
        }

        if(ans.empty() || ans.back().second != n){
            ans.push_back({ini + 1, n});
        }

        cout << ans.size() << '\n';
        for(pair<int, int> it : ans)
            cout << it.first << ' ' << it.second << '\n';
    }
}
