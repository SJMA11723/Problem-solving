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
    string s; cin >> s;
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for(char c : s){
        if(c == '0') cnt0++;
        else if(c == '1') cnt1++;
        else cnt2++;
    }

    for(int i = 0; i < n && cnt0 < n / 3; ++i){
        if(s[i] == '1' && cnt1 > n / 3){
            cnt0++;
            cnt1--;
            s[i] = '0';
        } else if(s[i] == '2' && cnt2 > n / 3){
            cnt0++;
            cnt2--;
            s[i] = '0';
        }
    }

    for(int i = n - 1; 0 <= i && cnt2 < n / 3; --i){
        if(s[i] == '1' && cnt1 > n / 3){
            cnt2++;
            cnt1--;
            s[i] = '2';
        } else if(s[i] == '0' && cnt0 > n / 3){
            cnt2++;
            cnt0--;
            s[i] = '2';
        }
    }

    int cnt2_r = 0;
    for(int i = n - 1; 0 <= i && cnt1 < n / 3; --i){
        if(s[i] == '2'){
            cnt2_r++;
            if(cnt2_r <= n / 3) continue;
        }

        if(s[i] == '2' && cnt2 > n / 3){
            cnt1++;
            cnt2--;
            s[i] = '1';
        } else if(s[i] == '0' && cnt0 > n / 3){
            cnt1++;
            cnt0--;
            s[i] = '1';
        }
    }

    cout << s << '\n';
}
