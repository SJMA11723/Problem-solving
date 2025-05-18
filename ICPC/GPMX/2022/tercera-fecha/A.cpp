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
    string s; cin >> s;
    s += "b"; n++;

    int ans = 0, cnt = 0;
    for(char c : s){
        if(c == 'a') cnt++;
        else {
            if(cnt > 1) ans += cnt;
            cnt = 0;
        }
    }
    cout << ans << '\n';
}
