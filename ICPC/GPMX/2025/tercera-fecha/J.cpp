#include <bits/stdc++.h>

using namespace std;


struct node{
    int val, lazy;
    node(): val(0), lazy(0){}
    node(int x, int lz = 0):val(x), lazy(lz){}
    const node operator+(const node &b)const{
        return node(val ^ b.val);
    }
};

struct segment_tree{
    vector <node> nodes;
    segment_tree(int n, int* data){
        nodes.resize(4 *n+1);
        build(1,n, data);
    }

    void build(int left , int right, int* data, int pos = 1){
        if(left == right){
            nodes[pos] = node(data[left]);
            return;
        }

        int mid = (left + right)/2;
        build(left, mid, data, pos*2);
        build(mid+1, right, data, pos*2+1);
        nodes[pos] = nodes[pos*2]+ nodes[pos*2+1];
    }

    void update(int x, int idx, int left, int right, int pos = 1){
        if(idx < left || right < idx) return;
        if(left == right){
            nodes[pos].val += x;
            return;
        }

        int mid = (left + right)/2;
        update(x, idx, left, mid, pos*2);
        update(x, idx, mid+1, right, pos*2+1);

        nodes[pos] = nodes[pos*2]+nodes[pos*2+1];
    }

    node query(int l , int r , int left, int right, int pos = 1){
        if(r < left || right < l) return node();
        if(l <= left && right <= r)return nodes[pos];

        int mid = (left+right)/2;
        return query(l,r, left, mid, pos*2)+query(l, r, mid+1, right, pos*2+1);
    }
};



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin>>n>>q;
    int arr[n + 1];

    for(int x = 1; x <= n; x++) cin>>arr[x];

    segment_tree st(n, arr);
    while(q--){
        char c;
        int l, r;

        cin>>c>>l>>r;
        if(c == 'P'){
            int qq = st.query(l, r, 1, n).val;
            if(qq == 0)cout<<"JUAN\n";
            else cout<<"FRANK\n";

        }
        else{
            st.update(r, l, 1, n);
        }
    }



    return 0;
}