#include <bits/stdc++.h>

using namespace std;

int primo(int x){
    if(x == 1) return 1;
    for(int i = 2; i * i <= x; ++i){
        if(x % i == 0) return i;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int64_t primes[] = {2, 3, 5, 7, 23, 37, 53, 73, 373};

//    for(int x = 2; x < 1e5; ++x){
//        string s = to_string(x);
//        bool ok = true;
//        for(int i = 0; i < s.size(); ++i){
//            for(int j = i; j < s.size(); ++j){
//                int p = stoi(s.substr(i, j - i + 1));
//                ok = ok && !primo(p);
//            }
//        }
//        if(ok) cout << x << '\n';
//    }

    int N = sizeof(primes) / sizeof(int64_t);
    int64_t n, m; cin >> n >> m;
    cout << upper_bound(primes, primes + N, m) - lower_bound(primes, primes + N, n) << '\n';
}
