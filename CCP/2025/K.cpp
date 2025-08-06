#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    priority_queue<pair<int, int>> pq;
    for(int i = 1; i <= n; ++i){
        int x; cin >> x;
        pq.push({x, i});
        if(i >= k){
            while(pq.top().second <= i - k) pq.pop();
            cout << pq.top().first << ' ';
        }
    }
}