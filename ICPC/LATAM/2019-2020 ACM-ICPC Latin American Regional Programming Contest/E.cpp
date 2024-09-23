#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string cake; cin >> cake;
    int s; cin >> s;
    int n = cake.size();
    cake += cake;

    int next[n] = {};
    int last = -1;
    for(int i = n; i < cake.size(); ++i)
    if(cake[i] == 'E'){
        last = i;
        break;
    }

    if(last == -1){
        cout << "0\n";
        return 0;
    }

    for(int i = n - 1; 0 <= i; --i){
        if(cake[i] == 'E') last = i;
        next[i] = last;
    }

    int64_t ans = 0;
    for(int i = 0; i < n; ++i) ans += max(0, i + s - next[i]);
    cout << ans << '\n';
}
