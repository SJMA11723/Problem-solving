#include <bits/stdc++.h>

using namespace std;

int A, B, N;
bitset<1000000> ap;

int BFS(){
    queue<pair<int, int> > cola;
    pair<int, int> p = {1, 0};
    cola.push(p);

    while(!cola.empty()){
        pair<int, int> act = cola.front();
        cola.pop();

        if(act.first * A == N){
            return act.second + 1;
        } else {
            int nf = act.first * A;
            if(nf > 9999) nf = 1;
            if(!ap[nf]) {
                ap.set(nf);
                cola.push({nf, act.second + 1});
          }
        }

        if(act.first / B == N){
            return act.second + 1;
        } else {
            if(!ap[act.first / B]){
                ap.set(act.first / B);
                cola.push({act.first / B, act.second + 1});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> A >> B >> N;

    ap.reset();

    cout << BFS();

    return 0;
}
