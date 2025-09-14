#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

struct segment_tree{
    struct node{
        vector<int> nums;
        node(){}
        node(vector<int> &oset): nums(oset){}
        const node operator+(const node &b)const{
            vector<int> res(nums.size() + b.nums.size());

            int tam1 = nums.size(), tam2 = b.nums.size();
            for(int i = 0, idx1 = 0, idx2 = 0; i < res.size(); ++i){
                if(idx1 < tam1 && idx2 < tam2){
                    res[i] = nums[idx1] < b.nums[idx2] ? nums[idx1++] : b.nums[idx2++];
                } else {
                    res[i] = idx1 < tam1 ? nums[idx1++] : b.nums[idx2++];
                }
            }
            return node(res);
        }

        int smaller(int x){
            return nums.end() - upper_bound(nums.begin(), nums.end(), x - 1);
        }
    };
    vector<node> nodes;
    segment_tree(int n, int data[]){
        nodes.resize(4 * n + 1);
        build(1, n, data);
    }

    void build(int left, int right, int data[], int pos = 1){
        if(left == right){
            nodes[pos].nums.push_back(data[left]);
            return;
        }

        int mid = left + (right - left) / 2;
        build(left, mid, data, pos * 2);
        build(mid + 1, right, data, pos * 2 + 1);
        nodes[pos] = nodes[pos * 2] + nodes[pos * 2 + 1];
    }

    int query(int x, int l, int r, int left, int right, int pos = 1){
        if(r < left || right < l) return 0;
        if(l <= left && right <= r) return nodes[pos].smaller(x);
        int mid = left + (right - left) / 2;
        return query(x, l, r, left, mid, pos * 2) + query(x, l, r, mid + 1, right, pos * 2 + 1);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int Y, N; cin >> Y >> N;
    int arr[Y + 1];
    for(int i = 1; i <= Y; ++i) cin >> arr[i];

    segment_tree seg_tree(Y, arr);

    for(int i = 0; i < N; ++i){
        int a, p, f; cin >> a >> p >> f;

        if(arr[a] >= p || !f) cout << "0\n";
        else cout << seg_tree.query(p, a + 1, a + f, 1, Y) << '\n';
    }
}
