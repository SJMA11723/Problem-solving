#include <bits\stdc++.h>

using namespace std;

bool border(int x, int y, int w, int h){
    return !x || x == w || !y || y == h;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int w, h; cin >> w >> h;
    int n; cin >> n;
    vector<pair<int, int>> arr[4];
    for(int i = 0; i < n; ++i){
        int a, b, c, d; cin >> a >> b >> c >> d;
        if(!border(a, b, w, h) || !border(c, d, w, h)) continue;

        if(a == 0) arr[0].push_back({b, i});
        else if(a == w) arr[2].push_back({b, i});
        else if(b == 0) arr[1].push_back({a, i});
        else if(b == h) arr[3].push_back({a, i});

        if(c == 0) arr[0].push_back({d, i});
        else if(c == w) arr[2].push_back({d, i});
        else if(d == 0) arr[1].push_back({c, i});
        else if(d == h) arr[3].push_back({c, i});
    }
    sort(arr[0].rbegin(), arr[0].rend());
    sort(arr[1].begin(), arr[1].end());
    sort(arr[2].begin(), arr[2].end());
    sort(arr[3].rbegin(), arr[3].rend());

    stack<int> st;
    for(int k = 0; k < 4; ++k){
        for(auto [foo, x] : arr[k]){
            if(st.empty() || st.top() != x) st.push(x);
            else st.pop();
        }
    }
    cout << (st.empty() ? 'Y' : 'N') << '\n';
}
