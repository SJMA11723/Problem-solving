#include <bits/stdc++.h>

using namespace std;

void divisores(int64_t num, vector<int> &divs){
    vector<int> mayores;
    for(int i = 1; i * i <= num; ++i){
        if(num % i) continue;
        divs.push_back(i);
        if(i * i != num) mayores.push_back(num / i);
    }
    reverse(mayores.begin(), mayores.end());
    for(int d : mayores) divs.push_back(d);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int f; cin >> f;
    while(f){
        int arr[f];
        int g = 0;
        for(int &x : arr){
            cin >> x;
            g = gcd(g, x);
        }

        vector<int> divs;
        divisores(g, divs);

        int64_t ans = 0;
        for(int d : divs){
            int64_t add = LLONG_MAX;
            int r = arr[0] / d % f;
            for(int i = 0; i < f; ++i){
                if(r != arr[i] / d % f || arr[i] / d <= f){
                    add = 0;
                    break;
                }
                add = min(add, 1ll* (arr[i] / d - 1) / f);
            }
            ans += add;
        }

        cout << ans << '\n';
        cin >> f;
    }
}
