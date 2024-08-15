#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int arr[n + 1];
    for(int i = 1; i <= n; ++i){
        string s; cin >> s;
        arr[i] = s.size();
    }

    arr[0] = 0;
    for(int i = 1; i <= n; ++i) arr[i] += arr[i - 1];

    const int MAXW = arr[n] + n - 1;
    int ans = INT_MAX;
    for(int w = 1; w <= MAXW; ++w){
        int cur_word = 1, h = 0;
        bool ok = true;
        while(cur_word <= n){
            h++;
            int l = cur_word, r = n + 1;
            while(l < r){
                int mid = l + (r - l) / 2;
                if(arr[mid] - arr[cur_word - 1] + mid - cur_word > w) r = mid;
                else l = mid + 1;
            }
            if(l == cur_word){
                ok = false;
                break;
            }
            cur_word = l;
        }
        if(ok) ans = min(ans, w + h);
    }
    cout << ans << '\n';
}
