/**
* Author: Mathgic
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct FenwickTree{
    int n, *BIT;

    FenwickTree(int n_size){
        n = n_size;
        BIT = new int[n];
        memset(BIT, 0, sizeof(int) * n);
    }

    void add(int pos, int x){
        while(pos <= n){
            BIT[pos] += x;
            pos += pos & -pos;
        }
    }

    int sum(int pos){
        int ret = 0;
        while(pos){
            ret += BIT[pos];
            pos -= pos & -pos;
        }
        return ret;
    }

    ~FenwickTree(){
        delete[] BIT;
    }
};

unordered_set<int> mset;
vector<int> nums;

/// Se reindexa en 1 porque el BIT esta indexado en 1
int mhash(int x){
    return lower_bound(nums.begin(), nums.end(), x) - nums.begin() + 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q; cin >> n >> q;

    vector<int> arr(n);
    vector<int> queries[q];
    nums.reserve(4e6);
    arr.reserve(2e6);
    mset.reserve(4e6);

    for(int i = 0; i < n ; ++i){
        cin >> arr[i];
        mset.insert(arr[i]);
    }
    sort(arr.begin(), arr.end());

    for(int i = 0; i < q; ++i){
        int t, a; cin >> t >> a;
        queries[i].push_back(t);
        queries[i].push_back(a);
        mset.insert(a);
        mset.insert(a - 1);
        if(t == 2){
            int b; cin >> b;
            queries[i].push_back(b);
            mset.insert(b);
        }
    }

    FenwickTree BIT(mset.size() + 2);

    for(auto &it : mset) nums.push_back(it);
    sort(nums.begin(), nums.end());

    for(int &it : arr) BIT.add(mhash(it), 1);

    for(vector<int> &query : queries){
        int t, a, b;
        t = query[0];
        a = query[1];
        if(t == 1){
            int pos = lower_bound(arr.begin(), arr.end(), a) - arr.begin();
            if(pos == arr.size()) arr.push_back(a);
            else {
                BIT.add(mhash(arr[pos]), -1);
                arr[pos] = a;
            }
            BIT.add(mhash(a), 1);
        } else {
            b = query[2];
            cout << BIT.sum(mhash(b)) - BIT.sum(mhash(a - 1)) << '\n';
        }
    }
}
