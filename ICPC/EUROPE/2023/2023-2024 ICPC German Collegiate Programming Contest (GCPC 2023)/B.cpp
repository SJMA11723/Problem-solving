#include <bits/stdc++.h>
#define is_on(n, i) ((n) & (1 << (i)))

using namespace std;

struct point{
    int x, y;

    int operator*(const point &b){
        return x * b.y - b.x * y;
    }

    point operator-(point b){
        return {x - b.x, y - b.y};
    }
};

bool collinear(point a, point b, point c){
    return !((b - a) * (c - a));
}

bool compute(int k, int n, point arr[], bool vis[]){
    bool rem = false;
    for(int i = 0; i < n; ++i) if(!vis[i]) rem = true;

    if(k == 0) return !rem;
    if(!rem) return true;

    vector<int> first;
    for(int i = 0; i < n && first.size() <= k; ++i){
        if(vis[i]) continue;
        first.push_back(i);
    }

    if(first.size() == 1) return true;

    for(int i = 0; i < first.size(); ++i)
    for(int j = i + 1; j < first.size(); ++j){
        vis[ first[i] ] = vis[ first[j] ] = true;
        for(int k = 0; k < n; ++k){
            if(vis[k]) continue;
            if(collinear(arr[ first[i] ], arr[ first[j] ], arr[k])) vis[k] = true;
        }

        if(compute(k - 1, n, arr, vis)) return true;

        for(int k = 0; k < n; ++k){
            if(vis[k]) continue;
            if(collinear(arr[ first[i] ], arr[ first[j] ], arr[k])) vis[k] = false;
        }

        vis[ first[i] ] = vis[ first[j] ] = false;
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    point arr[n];
    for(point &p : arr) cin >> p.x >> p.y;

    if(n <= 6){
        cout << "possible\n";
        return 0;
    }

    bool vis[n] = {};
    cout << (compute(3, n, arr, vis) ? "possible\n" : "impossible\n");
}
