/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define fi first
#define se second

using namespace std;

struct pos{
    int val, freq;
    int64_t sum;
};

bool check(int idx, vector<pos> &arr){
    int64_t sum = arr[idx].sum;
    //cout << "Llega " << arr[idx].val << ' ' << sum << endl;
    while(sum < arr.back().val){
        int l = 0, r = arr.size();
        while(l < r){
            int mid = l + (r - l) / 2;
            //cout << "    " << l << ' ' << r << ' ' << mid << ' ' << arr[mid].val << endl;
            if(sum < arr[mid].val) r = mid;
            else l = mid + 1;
        }
        if(l < arr.size() && idx + 1 == l) return false;
        l--;
        idx = l;
        sum = arr[idx].sum;
        //cout << "  SUM = " << sum << ' ' << idx << '\n';
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        map<int, vector<int>> cub;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            cub[x].pb(i + 1);
        }

        vector<pos> arr;
        for(auto &it : cub) arr.pb({it.fi, it.se.size(), 1ll * it.fi * it.se.size() + (arr.empty() ? 0 : arr.back().sum)});

        int l = 0, r = arr.size();
        while(l < r){
            //cout << l << ' ' << r << endl;
            int mid = l + (r - l) / 2;
            if(check(mid, arr)) r = mid;
            else l = mid + 1;
        }


        int target_val = INT_MAX;
        if(r < arr.size()) target_val = arr[r].val;

        //cout  << "Fin: " << l << ' ' << target_val << endl;

        vector<int> ans;
        for(auto &it : cub)
        if(it.fi >= target_val)
            for(int x : it.se) ans.pb(x);

        sort(all(ans));
        cout << ans.size() << '\n';
        for(int i = 0; i < ans.size(); ++i) cout << ans[i] << " \n"[i + 1 == ans.size()];
    }
}
