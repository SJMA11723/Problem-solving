#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, l; cin >> n >> k >> l;
    string s, alph;
    cin >> s >> alph;
    bool ap[26] = {};
    for(char c : alph) ap[c - 'a'] = 1;
    int cnt[n] = {};
    if(!ap[s[n - 1] - 'a']) cnt[n - 1] = 1;

    for(int i = n - 2; 0 <= i; --i){
        if(ap[s[i] - 'a']) cnt[i] = 0;
        else cnt[i] = cnt[i + 1] + 1;
    }

    int64_t ans = 0;
    int ptrl = 0, inset = 0, last0 = 0;
    for(int r = 0; r < n; ++r){
        if(ap[s[r] - 'a']){
            inset++;
            if(inset > k) ans += 1ll * (cnt[ptrl] + 1) * (last0 + 1);
            last0 = 0;
        } else last0++;

        while(inset > k){
            if(ap[s[ptrl] - 'a']) inset--;
            ptrl++;
        }
    }

    if(inset == k) ans += (last0 + 1) * (cnt[ptrl] + 1);

    cout << ans << '\n';
}
