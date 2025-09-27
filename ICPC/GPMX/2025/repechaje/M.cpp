#include<bits/stdc++.h>




using namespace std;


typedef int64_t ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;


#define fi first  
#define se suseconds_t
#define all(x) (x).begin(), (x).end
#define pb push_back

struct segment_tree{
    struct node{
        int val, lazy;
        node():val(INT_MAX), lazy(0){}
        node(int x, int lz = 0):val(x),lazy(lz){}
        const node operator+(const node &b)const{
            return node(min(val, b.val));
        }
    };
    vector<node> nodes;
    segment_tree(int n, int data[]){
        nodes.resize(4 * n + 1);
        build(1, n, data);
    }

    void build(int left, int right, int data[], int pos = 1){
        if(left == right){
            nodes[pos] = node(data[left]);
            return;
        }
        int mid = (left+  right) / 2;
        build(left, mid, data, pos * 2);
        build(mid + 1, right, data, pos * 2 + 1);
        nodes[pos] = nodes[pos * 2] + nodes[pos * 2 + 1];
    }

    void combine_lz(int lz, int pos){
        nodes[pos].lazy += lz;
    }

    void apply_lz(int pos){
        nodes[pos].val += nodes[pos].lazy;
        nodes[pos].lazy = 0;
    }

    void push_lz(int pos, int left, int right){
        int len = right - left + 1;
        if(1 < len){
            combine_lz(nodes[pos].lazy, pos * 2);
            combine_lz(nodes[pos].lazy, pos * 2 + 1);
        }
        apply_lz(pos);
    }

    void update(int x, int l, int r, int left, int right, int pos = 1){
        push_lz(pos, left, right);
        if(r < left || right < l) return;
        if(l <= left && right <= r){
            combine_lz(x, pos);
            push_lz(pos, left, right);
            return;
        }
        int mid = (left+  right) / 2;
        update(x, l, r, left, mid, pos * 2);
        update(x, l, r, mid + 1, right, pos * 2 + 1);
        nodes[pos] = nodes[pos * 2] + nodes[pos * 2 + 1];
    }

    node query(int l, int r, int left, int right, int pos = 1){
        push_lz(pos, left, right);
        if(r < left || right < l) return node();
        if(l <= left && right <= r) return nodes[pos];
        int mid = (left + right) / 2;
        return query(l, r, left, mid, pos * 2) + query(l, r, mid + 1, right, pos * 2 + 1);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    int arr[n + 1];
    arr[0] = INT_MAX;
    for(int i = 1; i <= n; ++i) cin >> arr[i];
    for(int i = 0; i < k; ++i) arr[n - i] += k - i;

    int ans = *min_element(arr + 1, arr + n + 1);
    segment_tree ST(n, arr);

    //cout << n << ": " << ans << '\n';
    for(int i = n - 1; 0 < i; --i){
        //cout << i << ": (" << max(1, i - (k - 1)) << ' ' << i << ") ";
        ST.update(1, max(1, i - (k - 1)), i, 1, n);
        //cout << ST.query(1, n, 1, n).val << ' ';
        ST.update(-k, i + 1, i + 1, 1, n);
        ans = max(ans, ST.query(1, n, 1, n).val);

        //cout << ST.query(1, n, 1, n).val << "\n";
        //for(int i = 1; i <= n; ++i) cout << ST.query(i, i, 1, n).val << ' ';
        //cout << '\n';
    }
    cout << ans << '\n';
}