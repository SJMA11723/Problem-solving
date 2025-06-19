#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p){return os << '(' << p.fi << ", " << p.se << ')';}
template<typename C, typename T = typename enable_if<!is_same<C, string>::value, typename C::value_type>::type>
ostream& operator<<(ostream &os, const C &v){string sep; for(const T &x : v) os << sep << x, sep = " "; return os;}
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values){
    cout << "[Debug]\n\t" << vars << " = ";
    string d = "[";
    (..., (cout << d << values, d = "] ["));
    cout << "]\n";
}

typedef uint64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define MAXK 63
#define is_on(s, i) ((s) & (1ll << (i)))

struct node{
    ll val, lazy;
    node():val(LLONG_MAX), lazy(LLONG_MAX){}
    node(ll x, ll lz = LLONG_MAX):val(x), lazy(lz){}
    const node operator+(const node &b)const{
        return node(val & b.val);
    }
};

struct segment_tree{
    vector<node> nodes;
    segment_tree(int n, ll data[]){
        nodes.resize(4 * n + 1);
        build(1, n, data);
    }

    void build(int left, int right, ll data[], int pos = 1){
        if(left == right){
            nodes[pos] = node(data[left]);
            return;
        }
        int mid = (left + right) / 2;
        build(left, mid, data, pos * 2);
        build(mid + 1, right, data, pos * 2 + 1);
        nodes[pos] = nodes[pos * 2] + nodes[pos * 2 + 1];
    }

    void combine_lz(ll lz, int pos){
        nodes[pos].lazy &= lz;
    }

    void apply_lz(int pos){
        nodes[pos].val &= nodes[pos].lazy;
        nodes[pos].lazy = LLONG_MAX;
    }

    void push_lz(int pos, int left, int right){
        int len = right - left + 1;
        if(1 < len){
            combine_lz(nodes[pos].lazy, pos * 2);
            combine_lz(nodes[pos].lazy, pos * 2 + 1);
        }
        apply_lz(pos);
    }

    void update(ll x, bool t, int l, int r, int left, int right, int pos = 1){
        push_lz(pos, left, right);
        if(r < left || right < l) return;
        if(l <= left && right <= r){
            if(t){
                combine_lz(x, pos);
                push_lz(pos, left, right);
            } else nodes[pos].val = x;

            return;
        }
        int mid = (left + right) / 2;
        update(x, t, l, r, left, mid, pos * 2);
        update(x, t, l, r, mid + 1, right, pos * 2 + 1);
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

set<pii>::iterator add_interval(set<pii> &intervals, int l, int r){
    if(l == r) return intervals.end();
    auto it = intervals.lower_bound({l, r}), before = it;

    while(it != intervals.end() && it->fi <= r){
        r = max(r, it->se);
        before = it = intervals.erase(it);
    }

    if(it != intervals.begin() && (--it)->se >= l){
        l = min(l, it->fi);
        r = max(r, it->se);
        intervals.erase(it);
    }

    return intervals.insert(before, {l, r});
}

void remove_interval(set<pii> &intervals, int l, int r){
    if(l == r) return;
    auto it = add_interval(intervals, l, r);
    auto r2 = it->second;
    if(it->first == l) intervals.erase(it);
    else (int &)it->second = l;
    if(r != r2) intervals.emplace(r, r2);
}

int nxt(set<pii> &intervals, int x){
    int res = INT_MAX;
    auto it = intervals.lower_bound({x, -1});
    if(it != intervals.end()) res = it->fi;
    if(it != intervals.begin()){
        it--;
        if(x < it->se) res = x;
    }
    return res;
}

int prv(set<pii> &intervals, int x){
    int res = 0;
    auto it = intervals.lower_bound({x + 1, -1});
    //deb(x, it->fi, it->se);
    if(it != intervals.begin()){
        it--;
        res = min(x, it->se - 1);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q; cin >> n >> q;
    ll arr[n + 1];
    for(int i = 1; i <= n; ++i) cin >> arr[i];

    segment_tree ST(n, arr);
    set<pii> intervals[MAXK + 1];

    for(int k = 0; k <= MAXK; ++k){
        int len = 0;
        for(int i = 1; i <= n; ++i){
            if(!is_on(arr[i], k)) len++;
            else {
                if(len > 0){
                    add_interval(intervals[k], i - len + 1, i + 1);
                }
                len = 0;
            }
        }
        if(len > 0) add_interval(intervals[k], n - len + 1, n + 1);
    }

    while(q--){
        int t; cin >> t;
        if(t == 1){
            int l, r;
            ll x;
            cin >> l >> r >> x;
            ST.update(x, 1, l, r, 1, n);

            for(int k = 0; k <= MAXK; ++k)
                if(!is_on(x, k)) add_interval(intervals[k], l, r + 1);
        } else if(t == 2){
            int s;
            ll x;
            cin >> s >> x;
            ST.update(x, 0, s, s, 1, n);

            for(int k = 0; k <= MAXK; ++k)
            if(is_on(x, k)){
                auto it = intervals[k].lower_bound({s + 1, -1});
                if(it != intervals[k].begin()){
                    it--;
                    /// break interval
                    if(it->fi <= s && s < it->se){
                        int l, r;
                        tie(l, r) = *it;
                        
                        remove_interval(intervals[k], l, r);
                        add_interval(intervals[k], l, s);
                        add_interval(intervals[k], s + 1, r);
                    }
                }
            } else add_interval(intervals[k], s, s + 1);
        } else {
            int l, r; cin >> l >> r;
            bool first = false;
            int pos_first = -1;
            ll ans = ST.query(l, r, 1, n).val;
            
            //deb(ans);

            for(int k = MAXK; 0 <= k; --k){
                if(is_on(ans, k)) continue;

                int left0 = nxt(intervals[k], l);
                int right0 = prv(intervals[k], r);

                //deb(k, left0, right0);

                if(first){
                    if(left0 == right0 && left0 == pos_first)
                        ans += (1ll << k);
                    
                    //cout << " ";
                    //deb(ans);
                } else if(left0 == right0){
                    first = 1;
                    pos_first = left0;
                    ans += (1ll << k);

                    //cout << " First aqui\n";
                    //cout << " ";
                    //deb(pos_first, ans, k);
                }
            }
            cout << ans << '\n';
            //cout << endl;
        }
    }
}