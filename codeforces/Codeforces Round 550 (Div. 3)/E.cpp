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
    int k; cin >> k;
    vector<int> a, b;
    for(int i = 0; i < k; ++i){
        char c; cin >> c;
        a.push_back(c - 'a');
    }

    for(int i = 0; i < k; ++i){
        char c; cin >> c;
        b.push_back(c - 'a');
    }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for(int i = 0; i < k; ++i){
        a[i] += b[i];
        if(a[i] > 25){
            if(i + 1 == k) a.push_back(1);
            else a[i + 1]++;
            a[i] -= 26;
        }
    }

    int rem = 0;
    string ans;
    while(a.size()){
        int last = a.back();
        a.pop_back();

        int num = rem * 26 + last;
        ans += char('a' + num / 2);
        rem = num % 2;
    }

    if(ans.size() > k) ans.erase(ans.begin());
    cout << ans << '\n';
}
