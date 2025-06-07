/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define fi first
#define se second

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    map<tuple<string, int, int>, int> cnt;
    string arr[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        for(int j = 0; j < i; ++j){
            if(arr[i].size() != arr[j].size()) continue;
            bool ok = false;
            for(int k = 0; k < arr[i].size(); ++k){
                if(arr[i][k] == arr[j][k]) continue;

                if(k + 1 == arr[i].size()) break;
                if(arr[i][k + 1] == arr[j][k + 1]) break;

                ok = true;
                for(int idx = k + 2; idx < arr[i].size(); ++idx){
                    ok &= arr[i][idx] == arr[j][idx];
                }
                if(!ok) break;

                string str1(1, arr[i][k]);
                str1 += arr[i][k + 1];
                string str2(1, arr[j][k]);
                str2 += arr[j][k + 1];
                if(str1 > str2) swap(str1, str2);
                string str = str1 + str2;
                cnt[{str, k, (int)arr[i].size() - k - 2}]++;
                break;
            }
        }
    }

    int ans = 0;
    for(auto &it : cnt) ans += it.second == 1;
    cout << ans << '\n';
}
