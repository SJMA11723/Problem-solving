#include <bits/stdc++.h>

using namespace std;

int64_t eval_int(int64_t A, int64_t B, int64_t C, int64_t L, int64_t R){
    return 2 * A * (R * R * R - L * L * L) + 3 * B * (R * R - L * L) + 6 * C * (R - L);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int64_t A, B, C, L, R;
        cin >> A >> B >> C >> L >> R;
        int64_t p = eval_int(A, B, C, L, R);

        int64_t disc = B * B - 4 * A * C;
        if(disc > 0){
            int64_t l = (-B - sqrt(disc)) / 2;
            int64_t r = (-B + sqrt(disc)) / 2;
            if(r < l) swap(l, r);

            if(!(l <= L && R <= r)){
                l = max(l, L);
                r = min(r, R);
                if(l < r) p -= 2 * eval_int(A, B, C, l, r);
            }
        }

        p = abs(p);
        int64_t q = 6;
        int64_t g = __gcd(p, q);
        p /= g;
        q /= g;
        cout << p << '/' << q << '\n';
    }
}
