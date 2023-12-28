/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n){
    for(int i = 2; i * i <= n; ++i)
        if(n % i == 0) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    int max_idx = 0, cub[26] = {};
    for(int i = 0; i < s.size(); ++i) cub[s[i] - 'a']++, max_idx = cub[max_idx] < cub[s[i] - 'a'] ? s[i] - 'a' : max_idx;

    vector<bool> ap(s.size());
    for(int i = 2; i <= s.size(); ++i){
        if(!is_prime(i) || i * 2 > s.size()) continue;
        for(int j = i - 1; j < s.size(); j += i) ap[j] = true;
    }

    int cnt = 0;
    for(int i = 0; i < ap.size(); ++i) cnt += ap[i];
    if(cnt > cub[max_idx]) cout << "NO\n";
    else {
        for(int i = 0; i < s.size(); ++i){
            if(ap[i]){
                cub[max_idx]--;
                s[i] = max_idx + 'a';
            }
        }

        int idx = 0;
        for(int i = 0; i < 26; ++i){
            while(cub[i]){
                cub[i]--;
                while(ap[idx]) idx++;
                s[idx] = i + 'a';
                idx++;
            }
        }
        cout << "YES\n" << s << '\n';
    }
}
