#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, res = 0;
    cin >> n;
    while(n--){
        int con = 0;
        for(int i = 0; i < 3; ++i){
            int x;
            cin >> x;
            con += x;
        }
        if(2 <= con) res++;
    }
    cout << res;
}