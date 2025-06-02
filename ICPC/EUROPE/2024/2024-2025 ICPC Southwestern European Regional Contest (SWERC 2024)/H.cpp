// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
int n;
    cin>>n;
    map<string, int> m;

    for(int x = 0; x< n; x++){
        string s;
        cin>>s;
        m[s]++;
    }
    string ans = "";
    int max = -1;
    for( auto [s, cnt]: m){
        if(cnt > max){
            max = cnt;
            ans = s;
        }
    }

    cout<<ans<<"\n";
}
