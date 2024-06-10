#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--){
        string str; cin >> str;
        int k; cin >> k;

        bool ok = true;
        string ans, freq;
        for(int i = 0; i < str.size(); ++i){
            if('a' <= str[i] && str[i] <= 'z'){
                int cnt = (freq.empty() ? 1 : stoi(freq));
                freq = "";
                while(cnt--) ans += str[i];
            } else {
                freq += str[i];
                if(freq.size() > 7){
                    ok = false;
                    break;
                }
            }

            if(ans.size() > k){
                ok = false;
                break;
            }
        }

        cout << (ok ? ans : "unfeasible") << '\n';
    }

    return 0;
}
