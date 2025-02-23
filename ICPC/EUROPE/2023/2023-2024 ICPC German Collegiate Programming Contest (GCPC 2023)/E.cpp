#include <bits/stdc++.h>
#define is_on(n, i) ((n) & (1 << (i)))

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    int n = s.size();
    vector<int> idx;
    for(int i = 1; i < n; ++i)
        if(s[i] == 'S' && s[i - 1] == 'S') idx.push_back(i - 1);

    int lim = 1 << idx.size();
    for(int mask = 0; mask < lim; ++mask){
        bool vis[n] = {};
        bool ok = true;
        for(int i = 0; i < idx.size(); ++i){
            if(is_on(mask, i)){
                if(vis[idx[i]] || vis[idx[i] + 1]){
                    ok = false;
                    break;
                }
                vis[idx[i]] = true;
                vis[idx[i] + 1] = true;
            }
        }
        if(!ok) continue;

        for(int i = 0; i < n; ++i){
            if(vis[i]){
                cout << 'B';
                i++;
                continue;
            }
            cout << char(s[i] - 'A' + 'a');
        }
        cout << '\n';
    }
}
