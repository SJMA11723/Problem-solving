#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, ans = 0;
        cin >> n;
        string str;
        cin >> str;

        /**
            answer is insert 0 between two consecutive 1's and viceversa
        */
        for(int i = 1; i < n; ++i){
            if(str[i] == str[i - 1])
                ans++;
        }

        cout << ans << '\n';
    }
}
