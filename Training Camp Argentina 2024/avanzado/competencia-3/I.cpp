/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 55

using namespace std;

string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string first = "What are you doing while sending \"";
string second = "\"? Are you busy? Will you send \"";
string third = "\"?";

__int128_t sz[MAXN + 1];

char solve(int n, int64_t k){
    if(n == 0){
        if(k <= sz[0]) return f0[k - 1];
        return '.';
    }

    if(n > MAXN){
        int64_t nk = max(0ll, k - (int)first.size() * (n - MAXN));
        if(!nk) return first[(k - 1) % first.size()];
        return solve(MAXN, nk);
    } else if(k <= first.size()) return first[k - 1];
    else if(k <= first.size() + sz[n - 1]) return solve(n - 1, k - first.size()); /// revisar
    else if(k <= first.size() + sz[n - 1] + second.size()) return second[k - (first.size() + sz[n - 1]) - 1]; /// cuidado overflow por .size()
    else if(k <= first.size() + 2*sz[n - 1] + second.size()) return solve(n - 1, k - (first.size() + sz[n - 1] + second.size()) ); /// cuidado overflow por .size()
    else if(k <= sz[n]) return third[k - (first.size() + 2*sz[n - 1] + second.size()) - 1]; /// cuidado overflow por .size()
    else return '.';
    return 'a';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sz[0] = f0.size();
    for(int i = 1; i <= MAXN; ++i) sz[i] = first.size() + sz[i - 1] + second.size() + sz[i - 1] + third.size();

    int q; cin >> q;
    while(q--){
        int64_t n, k; cin >> n >> k;
        cout << solve(n, k);
    }
    cout << '\n';
}
