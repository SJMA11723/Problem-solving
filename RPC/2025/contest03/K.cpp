#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int arr[n];
    for(int &x : arr){
        cin >> x;
        x--;
    }
    bool vis[n] = {};
    int cur = 0, ans = 0;
    while(!vis[cur]){
        vis[cur] = true;
        ans++;
        cur = arr[cur];
    }
    cout << ans << '\n';
}
