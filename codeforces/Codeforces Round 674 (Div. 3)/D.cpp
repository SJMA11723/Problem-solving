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
    int n; cin >> n;
    int ans = 0;
    int64_t sum = 0;
    set<int64_t> prefs;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        sum += x;
        if(sum == 0 || prefs.count(sum)){
            ans++;
            sum = x;
            prefs.clear();
        }
        prefs.insert(sum);
    }
    cout << ans << '\n';
}
