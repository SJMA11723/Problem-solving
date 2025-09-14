#include <bits/stdc++.h>
#define MUCHO 100005

using namespace std;

int n, k;
int blocks[MUCHO][2];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int c=0; c < n; c++){
        cin >> blocks[c][0] >> blocks[c][1];
    }
    bool puede = true;
    for(int c=0; c < n; c++){
        int act = blocks[c][0]-1;
        int colAct = blocks[c][1];
        if(blocks[act][1] != colAct)
            puede = false;
    }
    if(puede)
        cout << "Y\n";
    else
        cout << "N\n";
}
