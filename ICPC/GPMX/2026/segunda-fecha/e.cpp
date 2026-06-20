#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    int n = s.size();

    int N = 6; // mesero
    int M = 7;
    string ans;

    for(int i = 0; i < n; ++i){
        if(s.substr(i, N) == "mesero"){
            ans += "taquero";
            i += N - 1;
        } else ans += s[i];
    }

    cout << ans << '\n';
}