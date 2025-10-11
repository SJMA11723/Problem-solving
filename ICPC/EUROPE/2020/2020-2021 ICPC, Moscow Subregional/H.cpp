#include <bits/stdc++.h>

using namespace std;

int t;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for(int i=0; i < t; i++){
        int a,x,b,y;
        cin >> a >> x >> b >> y;

        if(!a && !b){
            cout << "Yes\n";
            continue;
        }

        if(!x && !y){
            cout << "No\n";
            continue;
        }

        if(b >= a + 2){
            cout << "Yes\n";
            continue;
        }

        if(a == 1 || b == 1){
            cout << "Yes\n";
            continue;
        }

        /// a = b
        if(a == b){
            if(a == 2 && y) cout << "Yes\n";
            else if(x && y) cout << "Yes\n";
            else cout << "No\n";
            continue;
        }

        /// a + 1 = b
        if(b == 3 && y) cout << "Yes\n";
        else if(x && y) cout << "Yes\n";
        else cout << "No\n";
    }
}
