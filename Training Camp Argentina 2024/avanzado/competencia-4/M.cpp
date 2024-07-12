/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool check(int n, int a[], int k, int h){
    int64_t sum = 0;
    priority_queue<int> pq;
    for(int i = 0; i < k; ++i) pq.push(a[i]);

    while(pq.size()){
        sum += pq.top();
        pq.pop();
        if(pq.size()) pq.pop();
    }

    return sum <= h;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, h; cin >> n >> h;
    int a[n];
    for(int &x : a) cin >> x;

    int l = 1, r = n + 1;
    while(l < r){
        int mid = l + (r - l) / 2;
        if(check(n, a, mid, h)) l = mid + 1;
        else r = mid;
    }
    cout << l - 1 << '\n';
}
