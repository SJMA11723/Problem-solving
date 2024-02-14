/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 3001

using namespace std;

struct dsu{
    int P[MAXN], RA[MAXN], cnt_comp;
    vector<char> ap;

    dsu(){
        fill(P, P + MAXN, -1);
        fill(RA, RA + MAXN, -1);
        ap.resize(MAXN);
        cnt_comp = 0;
    }

    dsu(int n){
        ap.resize(n + 1);
        for(int i = 1; i <= n; ++i){
            RA[i] = 1;
            P[i] = i;
            ap[i] = true;
        }
        cnt_comp = n;
    }

    void make_set(int x){
        P[x] = x;
        RA[x] = 1;
        ap[x] = true;
        cnt_comp++;
    }

    int root(int x){
        while(x != P[x]) x = P[x];
        return x;
    }

    void join(int x, int y){
        int Px = root(x);
        int Py = root(y);

        if(Px == Py) return;

        if(RA[Px] > RA[Py]) swap(Px, Py);
        RA[Py] += RA[Px];
        P[Px] = Py;
        cnt_comp--;
    }

    bool exists(int x){
        return ap[x];
    }
};

vector<int> grafo[MAXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ifstream in("closing.in");
    ofstream out("closing.out");

    int n, m;
    in >> n >> m;
    while(m--){
        int a, b;
        in >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    dsu sets;
    int queries[n];
    vector<char> ans(n);
    for(int i = 0; i < n; ++i) in >> queries[i];

    for(int i = n - 1; 0 <= i; --i){
        int x = queries[i];
        sets.make_set(x);

        for(int v : grafo[x])
            if(sets.exists(v))
                sets.join(x, v);

        ans[i] = sets.cnt_comp == 1 ? true : false;
    }

    for(int i = 0; i < n; ++i) ans[i] ? out << "YES\n" : out << "NO\n";
}
