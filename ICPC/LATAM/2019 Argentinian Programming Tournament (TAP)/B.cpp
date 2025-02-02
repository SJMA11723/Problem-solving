#include <bits/stdc++.h>

using namespace std;

struct circle{
    int h, k, r;
};

bool intersection(circle A, circle B){
    int dx = A.h - B.h;
    int dy = A.k - B.k;
    int d = dx * dx + dy * dy;
    int sr = A.r + B.r;
    if(d > sr * sr) return false;
    if(d == sr * sr) return true;
    return sqrt(d) + min(A.r, B.r) >= max(A.r, B.r);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    circle arr[n];
    bool ok = true;
    for(int i = 0; i < n; ++i){
        int h, k, r; cin >> h >> k >> r;
        arr[i] = {h, k, r};
        for(int j = 0; j < i; ++j) ok = ok && !intersection(arr[i], arr[j]);
    }

    cout << (ok ? "SI\n" : "NO\n");
}
