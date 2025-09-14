#include <bits/stdc++.h>

using namespace std;

int64_t MAXN = 1e18 + 1e9;

struct node{
    int64_t val, lazy, mini, maxi;
    node *left = nullptr, *right = nullptr;
    node(): val(0), lazy(0), mini(0), maxi(0){}
    node(int64_t x): val(x), lazy(0), mini(x), maxi(x){}
};


void combine_lazy(int64_t lz, node *u){
    u->lazy += lz;
}

void apply_lazy(node *u){
    u->val += u->lazy;
    u->mini += u->lazy;
    u->maxi += u->lazy;
    u->lazy = 0;
}

void push_lazy(node *u, int64_t L, int64_t R){
    int len = R - L + 1;
    int64_t mid = L + (R - L) / 2;
    if(len){
        if(u->left == nullptr) u->left = new node;
        if(u->right == nullptr) u->right = new node;

        combine_lazy(u->lazy, u->left);
        combine_lazy(u->lazy, u->right);
    }
    apply_lazy(u);
}

void update(int64_t x, int64_t l, int64_t r, int64_t L, int64_t R, node *u){
    push_lazy(u, L, R);
    if(r < L || R < l) return;
    if(l <= L && R <= r){
        combine_lazy(x, u);
        push_lazy(u, L, R);
        return;
    }

    int64_t mid = L + (R - L) / 2;

    if(u->left == nullptr) u->left = new node;
    if(u->right == nullptr) u->right = new node;

    update(x, l, r, L, mid, u->left);
    update(x, l, r, mid + 1, R, u->right);

    u->mini = min(u->left->mini, u->right->mini);
    u->maxi = max(u->left->maxi, u->right->maxi);
}

/// min-max
void query(int64_t l, int64_t r, int64_t L, int64_t R, node *u, int64_t &mini, int64_t &maxi){
    if(u == nullptr) return;
    push_lazy(u, L, R);
    if(r < L || R < l) return;
    if(l <= L && R <= r){
        //cout << L << ' ' << R << ' ' << u->mini << ' ' << u->maxi << endl;
        mini = min(mini, u->mini);
        maxi = max(maxi, u->maxi);
        //return {u->mini, u->maxi};
        return;
    }

    int64_t mid = L + (R - L) / 2;
    query(l, r, L, mid, u->left, mini, maxi);
    query(l, r, mid + 1, R, u->right, mini, maxi);
    //return {min(qleft.first, qright.first), max(qleft.second, qright.second)};
}

void dfs_delete(node *u){
    if(u->left) dfs_delete(u->left);
    if(u->right) dfs_delete(u->right);
    delete u;
    u = nullptr;
}

struct Q{
    char c;
    int64_t len, p;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    pair<pair<int64_t, int64_t>, int> intervals[n];
    Q queries[n];

    for(int i = 0; i < n; ++i){
        char c; cin >> c;
        int64_t len, p; cin >> len >> p;
        queries[i] = {c, len, p};
        if(c == '-') intervals[i] = {{p, p + len - 1}, i};
        else intervals[i] = {{p, p}, i};
    }
    sort(intervals, intervals + n);

    int64_t acc = 0;
    MAXN = 0;
    for(int i = 0; i < n; ++i){
        int64_t &l = intervals[i].first.first;
        int64_t &r = intervals[i].first.second;

        l -= acc;
        r -= acc;

        //cout << "-------\n";
        //cout << l << ' ' << r << '\n';

        int64_t diff = max(0ll, l - MAXN - 1);
        l -= diff;
        r -= diff;
        MAXN = max(MAXN, r);
        acc += diff;

        //cout << l << ' ' << r << ' ' << MAXN << '\n';

        int idx = intervals[i].second;
        queries[idx].p = l;
    }


    node *root = new node;

    for(int i = 0; i < n; ++i){
        char c = queries[i].c;
        int64_t len = queries[i].len;
        int64_t p = queries[i].p;
        if(c == '-'){
            int64_t mini = LLONG_MAX, maxi = LLONG_MIN;
            query(p, p + len - 1, 1, MAXN, root, mini, maxi);

            //cout << "hola " << mini << ' ' << maxi << endl;

            if(mini == maxi){
                update(1, p, p + len - 1, 1, MAXN, root);
                cout << 'S';
            } else cout << 'U';
        } else {
            update(len, p, p, 1, MAXN, root);
            cout << 'S';
        }
    }
    cout << '\n';

    //dfs_delete(root);
}
