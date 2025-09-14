#include <bits/stdc++.h>

using namespace std;

bool vocal(char c){
    return c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    int cnt = 0;
    for(char c : s) cnt += vocal(c);

    if(cnt == 0){
        cout << "1\n";
        return 0;
    }

    if(!vocal(s[0])){
        cout << "0\n";
        return 0;
    }

    if(cnt == 1){
        cout << s.size() << '\n';
        return 0;
    }

    int cnt2 = -1, ans = 0;
    //cout << (cnt + 1) / 2 - 1 << ' ' << (cnt + 1) / 2 << '\n';
    for(char c : s){
        cnt2 += vocal(c);
        if((cnt + 1) / 2 - 1 <= cnt2 && cnt2 < (cnt + 1) / 2)
            ans++;
        //cout << c << ' ' << cnt2 << ' ' << ans << '\n';
    }
    cout << ans << '\n';
}
