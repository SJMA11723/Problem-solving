#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n;
        char c;
        cin >> n >> c;
        string str;
        cin >> str;

        if(c == 'g'){
            cout << "0\n";
            continue;
        }

        n *= 2;
        str += str;

        int ans = 0;
        stack<int> pila;
        for(int i = 0; i < n; ++i){
            if(str[i] == c){
                pila.push(i);
            } else if(str[i] == 'g'){
                while(pila.size()){
                    ans = max(ans, i - pila.top());
                    pila.pop();
                }
            }
        }

        cout << ans << '\n';
    }
}
