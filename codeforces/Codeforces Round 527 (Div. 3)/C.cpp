/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int len = n;
    n = 2 * n - 2;
    bool ans[n] = {};
    string arr[n];
    int pref = -1, suff;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        if(arr[i].size() == len - 1){
            if(pref == -1) pref = i;
            else suff = i;
        }
    }

    int cnt = 0, cnt2 = 0;

    for(int i = 0; i + 1 < len; ++i)
        for(int j = 0; j < n; ++j)
            if(arr[j] == arr[suff].substr(i)){
                 cnt2++;
                 ans[j] = true;
                 break;
            }

    for(int i = 1; i < len; ++i)
        for(int j = 0; j < n; ++j)
            if(!ans[j] && arr[j].size() == i && arr[pref].find(arr[j]) == 0){
                 cnt++;
                 break;
            }

    if(cnt != n / 2 || cnt2 != n / 2){
        swap(pref, suff);
        memset(ans, 0, sizeof(ans));

        for(int i = 0; i + 1 < len; ++i)
        for(int j = 0; j < n; ++j)
            if(arr[j] == arr[suff].substr(i)){
                 ans[j] = true;
                 break;
            }
    }

    for(int i = 0; i < n; ++i) cout << (ans[i] ? 'S' : 'P');
    cout << '\n';
}
