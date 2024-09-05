/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 1000'000

using namespace std;

const int BLOCK_SIZE = 100;

struct query{
    int l, r, block, i;
    bool operator<(const query &b)const{
        if(block == b.block) return r < b.r;
        return block < b.block;
    }
};


int cub[MAXN + 1], cnt_diff[MAXN];
set<int> nums;
priority_queue<int, vector<int>, greater<int>> min_diff;

void add(int x){
    if(cub[x]){
        cub[x]++;
        cnt_diff[0]++;
        if(cnt_diff[0] == 1) min_diff.push(0);
        return;
    }

    if(nums.size()){
        auto r = nums.upper_bound(x);
        if(r != nums.end()){
            cnt_diff[*r - x]++;
            if(cnt_diff[*r - x] == 1) min_diff.push(*r - x);
        }

        auto l = r;

        if(l != nums.begin()){
            l--;
            cnt_diff[x - *l]++;
            if(cnt_diff[x - *l] == 1) min_diff.push(x - *l);

            if(r != nums.end()) cnt_diff[*r - *l]--;
        }
    }

    cub[x]++;
    nums.insert(x);
}

void remove(int x){
    if(cub[x] > 1){
        cub[x]--;
        cnt_diff[0]--;
        return;
    }

    auto r = nums.upper_bound(x);
    auto l = r; l--;

    if(r != nums.end()) cnt_diff[*r - x]--;

    if(l != nums.begin()) cnt_diff[x - *(--l)]--;

    if(r != nums.end() && *l != x){
        cnt_diff[*r - *l]++;
        if(cnt_diff[*r - *l] == 1) min_diff.push(*r - *l);
    }

    cub[x]--;
    nums.erase(x);
}

int get_answer(){
    while(!cnt_diff[min_diff.top()]) min_diff.pop();
    return min_diff.top();
}

vector<int> solve(vector<query> &queries, int arr[]){
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());
    int cur_l = 0;
    int cur_r = -1;
    for(query &q : queries){
        while(cur_l > q.l) add(arr[--cur_l]);
        while(cur_r < q.r) add(arr[++cur_r]);
        while(cur_l < q.l) remove(arr[cur_l++]);
        while(cur_r > q.r) remove(arr[cur_r--]);
        answers[q.i] = get_answer();
    }
    return answers;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int arr[n];
    for(int &x : arr) cin >> x;

    int q; cin >> q;
    vector<query> queries;
    for(int i = 0; i < q; ++i){
        int l, r; cin >> l >> r;
        l--, r--;
        queries.push_back({l, r, l / BLOCK_SIZE, i});
    }

    vector<int> ans = solve(queries, arr);

    for(int d : ans) cout << d << '\n';
}
