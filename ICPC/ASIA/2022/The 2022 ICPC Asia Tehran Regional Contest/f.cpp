#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

const int64_t MOD = 1e9 + 7;

struct node_row{
    struct ST_row{
        vector<int> nodes;

        ST_row(){}

        ST_row(int n, vi &data){
            nodes.resize(4 * n + 1);
            build(0, n - 1, data);
        }

        void build(int left, int right, vi &data, int pos = 1){
            if(left == right){
                nodes[pos] = data[left];
                return;
            }

            int mid = (left + right) / 2;
            build(left, mid, data, pos * 2);
            build(mid + 1, right, data, pos * 2 + 1);
            nodes[pos] = max(nodes[pos * 2], nodes[pos * 2 + 1]);
        }

        void update(int x, int idx, int left, int right, int pos = 1){
            if(idx < left || right < idx) return;
            if(left == right){
                nodes[pos] = max(nodes[pos], x);
                return;
            }

            int mid = (left + right) / 2;
            update(x, idx, left, mid, pos * 2);
            update(x, idx, mid + 1, right, pos * 2 + 1);
            nodes[pos] = max(nodes[pos * 2], nodes[pos * 2 + 1]);
        }

        int query(int l, int r, int left, int right, int pos = 1){
            if(r < left || right < l || r < l) return INT_MIN;
            if(l <= left && right <= r) return nodes[pos];
            int mid = (left + right) / 2;
            return max(query(l, r, left, mid, pos * 2), query(l, r, mid + 1, right, pos * 2 + 1));
        }
    } seg_tree_row;
    
    int n;
    node_row():n(0){}
    node_row(vi &row){
        n = row.size();
        seg_tree_row = ST_row(n, row);
    }

    int val(int l, int r){
        return seg_tree_row.query(l, r, 0, n - 1);
    }

    const node_row operator+(const node_row &b){
        node_row res = b;
        for(int i = 0; i < n; ++i)
            res.seg_tree_row.update(val(i, i), i, 0, n - 1);
        return res;
    }
};

struct segment_tree{
    vector<node_row> nodes;
    segment_tree(int n, vector<vector<int>> &data){
        nodes.resize(4 * n + 1);
        build(0, n - 1, data);
    }

    void build(int left, int right, vector<vector<int>> &data, int pos = 1){
        if(left == right){
            nodes[pos] = node_row(data[left]);
            return;
        }

        int mid = (left + right) / 2;
        build(left, mid, data, pos * 2);
        build(mid + 1, right, data, pos * 2 + 1);
        nodes[pos] = nodes[pos * 2] + nodes[pos * 2 + 1];
    }

    int query(int l, int r, int a, int b, int left, int right, int pos = 1){
        if(r < left || right < l || r < l) return INT_MIN;
        if(l <= left && right <= r) return nodes[pos].val(a, b);
        int mid = (left + right) / 2;
        return max(query(l, r, a, b, left, mid, pos * 2), query(l, r, a, b, mid + 1, right, pos * 2 + 1));
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    int U[n][m], D[n][m], L[n][m], R[n][m];
    memset(U, -1, sizeof(U));
    memset(D, -1, sizeof(D));
    memset(L, -1, sizeof(L));
    memset(R, -1, sizeof(R));
    for(int i = 0; i < n; ++i){
        stack<int> st;
        for(int j = 0; j < m; ++j){
            cin >> mat[i][j];
            while(st.size() && mat[i][st.top()] < mat[i][j]){
                R[i][st.top()] = j;
                st.pop();
            }
            st.push(j);
        }
        while(st.size()) st.pop();

        for(int j = m - 1; 0 <= j; --j){
            while(st.size() && mat[i][st.top()] < mat[i][j]){
                L[i][st.top()] = j;
                st.pop();
            }
            st.push(j);
        }
        while(st.size()) st.pop();
    }

    for(int j = 0; j < m; ++j){
        stack<int> st;
        for(int i = 0; i < n; ++i){
            while(st.size() && mat[st.top()][j] < mat[i][j]){
                D[st.top()][j] = i;
                st.pop();
            }
            st.push(i);
        }
        while(st.size()) st.pop();

        for(int i = n - 1; 0 <= i; --i){
            while(st.size() && mat[st.top()][j] < mat[i][j]){
                U[st.top()][j] = i;
                st.pop();
            }
            st.push(i);
        }
        while(st.size()) st.pop();
    }

    segment_tree ST(n, mat);

    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            int v = mat[i][j];

            //cout << i << ' ' << j << ':' << endl;
            if(R[i][j] != -1){
                if(D[i][j] != -1 && v < mat[ D[i][j] ][ R[i][j] ] &&
                    ST.query(i + 1, D[i][j] - 1, j + 1, R[i][j], 0, n - 1) < v &&
                    ST.query(D[i][j], D[i][j], j + 1, R[i][j] - 1, 0, n - 1) < v){
                        //cout << i << ' ' << D[i][j] << ' ' << j << ' ' << R[i][j] << endl;
                        ans++;
                    }

                if(U[i][j] != -1 && v < mat[ U[i][j] ][ R[i][j] ] &&
                    ST.query(U[i][j] + 1, i - 1, j + 1, R[i][j], 0, n - 1) < v &&
                    ST.query(U[i][j], U[i][j], j + 1, R[i][j] - 1, 0, n - 1) < v){
                        //cout << U[i][j] << ' ' << i << ' ' << j << ' ' << R[i][j] << endl;
                        ans++;
                    }
            }

            if(L[i][j] != -1){
                if(D[i][j] != -1 && v < mat[ D[i][j] ][ L[i][j] ] &&
                    ST.query(i + 1, D[i][j] - 1, L[i][j], j - 1, 0, n - 1) < v &&
                    ST.query(D[i][j], D[i][j], L[i][j] + 1, j - 1, 0, n - 1) < v){
                        //cout << i << ' ' << D[i][j] << ' ' << L[i][j] << ' ' << j << endl;
                        ans++;
                    }

                if(U[i][j] != -1 && v < mat[ U[i][j] ][ L[i][j] ] &&
                    ST.query(U[i][j] + 1, i - 1, L[i][j], j - 1, 0, n - 1) < v &&
                    ST.query(U[i][j], U[i][j], L[i][j] + 1, j - 1, 0, n - 1) < v){
                        //cout << U[i][j] << ' ' << i << ' ' << L[i][j] << ' ' << j << endl;
                        ans++;
                    }
            }
        }
    }

    cout << ans << '\n';
}