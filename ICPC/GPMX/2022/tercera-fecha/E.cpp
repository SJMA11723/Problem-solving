/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define ff first
#define ss second
#define MAXK 1000000

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int cnt[MAXK + 1] = {}, ans = 0;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        if(cnt[x]) cnt[x]--;
        else ans++;
        cnt[x - 1]++;
    }
    cout << ans << '\n';
}
