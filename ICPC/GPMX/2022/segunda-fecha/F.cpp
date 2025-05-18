#include <bits/stdc++.h>

using namespace std;

struct punto{
    long long x, y;

    const punto operator-(const punto &b) const {
        punto r;
        r.x = x - b.x;
        r.y = y - b.y;

        return r;
    }

    const long long operator*(const punto &b) const {
        return x * b.y - b.x * y;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;

    punto p[n];

    for(int i = 0; i < n; ++i){
        long long a, b;
        cin >> a >> b;
        p[i].x = a;
        p[i].y = b;
    }

    long long ans = 0;

    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            for(int k = j + 1; k < n; ++k){
                if((p[k] - p[i]) * (p[k] - p[j]) == 0) continue;

                for(int l = k + 1; l < n; ++l){
                    if((p[l] - p[j]) * (p[l] - p[k]) == 0 ||
                       (p[l] - p[k]) * (p[l] - p[i]) == 0 ||
                       (p[l] - p[i]) * (p[l] - p[j]) == 0) continue;
                    ans++;
                }
            }
        }
    }

    cout << ans << '\n';
}