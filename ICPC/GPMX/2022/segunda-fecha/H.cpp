#include <bits/stdc++.h>

using namespace std;

int n;
long long x, arr[23];
long long ans;

int cbits(int a){
    int ret = 0;
    while(a){
        ret += a % 2;
        a /= 2;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    for(int i = 0; i < n; ++i)
        cin >> arr[i];

    int lim = 1 << n;
    for(int i = 1; i < lim; ++i){
        int bits = cbits(i);
        int idx = 0;
        long long tmp = i, mcm = 1;

        while(tmp){
            if(tmp % 2){
                mcm = mcm * arr[idx] / __gcd(mcm, arr[idx]);
            }

            if(x < mcm) break;
            tmp /= 2;
            idx++;
        }

        if(bits % 2) ans += x / mcm;
        else ans -= x / mcm;
    }

    cout << ans << '\n';
}