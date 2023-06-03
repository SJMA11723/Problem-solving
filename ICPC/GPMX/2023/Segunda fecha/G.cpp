#include <bits/stdc++.h>
#define MAXN 100001

using namespace std;

vector<int> grafo[MAXN];
int entra[MAXN], sale[MAXN];
int maxE, maxS;
long long w;

bitset<100001> idxE, idxS, cero;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, t; cin >> n >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        grafo[a].push_back(b);
        entra[b]++;
        sale[a]++;

        if(maxE < entra[b]){
            idxE = idxE & cero;
            idxE.set(b);
            maxE = entra[b];
        } else if(maxE == entra[b]){
            idxE.set(b);
        }

        if(maxS < sale[a]){
            idxS = idxS & cero;
            idxS.set(a);
            maxS = sale[a];
        } else if(maxS == sale[a]){
            idxS.set(a);
        }

        w += grafo[b].size() + entra[a];
        if(a == b) w--;
        //cout << "M: " << maxE << ' ' << maxS << '\n';
        int num2 = maxE + maxS;
        bitset<100001> in = idxE & idxS;
        if(in.count()) num2++;
        cout << w << ' ' << num2 << '\n';
    }
    return 0;
}
