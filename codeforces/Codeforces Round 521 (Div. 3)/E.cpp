/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    map<int, int> freq;
    while(n--){
        int x; cin >> x;
        freq[x]++;
    }

    vector<int> sorted;
    for(auto [v, f] : freq) sorted.push_back(f);
    sort(sorted.begin(), sorted.end());

    int ans = 0, ptr_first = 0;
    for(int init = 1; init <= sorted.back(); ++init){
        while(sorted[ptr_first] < init) ptr_first++;

        int cnt = init, target = init;
        int last = ptr_first;
        while(last < sorted.size()){
            target *= 2;

            int l = last + 1, r = sorted.size();
            while(l < r){
                int mid = l + (r - l) / 2;
                if(target <= sorted[mid]) r = mid;
                else l = mid + 1;
            }

            last = l;
            if(l < sorted.size()) cnt += target;
        }

        ans = max(ans, cnt);
    }

    cout << ans << '\n';
}
