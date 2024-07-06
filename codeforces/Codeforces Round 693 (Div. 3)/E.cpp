/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct shape{
    int h, w;
    int i;

    bool operator<(const shape &o){
        return make_pair(h, w) < make_pair(o.h, o.w);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        shape arr[n], rot_arr[n];
        for(int i = 0; i < n; ++i){
            int h, w; cin >> h >> w;
            arr[i] = {h, w, i};
            rot_arr[i] = {w, h, i};
        }
        sort(arr, arr + n);
        sort(rot_arr, rot_arr + n);

        int ans[n];
        fill(ans, ans + n, -1);

        int mini = INT_MAX, idx_min, j = 0;
        for(int i = 0; i < n; ++i){
            while(j < n && arr[j].h < arr[i].h){
                if(arr[j].w < mini){
                    mini = arr[j].w;
                    idx_min = j;
                }
                j++;
            }
            if(arr[idx_min].h < arr[i].h && mini < arr[i].w) ans[arr[i].i] = arr[idx_min].i + 1;
        }

        mini = INT_MAX;
        j = 0;
        for(int i = 0; i < n; ++i){
            while(j < n && rot_arr[j].h < arr[i].h){
                if(rot_arr[j].w < mini){
                    mini = rot_arr[j].w;
                    idx_min = j;
                }
                j++;
            }
            if(rot_arr[idx_min].h < arr[i].h && mini < arr[i].w) ans[arr[i].i] = rot_arr[idx_min].i + 1;
        }

        for(int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
    }
}
