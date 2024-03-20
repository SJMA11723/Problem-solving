#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string line; cin >> line;
    int64_t n = line.size();
    int64_t ans = 0;
    string line2;
    int64_t cnt = 0;
    for(int64_t i = n - 1; 0 <= i; --i){
        if(line[i] == '2') ans += n - i - 1 - cnt++;
        else line2 += line[i];
    }
    reverse(line2.begin(), line2.end());

    cnt = 0;
    n = line2.size();
    for(int64_t i = n - 1; 0 <= i; --i){
        if(line2[i] == '1') ans += n - i - 1 - cnt++;
    }

    cout << ans << '\n';
}
