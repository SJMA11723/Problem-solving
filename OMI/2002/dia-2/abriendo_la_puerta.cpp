#include <bits/stdc++.h>

using namespace std;

int p, r;
int nextNode[20000], prevNode[20000];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> p >> r;
    r--;

    for(int i = 0; i < p; ++i){
        nextNode[i] = i + 1;
        prevNode[i] = i - 1;
    }

    int pos = 0;

    nextNode[p - 1] = 0;
    prevNode[0] = p - 1;

    for(int i = 1; i < p; ++i){
        int x; cin >> x;

        nextNode[ prevNode[pos] ] = nextNode[pos];
        prevNode[ nextNode[pos] ] = prevNode[pos];

        while(x--){
            pos = nextNode[pos];
        }
    }

    cout << 1 + (p + r - pos) % p;
}
